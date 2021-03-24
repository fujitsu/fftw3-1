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
/* Generated on Wed Mar 24 13:48:26 JST 2021 */

#include "dft/codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_notw.native -fma -simd -compact -variables 4 -pipeline-latency 8 -n 8 -name n2sv_8 -with-ostride 1 -include dft/simd/n2s.h -store-multiple 4 */

/*
 * This function contains 52 FP additions, 8 FP multiplications,
 * (or, 44 additions, 0 multiplications, 8 fused multiply/add),
 * 34 stack variables, 1 constants, and 36 memory accesses
 */
#include "dft/simd/n2s.h"

static void n2sv_8(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     VENTER(); {
	  INT i;
	  for (i = v; i > 0; i = i - (2 * VL), ri = ri + ((2 * VL) * ivs), ii = ii + ((2 * VL) * ivs), ro = ro + ((2 * VL) * ovs), io = io + ((2 * VL) * ovs), MAKE_VOLATILE_STRIDE(32, is), MAKE_VOLATILE_STRIDE(32, os)) {
	       V T3, Tn, Ti, TC, T6, TB, Tl, To, Td, TN, Tz, TH, Ta, TM, Tu;
	       V TG;
	       {
		    V T1, T2, Tj, Tk;
		    T1 = LD(&(ri[0]), ivs, &(ri[0]));
		    T2 = LD(&(ri[WS(is, 4)]), ivs, &(ri[0]));
		    T3 = VADD(T1, T2);
		    Tn = VSUB(T1, T2);
		    {
			 V Tg, Th, T4, T5;
			 Tg = LD(&(ii[0]), ivs, &(ii[0]));
			 Th = LD(&(ii[WS(is, 4)]), ivs, &(ii[0]));
			 Ti = VADD(Tg, Th);
			 TC = VSUB(Tg, Th);
			 T4 = LD(&(ri[WS(is, 2)]), ivs, &(ri[0]));
			 T5 = LD(&(ri[WS(is, 6)]), ivs, &(ri[0]));
			 T6 = VADD(T4, T5);
			 TB = VSUB(T4, T5);
		    }
		    Tj = LD(&(ii[WS(is, 2)]), ivs, &(ii[0]));
		    Tk = LD(&(ii[WS(is, 6)]), ivs, &(ii[0]));
		    Tl = VADD(Tj, Tk);
		    To = VSUB(Tj, Tk);
		    {
			 V Tb, Tc, Tv, Tw, Tx, Ty;
			 Tb = LD(&(ri[WS(is, 7)]), ivs, &(ri[WS(is, 1)]));
			 Tc = LD(&(ri[WS(is, 3)]), ivs, &(ri[WS(is, 1)]));
			 Tv = VSUB(Tb, Tc);
			 Tw = LD(&(ii[WS(is, 7)]), ivs, &(ii[WS(is, 1)]));
			 Tx = LD(&(ii[WS(is, 3)]), ivs, &(ii[WS(is, 1)]));
			 Ty = VSUB(Tw, Tx);
			 Td = VADD(Tb, Tc);
			 TN = VADD(Tw, Tx);
			 Tz = VSUB(Tv, Ty);
			 TH = VADD(Tv, Ty);
		    }
		    {
			 V T8, T9, Tq, Tr, Ts, Tt;
			 T8 = LD(&(ri[WS(is, 1)]), ivs, &(ri[WS(is, 1)]));
			 T9 = LD(&(ri[WS(is, 5)]), ivs, &(ri[WS(is, 1)]));
			 Tq = VSUB(T8, T9);
			 Tr = LD(&(ii[WS(is, 1)]), ivs, &(ii[WS(is, 1)]));
			 Ts = LD(&(ii[WS(is, 5)]), ivs, &(ii[WS(is, 1)]));
			 Tt = VSUB(Tr, Ts);
			 Ta = VADD(T8, T9);
			 TM = VADD(Tr, Ts);
			 Tu = VADD(Tq, Tt);
			 TG = VSUB(Tt, Tq);
		    }
	       }
	       {
		    V TR, TS, TT, TU, TV, TW, TX, TY;
		    {
			 V T7, Te, TP, TQ;
			 T7 = VADD(T3, T6);
			 Te = VADD(Ta, Td);
			 TR = VSUB(T7, Te);
			 STM4(&(ro[4]), TR, ovs, &(ro[0]));
			 TS = VADD(T7, Te);
			 STM4(&(ro[0]), TS, ovs, &(ro[0]));
			 TP = VADD(Ti, Tl);
			 TQ = VADD(TM, TN);
			 TT = VSUB(TP, TQ);
			 STM4(&(io[4]), TT, ovs, &(io[0]));
			 TU = VADD(TP, TQ);
			 STM4(&(io[0]), TU, ovs, &(io[0]));
		    }
		    {
			 V Tf, Tm, TL, TO;
			 Tf = VSUB(Td, Ta);
			 Tm = VSUB(Ti, Tl);
			 TV = VADD(Tf, Tm);
			 STM4(&(io[2]), TV, ovs, &(io[0]));
			 TW = VSUB(Tm, Tf);
			 STM4(&(io[6]), TW, ovs, &(io[0]));
			 TL = VSUB(T3, T6);
			 TO = VSUB(TM, TN);
			 TX = VSUB(TL, TO);
			 STM4(&(ro[6]), TX, ovs, &(ro[0]));
			 TY = VADD(TL, TO);
			 STM4(&(ro[2]), TY, ovs, &(ro[0]));
		    }
		    {
			 V TZ, T10, T11, T12;
			 {
			      V Tp, TA, TJ, TK;
			      Tp = VADD(Tn, To);
			      TA = VADD(Tu, Tz);
			      TZ = VFNMS(LDK(KP707106781), TA, Tp);
			      STM4(&(ro[5]), TZ, ovs, &(ro[1]));
			      T10 = VFMA(LDK(KP707106781), TA, Tp);
			      STM4(&(ro[1]), T10, ovs, &(ro[1]));
			      TJ = VSUB(TC, TB);
			      TK = VADD(TG, TH);
			      T11 = VFNMS(LDK(KP707106781), TK, TJ);
			      STM4(&(io[5]), T11, ovs, &(io[1]));
			      T12 = VFMA(LDK(KP707106781), TK, TJ);
			      STM4(&(io[1]), T12, ovs, &(io[1]));
			 }
			 {
			      V TD, TE, T13, T14;
			      TD = VADD(TB, TC);
			      TE = VSUB(Tz, Tu);
			      T13 = VFNMS(LDK(KP707106781), TE, TD);
			      STM4(&(io[7]), T13, ovs, &(io[1]));
			      STN4(&(io[4]), TT, T11, TW, T13, ovs);
			      T14 = VFMA(LDK(KP707106781), TE, TD);
			      STM4(&(io[3]), T14, ovs, &(io[1]));
			      STN4(&(io[0]), TU, T12, TV, T14, ovs);
			 }
			 {
			      V TF, TI, T15, T16;
			      TF = VSUB(Tn, To);
			      TI = VSUB(TG, TH);
			      T15 = VFNMS(LDK(KP707106781), TI, TF);
			      STM4(&(ro[7]), T15, ovs, &(ro[1]));
			      STN4(&(ro[4]), TR, TZ, TX, T15, ovs);
			      T16 = VFMA(LDK(KP707106781), TI, TF);
			      STM4(&(ro[3]), T16, ovs, &(ro[1]));
			      STN4(&(ro[0]), TS, T10, TY, T16, ovs);
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 8, XSIMD_STRING("n2sv_8"), { 44, 0, 8, 0 }, &GENUS, 0, 1, 0, 0 };

void XSIMD(codelet_n2sv_8) (planner *p) { X(kdft_register) (p, n2sv_8, &desc);
}

#else

/* Generated by: ../../../genfft/gen_notw.native -simd -compact -variables 4 -pipeline-latency 8 -n 8 -name n2sv_8 -with-ostride 1 -include dft/simd/n2s.h -store-multiple 4 */

/*
 * This function contains 52 FP additions, 4 FP multiplications,
 * (or, 52 additions, 4 multiplications, 0 fused multiply/add),
 * 34 stack variables, 1 constants, and 36 memory accesses
 */
#include "dft/simd/n2s.h"

static void n2sv_8(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
     VENTER(); {
	  INT i;
	  for (i = v; i > 0; i = i - (2 * VL), ri = ri + ((2 * VL) * ivs), ii = ii + ((2 * VL) * ivs), ro = ro + ((2 * VL) * ovs), io = io + ((2 * VL) * ovs), MAKE_VOLATILE_STRIDE(32, is), MAKE_VOLATILE_STRIDE(32, os)) {
	       V T3, Tn, Ti, TC, T6, TB, Tl, To, Td, TN, Tz, TH, Ta, TM, Tu;
	       V TG;
	       {
		    V T1, T2, Tj, Tk;
		    T1 = LD(&(ri[0]), ivs, &(ri[0]));
		    T2 = LD(&(ri[WS(is, 4)]), ivs, &(ri[0]));
		    T3 = VADD(T1, T2);
		    Tn = VSUB(T1, T2);
		    {
			 V Tg, Th, T4, T5;
			 Tg = LD(&(ii[0]), ivs, &(ii[0]));
			 Th = LD(&(ii[WS(is, 4)]), ivs, &(ii[0]));
			 Ti = VADD(Tg, Th);
			 TC = VSUB(Tg, Th);
			 T4 = LD(&(ri[WS(is, 2)]), ivs, &(ri[0]));
			 T5 = LD(&(ri[WS(is, 6)]), ivs, &(ri[0]));
			 T6 = VADD(T4, T5);
			 TB = VSUB(T4, T5);
		    }
		    Tj = LD(&(ii[WS(is, 2)]), ivs, &(ii[0]));
		    Tk = LD(&(ii[WS(is, 6)]), ivs, &(ii[0]));
		    Tl = VADD(Tj, Tk);
		    To = VSUB(Tj, Tk);
		    {
			 V Tb, Tc, Tv, Tw, Tx, Ty;
			 Tb = LD(&(ri[WS(is, 7)]), ivs, &(ri[WS(is, 1)]));
			 Tc = LD(&(ri[WS(is, 3)]), ivs, &(ri[WS(is, 1)]));
			 Tv = VSUB(Tb, Tc);
			 Tw = LD(&(ii[WS(is, 7)]), ivs, &(ii[WS(is, 1)]));
			 Tx = LD(&(ii[WS(is, 3)]), ivs, &(ii[WS(is, 1)]));
			 Ty = VSUB(Tw, Tx);
			 Td = VADD(Tb, Tc);
			 TN = VADD(Tw, Tx);
			 Tz = VSUB(Tv, Ty);
			 TH = VADD(Tv, Ty);
		    }
		    {
			 V T8, T9, Tq, Tr, Ts, Tt;
			 T8 = LD(&(ri[WS(is, 1)]), ivs, &(ri[WS(is, 1)]));
			 T9 = LD(&(ri[WS(is, 5)]), ivs, &(ri[WS(is, 1)]));
			 Tq = VSUB(T8, T9);
			 Tr = LD(&(ii[WS(is, 1)]), ivs, &(ii[WS(is, 1)]));
			 Ts = LD(&(ii[WS(is, 5)]), ivs, &(ii[WS(is, 1)]));
			 Tt = VSUB(Tr, Ts);
			 Ta = VADD(T8, T9);
			 TM = VADD(Tr, Ts);
			 Tu = VADD(Tq, Tt);
			 TG = VSUB(Tt, Tq);
		    }
	       }
	       {
		    V TR, TS, TT, TU, TV, TW, TX, TY;
		    {
			 V T7, Te, TP, TQ;
			 T7 = VADD(T3, T6);
			 Te = VADD(Ta, Td);
			 TR = VSUB(T7, Te);
			 STM4(&(ro[4]), TR, ovs, &(ro[0]));
			 TS = VADD(T7, Te);
			 STM4(&(ro[0]), TS, ovs, &(ro[0]));
			 TP = VADD(Ti, Tl);
			 TQ = VADD(TM, TN);
			 TT = VSUB(TP, TQ);
			 STM4(&(io[4]), TT, ovs, &(io[0]));
			 TU = VADD(TP, TQ);
			 STM4(&(io[0]), TU, ovs, &(io[0]));
		    }
		    {
			 V Tf, Tm, TL, TO;
			 Tf = VSUB(Td, Ta);
			 Tm = VSUB(Ti, Tl);
			 TV = VADD(Tf, Tm);
			 STM4(&(io[2]), TV, ovs, &(io[0]));
			 TW = VSUB(Tm, Tf);
			 STM4(&(io[6]), TW, ovs, &(io[0]));
			 TL = VSUB(T3, T6);
			 TO = VSUB(TM, TN);
			 TX = VSUB(TL, TO);
			 STM4(&(ro[6]), TX, ovs, &(ro[0]));
			 TY = VADD(TL, TO);
			 STM4(&(ro[2]), TY, ovs, &(ro[0]));
		    }
		    {
			 V TZ, T10, T11, T12;
			 {
			      V Tp, TA, TJ, TK;
			      Tp = VADD(Tn, To);
			      TA = VMUL(LDK(KP707106781), VADD(Tu, Tz));
			      TZ = VSUB(Tp, TA);
			      STM4(&(ro[5]), TZ, ovs, &(ro[1]));
			      T10 = VADD(Tp, TA);
			      STM4(&(ro[1]), T10, ovs, &(ro[1]));
			      TJ = VSUB(TC, TB);
			      TK = VMUL(LDK(KP707106781), VADD(TG, TH));
			      T11 = VSUB(TJ, TK);
			      STM4(&(io[5]), T11, ovs, &(io[1]));
			      T12 = VADD(TJ, TK);
			      STM4(&(io[1]), T12, ovs, &(io[1]));
			 }
			 {
			      V TD, TE, T13, T14;
			      TD = VADD(TB, TC);
			      TE = VMUL(LDK(KP707106781), VSUB(Tz, Tu));
			      T13 = VSUB(TD, TE);
			      STM4(&(io[7]), T13, ovs, &(io[1]));
			      STN4(&(io[4]), TT, T11, TW, T13, ovs);
			      T14 = VADD(TD, TE);
			      STM4(&(io[3]), T14, ovs, &(io[1]));
			      STN4(&(io[0]), TU, T12, TV, T14, ovs);
			 }
			 {
			      V TF, TI, T15, T16;
			      TF = VSUB(Tn, To);
			      TI = VMUL(LDK(KP707106781), VSUB(TG, TH));
			      T15 = VSUB(TF, TI);
			      STM4(&(ro[7]), T15, ovs, &(ro[1]));
			      STN4(&(ro[4]), TR, TZ, TX, T15, ovs);
			      T16 = VADD(TF, TI);
			      STM4(&(ro[3]), T16, ovs, &(ro[1]));
			      STN4(&(ro[0]), TS, T10, TY, T16, ovs);
			 }
		    }
	       }
	  }
     }
     VLEAVE();
}

static const kdft_desc desc = { 8, XSIMD_STRING("n2sv_8"), { 52, 4, 0, 0 }, &GENUS, 0, 1, 0, 0 };

void XSIMD(codelet_n2sv_8) (planner *p) { X(kdft_register) (p, n2sv_8, &desc);
}

#endif
