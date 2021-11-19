/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Nicholas_DCDC_Buck/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_sys_struct.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_mode.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_externals.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Nicholas_DCDC_Buck_d41060f2_1_ds_mode(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmIntVector out;
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
  int32_T Q_idx_0;
  Q_idx_0 = t1->mQ.mX[0];
  T_idx_0 = t1->mT.mX[0];
  U_idx_0 = t1->mU.mX[0];
  X_idx_2 = t1->mX.mX[2];
  X_idx_3 = t1->mX.mX[3];
  X_idx_4 = t1->mX.mX[4];
  X_idx_5 = t1->mX.mX[5];
  X_idx_6 = t1->mX.mX[6];
  X_idx_7 = t1->mX.mX[7];
  D_idx_0 = t1->mD.mX[0];
  D_idx_1 = t1->mD.mX[1];
  out = t2->mMODE;
  intrm_sf_mf_11 = (X_idx_5 * 1.0E-6 + X_idx_3) * 38.921701457926758;
  intrm_sf_mf_12 = (X_idx_4 * 1.0E-6 + X_idx_2) * 38.921701457926758;
  out.mX[0] = (int32_T)(U_idx_0 > 0.7);
  out.mX[1] = (int32_T)(U_idx_0 < 0.3);
  out.mX[2] = (int32_T)((U_idx_0 >= 0.5) && ((size_t)Q_idx_0 == 1ULL));
  out.mX[3] = (int32_T)((U_idx_0 < 0.5) && ((size_t)Q_idx_0 == 1ULL));
  out.mX[4] = 0;
  out.mX[5] = 0;
  out.mX[6] = 0;
  out.mX[7] = 0;
  out.mX[8] = (int32_T)((T_idx_0 - D_idx_0 > 5.0000000000000004E-8) && ((size_t)
    Q_idx_0 == 6ULL));
  out.mX[9] = (int32_T)((U_idx_0 < 0.3) && ((size_t)Q_idx_0 == 5ULL));
  out.mX[10] = (int32_T)((T_idx_0 - D_idx_1 > 5.0000000000000004E-8) && ((size_t)
    Q_idx_0 == 3ULL));
  out.mX[11] = (int32_T)((U_idx_0 > 0.7) && ((size_t)Q_idx_0 == 2ULL));
  out.mX[12] = (int32_T)(intrm_sf_mf_11 > 40.0);
  out.mX[13] = (int32_T)(intrm_sf_mf_11 < -39.0);
  out.mX[14] = (int32_T)(intrm_sf_mf_12 > 40.0);
  out.mX[15] = (int32_T)(intrm_sf_mf_12 < -39.0);
  out.mX[16] = (int32_T)((((((-X_idx_2 + X_idx_4 * -0.010001) + X_idx_5 *
    -0.0099990000000000009) + X_idx_6 * -0.0101) + X_idx_7 * -0.01) + X_idx_3) +
    -100.0 > 0.6);
  (void)sys;
  (void)t2;
  return 0;
}
