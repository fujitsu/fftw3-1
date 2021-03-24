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
/* Generated on Wed Mar 24 13:48:25 JST 2021 */

#include "dft/codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_notw_c.native -fma -simd -compact -variables 4 -pipeline-latency 8 -sign 1 -n 3 -name n1bv_3 -include dft/simd/n1b.h */

/*
 * This function contains 6 FP additions, 4 FP multiplications,
 * (or, 3 additions, 1 multiplications, 3 fused multiply/add),
 * 11 stack variables, 2 constants, and 6 memory accesses
 */
#include "dft/simd/n1b.h"

static void n1bv_3(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     VENTER(); {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ii;
	  xo = io;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(6, is), MAKE_VOLATILE_STRIDE(6, os)) {
	       V T1, T4, T6, T2, T3, T5;
	       T1 = LD(&(xi[0]), ivs, &(xi[0]));
	       T2 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
	       T3 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
	       T4 = VADD(T2, T3);
	       T6 = VMUL(LDK(KP866025403), VSUB(T2, T3));
	       ST(&(xo[0]), VADD(T1, T4), ovs, &(xo[0]));
	       T5 = VFNMS(LDK(KP500000000), T4, T1);
	       ST(&(xo[WS(os, 1)]), VFMAI(T6, T5), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 2)]), VFNMSI(T6, T5), ovs, &(xo[0]));
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 3, XSIMD_STRING("n1bv_3"), { 3, 1, 3, 0 }, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1bv_3) (planner *p) { X(kdft_register) (p, n1bv_3, &desc);
}

#else

/* Generated by: ../../../genfft/gen_notw_c.native -simd -compact -variables 4 -pipeline-latency 8 -sign 1 -n 3 -name n1bv_3 -include dft/simd/n1b.h */

/*
 * This function contains 6 FP additions, 2 FP multiplications,
 * (or, 5 additions, 1 multiplications, 1 fused multiply/add),
 * 11 stack variables, 2 constants, and 6 memory accesses
 */
#include "dft/simd/n1b.h"

static void n1bv_3(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DVK(KP866025403, +0.866025403784438646763723170752936183471402627);
     VENTER(); {
	  INT i;
	  const R *xi;
	  R *xo;
	  xi = ii;
	  xo = io;
	  for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(6, is), MAKE_VOLATILE_STRIDE(6, os)) {
	       V T4, T3, T5, T1, T2, T6;
	       T4 = LD(&(xi[0]), ivs, &(xi[0]));
	       T1 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
	       T2 = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
	       T3 = VBYI(VMUL(LDK(KP866025403), VSUB(T1, T2)));
	       T5 = VADD(T1, T2);
	       ST(&(xo[0]), VADD(T4, T5), ovs, &(xo[0]));
	       T6 = VFNMS(LDK(KP500000000), T5, T4);
	       ST(&(xo[WS(os, 1)]), VADD(T3, T6), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 2)]), VSUB(T6, T3), ovs, &(xo[0]));
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 3, XSIMD_STRING("n1bv_3"), { 5, 1, 1, 0 }, &GENUS, 0, 0, 0, 0 };

void XSIMD(codelet_n1bv_3) (planner *p) { X(kdft_register) (p, n1bv_3, &desc);
}

#endif
