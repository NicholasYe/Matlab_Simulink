/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Nicholas_DCDC_Buck/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_sys_struct.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_update_i.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_externals.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Nicholas_DCDC_Buck_d41060f2_1_ds_update_i(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t2, NeDsMethodOutput *t3)
{
  PmIntVector out;
  real_T D_idx_0;
  real_T D_idx_1;
  real_T T_idx_0;
  real_T U_idx_0;
  size_t t0;
  int32_T CI_idx_2;
  int32_T CI_idx_20;
  int32_T CI_idx_21;
  int32_T CI_idx_22;
  int32_T CI_idx_23;
  int32_T CI_idx_3;
  int32_T Q_idx_0;
  int32_T Q_idx_1;
  Q_idx_0 = t2->mQ.mX[0];
  Q_idx_1 = t2->mQ.mX[1];
  T_idx_0 = t2->mT.mX[0];
  U_idx_0 = t2->mU.mX[0];
  D_idx_0 = t2->mD.mX[0];
  D_idx_1 = t2->mD.mX[1];
  CI_idx_2 = t2->mCI.mX[2];
  CI_idx_3 = t2->mCI.mX[3];
  CI_idx_20 = t2->mCI.mX[20];
  CI_idx_21 = t2->mCI.mX[21];
  CI_idx_22 = t2->mCI.mX[22];
  CI_idx_23 = t2->mCI.mX[23];
  out = t3->mUPDATE_I;
  if (((CI_idx_3 == 0) && (U_idx_0 < 0.5) && ((size_t)Q_idx_0 == 1ULL)) ||
      ((U_idx_0 < 0.5) && ((size_t)Q_idx_0 == 1ULL) && (Q_idx_1 != 0))) {
    t0 = 2ULL;
  } else if (((CI_idx_2 == 0) && (U_idx_0 >= 0.5) && ((size_t)Q_idx_0 == 1ULL)) ||
             ((U_idx_0 >= 0.5) && ((size_t)Q_idx_0 == 1ULL) && (Q_idx_1 != 0)))
  {
    t0 = 5ULL;
  } else if (((CI_idx_23 == 0) && (U_idx_0 > 0.7) && ((size_t)Q_idx_0 == 2ULL)) ||
             ((U_idx_0 > 0.7) && ((size_t)Q_idx_0 == 2ULL) && (Q_idx_1 != 0))) {
    t0 = 3ULL;
  } else if (((CI_idx_22 == 0) && (T_idx_0 - D_idx_1 > 5.0000000000000004E-8) &&
              ((size_t)Q_idx_0 == 3ULL)) || ((T_idx_0 - D_idx_1 >
               5.0000000000000004E-8) && ((size_t)Q_idx_0 == 3ULL) && (Q_idx_1
               != 0))) {
    t0 = 5ULL;
  } else if (((CI_idx_21 == 0) && (U_idx_0 < 0.3) && ((size_t)Q_idx_0 == 5ULL)) ||
             ((U_idx_0 < 0.3) && ((size_t)Q_idx_0 == 5ULL) && (Q_idx_1 != 0))) {
    t0 = 6ULL;
  } else if (((CI_idx_20 == 0) && (T_idx_0 - D_idx_0 > 5.0000000000000004E-8) &&
              ((size_t)Q_idx_0 == 6ULL)) || ((T_idx_0 - D_idx_0 >
               5.0000000000000004E-8) && ((size_t)Q_idx_0 == 6ULL) && (Q_idx_1
               != 0))) {
    t0 = 2ULL;
  } else {
    t0 = (size_t)Q_idx_0;
  }

  out.mX[0] = (int32_T)t0;
  out.mX[1] = 0;
  (void)sys;
  (void)t3;
  return 0;
}
