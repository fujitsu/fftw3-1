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
/* Generated on Wed Mar 24 13:54:40 JST 2021 */

#include "rdft/codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_hc2c.native -fma -compact -variables 4 -pipeline-latency 4 -sign 1 -n 10 -dif -name hc2cb_10 -include rdft/scalar/hc2cb.h */

/*
 * This function contains 102 FP additions, 72 FP multiplications,
 * (or, 48 additions, 18 multiplications, 54 fused multiply/add),
 * 47 stack variables, 4 constants, and 40 memory accesses
 */
#include "rdft/scalar/hc2cb.h"

static void hc2cb_10(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP618033988, +0.618033988749894848204586834365638117720309180);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 18); m < me; m = m + 1, Rp = Rp + ms, Ip = Ip + ms, Rm = Rm - ms, Im = Im - ms, W = W + 18, MAKE_VOLATILE_STRIDE(40, rs)) {
	       E TH, T1B, TB, T11, T1E, T1G, TK, TM, T1x, T1V, T3, T1g, Tl, T1I, T1J;
	       E TO, TP, T1p, Ti, Tk, T1n, T1o, TF, TG;
	       TF = Ip[0];
	       TG = Im[WS(rs, 4)];
	       TH = TF - TG;
	       T1B = TF + TG;
	       {
		    E Tp, T1u, Tz, T1s, Ts, T1v, Tw, T1r;
		    {
			 E Tn, To, Tx, Ty;
			 Tn = Ip[WS(rs, 4)];
			 To = Im[0];
			 Tp = Tn - To;
			 T1u = Tn + To;
			 Tx = Ip[WS(rs, 3)];
			 Ty = Im[WS(rs, 1)];
			 Tz = Tx - Ty;
			 T1s = Tx + Ty;
		    }
		    {
			 E Tq, Tr, Tu, Tv;
			 Tq = Ip[WS(rs, 1)];
			 Tr = Im[WS(rs, 3)];
			 Ts = Tq - Tr;
			 T1v = Tq + Tr;
			 Tu = Ip[WS(rs, 2)];
			 Tv = Im[WS(rs, 2)];
			 Tw = Tu - Tv;
			 T1r = Tu + Tv;
		    }
		    {
			 E Tt, TA, T1C, T1D;
			 Tt = Tp - Ts;
			 TA = Tw - Tz;
			 TB = FNMS(KP618033988, TA, Tt);
			 T11 = FMA(KP618033988, Tt, TA);
			 T1C = T1r - T1s;
			 T1D = T1u - T1v;
			 T1E = T1C + T1D;
			 T1G = T1C - T1D;
		    }
		    {
			 E TI, TJ, T1t, T1w;
			 TI = Tw + Tz;
			 TJ = Tp + Ts;
			 TK = TI + TJ;
			 TM = TI - TJ;
			 T1t = T1r + T1s;
			 T1w = T1u + T1v;
			 T1x = FMA(KP618033988, T1w, T1t);
			 T1V = FNMS(KP618033988, T1t, T1w);
		    }
	       }
	       {
		    E Td, T1k, Tg, T1l, Th, T1m, T6, T1h, T9, T1i, Ta, T1j, T1, T2;
		    T1 = Rp[0];
		    T2 = Rm[WS(rs, 4)];
		    T3 = T1 + T2;
		    T1g = T1 - T2;
		    {
			 E Tb, Tc, Te, Tf;
			 Tb = Rp[WS(rs, 4)];
			 Tc = Rm[0];
			 Td = Tb + Tc;
			 T1k = Tb - Tc;
			 Te = Rm[WS(rs, 3)];
			 Tf = Rp[WS(rs, 1)];
			 Tg = Te + Tf;
			 T1l = Te - Tf;
		    }
		    Th = Td + Tg;
		    T1m = T1k + T1l;
		    {
			 E T4, T5, T7, T8;
			 T4 = Rp[WS(rs, 2)];
			 T5 = Rm[WS(rs, 2)];
			 T6 = T4 + T5;
			 T1h = T4 - T5;
			 T7 = Rm[WS(rs, 1)];
			 T8 = Rp[WS(rs, 3)];
			 T9 = T7 + T8;
			 T1i = T7 - T8;
		    }
		    Ta = T6 + T9;
		    T1j = T1h + T1i;
		    Tl = Ta - Th;
		    T1I = T1h - T1i;
		    T1J = T1k - T1l;
		    TO = Td - Tg;
		    TP = T6 - T9;
		    T1p = T1j - T1m;
		    Ti = Ta + Th;
		    Tk = FNMS(KP250000000, Ti, T3);
		    T1n = T1j + T1m;
		    T1o = FNMS(KP250000000, T1n, T1g);
	       }
	       Rp[0] = T3 + Ti;
	       Rm[0] = TH + TK;
	       {
		    E T2d, T29, T2b, T2c, T2e, T2a;
		    T2d = T1B + T1E;
		    T2a = T1g + T1n;
		    T29 = W[8];
		    T2b = T29 * T2a;
		    T2c = W[9];
		    T2e = T2c * T2a;
		    Ip[WS(rs, 2)] = FNMS(T2c, T2d, T2b);
		    Im[WS(rs, 2)] = FMA(T29, T2d, T2e);
	       }
	       {
		    E TQ, T16, TC, TU, TN, T15, T12, T1a, Tm, TL, T10;
		    TQ = FNMS(KP618033988, TP, TO);
		    T16 = FMA(KP618033988, TO, TP);
		    Tm = FNMS(KP559016994, Tl, Tk);
		    TC = FMA(KP951056516, TB, Tm);
		    TU = FNMS(KP951056516, TB, Tm);
		    TL = FNMS(KP250000000, TK, TH);
		    TN = FNMS(KP559016994, TM, TL);
		    T15 = FMA(KP559016994, TM, TL);
		    T10 = FMA(KP559016994, Tl, Tk);
		    T12 = FMA(KP951056516, T11, T10);
		    T1a = FNMS(KP951056516, T11, T10);
		    {
			 E TR, TE, TS, Tj, TD;
			 TR = FNMS(KP951056516, TQ, TN);
			 TE = W[3];
			 TS = TE * TC;
			 Tj = W[2];
			 TD = Tj * TC;
			 Rp[WS(rs, 1)] = FNMS(TE, TR, TD);
			 Rm[WS(rs, 1)] = FMA(Tj, TR, TS);
		    }
		    {
			 E T1d, T1c, T1e, T19, T1b;
			 T1d = FMA(KP951056516, T16, T15);
			 T1c = W[11];
			 T1e = T1c * T1a;
			 T19 = W[10];
			 T1b = T19 * T1a;
			 Rp[WS(rs, 3)] = FNMS(T1c, T1d, T1b);
			 Rm[WS(rs, 3)] = FMA(T19, T1d, T1e);
		    }
		    {
			 E TX, TW, TY, TT, TV;
			 TX = FMA(KP951056516, TQ, TN);
			 TW = W[15];
			 TY = TW * TU;
			 TT = W[14];
			 TV = TT * TU;
			 Rp[WS(rs, 4)] = FNMS(TW, TX, TV);
			 Rm[WS(rs, 4)] = FMA(TT, TX, TY);
		    }
		    {
			 E T17, T14, T18, TZ, T13;
			 T17 = FNMS(KP951056516, T16, T15);
			 T14 = W[7];
			 T18 = T14 * T12;
			 TZ = W[6];
			 T13 = TZ * T12;
			 Rp[WS(rs, 2)] = FNMS(T14, T17, T13);
			 Rm[WS(rs, 2)] = FMA(TZ, T17, T18);
		    }
	       }
	       {
		    E T1K, T20, T1y, T1O, T1H, T1Z, T1W, T24, T1q, T1F, T1U;
		    T1K = FMA(KP618033988, T1J, T1I);
		    T20 = FNMS(KP618033988, T1I, T1J);
		    T1q = FMA(KP559016994, T1p, T1o);
		    T1y = FNMS(KP951056516, T1x, T1q);
		    T1O = FMA(KP951056516, T1x, T1q);
		    T1F = FNMS(KP250000000, T1E, T1B);
		    T1H = FMA(KP559016994, T1G, T1F);
		    T1Z = FNMS(KP559016994, T1G, T1F);
		    T1U = FNMS(KP559016994, T1p, T1o);
		    T1W = FNMS(KP951056516, T1V, T1U);
		    T24 = FMA(KP951056516, T1V, T1U);
		    {
			 E T1L, T1A, T1M, T1f, T1z;
			 T1L = FMA(KP951056516, T1K, T1H);
			 T1A = W[1];
			 T1M = T1A * T1y;
			 T1f = W[0];
			 T1z = T1f * T1y;
			 Ip[0] = FNMS(T1A, T1L, T1z);
			 Im[0] = FMA(T1f, T1L, T1M);
		    }
		    {
			 E T27, T26, T28, T23, T25;
			 T27 = FNMS(KP951056516, T20, T1Z);
			 T26 = W[13];
			 T28 = T26 * T24;
			 T23 = W[12];
			 T25 = T23 * T24;
			 Ip[WS(rs, 3)] = FNMS(T26, T27, T25);
			 Im[WS(rs, 3)] = FMA(T23, T27, T28);
		    }
		    {
			 E T1R, T1Q, T1S, T1N, T1P;
			 T1R = FNMS(KP951056516, T1K, T1H);
			 T1Q = W[17];
			 T1S = T1Q * T1O;
			 T1N = W[16];
			 T1P = T1N * T1O;
			 Ip[WS(rs, 4)] = FNMS(T1Q, T1R, T1P);
			 Im[WS(rs, 4)] = FMA(T1N, T1R, T1S);
		    }
		    {
			 E T21, T1Y, T22, T1T, T1X;
			 T21 = FMA(KP951056516, T20, T1Z);
			 T1Y = W[5];
			 T22 = T1Y * T1W;
			 T1T = W[4];
			 T1X = T1T * T1W;
			 Ip[WS(rs, 1)] = FNMS(T1Y, T21, T1X);
			 Im[WS(rs, 1)] = FMA(T1T, T21, T22);
		    }
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     { TW_FULL, 1, 10 },
     { TW_NEXT, 1, 0 }
};

static const hc2c_desc desc = { 10, "hc2cb_10", twinstr, &GENUS, { 48, 18, 54, 0 } };

void X(codelet_hc2cb_10) (planner *p) {
     X(khc2c_register) (p, hc2cb_10, &desc, HC2C_VIA_RDFT);
}
#else

/* Generated by: ../../../genfft/gen_hc2c.native -compact -variables 4 -pipeline-latency 4 -sign 1 -n 10 -dif -name hc2cb_10 -include rdft/scalar/hc2cb.h */

/*
 * This function contains 102 FP additions, 60 FP multiplications,
 * (or, 72 additions, 30 multiplications, 30 fused multiply/add),
 * 39 stack variables, 4 constants, and 40 memory accesses
 */
#include "rdft/scalar/hc2cb.h"

static void hc2cb_10(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 18); m < me; m = m + 1, Rp = Rp + ms, Ip = Ip + ms, Rm = Rm - ms, Im = Im - ms, W = W + 18, MAKE_VOLATILE_STRIDE(40, rs)) {
	       E T3, T18, TJ, T1i, TE, TF, T1B, T1A, T1f, T1t, Ti, Tl, Tt, TA, T1w;
	       E T1v, T1p, T1E, TM, TO;
	       {
		    E T1, T2, TH, TI;
		    T1 = Rp[0];
		    T2 = Rm[WS(rs, 4)];
		    T3 = T1 + T2;
		    T18 = T1 - T2;
		    TH = Ip[0];
		    TI = Im[WS(rs, 4)];
		    TJ = TH - TI;
		    T1i = TH + TI;
	       }
	       {
		    E T6, T19, Tg, T1d, T9, T1a, Td, T1c;
		    {
			 E T4, T5, Te, Tf;
			 T4 = Rp[WS(rs, 2)];
			 T5 = Rm[WS(rs, 2)];
			 T6 = T4 + T5;
			 T19 = T4 - T5;
			 Te = Rm[WS(rs, 3)];
			 Tf = Rp[WS(rs, 1)];
			 Tg = Te + Tf;
			 T1d = Te - Tf;
		    }
		    {
			 E T7, T8, Tb, Tc;
			 T7 = Rm[WS(rs, 1)];
			 T8 = Rp[WS(rs, 3)];
			 T9 = T7 + T8;
			 T1a = T7 - T8;
			 Tb = Rp[WS(rs, 4)];
			 Tc = Rm[0];
			 Td = Tb + Tc;
			 T1c = Tb - Tc;
		    }
		    TE = T6 - T9;
		    TF = Td - Tg;
		    T1B = T1c - T1d;
		    T1A = T19 - T1a;
		    {
			 E T1b, T1e, Ta, Th;
			 T1b = T19 + T1a;
			 T1e = T1c + T1d;
			 T1f = T1b + T1e;
			 T1t = KP559016994 * (T1b - T1e);
			 Ta = T6 + T9;
			 Th = Td + Tg;
			 Ti = Ta + Th;
			 Tl = KP559016994 * (Ta - Th);
		    }
	       }
	       {
		    E Tp, T1j, Tz, T1n, Ts, T1k, Tw, T1m;
		    {
			 E Tn, To, Tx, Ty;
			 Tn = Ip[WS(rs, 2)];
			 To = Im[WS(rs, 2)];
			 Tp = Tn - To;
			 T1j = Tn + To;
			 Tx = Ip[WS(rs, 1)];
			 Ty = Im[WS(rs, 3)];
			 Tz = Tx - Ty;
			 T1n = Tx + Ty;
		    }
		    {
			 E Tq, Tr, Tu, Tv;
			 Tq = Ip[WS(rs, 3)];
			 Tr = Im[WS(rs, 1)];
			 Ts = Tq - Tr;
			 T1k = Tq + Tr;
			 Tu = Ip[WS(rs, 4)];
			 Tv = Im[0];
			 Tw = Tu - Tv;
			 T1m = Tu + Tv;
		    }
		    Tt = Tp - Ts;
		    TA = Tw - Tz;
		    T1w = T1m + T1n;
		    T1v = T1j + T1k;
		    {
			 E T1l, T1o, TK, TL;
			 T1l = T1j - T1k;
			 T1o = T1m - T1n;
			 T1p = T1l + T1o;
			 T1E = KP559016994 * (T1l - T1o);
			 TK = Tp + Ts;
			 TL = Tw + Tz;
			 TM = TK + TL;
			 TO = KP559016994 * (TK - TL);
		    }
	       }
	       Rp[0] = T3 + Ti;
	       Rm[0] = TJ + TM;
	       {
		    E T1g, T1q, T17, T1h;
		    T1g = T18 + T1f;
		    T1q = T1i + T1p;
		    T17 = W[8];
		    T1h = W[9];
		    Ip[WS(rs, 2)] = FNMS(T1h, T1q, T17 * T1g);
		    Im[WS(rs, 2)] = FMA(T1h, T1g, T17 * T1q);
	       }
	       {
		    E TB, TG, T11, TX, TP, T10, Tm, TW, TN, Tk;
		    TB = FNMS(KP951056516, TA, KP587785252 * Tt);
		    TG = FNMS(KP951056516, TF, KP587785252 * TE);
		    T11 = FMA(KP951056516, TE, KP587785252 * TF);
		    TX = FMA(KP951056516, Tt, KP587785252 * TA);
		    TN = FNMS(KP250000000, TM, TJ);
		    TP = TN - TO;
		    T10 = TO + TN;
		    Tk = FNMS(KP250000000, Ti, T3);
		    Tm = Tk - Tl;
		    TW = Tl + Tk;
		    {
			 E TC, TQ, Tj, TD;
			 TC = Tm - TB;
			 TQ = TG + TP;
			 Tj = W[2];
			 TD = W[3];
			 Rp[WS(rs, 1)] = FNMS(TD, TQ, Tj * TC);
			 Rm[WS(rs, 1)] = FMA(TD, TC, Tj * TQ);
		    }
		    {
			 E T14, T16, T13, T15;
			 T14 = TW - TX;
			 T16 = T11 + T10;
			 T13 = W[10];
			 T15 = W[11];
			 Rp[WS(rs, 3)] = FNMS(T15, T16, T13 * T14);
			 Rm[WS(rs, 3)] = FMA(T15, T14, T13 * T16);
		    }
		    {
			 E TS, TU, TR, TT;
			 TS = Tm + TB;
			 TU = TP - TG;
			 TR = W[14];
			 TT = W[15];
			 Rp[WS(rs, 4)] = FNMS(TT, TU, TR * TS);
			 Rm[WS(rs, 4)] = FMA(TT, TS, TR * TU);
		    }
		    {
			 E TY, T12, TV, TZ;
			 TY = TW + TX;
			 T12 = T10 - T11;
			 TV = W[6];
			 TZ = W[7];
			 Rp[WS(rs, 2)] = FNMS(TZ, T12, TV * TY);
			 Rm[WS(rs, 2)] = FMA(TZ, TY, TV * T12);
		    }
	       }
	       {
		    E T1x, T1C, T1Q, T1N, T1F, T1R, T1u, T1M, T1D, T1s;
		    T1x = FNMS(KP951056516, T1w, KP587785252 * T1v);
		    T1C = FNMS(KP951056516, T1B, KP587785252 * T1A);
		    T1Q = FMA(KP951056516, T1A, KP587785252 * T1B);
		    T1N = FMA(KP951056516, T1v, KP587785252 * T1w);
		    T1D = FNMS(KP250000000, T1p, T1i);
		    T1F = T1D - T1E;
		    T1R = T1E + T1D;
		    T1s = FNMS(KP250000000, T1f, T18);
		    T1u = T1s - T1t;
		    T1M = T1t + T1s;
		    {
			 E T1y, T1G, T1r, T1z;
			 T1y = T1u - T1x;
			 T1G = T1C + T1F;
			 T1r = W[12];
			 T1z = W[13];
			 Ip[WS(rs, 3)] = FNMS(T1z, T1G, T1r * T1y);
			 Im[WS(rs, 3)] = FMA(T1r, T1G, T1z * T1y);
		    }
		    {
			 E T1U, T1W, T1T, T1V;
			 T1U = T1M + T1N;
			 T1W = T1R - T1Q;
			 T1T = W[16];
			 T1V = W[17];
			 Ip[WS(rs, 4)] = FNMS(T1V, T1W, T1T * T1U);
			 Im[WS(rs, 4)] = FMA(T1T, T1W, T1V * T1U);
		    }
		    {
			 E T1I, T1K, T1H, T1J;
			 T1I = T1u + T1x;
			 T1K = T1F - T1C;
			 T1H = W[4];
			 T1J = W[5];
			 Ip[WS(rs, 1)] = FNMS(T1J, T1K, T1H * T1I);
			 Im[WS(rs, 1)] = FMA(T1H, T1K, T1J * T1I);
		    }
		    {
			 E T1O, T1S, T1L, T1P;
			 T1O = T1M - T1N;
			 T1S = T1Q + T1R;
			 T1L = W[0];
			 T1P = W[1];
			 Ip[0] = FNMS(T1P, T1S, T1L * T1O);
			 Im[0] = FMA(T1L, T1S, T1P * T1O);
		    }
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     { TW_FULL, 1, 10 },
     { TW_NEXT, 1, 0 }
};

static const hc2c_desc desc = { 10, "hc2cb_10", twinstr, &GENUS, { 72, 30, 30, 0 } };

void X(codelet_hc2cb_10) (planner *p) {
     X(khc2c_register) (p, hc2cb_10, &desc, HC2C_VIA_RDFT);
}
#endif
