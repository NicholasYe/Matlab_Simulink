/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Nicholas_DCDC_Buck/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_sys_struct.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_f.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_externals.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Nicholas_DCDC_Buck_d41060f2_1_ds_f(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t4, NeDsMethodOutput *t5)
{
  PmRealVector out;
  real_T Diode_n_v;
  real_T Diode_v;
  real_T Gate_Driver_G_v;
  real_T Gate_Driver_i;
  real_T X_idx_0;
  real_T X_idx_1;
  real_T X_idx_2;
  real_T X_idx_3;
  real_T X_idx_4;
  real_T X_idx_5;
  real_T X_idx_6;
  real_T X_idx_7;
  real_T t1;
  int32_T M_idx_12;
  int32_T M_idx_13;
  int32_T M_idx_14;
  int32_T M_idx_15;
  int32_T M_idx_16;
  int32_T Q_idx_0;
  Q_idx_0 = t4->mQ.mX[0];
  M_idx_12 = t4->mM.mX[12];
  M_idx_13 = t4->mM.mX[13];
  M_idx_14 = t4->mM.mX[14];
  M_idx_15 = t4->mM.mX[15];
  M_idx_16 = t4->mM.mX[16];
  X_idx_0 = t4->mX.mX[0];
  X_idx_1 = t4->mX.mX[1];
  X_idx_2 = t4->mX.mX[2];
  X_idx_3 = t4->mX.mX[3];
  X_idx_4 = t4->mX.mX[4];
  X_idx_5 = t4->mX.mX[5];
  X_idx_6 = t4->mX.mX[6];
  X_idx_7 = t4->mX.mX[7];
  out = t5->mF;
  t1 = (((((((X_idx_0 * -1.0E-9 + X_idx_2 * 1.0E-9) + X_idx_3 * -1.0E-9) +
            X_idx_4 * 1.0000000000100009) + X_idx_5 * 1.0000000000099989) +
          X_idx_6 * 1.0000000000101) + X_idx_7 * 1.00000000001) + X_idx_1) +
    1.0000000000000001E-7;
  Diode_n_v = (((((-X_idx_3 + X_idx_4 * 0.010001) + X_idx_5 *
                  0.0099990000000000009) + X_idx_6 * 0.0101) + X_idx_7 * 0.01) +
               X_idx_2) + 100.0;
  Diode_v = (((((-X_idx_2 + X_idx_4 * -0.010001) + X_idx_5 *
                -0.0099990000000000009) + X_idx_6 * -0.0101) + X_idx_7 * -0.01)
             + X_idx_3) + -100.0;
  Gate_Driver_G_v = ((((X_idx_4 * 1.010001 + X_idx_5 * 1.01) + X_idx_6 * 0.01) +
                      X_idx_7 * 1.01) + X_idx_2) + 100.0;
  Gate_Driver_i = (-X_idx_4 + -X_idx_5) + -X_idx_7;
  X_idx_7 = X_idx_4 * 1.0E-6 + X_idx_2;
  X_idx_1 = (X_idx_5 * 1.0E-6 + X_idx_3) * 38.921701457926758;
  X_idx_0 = X_idx_7 * 38.921701457926758;
  X_idx_6 = 1.0 - X_idx_7 / 15.448951451824009;
  if (M_idx_12 != 0) {
    X_idx_7 = (X_idx_1 - 39.0) * 2.3538526683701997E+17;
  } else if (M_idx_13 != 0) {
    X_idx_7 = (X_idx_1 + 40.0) * 1.1548224173015786E-17;
  } else {
    X_idx_7 = exp(X_idx_1);
  }

  if (M_idx_14 != 0) {
    X_idx_1 = (X_idx_0 - 39.0) * 2.3538526683701997E+17;
  } else if (M_idx_15 != 0) {
    X_idx_1 = (X_idx_0 + 40.0) * 1.1548224173015786E-17;
  } else {
    X_idx_1 = exp(X_idx_0);
  }

  if (M_idx_16 != 0) {
    X_idx_0 = t1 - (Diode_v - 0.59999999819999994) / 0.3;
  } else {
    X_idx_0 = t1 - Diode_v * 1.0E-8;
  }

  if ((size_t)Q_idx_0 == 1ULL) {
    t1 = (Gate_Driver_G_v - Diode_n_v) - Gate_Driver_i * 2.0;
  } else if ((size_t)Q_idx_0 == 2ULL) {
    t1 = (Gate_Driver_G_v - Diode_n_v) - Gate_Driver_i * 2.0;
  } else if ((size_t)Q_idx_0 == 3ULL) {
    t1 = (Gate_Driver_G_v - Diode_n_v) - Gate_Driver_i * 2.0;
  } else if ((size_t)Q_idx_0 == 4ULL) {
    t1 = (Gate_Driver_G_v - Diode_n_v) - Gate_Driver_i * 2.0;
  } else {
    t1 = (Gate_Driver_G_v - Diode_n_v) - (Gate_Driver_i * 2.0 + 15.0);
  }

  out.mX[0] = -1.0000000000000001E-7;
  out.mX[1] = -8.3333333333333339;
  out.mX[2] = -0.0;
  out.mX[3] = -0.0;
  out.mX[4] = X_idx_0;
  out.mX[5] = t1 / 2.0;
  out.mX[6] = -(((X_idx_7 - X_idx_1) * X_idx_6 - X_idx_1) *
                1.9907674850572683E-11) + -1.9907674850572683E-11;
  out.mX[7] = -((X_idx_7 * 0.012929224974655049 + X_idx_1) *
                1.9907674850572683E-11) + 2.0165065657438021E-11;
  (void)sys;
  (void)t5;
  return 0;
}
