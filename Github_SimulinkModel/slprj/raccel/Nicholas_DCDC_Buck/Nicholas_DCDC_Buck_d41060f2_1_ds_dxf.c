/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Nicholas_DCDC_Buck/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_sys_struct.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_dxf.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_externals.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Nicholas_DCDC_Buck_d41060f2_1_ds_dxf(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t29, NeDsMethodOutput *t30)
{
  PmRealVector out;
  real_T t6[22];
  real_T t10[4];
  real_T t7[4];
  real_T t8[4];
  real_T t9[4];
  real_T X_idx_2;
  real_T X_idx_3;
  real_T X_idx_4;
  real_T X_idx_5;
  real_T intermediate_der83;
  real_T intermediate_der84;
  real_T intermediate_der88;
  real_T intrm_sf_mf_13;
  real_T t0;
  real_T t2;
  real_T t20;
  real_T t28;
  real_T zc_int2;
  size_t t15;
  int32_T M_idx_12;
  int32_T M_idx_13;
  int32_T M_idx_14;
  int32_T M_idx_15;
  int32_T M_idx_16;
  M_idx_12 = t29->mM.mX[12];
  M_idx_13 = t29->mM.mX[13];
  M_idx_14 = t29->mM.mX[14];
  M_idx_15 = t29->mM.mX[15];
  M_idx_16 = t29->mM.mX[16];
  X_idx_2 = t29->mX.mX[2];
  X_idx_3 = t29->mX.mX[3];
  X_idx_4 = t29->mX.mX[4];
  X_idx_5 = t29->mX.mX[5];
  out = t30->mDXF;
  t20 = X_idx_4 * 1.0E-6 + X_idx_2;
  t28 = (X_idx_5 * 1.0E-6 + X_idx_3) * 38.921701457926758;
  t0 = t20 * 38.921701457926758;
  intrm_sf_mf_13 = 1.0 - t20 / 15.448951451824009;
  if (M_idx_12 != 0) {
    t20 = (t28 - 39.0) * 2.3538526683701997E+17;
  } else if (M_idx_13 != 0) {
    t20 = (t28 + 40.0) * 1.1548224173015786E-17;
  } else {
    t20 = exp(t28);
  }

  if (M_idx_14 != 0) {
    zc_int2 = (t0 - 39.0) * 2.3538526683701997E+17;
  } else if (M_idx_15 != 0) {
    zc_int2 = (t0 + 40.0) * 1.1548224173015786E-17;
  } else {
    zc_int2 = exp(t0);
  }

  intermediate_der88 = 38.921701457926758;
  intermediate_der84 = 3.892170145792676E-5;
  t2 = 38.921701457926758;
  X_idx_2 = 3.892170145792676E-5;
  if (M_idx_12 != 0) {
    intermediate_der83 = intermediate_der84 * 2.3538526683701997E+17;
  } else if (M_idx_13 != 0) {
    intermediate_der83 = intermediate_der84 * 1.1548224173015786E-17;
  } else {
    intermediate_der83 = exp(t28) * intermediate_der84;
  }

  if (M_idx_12 != 0) {
    intermediate_der84 = intermediate_der88 * 2.3538526683701997E+17;
  } else if (M_idx_13 != 0) {
    intermediate_der84 = intermediate_der88 * 1.1548224173015786E-17;
  } else {
    intermediate_der84 = exp(t28) * intermediate_der88;
  }

  if (M_idx_14 != 0) {
    t28 = X_idx_2 * 2.3538526683701997E+17;
  } else if (M_idx_15 != 0) {
    t28 = X_idx_2 * 1.1548224173015786E-17;
  } else {
    t28 = exp(t0) * X_idx_2;
  }

  if (M_idx_14 != 0) {
    intermediate_der88 = t2 * 2.3538526683701997E+17;
  } else if (M_idx_15 != 0) {
    intermediate_der88 = t2 * 1.1548224173015786E-17;
  } else {
    intermediate_der88 = exp(t0) * t2;
  }

  if (M_idx_16 != 0) {
    t0 = 3.3333333343333336;
  } else {
    t0 = 1.1000000000000001E-8;
  }

  if (M_idx_16 != 0) {
    X_idx_2 = -3.3333333343333336;
  } else {
    X_idx_2 = -1.1000000000000001E-8;
  }

  if (M_idx_16 != 0) {
    t2 = 1.0333366666766675;
  } else {
    t2 = 1.0000000001100109;
  }

  if (M_idx_16 != 0) {
    X_idx_4 = 1.033330000009999;
  } else {
    X_idx_4 = 1.0000000001099889;
  }

  if (M_idx_16 != 0) {
    X_idx_3 = 1.0336666666767667;
  } else {
    X_idx_3 = 1.0000000001111;
  }

  if (M_idx_16 != 0) {
    X_idx_5 = 1.0333333333433334;
  } else {
    X_idx_5 = 1.00000000011;
  }

  t7[0ULL] = t0;
  t7[1ULL] = 0.0;
  t7[2ULL] = -(((-intermediate_der88 * intrm_sf_mf_13 + (t20 - zc_int2) *
                 -0.064729312090752486) - intermediate_der88) *
               1.9907674850572683E-11);
  t7[3ULL] = -(intermediate_der88 * 1.9907674850572683E-11);
  t8[0ULL] = X_idx_2;
  t8[1ULL] = 0.5;
  t8[2ULL] = -(intermediate_der84 * intrm_sf_mf_13 * 1.9907674850572683E-11);
  t8[3ULL] = -(intermediate_der84 * 2.5739080686533654E-13);
  t9[0ULL] = t2;
  t9[1ULL] = 1.5;
  t9[2ULL] = -(((-t28 * intrm_sf_mf_13 + (t20 - zc_int2) * -6.472931209075249E-8)
                - t28) * 1.9907674850572683E-11);
  t9[3ULL] = -(t28 * 1.9907674850572683E-11);
  t10[0ULL] = X_idx_4;
  t10[1ULL] = 1.5000005;
  t10[2ULL] = -(intermediate_der83 * intrm_sf_mf_13 * 1.9907674850572683E-11);
  t10[3ULL] = -(intermediate_der83 * 2.5739080686533654E-13);
  t6[0ULL] = -1.0E-9;
  t6[1ULL] = 1.0;
  for (t15 = 0ULL; t15 < 4ULL; t15++) {
    t6[t15 + 2ULL] = t7[t15];
  }

  for (t15 = 0ULL; t15 < 4ULL; t15++) {
    t6[t15 + 6ULL] = t8[t15];
  }

  for (t15 = 0ULL; t15 < 4ULL; t15++) {
    t6[t15 + 10ULL] = t9[t15];
  }

  for (t15 = 0ULL; t15 < 4ULL; t15++) {
    t6[t15 + 14ULL] = t10[t15];
  }

  out.mX[0] = t6[0];
  out.mX[1] = t6[1];
  out.mX[2] = t6[2];
  out.mX[3] = t6[3];
  out.mX[4] = t6[4];
  out.mX[5] = t6[5];
  out.mX[6] = t6[6];
  out.mX[7] = t6[7];
  out.mX[8] = t6[8];
  out.mX[9] = t6[9];
  out.mX[10] = t6[10];
  out.mX[11] = t6[11];
  out.mX[12] = t6[12];
  out.mX[13] = t6[13];
  out.mX[14] = t6[14];
  out.mX[15] = t6[15];
  out.mX[16] = t6[16];
  out.mX[17] = t6[17];
  out.mX[18] = X_idx_3;
  out.mX[19] = -4.99999999999997E-5;
  out.mX[20] = X_idx_5;
  out.mX[21] = 1.5;
  (void)sys;
  (void)t30;
  return 0;
}
