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
/* Generated on Wed Mar 24 13:53:00 JST 2021 */

#include "rdft/codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_hc2cdft.native -fma -compact -variables 4 -pipeline-latency 4 -twiddle-log3 -precompute-twiddles -n 20 -dit -name hc2cfdft2_20 -include rdft/scalar/hc2cf.h */

/*
 * This function contains 316 FP additions, 238 FP multiplications,
 * (or, 176 additions, 98 multiplications, 140 fused multiply/add),
 * 164 stack variables, 5 constants, and 80 memory accesses
 */
#include "rdft/scalar/hc2cf.h"

static void hc2cfdft2_20(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP618033988, +0.618033988749894848204586834365638117720309180);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 8); m < me; m = m + 1, Rp = Rp + ms, Ip = Ip + ms, Rm = Rm - ms, Im = Im - ms, W = W + 8, MAKE_VOLATILE_STRIDE(80, rs)) {
	       E Tm, Tq, Tn, T1, T6, Tg, Tp, Tr, Tx, TU, Tb, T1i, T1A, T2y, T33;
	       E T1o, T1u, T2B, T30, T1Q, T2a, T26, T2e, T22, T2V, T2R, TG, TD, TH, T1V;
	       E TN, TW, TX, T13, T2u, T2q, T2m, T2j;
	       {
		    E Tw, T1h, T29, T1n, T2d, T1z, T25, TC, T21, T1t, To, T2U;
		    Tm = W[0];
		    Tq = W[3];
		    Tn = W[2];
		    To = Tm * Tn;
		    Tw = Tm * Tq;
		    T1 = W[6];
		    T1h = Tn * T1;
		    T29 = Tm * T1;
		    T6 = W[7];
		    T1n = Tn * T6;
		    T2d = Tm * T6;
		    Tg = W[5];
		    T1z = Tn * Tg;
		    T25 = Tm * Tg;
		    Tp = W[1];
		    Tr = FNMS(Tp, Tq, To);
		    Tx = FMA(Tp, Tn, Tw);
		    TU = FMA(Tp, Tq, To);
		    Tb = W[4];
		    TC = Tr * Tb;
		    T21 = Tm * Tb;
		    T1t = Tn * Tb;
		    T1i = FMA(Tq, T6, T1h);
		    T1A = FNMS(Tq, Tb, T1z);
		    T2y = FNMS(Tq, Tg, T1t);
		    T33 = FMA(Tp, Tb, T25);
		    T1o = FNMS(Tq, T1, T1n);
		    T1u = FMA(Tq, Tg, T1t);
		    T2B = FMA(Tq, Tb, T1z);
		    T30 = FNMS(Tp, Tg, T21);
		    T1Q = FNMS(Tx, Tg, TC);
		    T2a = FMA(Tp, T6, T29);
		    T26 = FNMS(Tp, Tb, T25);
		    T2e = FNMS(Tp, T1, T2d);
		    T22 = FMA(Tp, Tg, T21);
		    T2U = Tr * T6;
		    T2V = FNMS(Tx, T1, T2U);
		    {
			 E T2Q, TF, TE, TM;
			 T2Q = Tr * T1;
			 T2R = FMA(Tx, T6, T2Q);
			 TF = Tr * Tg;
			 TG = FNMS(Tx, Tb, TF);
			 TD = FMA(Tx, Tg, TC);
			 TE = TD * T1;
			 TM = TD * T6;
			 TH = FMA(TG, T6, TE);
			 T1V = FMA(Tx, Tb, TF);
			 TN = FNMS(TG, T1, TM);
			 {
			      E TV, T2t, T12, T2p;
			      TV = TU * Tb;
			      T2t = TU * T1;
			      T12 = TU * Tg;
			      T2p = TU * T6;
			      TW = FNMS(Tp, Tn, Tw);
			      TX = FNMS(TW, Tg, TV);
			      T13 = FMA(TW, Tb, T12);
			      T2u = FMA(TW, T6, T2t);
			      T2q = FNMS(TW, T1, T2p);
			      T2m = FNMS(TW, Tb, T12);
			      T2j = FMA(TW, Tg, TV);
			 }
		    }
	       }
	       {
		    E T36, T3Q, T4D, T5f, T2Y, T5g, T3P, T4E, TT, T5k, T5R, T39, T3m, T49, T4X;
		    E T3T, T2i, T5r, T5T, T3c, T3B, T4o, T4U, T3W, T2J, T5u, T5U, T3d, T3I, T4v;
		    E T4V, T3X, T1G, T5n, T5Q, T3a, T3t, T4g, T4Y, T3U;
		    {
			 E T9, T2f, T5, T4k, T2c, T3i, TA, T2O, T1e, T2Z, T1O, T2G, TQ, T2W, T1Y;
			 E T2C, T3v, Tj, T27, T3g, T1l, T1m, T2v, T1D, T2n, T3E, T4c, T1x, T2k, T1y;
			 E T2l, T10, T31, T11, T32, T16, T34, T3p, T4B, T1b, T4A, T3n, T1T, T1U, T4q;
			 E T2A, Te, Tf, T4i, T24, T1r, T2s, T4a, T3C, Tv, T43, T2N, T3L, TL, T45;
			 E T2T, T3N, T1L, T4s, T2F, T3x, T35, T4C;
			 {
			      E Th, Ti, T14, T15;
			      {
				   E T7, T8, Ty, Tz;
				   T7 = Rp[WS(rs, 9)];
				   T8 = Rm[WS(rs, 9)];
				   T9 = T7 - T8;
				   T2f = T7 + T8;
				   {
					E T4, T2b, T2, T3;
					T2 = Ip[WS(rs, 9)];
					T3 = Im[WS(rs, 9)];
					T4 = T2 + T3;
					T2b = T2 - T3;
					T5 = T1 * T4;
					T4k = T2e * T2b;
					T2c = T2a * T2b;
					T3i = T6 * T4;
				   }
				   Ty = Rp[WS(rs, 2)];
				   Tz = Rm[WS(rs, 2)];
				   TA = Ty + Tz;
				   T2O = Ty - Tz;
				   {
					E T1c, T1d, T1M, T1N;
					T1c = Ip[0];
					T1d = Im[0];
					T1e = T1c + T1d;
					T2Z = T1c - T1d;
					T1M = Rp[WS(rs, 1)];
					T1N = Rm[WS(rs, 1)];
					T1O = T1M - T1N;
					T2G = T1M + T1N;
				   }
			      }
			      {
				   E TO, TP, T1W, T1X;
				   TO = Rp[WS(rs, 7)];
				   TP = Rm[WS(rs, 7)];
				   TQ = TO + TP;
				   T2W = TO - TP;
				   T1W = Rm[WS(rs, 6)];
				   T1X = Rp[WS(rs, 6)];
				   T1Y = T1W - T1X;
				   T2C = T1X + T1W;
				   T3v = T1Q * T1Y;
			      }
			      Th = Rm[WS(rs, 4)];
			      Ti = Rp[WS(rs, 4)];
			      Tj = Th - Ti;
			      T27 = Ti + Th;
			      T3g = Tb * Tj;
			      {
				   E T1j, T1k, T1B, T1C;
				   T1j = Ip[WS(rs, 8)];
				   T1k = Im[WS(rs, 8)];
				   T1l = T1j - T1k;
				   T1m = T1i * T1l;
				   T2v = T1j + T1k;
				   T1B = Rp[WS(rs, 3)];
				   T1C = Rm[WS(rs, 3)];
				   T1D = T1B + T1C;
				   T2n = T1B - T1C;
				   T3E = T2j * T2n;
				   T4c = T1u * T1D;
			      }
			      {
				   E T1v, T1w, TY, TZ;
				   T1v = Ip[WS(rs, 3)];
				   T1w = Im[WS(rs, 3)];
				   T1x = T1v - T1w;
				   T2k = T1v + T1w;
				   T1y = T1u * T1x;
				   T2l = T2j * T2k;
				   TY = Ip[WS(rs, 5)];
				   TZ = Im[WS(rs, 5)];
				   T10 = TY + TZ;
				   T31 = TY - TZ;
				   T11 = TX * T10;
				   T32 = T30 * T31;
			      }
			      T14 = Rp[WS(rs, 5)];
			      T15 = Rm[WS(rs, 5)];
			      T16 = T14 - T15;
			      T34 = T14 + T15;
			      T3p = TX * T16;
			      T4B = T30 * T34;
			      {
				   E T18, T19, T1a, T2z, T1R, T1S;
				   T18 = Rm[0];
				   T19 = Rp[0];
				   T1a = T18 - T19;
				   T1b = Tp * T1a;
				   T4A = T19 + T18;
				   T3n = Tm * T1a;
				   T1R = Ip[WS(rs, 6)];
				   T1S = Im[WS(rs, 6)];
				   T1T = T1R + T1S;
				   T2z = T1R - T1S;
				   T1U = T1Q * T1T;
				   T4q = T2B * T2z;
				   T2A = T2y * T2z;
			      }
			      {
				   E T23, Tc, Td, T2r, T1p, T1q;
				   Tc = Ip[WS(rs, 4)];
				   Td = Im[WS(rs, 4)];
				   Te = Tc + Td;
				   T23 = Tc - Td;
				   Tf = Tb * Te;
				   T4i = T26 * T23;
				   T24 = T22 * T23;
				   T1p = Rp[WS(rs, 8)];
				   T1q = Rm[WS(rs, 8)];
				   T1r = T1p + T1q;
				   T2r = T1q - T1p;
				   T2s = T2q * T2r;
				   T4a = T1i * T1r;
				   T3C = T2u * T2r;
			      }
			      {
				   E Tu, T2M, Ts, Tt;
				   Ts = Ip[WS(rs, 2)];
				   Tt = Im[WS(rs, 2)];
				   Tu = Ts - Tt;
				   T2M = Ts + Tt;
				   Tv = Tr * Tu;
				   T43 = Tx * Tu;
				   T2N = TD * T2M;
				   T3L = TG * T2M;
			      }
			      {
				   E TK, T2S, TI, TJ;
				   TI = Ip[WS(rs, 7)];
				   TJ = Im[WS(rs, 7)];
				   TK = TI - TJ;
				   T2S = TI + TJ;
				   TL = TH * TK;
				   T45 = TN * TK;
				   T2T = T2R * T2S;
				   T3N = T2V * T2S;
			      }
			      {
				   E T1K, T2E, T1I, T1J;
				   T1I = Ip[WS(rs, 1)];
				   T1J = Im[WS(rs, 1)];
				   T1K = T1I + T1J;
				   T2E = T1I - T1J;
				   T1L = Tn * T1K;
				   T4s = TW * T2E;
				   T2F = TU * T2E;
				   T3x = Tq * T1K;
			      }
			 }
			 T35 = FNMS(T33, T34, T32);
			 T36 = T2Z - T35;
			 T3Q = T35 + T2Z;
			 T4C = FMA(T33, T31, T4B);
			 T4D = T4A - T4C;
			 T5f = T4A + T4C;
			 {
			      E T2P, T2X, T3M, T3O;
			      T2P = FNMS(TG, T2O, T2N);
			      T2X = FNMS(T2V, T2W, T2T);
			      T2Y = T2P - T2X;
			      T5g = T2P + T2X;
			      T3M = FMA(TD, T2O, T3L);
			      T3O = FMA(T2R, T2W, T3N);
			      T3P = T3M + T3O;
			      T4E = T3O - T3M;
			 }
			 {
			      E Tl, T5j, T47, T5i, TS, T3l, T3k, T48;
			      {
				   E Ta, Tk, T44, T46;
				   Ta = FNMS(T6, T9, T5);
				   Tk = FMA(Tg, Tj, Tf);
				   Tl = Ta - Tk;
				   T5j = Tk + Ta;
				   T44 = FMA(Tr, TA, T43);
				   T46 = FMA(TH, TQ, T45);
				   T47 = T44 - T46;
				   T5i = T44 + T46;
			      }
			      {
				   E TB, TR, T3h, T3j;
				   TB = FNMS(Tx, TA, Tv);
				   TR = FNMS(TN, TQ, TL);
				   TS = TB - TR;
				   T3l = TB + TR;
				   T3h = FNMS(Tg, Te, T3g);
				   T3j = FMA(T1, T9, T3i);
				   T3k = T3h - T3j;
				   T48 = T3h + T3j;
			      }
			      TT = Tl - TS;
			      T5k = T5i + T5j;
			      T5R = T5i - T5j;
			      T39 = TS + Tl;
			      T3m = T3k - T3l;
			      T49 = T47 + T48;
			      T4X = T47 - T48;
			      T3T = T3l + T3k;
			 }
			 {
			      E T20, T5q, T4m, T5p, T2h, T3A, T3z, T4n;
			      {
				   E T1P, T1Z, T4j, T4l;
				   T1P = FNMS(Tq, T1O, T1L);
				   T1Z = FMA(T1V, T1Y, T1U);
				   T20 = T1P - T1Z;
				   T5q = T1Z + T1P;
				   T4j = FMA(T22, T27, T4i);
				   T4l = FMA(T2a, T2f, T4k);
				   T4m = T4j - T4l;
				   T5p = T4j + T4l;
			      }
			      {
				   E T28, T2g, T3w, T3y;
				   T28 = FNMS(T26, T27, T24);
				   T2g = FNMS(T2e, T2f, T2c);
				   T2h = T28 - T2g;
				   T3A = T28 + T2g;
				   T3w = FNMS(T1V, T1T, T3v);
				   T3y = FMA(Tn, T1O, T3x);
				   T3z = T3w - T3y;
				   T4n = T3w + T3y;
			      }
			      T2i = T20 - T2h;
			      T5r = T5p + T5q;
			      T5T = T5p - T5q;
			      T3c = T2h + T20;
			      T3B = T3z - T3A;
			      T4o = T4m + T4n;
			      T4U = T4m - T4n;
			      T3W = T3A + T3z;
			 }
			 {
			      E T2x, T5s, T4u, T5t, T2I, T3H, T3G, T4p;
			      {
				   E T2o, T2w, T4r, T4t;
				   T2o = FNMS(T2m, T2n, T2l);
				   T2w = FMA(T2u, T2v, T2s);
				   T2x = T2o - T2w;
				   T5s = T2w + T2o;
				   T4r = FMA(T2y, T2C, T4q);
				   T4t = FMA(TU, T2G, T4s);
				   T4u = T4r - T4t;
				   T5t = T4r + T4t;
			      }
			      {
				   E T2D, T2H, T3D, T3F;
				   T2D = FNMS(T2B, T2C, T2A);
				   T2H = FNMS(TW, T2G, T2F);
				   T2I = T2D - T2H;
				   T3H = T2D + T2H;
				   T3D = FNMS(T2q, T2v, T3C);
				   T3F = FMA(T2m, T2k, T3E);
				   T3G = T3D - T3F;
				   T4p = T3D + T3F;
			      }
			      T2J = T2x - T2I;
			      T5u = T5s + T5t;
			      T5U = T5t - T5s;
			      T3d = T2x + T2I;
			      T3I = T3G - T3H;
			      T4v = T4p + T4u;
			      T4V = T4u - T4p;
			      T3X = T3G + T3H;
			 }
			 {
			      E T1g, T5m, T4e, T5l, T1F, T3s, T3r, T4f;
			      {
				   E T17, T1f, T4b, T4d;
				   T17 = FNMS(T13, T16, T11);
				   T1f = FMA(Tm, T1e, T1b);
				   T1g = T17 - T1f;
				   T5m = T17 + T1f;
				   T4b = FMA(T1o, T1l, T4a);
				   T4d = FMA(T1A, T1x, T4c);
				   T4e = T4b - T4d;
				   T5l = T4b + T4d;
			      }
			      {
				   E T1s, T1E, T3o, T3q;
				   T1s = FNMS(T1o, T1r, T1m);
				   T1E = FNMS(T1A, T1D, T1y);
				   T1F = T1s - T1E;
				   T3s = T1s + T1E;
				   T3o = FNMS(Tp, T1e, T3n);
				   T3q = FMA(T13, T10, T3p);
				   T3r = T3o - T3q;
				   T4f = T3q + T3o;
			      }
			      T1G = T1g - T1F;
			      T5n = T5l + T5m;
			      T5Q = T5l - T5m;
			      T3a = T1F + T1g;
			      T3t = T3r - T3s;
			      T4g = T4e + T4f;
			      T4Y = T4e - T4f;
			      T3U = T3s + T3r;
			 }
		    }
		    {
			 E T50, T52, T37, T2L, T4R, T4S, T51, T4T;
			 {
			      E T4W, T4Z, T1H, T2K;
			      T4W = T4U - T4V;
			      T4Z = T4X - T4Y;
			      T50 = FNMS(KP618033988, T4Z, T4W);
			      T52 = FMA(KP618033988, T4W, T4Z);
			      T37 = T2Y + T36;
			      T1H = TT + T1G;
			      T2K = T2i + T2J;
			      T2L = T1H + T2K;
			      T4R = FMA(KP250000000, T2L, T37);
			      T4S = T1H - T2K;
			 }
			 Im[WS(rs, 4)] = KP500000000 * (T2L - T37);
			 T51 = FNMS(KP559016994, T4S, T4R);
			 Im[0] = -(KP500000000 * (FMA(KP951056516, T52, T51)));
			 Im[WS(rs, 8)] = -(KP500000000 * (FNMS(KP951056516, T52, T51)));
			 T4T = FMA(KP559016994, T4S, T4R);
			 Ip[WS(rs, 3)] = KP500000000 * (FNMS(KP951056516, T50, T4T));
			 Ip[WS(rs, 7)] = KP500000000 * (FMA(KP951056516, T50, T4T));
		    }
		    {
			 E T5c, T5e, T53, T56, T57, T58, T5d, T59;
			 {
			      E T5a, T5b, T54, T55;
			      T5a = T2J - T2i;
			      T5b = T1G - TT;
			      T5c = FNMS(KP618033988, T5b, T5a);
			      T5e = FMA(KP618033988, T5a, T5b);
			      T53 = T4D - T4E;
			      T54 = T4X + T4Y;
			      T55 = T4U + T4V;
			      T56 = T54 + T55;
			      T57 = FNMS(KP250000000, T56, T53);
			      T58 = T54 - T55;
			 }
			 Rm[WS(rs, 4)] = KP500000000 * (T53 + T56);
			 T5d = FMA(KP559016994, T58, T57);
			 Rm[WS(rs, 8)] = KP500000000 * (FMA(KP951056516, T5e, T5d));
			 Rm[0] = KP500000000 * (FNMS(KP951056516, T5e, T5d));
			 T59 = FNMS(KP559016994, T58, T57);
			 Rp[WS(rs, 3)] = KP500000000 * (FMA(KP951056516, T5c, T59));
			 Rp[WS(rs, 7)] = KP500000000 * (FNMS(KP951056516, T5c, T59));
		    }
		    {
			 E T4x, T4z, T38, T3f, T40, T41, T4y, T42;
			 {
			      E T4h, T4w, T3b, T3e;
			      T4h = T49 - T4g;
			      T4w = T4o - T4v;
			      T4x = FMA(KP618033988, T4w, T4h);
			      T4z = FNMS(KP618033988, T4h, T4w);
			      T38 = T36 - T2Y;
			      T3b = T39 + T3a;
			      T3e = T3c + T3d;
			      T3f = T3b + T3e;
			      T40 = FNMS(KP250000000, T3f, T38);
			      T41 = T3b - T3e;
			 }
			 Ip[WS(rs, 5)] = KP500000000 * (T38 + T3f);
			 T4y = FNMS(KP559016994, T41, T40);
			 Im[WS(rs, 2)] = -(KP500000000 * (FMA(KP951056516, T4z, T4y)));
			 Im[WS(rs, 6)] = -(KP500000000 * (FNMS(KP951056516, T4z, T4y)));
			 T42 = FMA(KP559016994, T41, T40);
			 Ip[WS(rs, 1)] = KP500000000 * (FNMS(KP951056516, T4x, T42));
			 Ip[WS(rs, 9)] = KP500000000 * (FMA(KP951056516, T4x, T42));
		    }
		    {
			 E T4O, T4Q, T4F, T4I, T4J, T4K, T4P, T4L;
			 {
			      E T4M, T4N, T4G, T4H;
			      T4M = T39 - T3a;
			      T4N = T3c - T3d;
			      T4O = FMA(KP618033988, T4N, T4M);
			      T4Q = FNMS(KP618033988, T4M, T4N);
			      T4F = T4D + T4E;
			      T4G = T49 + T4g;
			      T4H = T4o + T4v;
			      T4I = T4G + T4H;
			      T4J = FNMS(KP250000000, T4I, T4F);
			      T4K = T4G - T4H;
			 }
			 Rp[WS(rs, 5)] = KP500000000 * (T4F + T4I);
			 T4P = FNMS(KP559016994, T4K, T4J);
			 Rm[WS(rs, 6)] = KP500000000 * (FMA(KP951056516, T4Q, T4P));
			 Rm[WS(rs, 2)] = KP500000000 * (FNMS(KP951056516, T4Q, T4P));
			 T4L = FMA(KP559016994, T4K, T4J);
			 Rp[WS(rs, 1)] = KP500000000 * (FMA(KP951056516, T4O, T4L));
			 Rp[WS(rs, 9)] = KP500000000 * (FNMS(KP951056516, T4O, T4L));
		    }
		    {
			 E T5W, T5Y, T3R, T3K, T5N, T5O, T5X, T5P;
			 {
			      E T5S, T5V, T3u, T3J;
			      T5S = T5Q - T5R;
			      T5V = T5T - T5U;
			      T5W = FNMS(KP618033988, T5V, T5S);
			      T5Y = FMA(KP618033988, T5S, T5V);
			      T3R = T3P + T3Q;
			      T3u = T3m + T3t;
			      T3J = T3B + T3I;
			      T3K = T3u + T3J;
			      T5N = FMA(KP250000000, T3K, T3R);
			      T5O = T3J - T3u;
			 }
			 Im[WS(rs, 9)] = KP500000000 * (T3K - T3R);
			 T5X = FNMS(KP559016994, T5O, T5N);
			 Ip[WS(rs, 2)] = KP500000000 * (FMA(KP951056516, T5Y, T5X));
			 Im[WS(rs, 1)] = -(KP500000000 * (FNMS(KP951056516, T5Y, T5X)));
			 T5P = FMA(KP559016994, T5O, T5N);
			 Ip[WS(rs, 6)] = KP500000000 * (FMA(KP951056516, T5W, T5P));
			 Im[WS(rs, 5)] = -(KP500000000 * (FNMS(KP951056516, T5W, T5P)));
		    }
		    {
			 E T68, T6a, T5Z, T62, T63, T64, T69, T65;
			 {
			      E T66, T67, T60, T61;
			      T66 = T3I - T3B;
			      T67 = T3t - T3m;
			      T68 = FNMS(KP618033988, T67, T66);
			      T6a = FMA(KP618033988, T66, T67);
			      T5Z = T5f - T5g;
			      T60 = T5R + T5Q;
			      T61 = T5T + T5U;
			      T62 = T60 + T61;
			      T63 = FNMS(KP250000000, T62, T5Z);
			      T64 = T60 - T61;
			 }
			 Rm[WS(rs, 9)] = KP500000000 * (T5Z + T62);
			 T69 = FMA(KP559016994, T64, T63);
			 Rp[WS(rs, 6)] = KP500000000 * (FMA(KP951056516, T6a, T69));
			 Rm[WS(rs, 5)] = KP500000000 * (FNMS(KP951056516, T6a, T69));
			 T65 = FNMS(KP559016994, T64, T63);
			 Rp[WS(rs, 2)] = KP500000000 * (FNMS(KP951056516, T68, T65));
			 Rm[WS(rs, 1)] = KP500000000 * (FMA(KP951056516, T68, T65));
		    }
		    {
			 E T5K, T5M, T3S, T3Z, T5F, T5G, T5L, T5H;
			 {
			      E T5I, T5J, T3V, T3Y;
			      T5I = T5k - T5n;
			      T5J = T5u - T5r;
			      T5K = FNMS(KP618033988, T5J, T5I);
			      T5M = FMA(KP618033988, T5I, T5J);
			      T3S = T3Q - T3P;
			      T3V = T3T + T3U;
			      T3Y = T3W + T3X;
			      T3Z = T3V + T3Y;
			      T5F = FNMS(KP250000000, T3Z, T3S);
			      T5G = T3V - T3Y;
			 }
			 Ip[0] = KP500000000 * (T3S + T3Z);
			 T5L = FNMS(KP559016994, T5G, T5F);
			 Ip[WS(rs, 8)] = KP500000000 * (FMA(KP951056516, T5M, T5L));
			 Im[WS(rs, 7)] = -(KP500000000 * (FNMS(KP951056516, T5M, T5L)));
			 T5H = FMA(KP559016994, T5G, T5F);
			 Ip[WS(rs, 4)] = KP500000000 * (FMA(KP951056516, T5K, T5H));
			 Im[WS(rs, 3)] = -(KP500000000 * (FNMS(KP951056516, T5K, T5H)));
		    }
		    {
			 E T5C, T5E, T5h, T5w, T5x, T5y, T5D, T5z;
			 {
			      E T5A, T5B, T5o, T5v;
			      T5A = T3T - T3U;
			      T5B = T3W - T3X;
			      T5C = FMA(KP618033988, T5B, T5A);
			      T5E = FNMS(KP618033988, T5A, T5B);
			      T5h = T5f + T5g;
			      T5o = T5k + T5n;
			      T5v = T5r + T5u;
			      T5w = T5o + T5v;
			      T5x = FNMS(KP250000000, T5w, T5h);
			      T5y = T5o - T5v;
			 }
			 Rp[0] = KP500000000 * (T5h + T5w);
			 T5D = FNMS(KP559016994, T5y, T5x);
			 Rp[WS(rs, 8)] = KP500000000 * (FMA(KP951056516, T5E, T5D));
			 Rm[WS(rs, 7)] = KP500000000 * (FNMS(KP951056516, T5E, T5D));
			 T5z = FMA(KP559016994, T5y, T5x);
			 Rp[WS(rs, 4)] = KP500000000 * (FNMS(KP951056516, T5C, T5z));
			 Rm[WS(rs, 3)] = KP500000000 * (FMA(KP951056516, T5C, T5z));
		    }
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     { TW_CEXP, 1, 1 },
     { TW_CEXP, 1, 3 },
     { TW_CEXP, 1, 9 },
     { TW_CEXP, 1, 19 },
     { TW_NEXT, 1, 0 }
};

static const hc2c_desc desc = { 20, "hc2cfdft2_20", twinstr, &GENUS, { 176, 98, 140, 0 } };

void X(codelet_hc2cfdft2_20) (planner *p) {
     X(khc2c_register) (p, hc2cfdft2_20, &desc, HC2C_VIA_DFT);
}
#else

/* Generated by: ../../../genfft/gen_hc2cdft.native -compact -variables 4 -pipeline-latency 4 -twiddle-log3 -precompute-twiddles -n 20 -dit -name hc2cfdft2_20 -include rdft/scalar/hc2cf.h */

/*
 * This function contains 316 FP additions, 180 FP multiplications,
 * (or, 244 additions, 108 multiplications, 72 fused multiply/add),
 * 134 stack variables, 5 constants, and 80 memory accesses
 */
#include "rdft/scalar/hc2cf.h"

static void hc2cfdft2_20(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP125000000, +0.125000000000000000000000000000000000000000000);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP279508497, +0.279508497187473712051146708591409529430077295);
     DK(KP293892626, +0.293892626146236564584352977319536384298826219);
     DK(KP475528258, +0.475528258147576786058219666689691071702849317);
     {
	  INT m;
	  for (m = mb, W = W + ((mb - 1) * 8); m < me; m = m + 1, Rp = Rp + ms, Ip = Ip + ms, Rm = Rm - ms, Im = Im - ms, W = W + 8, MAKE_VOLATILE_STRIDE(80, rs)) {
	       E T4, T7, Tm, To, Tq, Tu, T1I, T1G, T8, T5, Ta, T1u, T2u, Tg, T2s;
	       E T21, T1A, T1Z, T1O, T2I, T1K, T2G, Tw, TC, T2a, T2e, TH, TI, TJ, TX;
	       E T2D, TN, T2B, T26, T1n, TZ, T24, T1j;
	       {
		    E T9, T1y, Te, T1t, T6, T1z, Tf, T1s;
		    {
			 E Tn, Tt, Tp, Ts;
			 T4 = W[0];
			 T7 = W[1];
			 Tm = W[2];
			 To = W[3];
			 Tn = T4 * Tm;
			 Tt = T7 * Tm;
			 Tp = T7 * To;
			 Ts = T4 * To;
			 Tq = Tn - Tp;
			 Tu = Ts + Tt;
			 T1I = Ts - Tt;
			 T1G = Tn + Tp;
			 T8 = W[5];
			 T9 = T7 * T8;
			 T1y = Tm * T8;
			 Te = T4 * T8;
			 T1t = To * T8;
			 T5 = W[4];
			 T6 = T4 * T5;
			 T1z = To * T5;
			 Tf = T7 * T5;
			 T1s = Tm * T5;
		    }
		    Ta = T6 - T9;
		    T1u = T1s + T1t;
		    T2u = T1y + T1z;
		    Tg = Te + Tf;
		    T2s = T1s - T1t;
		    T21 = Te - Tf;
		    T1A = T1y - T1z;
		    T1Z = T6 + T9;
		    {
			 E T1M, T1N, T1H, T1J;
			 T1M = T1G * T8;
			 T1N = T1I * T5;
			 T1O = T1M + T1N;
			 T2I = T1M - T1N;
			 T1H = T1G * T5;
			 T1J = T1I * T8;
			 T1K = T1H - T1J;
			 T2G = T1H + T1J;
			 {
			      E Tr, Tv, TA, TB;
			      Tr = Tq * T5;
			      Tv = Tu * T8;
			      Tw = Tr + Tv;
			      TA = Tq * T8;
			      TB = Tu * T5;
			      TC = TA - TB;
			      T2a = Tr - Tv;
			      T2e = TA + TB;
			      TH = W[6];
			      TI = W[7];
			      TJ = FMA(Tq, TH, Tu * TI);
			      TX = FMA(Tw, TH, TC * TI);
			      T2D = FMA(T1G, TH, T1I * TI);
			      TN = FNMS(Tu, TH, Tq * TI);
			      T2B = FNMS(T1I, TH, T1G * TI);
			      T26 = FNMS(T7, TH, T4 * TI);
			      T1n = FNMS(To, TH, Tm * TI);
			      TZ = FNMS(TC, TH, Tw * TI);
			      T24 = FMA(T4, TH, T7 * TI);
			      T1j = FMA(Tm, TH, To * TI);
			 }
		    }
	       }
	       {
		    E Tl, T3n, T1i, T2Q, T47, T50, T4S, T5i, T2M, T2T, T4I, T5f, T4L, T5e, T4P;
		    E T5h, T2r, T2S, T1X, T2P, T31, T3u, T36, T3t, T3E, T4l, T3U, T4j, T3h, T3r;
		    E T3J, T4m, T3c, T3q, T3P, T4i, TS, T51, T3m, T48;
		    {
			 E T3, T45, T1V, T3f, Tz, TF, TW, T3A, TM, TQ, T11, T3B, Td, Tj, T1Q;
			 E T3e, T19, T3L, T23, T39, T2p, T3S, T2z, T34, T1E, T3G, T2K, T2Y, T1g, T3M;
			 E T28, T3a, T2i, T3R, T2w, T33, T1r, T3F, T2F, T2X, T4N, T4O;
			 {
			      E T1, T2, T1R, T1S, T1T, T1U;
			      T1 = Ip[0];
			      T2 = Im[0];
			      T1R = T1 + T2;
			      T1S = Rp[0];
			      T1T = Rm[0];
			      T1U = T1S - T1T;
			      T3 = T1 - T2;
			      T45 = T1S + T1T;
			      T1V = FNMS(T7, T1U, T4 * T1R);
			      T3f = FMA(T4, T1U, T7 * T1R);
			 }
			 {
			      E Tx, Ty, TU, TD, TE, TV;
			      Tx = Ip[WS(rs, 2)];
			      Ty = Im[WS(rs, 2)];
			      TU = Tx - Ty;
			      TD = Rp[WS(rs, 2)];
			      TE = Rm[WS(rs, 2)];
			      TV = TD + TE;
			      Tz = Tx + Ty;
			      TF = TD - TE;
			      TW = FNMS(Tu, TV, Tq * TU);
			      T3A = FMA(Tu, TU, Tq * TV);
			 }
			 {
			      E TK, TL, TY, TO, TP, T10;
			      TK = Ip[WS(rs, 7)];
			      TL = Im[WS(rs, 7)];
			      TY = TK - TL;
			      TO = Rp[WS(rs, 7)];
			      TP = Rm[WS(rs, 7)];
			      T10 = TO + TP;
			      TM = TK + TL;
			      TQ = TO - TP;
			      T11 = FNMS(TZ, T10, TX * TY);
			      T3B = FMA(TZ, TY, TX * T10);
			 }
			 {
			      E Tb, Tc, T1L, Th, Ti, T1P;
			      Tb = Ip[WS(rs, 5)];
			      Tc = Im[WS(rs, 5)];
			      T1L = Tb + Tc;
			      Th = Rp[WS(rs, 5)];
			      Ti = Rm[WS(rs, 5)];
			      T1P = Th - Ti;
			      Td = Tb - Tc;
			      Tj = Th + Ti;
			      T1Q = FNMS(T1O, T1P, T1K * T1L);
			      T3e = FMA(T1K, T1P, T1O * T1L);
			 }
			 {
			      E T15, T20, T18, T22;
			      {
				   E T13, T14, T16, T17;
				   T13 = Ip[WS(rs, 4)];
				   T14 = Im[WS(rs, 4)];
				   T15 = T13 + T14;
				   T20 = T13 - T14;
				   T16 = Rp[WS(rs, 4)];
				   T17 = Rm[WS(rs, 4)];
				   T18 = T16 - T17;
				   T22 = T16 + T17;
			      }
			      T19 = FNMS(T8, T18, T5 * T15);
			      T3L = FMA(T21, T20, T1Z * T22);
			      T23 = FNMS(T21, T22, T1Z * T20);
			      T39 = FMA(T8, T15, T5 * T18);
			 }
			 {
			      E T2l, T2x, T2o, T2y;
			      {
				   E T2j, T2k, T2m, T2n;
				   T2j = Ip[WS(rs, 1)];
				   T2k = Im[WS(rs, 1)];
				   T2l = T2j + T2k;
				   T2x = T2j - T2k;
				   T2m = Rp[WS(rs, 1)];
				   T2n = Rm[WS(rs, 1)];
				   T2o = T2m - T2n;
				   T2y = T2m + T2n;
			      }
			      T2p = FNMS(To, T2o, Tm * T2l);
			      T3S = FMA(T1I, T2x, T1G * T2y);
			      T2z = FNMS(T1I, T2y, T1G * T2x);
			      T34 = FMA(To, T2l, Tm * T2o);
			 }
			 {
			      E T1x, T2H, T1D, T2J;
			      {
				   E T1v, T1w, T1B, T1C;
				   T1v = Ip[WS(rs, 3)];
				   T1w = Im[WS(rs, 3)];
				   T1x = T1v - T1w;
				   T2H = T1v + T1w;
				   T1B = Rp[WS(rs, 3)];
				   T1C = Rm[WS(rs, 3)];
				   T1D = T1B + T1C;
				   T2J = T1B - T1C;
			      }
			      T1E = FNMS(T1A, T1D, T1u * T1x);
			      T3G = FMA(T1u, T1D, T1A * T1x);
			      T2K = FNMS(T2I, T2J, T2G * T2H);
			      T2Y = FMA(T2G, T2J, T2I * T2H);
			 }
			 {
			      E T1c, T25, T1f, T27;
			      {
				   E T1a, T1b, T1d, T1e;
				   T1a = Ip[WS(rs, 9)];
				   T1b = Im[WS(rs, 9)];
				   T1c = T1a + T1b;
				   T25 = T1a - T1b;
				   T1d = Rp[WS(rs, 9)];
				   T1e = Rm[WS(rs, 9)];
				   T1f = T1d - T1e;
				   T27 = T1d + T1e;
			      }
			      T1g = FNMS(TI, T1f, TH * T1c);
			      T3M = FMA(T26, T25, T24 * T27);
			      T28 = FNMS(T26, T27, T24 * T25);
			      T3a = FMA(TI, T1c, TH * T1f);
			 }
			 {
			      E T2d, T2t, T2h, T2v;
			      {
				   E T2b, T2c, T2f, T2g;
				   T2b = Ip[WS(rs, 6)];
				   T2c = Im[WS(rs, 6)];
				   T2d = T2b + T2c;
				   T2t = T2b - T2c;
				   T2f = Rp[WS(rs, 6)];
				   T2g = Rm[WS(rs, 6)];
				   T2h = T2f - T2g;
				   T2v = T2f + T2g;
			      }
			      T2i = FNMS(T2e, T2h, T2a * T2d);
			      T3R = FMA(T2u, T2t, T2s * T2v);
			      T2w = FNMS(T2u, T2v, T2s * T2t);
			      T33 = FMA(T2e, T2d, T2a * T2h);
			 }
			 {
			      E T1m, T2E, T1q, T2C;
			      {
				   E T1k, T1l, T1o, T1p;
				   T1k = Ip[WS(rs, 8)];
				   T1l = Im[WS(rs, 8)];
				   T1m = T1k - T1l;
				   T2E = T1k + T1l;
				   T1o = Rp[WS(rs, 8)];
				   T1p = Rm[WS(rs, 8)];
				   T1q = T1o + T1p;
				   T2C = T1p - T1o;
			      }
			      T1r = FNMS(T1n, T1q, T1j * T1m);
			      T3F = FMA(T1j, T1q, T1n * T1m);
			      T2F = FMA(T2B, T2C, T2D * T2E);
			      T2X = FNMS(T2B, T2E, T2D * T2C);
			 }
			 {
			      E Tk, T12, T1h, T46;
			      Tk = FNMS(Tg, Tj, Ta * Td);
			      Tl = T3 - Tk;
			      T3n = Tk + T3;
			      T12 = TW - T11;
			      T1h = T19 - T1g;
			      T1i = T12 - T1h;
			      T2Q = T12 + T1h;
			      T46 = FMA(Ta, Tj, Tg * Td);
			      T47 = T45 - T46;
			      T50 = T45 + T46;
			      {
				   E T4Q, T4R, T2A, T2L;
				   T4Q = T2F + T2K;
				   T4R = T3R + T3S;
				   T4S = T4Q + T4R;
				   T5i = T4R - T4Q;
				   T2A = T2w - T2z;
				   T2L = T2F - T2K;
				   T2M = T2A - T2L;
				   T2T = T2L + T2A;
			      }
			 }
			 {
			      E T4G, T4H, T4J, T4K;
			      T4G = T3A + T3B;
			      T4H = T19 + T1g;
			      T4I = T4G + T4H;
			      T5f = T4G - T4H;
			      T4J = T3F + T3G;
			      T4K = T1Q + T1V;
			      T4L = T4J + T4K;
			      T5e = T4J - T4K;
			 }
			 T4N = T3L + T3M;
			 T4O = T2i + T2p;
			 T4P = T4N + T4O;
			 T5h = T4N - T4O;
			 {
			      E T29, T2q, T1F, T1W;
			      T29 = T23 - T28;
			      T2q = T2i - T2p;
			      T2r = T29 - T2q;
			      T2S = T29 + T2q;
			      T1F = T1r - T1E;
			      T1W = T1Q - T1V;
			      T1X = T1F + T1W;
			      T2P = T1W - T1F;
			 }
			 {
			      E T3C, T3D, T3N, T3O;
			      {
				   E T2Z, T30, T32, T35;
				   T2Z = T2X - T2Y;
				   T30 = T2w + T2z;
				   T31 = T2Z - T30;
				   T3u = T2Z + T30;
				   T32 = T23 + T28;
				   T35 = T33 + T34;
				   T36 = T32 + T35;
				   T3t = T32 - T35;
			      }
			      T3C = T3A - T3B;
			      T3D = T3a - T39;
			      T3E = T3C + T3D;
			      T4l = T3C - T3D;
			      {
				   E T3Q, T3T, T3d, T3g;
				   T3Q = T2X + T2Y;
				   T3T = T3R - T3S;
				   T3U = T3Q + T3T;
				   T4j = T3T - T3Q;
				   T3d = T1r + T1E;
				   T3g = T3e + T3f;
				   T3h = T3d + T3g;
				   T3r = T3d - T3g;
			      }
			      {
				   E T3H, T3I, T38, T3b;
				   T3H = T3F - T3G;
				   T3I = T3e - T3f;
				   T3J = T3H + T3I;
				   T4m = T3H - T3I;
				   T38 = TW + T11;
				   T3b = T39 + T3a;
				   T3c = T38 + T3b;
				   T3q = T38 - T3b;
			      }
			      T3N = T3L - T3M;
			      T3O = T34 - T33;
			      T3P = T3N + T3O;
			      T4i = T3N - T3O;
			      {
				   E TG, TR, T3k, T3l;
				   TG = FNMS(TC, TF, Tw * Tz);
				   TR = FNMS(TN, TQ, TJ * TM);
				   TS = TG - TR;
				   T51 = TG + TR;
				   T3k = FMA(TC, Tz, Tw * TF);
				   T3l = FMA(TN, TM, TJ * TQ);
				   T3m = T3k + T3l;
				   T48 = T3l - T3k;
			      }
			 }
		    }
		    {
			 E T3W, T3Y, TT, T2O, T3x, T3y, T3X, T3z;
			 {
			      E T3K, T3V, T1Y, T2N;
			      T3K = T3E - T3J;
			      T3V = T3P - T3U;
			      T3W = FMA(KP475528258, T3K, KP293892626 * T3V);
			      T3Y = FNMS(KP293892626, T3K, KP475528258 * T3V);
			      TT = Tl - TS;
			      T1Y = T1i + T1X;
			      T2N = T2r + T2M;
			      T2O = T1Y + T2N;
			      T3x = KP279508497 * (T1Y - T2N);
			      T3y = FNMS(KP125000000, T2O, KP500000000 * TT);
			 }
			 Ip[WS(rs, 5)] = KP500000000 * (TT + T2O);
			 T3X = T3x - T3y;
			 Im[WS(rs, 2)] = T3X - T3Y;
			 Im[WS(rs, 6)] = T3X + T3Y;
			 T3z = T3x + T3y;
			 Ip[WS(rs, 1)] = T3z - T3W;
			 Ip[WS(rs, 9)] = T3z + T3W;
		    }
		    {
			 E T41, T4d, T49, T4a, T44, T4b, T4e, T4c;
			 {
			      E T3Z, T40, T42, T43;
			      T3Z = T1i - T1X;
			      T40 = T2r - T2M;
			      T41 = FMA(KP475528258, T3Z, KP293892626 * T40);
			      T4d = FNMS(KP293892626, T3Z, KP475528258 * T40);
			      T49 = T47 + T48;
			      T42 = T3E + T3J;
			      T43 = T3P + T3U;
			      T4a = T42 + T43;
			      T44 = KP279508497 * (T42 - T43);
			      T4b = FNMS(KP125000000, T4a, KP500000000 * T49);
			 }
			 Rp[WS(rs, 5)] = KP500000000 * (T49 + T4a);
			 T4e = T4b - T44;
			 Rm[WS(rs, 6)] = T4d + T4e;
			 Rm[WS(rs, 2)] = T4e - T4d;
			 T4c = T44 + T4b;
			 Rp[WS(rs, 1)] = T41 + T4c;
			 Rp[WS(rs, 9)] = T4c - T41;
		    }
		    {
			 E T4o, T4q, T2W, T2V, T4f, T4g, T4p, T4h;
			 {
			      E T4k, T4n, T2R, T2U;
			      T4k = T4i - T4j;
			      T4n = T4l - T4m;
			      T4o = FNMS(KP293892626, T4n, KP475528258 * T4k);
			      T4q = FMA(KP475528258, T4n, KP293892626 * T4k);
			      T2W = TS + Tl;
			      T2R = T2P - T2Q;
			      T2U = T2S + T2T;
			      T2V = T2R - T2U;
			      T4f = FMA(KP500000000, T2W, KP125000000 * T2V);
			      T4g = KP279508497 * (T2R + T2U);
			 }
			 Im[WS(rs, 4)] = KP500000000 * (T2V - T2W);
			 T4p = T4g - T4f;
			 Im[0] = T4p - T4q;
			 Im[WS(rs, 8)] = T4p + T4q;
			 T4h = T4f + T4g;
			 Ip[WS(rs, 3)] = T4h - T4o;
			 Ip[WS(rs, 7)] = T4h + T4o;
		    }
		    {
			 E T4t, T4B, T4u, T4x, T4y, T4z, T4C, T4A;
			 {
			      E T4r, T4s, T4v, T4w;
			      T4r = T2S - T2T;
			      T4s = T2Q + T2P;
			      T4t = FNMS(KP293892626, T4s, KP475528258 * T4r);
			      T4B = FMA(KP475528258, T4s, KP293892626 * T4r);
			      T4u = T47 - T48;
			      T4v = T4l + T4m;
			      T4w = T4i + T4j;
			      T4x = T4v + T4w;
			      T4y = FNMS(KP125000000, T4x, KP500000000 * T4u);
			      T4z = KP279508497 * (T4v - T4w);
			 }
			 Rm[WS(rs, 4)] = KP500000000 * (T4u + T4x);
			 T4C = T4z + T4y;
			 Rm[WS(rs, 8)] = T4B + T4C;
			 Rm[0] = T4C - T4B;
			 T4A = T4y - T4z;
			 Rp[WS(rs, 3)] = T4t + T4A;
			 Rp[WS(rs, 7)] = T4A - T4t;
		    }
		    {
			 E T5k, T5m, T3o, T3j, T5b, T5c, T5l, T5d;
			 {
			      E T5g, T5j, T37, T3i;
			      T5g = T5e - T5f;
			      T5j = T5h - T5i;
			      T5k = FNMS(KP293892626, T5j, KP475528258 * T5g);
			      T5m = FMA(KP293892626, T5g, KP475528258 * T5j);
			      T3o = T3m + T3n;
			      T37 = T31 - T36;
			      T3i = T3c + T3h;
			      T3j = T37 - T3i;
			      T5b = FMA(KP500000000, T3o, KP125000000 * T3j);
			      T5c = KP279508497 * (T3i + T37);
			 }
			 Im[WS(rs, 9)] = KP500000000 * (T3j - T3o);
			 T5l = T5b - T5c;
			 Ip[WS(rs, 2)] = T5l + T5m;
			 Im[WS(rs, 1)] = T5m - T5l;
			 T5d = T5b + T5c;
			 Ip[WS(rs, 6)] = T5d + T5k;
			 Im[WS(rs, 5)] = T5k - T5d;
		    }
		    {
			 E T5w, T5x, T5n, T5q, T5r, T5s, T5y, T5t;
			 {
			      E T5u, T5v, T5o, T5p;
			      T5u = T36 + T31;
			      T5v = T3c - T3h;
			      T5w = FNMS(KP293892626, T5v, KP475528258 * T5u);
			      T5x = FMA(KP475528258, T5v, KP293892626 * T5u);
			      T5n = T50 - T51;
			      T5o = T5f + T5e;
			      T5p = T5h + T5i;
			      T5q = T5o + T5p;
			      T5r = FNMS(KP125000000, T5q, KP500000000 * T5n);
			      T5s = KP279508497 * (T5o - T5p);
			 }
			 Rm[WS(rs, 9)] = KP500000000 * (T5n + T5q);
			 T5y = T5s + T5r;
			 Rp[WS(rs, 6)] = T5x + T5y;
			 Rm[WS(rs, 5)] = T5y - T5x;
			 T5t = T5r - T5s;
			 Rp[WS(rs, 2)] = T5t - T5w;
			 Rm[WS(rs, 1)] = T5w + T5t;
		    }
		    {
			 E T4U, T4W, T3p, T3w, T4D, T4E, T4V, T4F;
			 {
			      E T4M, T4T, T3s, T3v;
			      T4M = T4I - T4L;
			      T4T = T4P - T4S;
			      T4U = FNMS(KP475528258, T4T, KP293892626 * T4M);
			      T4W = FMA(KP475528258, T4M, KP293892626 * T4T);
			      T3p = T3n - T3m;
			      T3s = T3q + T3r;
			      T3v = T3t + T3u;
			      T3w = T3s + T3v;
			      T4D = FNMS(KP125000000, T3w, KP500000000 * T3p);
			      T4E = KP279508497 * (T3s - T3v);
			 }
			 Ip[0] = KP500000000 * (T3p + T3w);
			 T4V = T4E + T4D;
			 Ip[WS(rs, 4)] = T4V + T4W;
			 Im[WS(rs, 3)] = T4W - T4V;
			 T4F = T4D - T4E;
			 Ip[WS(rs, 8)] = T4F + T4U;
			 Im[WS(rs, 7)] = T4U - T4F;
		    }
		    {
			 E T58, T59, T52, T53, T4Z, T54, T5a, T55;
			 {
			      E T56, T57, T4X, T4Y;
			      T56 = T3q - T3r;
			      T57 = T3t - T3u;
			      T58 = FMA(KP475528258, T56, KP293892626 * T57);
			      T59 = FNMS(KP293892626, T56, KP475528258 * T57);
			      T52 = T50 + T51;
			      T4X = T4I + T4L;
			      T4Y = T4P + T4S;
			      T53 = T4X + T4Y;
			      T4Z = KP279508497 * (T4X - T4Y);
			      T54 = FNMS(KP125000000, T53, KP500000000 * T52);
			 }
			 Rp[0] = KP500000000 * (T52 + T53);
			 T5a = T54 - T4Z;
			 Rp[WS(rs, 8)] = T59 + T5a;
			 Rm[WS(rs, 7)] = T5a - T59;
			 T55 = T4Z + T54;
			 Rp[WS(rs, 4)] = T55 - T58;
			 Rm[WS(rs, 3)] = T58 + T55;
		    }
	       }
	  }
     }
}

static const tw_instr twinstr[] = {
     { TW_CEXP, 1, 1 },
     { TW_CEXP, 1, 3 },
     { TW_CEXP, 1, 9 },
     { TW_CEXP, 1, 19 },
     { TW_NEXT, 1, 0 }
};

static const hc2c_desc desc = { 20, "hc2cfdft2_20", twinstr, &GENUS, { 244, 108, 72, 0 } };

void X(codelet_hc2cfdft2_20) (planner *p) {
     X(khc2c_register) (p, hc2cfdft2_20, &desc, HC2C_VIA_DFT);
}
#endif
