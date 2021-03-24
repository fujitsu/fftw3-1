/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Wed Mar 24 13:54:39 JST 2021 */

#include "rdft/codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_hc2hc.native -fma -compact -variables 4 -pipeline-latency 4 -sign 1 -n 3 -dif -name hb_3 -include rdft/scalar/hb.h */

/*
 * This function contains 16 FP additions, 14 FP multiplications,
 * (or, 6 additions, 4 multiplications, 10 fused multiply/add),
 * 17 stack variables, 2 constants, and 12 memory accesses
 */
#include "rdft/scalar/hb.h"

static void hb_3(R *cr, R *ci, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 4); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 4, MAKE_VOLATILE_STRIDE(6, rs)) {
	       E T1, T4, T6, Tg, Td, Te, T9, Tf;
	       {
		    E T2, T3, T7, T8;
		    T1 = cr[0];
		    T2 = cr[WS(rs, 1)];
		    T3 = ci[0];
		    T4 = T2 + T3;
		    T6 = FNMS(KP500000000, T4, T1);
		    Tg = T2 - T3;
		    Td = ci[WS(rs, 2)];
		    T7 = ci[WS(rs, 1)];
		    T8 = cr[WS(rs, 2)];
		    Te = T7 - T8;
		    T9 = T7 + T8;
		    Tf = FNMS(KP500000000, Te, Td);
	       }
	       cr[0] = T1 + T4;
	       ci[0] = Td + Te;
	       {
		    E Th, T5, Tb, Tc, Ti, Ta;
		    Th = FMA(KP866025403, Tg, Tf);
		    Ta = FNMS(KP866025403, T9, T6);
		    T5 = W[0];
		    Tb = T5 * Ta;
		    Tc = W[1];
		    Ti = Tc * Ta;
		    cr[WS(rs, 1)] = FNMS(Tc, Th, Tb);
		    ci[WS(rs, 1)] = FMA(T5, Th, Ti);
	       }
	       {
		    E Tn, Tj, Tl, Tm, To, Tk;
		    Tn = FNMS(KP866025403, Tg, Tf);
		    Tk = FMA(KP866025403, T9, T6);
		    Tj = W[2];
		    Tl = Tj * Tk;
		    Tm = W[3];
		    To = Tm * Tk;
		    cr[WS(rs, 2)] = FNMS(Tm, Tn, Tl);
		    ci[WS(rs, 2)] = FMA(Tj, Tn, To);
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     { TW_FULL, 1, 3 },
     { TW_NEXT, 1, 0 }
};

static const hc2hc_desc desc = { 3, "hb_3", twinstr, &GENUS, { 6, 4, 10, 0 } };

void X(codelet_hb_3) (planner *p) {
     X(khc2hc_register) (p, hb_3, &desc);
}
#else

/* Generated by: ../../../genfft/gen_hc2hc.native -compact -variables 4 -pipeline-latency 4 -sign 1 -n 3 -dif -name hb_3 -include rdft/scalar/hb.h */

/*
 * This function contains 16 FP additions, 12 FP multiplications,
 * (or, 10 additions, 6 multiplications, 6 fused multiply/add),
 * 15 stack variables, 2 constants, and 12 memory accesses
 */
#include "rdft/scalar/hb.h"

static void hb_3(R *cr, R *ci, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 4); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 4, MAKE_VOLATILE_STRIDE(6, rs)) {
	       E T1, T4, Ta, Te, T5, T8, Tb, Tf;
	       {
		    E T2, T3, T6, T7;
		    T1 = cr[0];
		    T2 = cr[WS(rs, 1)];
		    T3 = ci[0];
		    T4 = T2 + T3;
		    Ta = FNMS(KP500000000, T4, T1);
		    Te = KP866025403 * (T2 - T3);
		    T5 = ci[WS(rs, 2)];
		    T6 = ci[WS(rs, 1)];
		    T7 = cr[WS(rs, 2)];
		    T8 = T6 - T7;
		    Tb = KP866025403 * (T6 + T7);
		    Tf = FNMS(KP500000000, T8, T5);
	       }
	       cr[0] = T1 + T4;
	       ci[0] = T5 + T8;
	       {
		    E Tc, Tg, T9, Td;
		    Tc = Ta - Tb;
		    Tg = Te + Tf;
		    T9 = W[0];
		    Td = W[1];
		    cr[WS(rs, 1)] = FNMS(Td, Tg, T9 * Tc);
		    ci[WS(rs, 1)] = FMA(T9, Tg, Td * Tc);
	       }
	       {
		    E Ti, Tk, Th, Tj;
		    Ti = Ta + Tb;
		    Tk = Tf - Te;
		    Th = W[2];
		    Tj = W[3];
		    cr[WS(rs, 2)] = FNMS(Tj, Tk, Th * Ti);
		    ci[WS(rs, 2)] = FMA(Th, Tk, Tj * Ti);
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     { TW_FULL, 1, 3 },
     { TW_NEXT, 1, 0 }
};

static const hc2hc_desc desc = { 3, "hb_3", twinstr, &GENUS, { 10, 6, 6, 0 } };

void X(codelet_hb_3) (planner *p) {
     X(khc2hc_register) (p, hb_3, &desc);
}
#endif
