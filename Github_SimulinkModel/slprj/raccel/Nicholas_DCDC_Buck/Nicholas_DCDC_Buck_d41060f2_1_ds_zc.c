/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Nicholas_DCDC_Buck/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_sys_struct.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_zc.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_externals.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Nicholas_DCDC_Buck_d41060f2_1_ds_zc(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t3, NeDsMethodOutput *t4)
{
  PmRealVector out;
  real_T D_idx_0;
  real_T D_idx_1;
  real_T T_idx_0;
  real_T U_idx_0;
  real_T X_idx_2;
  real_T X_idx_3;
  real_T X_idx_4;
  real_T X_idx_5;
  real_T X_idx_6;
  real_T X_idx_7;
  real_T intrm_sf_mf_11;
  real_T intrm_sf_mf_12;
  real_T t0;
  real_T t1;
  int32_T M_idx_12;
  int32_T M_idx_14;
  int32_T Q_idx_0;
  Q_idx_0 = t3->mQ.mX[0];
  M_idx_12 = t3->mM.mX[12];
  M_idx_14 = t3->mM.mX[14];
  T_idx_0 = t3->mT.mX[0];
  U_idx_0 = t3->mU.mX[0];
  X_idx_2 = t3->mX.mX[2];
  X_idx_3 = t3->mX.mX[3];
  X_idx_4 = t3->mX.mX[4];
  X_idx_5 = t3->mX.mX[5];
  X_idx_6 = t3->mX.mX[6];
  X_idx_7 = t3->mX.mX[7];
  D_idx_0 = t3->mD.mX[0];
  D_idx_1 = t3->mD.mX[1];
  out = t4->mZC;
  intrm_sf_mf_11 = (X_idx_5 * 1.0E-6 + X_idx_3) * 38.921701457926758;
  intrm_sf_mf_12 = (X_idx_4 * 1.0E-6 + X_idx_2) * 38.921701457926758;
  if (M_idx_12 == 0) {
    t0 = -39.0 - intrm_sf_mf_11;
  } else {
    t0 = 0.0;
  }

  if (M_idx_14 == 0) {
    t1 = -39.0 - intrm_sf_mf_12;
  } else {
    t1 = 0.0;
  }

  out.mX[0] = (real_T)((U_idx_0 < 0.5) && ((size_t)Q_idx_0 == 1ULL));
  out.mX[1] = (real_T)((U_idx_0 >= 0.5) && ((size_t)Q_idx_0 == 1ULL));
  out.mX[2] = (real_T)((U_idx_0 > 0.7) && ((size_t)Q_idx_0 == 2ULL));
  out.mX[3] = (real_T)((T_idx_0 - D_idx_1 > 5.0000000000000004E-8) && ((size_t)
    Q_idx_0 == 3ULL));
  out.mX[4] = (real_T)((U_idx_0 < 0.3) && ((size_t)Q_idx_0 == 5ULL));
  out.mX[5] = (real_T)((T_idx_0 - D_idx_0 > 5.0000000000000004E-8) && ((size_t)
    Q_idx_0 == 6ULL));
  out.mX[6] = 0.0;
  out.mX[7] = 0.0;
  out.mX[8] = 0.0;
  out.mX[9] = 0.0;
  out.mX[10] = U_idx_0 - 0.7;
  out.mX[11] = 0.3 - U_idx_0;
  out.mX[12] = ((((((-X_idx_2 + X_idx_4 * -0.010001) + X_idx_5 *
                    -0.0099990000000000009) + X_idx_6 * -0.0101) + X_idx_7 *
                  -0.01) + X_idx_3) + -100.0) - 0.6;
  out.mX[13] = intrm_sf_mf_11 - 40.0;
  out.mX[14] = t0;
  out.mX[15] = intrm_sf_mf_12 - 40.0;
  out.mX[16] = t1;
  (void)sys;
  (void)t4;
  return 0;
}
