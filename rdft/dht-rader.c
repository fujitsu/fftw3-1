/*
 * Copyright (c) 2003 Matteo Frigo
 * Copyright (c) 2003 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include "rdft.h"

/*
 * Compute DHTs of prime sizes using Rader's trick: turn them
 * into convolutions of size n - 1, which we then perform via a pair
 * of FFTs.   (We can then do prime real FFTs via rdft-dht.c.)
 *
 * Optionally (determined by the "pad" field of the solver), we can
 * perform the (cyclic) convolution by zero-padding to a size
 * >= 2*(n-1) - 1.  This is advantageous if n-1 has large prime factors.
 *
 */

typedef struct {
     solver super;
     int pad;
} S;

typedef struct {
     plan_rdft super;

     plan *cld1, *cld2;
     R *omega;
     int n, npad, g, ginv;
     int is, os;
     plan *cld_omega;
} P;

static rader_tl *omegas = 0;

/***************************************************************************/

static void apply(const plan *ego_, R *I, R *O)
{
     const P *ego = (const P *) ego_;
     int n = ego->n;
     int npad = ego->npad; /* == n - 1 for unpadded Rader; always even */
     int is = ego->is, os;
     int k, gpower, g;
     R *buf, *omega;
     R r0;

     buf = (R *) MALLOC(sizeof(R) * npad, BUFFERS);

     /* First, permute the input, storing in buf: */
     g = ego->g; 
     for (gpower = 1, k = 0; k < n - 1; ++k, gpower = MULMOD(gpower, g, n)) {
	  buf[k] = I[gpower * is];
     }
     /* gpower == g^(n-1) mod n == 1 */;

     A(n - 1 <= npad);
     for (k = n - 1; k < npad; ++k) /* optionally, zero-pad convolution */
	  buf[k] = 0;

     os = ego->os;

     /* compute RDFT of buf, storing in buf (i.e., in-place): */
     {
	    plan_rdft *cld = (plan_rdft *) ego->cld1;
	    cld->apply((plan *) cld, buf, buf);
     }

     /* set output DC component: */
     O[0] = (r0 = I[0]) + buf[0];

     /* now, multiply by omega: */
     omega = ego->omega;
     buf[0] *= omega[0];
     for (k = 1; k < npad/2; ++k) {
	  E rB, iB, rW, iW;
	  rW = omega[k];
	  iW = omega[npad - k];
	  rB = buf[k];
	  iB = buf[npad - k];
	  buf[k] = rW * rB - iW * iB;
	  buf[npad - k] = rW * iB + iW * rB;
     }
     /* Nyquist component: */
     A(k + k == npad); /* since npad is even */
     buf[k] *= omega[k];
     
     /* this will add input[0] to all of the outputs after the ifft */
     buf[0] += (npad == n - 1) ? r0 : (r0 * 0.5);

     /* inverse FFT: */
     {
	    plan_rdft *cld = (plan_rdft *) ego->cld2;
	    cld->apply((plan *) cld, buf, buf);
     }

     /* do inverse permutation to unshuffle the output;
	also "fold" padded outputs (if any) back to get cyclic convolution */
     A(gpower == 1);
     g = ego->ginv;
     if (npad == n - 1) {
	  for (k = 0; k < n - 1; ++k, gpower = MULMOD(gpower, g, n)) {
	       O[gpower * os] = buf[k];
	  }
     }
     else {
	  A(npad >= 2*(n - 1) - 1);
	  for (k = 0; k < n - 1; ++k, gpower = MULMOD(gpower, g, n)) {
	       O[gpower * os] = buf[k] + buf[k + (n - 1)];
	  }
     }
     A(gpower == 1);

     X(ifree)(buf);
}

static R *mkomega(plan *p_, int n, int npad, int ginv)
{
     plan_rdft *p = (plan_rdft *) p_;
     R *omega;
     int i, gpower;
     trigreal scale;

     if ((omega = X(rader_tl_find)(n, npad + 1, ginv, omegas))) 
	  return omega;

     omega = (R *)MALLOC(sizeof(R) * npad, TWIDDLES);

     scale = npad; /* normalization for convolution */

     for (i = 0, gpower = 1; i < n-1; ++i, gpower = MULMOD(gpower, ginv, n)) {
	  omega[i] = (X(cos2pi)(gpower, n) + X(sin2pi)(gpower, n)) / scale;
     }
     A(gpower == 1);

     for (; i < npad; ++i)
	  omega[i] = 0.0;

     AWAKE(p_, 1);
     p->apply(p_, omega, omega);
     AWAKE(p_, 0);

     X(rader_tl_insert)(n, npad + 1, ginv, omega, &omegas);
     return omega;
}

static void free_omega(R *omega)
{
     X(rader_tl_delete)(omega, &omegas);
}

/***************************************************************************/

static void awake(plan *ego_, int flg)
{
     P *ego = (P *) ego_;

     AWAKE(ego->cld1, flg);
     AWAKE(ego->cld2, flg);

     if (flg) {
	  if (!ego->omega) 
	       ego->omega = mkomega(ego->cld_omega,ego->n,ego->npad,ego->ginv);
     } else {
	  free_omega(ego->omega);
	  ego->omega = 0;
     }
}

static void destroy(plan *ego_)
{
     P *ego = (P *) ego_;
     X(plan_destroy_internal)(ego->cld_omega);
     X(plan_destroy_internal)(ego->cld2);
     X(plan_destroy_internal)(ego->cld1);
}

static void print(const plan *ego_, printer *p)
{
     const P *ego = (const P *) ego_;

     p->print(p, "(dht-rader-%d-%d%ois=%oos=%(%p%)",
              ego->n, ego->npad, ego->is, ego->os, ego->cld1);
     if (ego->cld2 != ego->cld1)
          p->print(p, "%(%p%)", ego->cld2);
     if (ego->cld_omega != ego->cld1 && ego->cld_omega != ego->cld2)
          p->print(p, "%(%p%)", ego->cld_omega);
     p->putchr(p, ')');
}

static int applicable0(const problem *p_)
{
     if (RDFTP(p_)) {
          const problem_rdft *p = (const problem_rdft *) p_;
          return (1
		  && p->sz->rnk == 1
		  && p->vecsz->rnk == 0
		  && p->kind[0] == DHT
		  && X(is_prime)(p->sz->dims[0].n)
		  && p->sz->dims[0].n > 2
	       );
     }

     return 0;
}

static int applicable(const solver *ego, const problem *p, const planner *plnr)
{
     UNUSED(ego);
     return (!NO_UGLYP(plnr) && applicable0(p));
}

static int choose_transform_size(int minsz)
{
     static const int primes[] = { 2, 3, 5, 0 };
     while (!X(factors_into)(minsz, primes) || minsz % 2)
	  ++minsz;
     return minsz;
}

static plan *mkplan(const solver *ego_, const problem *p_, planner *plnr)
{
     const S *ego = (const S *) ego_;
     const problem_rdft *p = (const problem_rdft *) p_;
     P *pln;
     int n, npad;
     int is, os;
     plan *cld1 = (plan *) 0;
     plan *cld2 = (plan *) 0;
     plan *cld_omega = (plan *) 0;
     R *buf = (R *) 0;
     R *O;
     problem *cldp;

     static const plan_adt padt = {
	  X(rdft_solve), awake, print, destroy
     };

     if (!applicable(ego_, p_, plnr))
	  return (plan *) 0;

     n = p->sz->dims[0].n;
     is = p->sz->dims[0].is;
     os = p->sz->dims[0].os;
     O = p->O;

     if (ego->pad)
	  npad = choose_transform_size(2 * (n - 1) - 1);
     else
	  npad = n - 1;

     /* initial allocation for the purpose of planning */
     buf = (R *) MALLOC(sizeof(R) * npad, BUFFERS);

     cld1 = X(mkplan_d)(plnr, 
			X(mkproblem_rdft_1_d)(X(mktensor_1d)(npad, 1, 1),
					      X(mktensor_1d)(1, 0, 0),
					      buf, buf,
					      R2HC));
     if (!cld1) goto nada;

     cldp =
          X(mkproblem_rdft_1_d)(
               X(mktensor_1d)(npad, 1, 1),
               X(mktensor_1d)(1, 0, 0),
	       buf, buf, 
	       HC2R
	       );
     if (!(cld2 = X(mkplan_d)(plnr, cldp))) goto nada;


     /* plan for omega */
     plnr->planner_flags |= ESTIMATE;
     cld_omega = X(mkplan_d)(plnr, 
			     X(mkproblem_rdft_1_d)(X(mktensor_1d)(npad, 1, 1),
						   X(mktensor_1d)(1, 0, 0),
						   buf, buf, R2HC));
     if (!cld_omega) goto nada;

     /* deallocate buffers; let awake() or apply() allocate them for real */
     X(ifree)(buf);
     buf = 0;

     pln = MKPLAN_RDFT(P, &padt, apply);
     pln->cld1 = cld1;
     pln->cld2 = cld2;
     pln->cld_omega = cld_omega;
     pln->omega = 0;
     pln->n = n;
     pln->npad = npad;
     pln->is = is;
     pln->os = os;
     pln->g = X(find_generator)(n);
     pln->ginv = X(power_mod)(pln->g, n - 2, n);
     A(MULMOD(pln->g, pln->ginv, n) == 1);

     X(ops_add)(&cld1->ops, &cld2->ops, &pln->super.super.ops);
     pln->super.super.ops.other += (npad/2-1)*6 + npad + n + (n-1) * ego->pad;
     pln->super.super.ops.add += (npad/2-1)*2 + 2 + (n-1) * ego->pad;
     pln->super.super.ops.mul += (npad/2-1)*4 + 2 + ego->pad;

     return &(pln->super.super);

 nada:
     X(ifree0)(buf);
     X(plan_destroy_internal)(cld_omega);
     X(plan_destroy_internal)(cld2);
     X(plan_destroy_internal)(cld1);
     return 0;
}

/* constructors */

static solver *mksolver(int pad)
{
     static const solver_adt sadt = { mkplan };
     S *slv = MKSOLVER(S, &sadt);
     slv->pad = pad;
     return &(slv->super);
}

void X(dht_rader_register)(planner *p)
{
     REGISTER_SOLVER(p, mksolver(0));
     REGISTER_SOLVER(p, mksolver(1));
}
