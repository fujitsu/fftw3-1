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
/* Generated on Wed Mar 24 13:52:59 JST 2021 */

#include "rdft/codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_r2cf.native -fma -compact -variables 4 -pipeline-latency 4 -n 12 -name r2cfII_12 -dft-II -include rdft/scalar/r2cfII.h */

/*
 * This function contains 45 FP additions, 24 FP multiplications,
 * (or, 21 additions, 0 multiplications, 24 fused multiply/add),
 * 28 stack variables, 3 constants, and 24 memory accesses
 */
#include "rdft/scalar/r2cfII.h"

static void r2cfII_12(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DK(KP707106781, +0.707106781186547524400844362104849039284835938);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(48, rs), MAKE_VOLATILE_STRIDE(48, csr), MAKE_VOLATILE_STRIDE(48, csi)) {
	       E Tx, Ty, T8, Tz, Tl, Tm, Tv, T5, TA, Tt, Te, Tf, Tu, T6, T7;
	       E Tw, TF, TG;
	       Tx = R0[WS(rs, 3)];
	       T6 = R0[WS(rs, 5)];
	       T7 = R0[WS(rs, 1)];
	       Ty = T6 + T7;
	       T8 = T6 - T7;
	       Tz = FMA(KP500000000, Ty, Tx);
	       {
		    E Th, Ti, Tj, Tk;
		    Th = R1[WS(rs, 4)];
		    Ti = R1[WS(rs, 2)];
		    Tj = R1[0];
		    Tk = Ti - Tj;
		    Tl = FMA(KP500000000, Tk, Th);
		    Tm = Ti + Tj;
		    Tv = Ti - Tj - Th;
	       }
	       {
		    E T1, T2, T3, T4;
		    T1 = R0[0];
		    T2 = R0[WS(rs, 2)];
		    T3 = R0[WS(rs, 4)];
		    T4 = T2 - T3;
		    T5 = FMA(KP500000000, T4, T1);
		    TA = T3 + T2;
		    Tt = T1 + T3 - T2;
	       }
	       {
		    E Ta, Tb, Tc, Td;
		    Ta = R1[WS(rs, 1)];
		    Tb = R1[WS(rs, 3)];
		    Tc = R1[WS(rs, 5)];
		    Td = Tb - Tc;
		    Te = FMA(KP500000000, Td, Ta);
		    Tf = Tc + Tb;
		    Tu = Ta + Tc - Tb;
	       }
	       Tw = Tu + Tv;
	       Cr[WS(csr, 1)] = FNMS(KP707106781, Tw, Tt);
	       Cr[WS(csr, 4)] = FMA(KP707106781, Tw, Tt);
	       TF = Tx - Ty;
	       TG = Tv - Tu;
	       Ci[WS(csi, 4)] = FMS(KP707106781, TG, TF);
	       Ci[WS(csi, 1)] = FMA(KP707106781, TG, TF);
	       {
		    E T9, TD, To, TE, Tg, Tn;
		    T9 = FNMS(KP866025403, T8, T5);
		    TD = FNMS(KP866025403, TA, Tz);
		    Tg = FNMS(KP866025403, Tf, Te);
		    Tn = FNMS(KP866025403, Tm, Tl);
		    To = Tg - Tn;
		    TE = Tg + Tn;
		    Cr[WS(csr, 5)] = FNMS(KP707106781, To, T9);
		    Ci[WS(csi, 3)] = FMA(KP707106781, TE, TD);
		    Cr[0] = FMA(KP707106781, To, T9);
		    Ci[WS(csi, 2)] = FMS(KP707106781, TE, TD);
	       }
	       {
		    E Tp, TB, Ts, TC, Tq, Tr;
		    Tp = FMA(KP866025403, T8, T5);
		    TB = FMA(KP866025403, TA, Tz);
		    Tq = FMA(KP866025403, Tm, Tl);
		    Tr = FMA(KP866025403, Tf, Te);
		    Ts = Tq - Tr;
		    TC = Tr + Tq;
		    Cr[WS(csr, 3)] = FNMS(KP707106781, Ts, Tp);
		    Ci[WS(csi, 5)] = FNMS(KP707106781, TC, TB);
		    Cr[WS(csr, 2)] = FMA(KP707106781, Ts, Tp);
		    Ci[0] = -(FMA(KP707106781, TC, TB));
	       }
	  }
     }
}

static const kr2c_desc desc = { 12, "r2cfII_12", { 21, 0, 24, 0 }, &GENUS };

void X(codelet_r2cfII_12) (planner *p) { X(kr2c_register) (p, r2cfII_12, &desc);
}

#else

/* Generated by: ../../../genfft/gen_r2cf.native -compact -variables 4 -pipeline-latency 4 -n 12 -name r2cfII_12 -dft-II -include rdft/scalar/r2cfII.h */

/*
 * This function contains 43 FP additions, 12 FP multiplications,
 * (or, 39 additions, 8 multiplications, 4 fused multiply/add),
 * 28 stack variables, 5 constants, and 24 memory accesses
 */
#include "rdft/scalar/r2cfII.h"

static void r2cfII_12(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP353553390, +0.353553390593273762200422181052424519642417969);
     DK(KP707106781, +0.707106781186547524400844362104849039284835938);
     DK(KP612372435, +0.612372435695794524549321018676472847991486870);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     {
	  INT i;
	  for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs, Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(48, rs), MAKE_VOLATILE_STRIDE(48, csr), MAKE_VOLATILE_STRIDE(48, csi)) {
	       E Tx, Tg, T4, Tz, Ty, Tj, TA, T9, Tm, Tl, Te, Tp, To, Tf, TE;
	       E TF;
	       {
		    E T1, T3, T2, Th, Ti;
		    T1 = R0[0];
		    T3 = R0[WS(rs, 2)];
		    T2 = R0[WS(rs, 4)];
		    Tx = KP866025403 * (T2 + T3);
		    Tg = FMA(KP500000000, T3 - T2, T1);
		    T4 = T1 + T2 - T3;
		    Tz = R0[WS(rs, 3)];
		    Th = R0[WS(rs, 5)];
		    Ti = R0[WS(rs, 1)];
		    Ty = Th + Ti;
		    Tj = KP866025403 * (Th - Ti);
		    TA = FMA(KP500000000, Ty, Tz);
	       }
	       {
		    E T5, T6, T7, T8;
		    T5 = R1[WS(rs, 1)];
		    T6 = R1[WS(rs, 5)];
		    T7 = R1[WS(rs, 3)];
		    T8 = T6 - T7;
		    T9 = T5 + T8;
		    Tm = KP612372435 * (T6 + T7);
		    Tl = FNMS(KP353553390, T8, KP707106781 * T5);
	       }
	       {
		    E Td, Ta, Tb, Tc;
		    Td = R1[WS(rs, 4)];
		    Ta = R1[WS(rs, 2)];
		    Tb = R1[0];
		    Tc = Ta - Tb;
		    Te = Tc - Td;
		    Tp = FMA(KP353553390, Tc, KP707106781 * Td);
		    To = KP612372435 * (Ta + Tb);
	       }
	       Tf = KP707106781 * (T9 + Te);
	       Cr[WS(csr, 1)] = T4 - Tf;
	       Cr[WS(csr, 4)] = T4 + Tf;
	       TE = KP707106781 * (Te - T9);
	       TF = Tz - Ty;
	       Ci[WS(csi, 4)] = TE - TF;
	       Ci[WS(csi, 1)] = TE + TF;
	       {
		    E Tk, TB, Tr, Tw, Tn, Tq;
		    Tk = Tg - Tj;
		    TB = Tx - TA;
		    Tn = Tl - Tm;
		    Tq = To - Tp;
		    Tr = Tn + Tq;
		    Tw = Tn - Tq;
		    Cr[WS(csr, 5)] = Tk - Tr;
		    Ci[WS(csi, 2)] = Tw + TB;
		    Cr[0] = Tk + Tr;
		    Ci[WS(csi, 3)] = Tw - TB;
	       }
	       {
		    E Ts, TD, Tv, TC, Tt, Tu;
		    Ts = Tg + Tj;
		    TD = Tx + TA;
		    Tt = To + Tp;
		    Tu = Tm + Tl;
		    Tv = Tt - Tu;
		    TC = Tu + Tt;
		    Cr[WS(csr, 3)] = Ts - Tv;
		    Ci[WS(csi, 5)] = TD - TC;
		    Cr[WS(csr, 2)] = Ts + Tv;
		    Ci[0] = -(TC + TD);
	       }
	  }
     }
}

static const kr2c_desc desc = { 12, "r2cfII_12", { 39, 8, 4, 0 }, &GENUS };

void X(codelet_r2cfII_12) (planner *p) { X(kr2c_register) (p, r2cfII_12, &desc);
}

#endif
