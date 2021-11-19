/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Nicholas_DCDC_Buck/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_sys_struct.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_a.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_externals.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Nicholas_DCDC_Buck_d41060f2_1_ds_a(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t32, NeDsMethodOutput *t33)
{
  PmRealVector out;
  real_T t0[24];
  real_T t6[4];
  real_T t8[4];
  real_T t18;
  size_t t16;
  (void)t32;
  out = t33->mA;
  t18 = 0.083333333333333329;
  t6[0ULL] = -9.9990000000000021E-12;
  t6[1ULL] = -0.00083325000000000011;
  t6[2ULL] = -1.0;
  t6[3ULL] = -1.0;
  t8[0ULL] = -1.0000000000000001E-11;
  t8[1ULL] = -0.00083333333333333339;
  t8[2ULL] = -1.0;
  t8[3ULL] = 1.0;
  t0[0ULL] = 0.00033333433333333334;
  t0[1ULL] = t18;
  t0[2ULL] = -1.0;
  t0[3ULL] = -0.0;
  t0[4ULL] = -1.0E-9;
  t0[5ULL] = -0.083333333333333329;
  t0[6ULL] = -0.0;
  t0[7ULL] = 1.0E-9;
  t0[8ULL] = t18;
  t0[9ULL] = -0.0;
  t0[10ULL] = -1.0001E-11;
  t0[11ULL] = -0.00083341666666666666;
  t0[12ULL] = -1.0;
  for (t16 = 0ULL; t16 < 4ULL; t16++) {
    t0[t16 + 13ULL] = t6[t16];
  }

  t0[17ULL] = -1.0100000000000001E-11;
  t0[18ULL] = -0.00084166666666666667;
  t0[19ULL] = -1.0;
  for (t16 = 0ULL; t16 < 4ULL; t16++) {
    t0[t16 + 20ULL] = t8[t16];
  }

  out.mX[0] = t0[0];
  out.mX[1] = t0[1];
  out.mX[2] = t0[2];
  out.mX[3] = t0[3];
  out.mX[4] = t0[4];
  out.mX[5] = t0[5];
  out.mX[6] = t0[6];
  out.mX[7] = t0[7];
  out.mX[8] = t0[8];
  out.mX[9] = t0[9];
  out.mX[10] = t0[10];
  out.mX[11] = t0[11];
  out.mX[12] = t0[12];
  out.mX[13] = t0[13];
  out.mX[14] = t0[14];
  out.mX[15] = t0[15];
  out.mX[16] = t0[16];
  out.mX[17] = t0[17];
  out.mX[18] = t0[18];
  out.mX[19] = t0[19];
  out.mX[20] = t0[20];
  out.mX[21] = t0[21];
  out.mX[22] = t0[22];
  out.mX[23] = t0[23];
  (void)sys;
  (void)t33;
  return 0;
}
