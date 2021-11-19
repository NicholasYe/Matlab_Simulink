/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Nicholas_DCDC_Buck/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_sys_struct.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_lock2_i.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_externals.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Nicholas_DCDC_Buck_d41060f2_1_ds_lock2_i(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t3, NeDsMethodOutput *t4)
{
  PmBoolVector out;
  real_T D_idx_0;
  real_T D_idx_1;
  real_T T_idx_0;
  real_T U_idx_0;
  int32_T CI_idx_10;
  int32_T CI_idx_11;
  int32_T CI_idx_13;
  int32_T CI_idx_14;
  int32_T CI_idx_15;
  int32_T CI_idx_16;
  int32_T Q_idx_0;
  boolean_T t0;
  Q_idx_0 = t3->mQ.mX[0];
  T_idx_0 = t3->mT.mX[0];
  U_idx_0 = t3->mU.mX[0];
  D_idx_0 = t3->mD.mX[0];
  D_idx_1 = t3->mD.mX[1];
  CI_idx_10 = t3->mCI.mX[10];
  CI_idx_11 = t3->mCI.mX[11];
  CI_idx_13 = t3->mCI.mX[13];
  CI_idx_14 = t3->mCI.mX[14];
  CI_idx_15 = t3->mCI.mX[15];
  CI_idx_16 = t3->mCI.mX[16];
  out = t4->mLOCK2_I;
  if ((CI_idx_16 == 0) && (U_idx_0 < 0.0) && ((size_t)Q_idx_0 == 1ULL)) {
    t0 = true;
  } else if ((CI_idx_15 == 0) && (U_idx_0 > 0.0) && ((size_t)Q_idx_0 == 1ULL)) {
    t0 = true;
  } else if ((CI_idx_14 == 0) && (U_idx_0 > 0.0) && ((size_t)Q_idx_0 == 2ULL)) {
    t0 = true;
  } else {
    if ((!(fabs(-D_idx_1) == pmf_get_inf())) && (!(-D_idx_1 != -D_idx_1))) {
      t0 = (T_idx_0 > 0.0);
    } else {
      t0 = false;
    }

    if ((CI_idx_13 == 0) && ((size_t)Q_idx_0 == 3ULL) && t0) {
      t0 = true;
    } else if ((CI_idx_11 == 0) && (U_idx_0 < 0.0) && ((size_t)Q_idx_0 == 5ULL))
    {
      t0 = true;
    } else {
      if ((!(fabs(-D_idx_0) == pmf_get_inf())) && (!(-D_idx_0 != -D_idx_0))) {
        t0 = (T_idx_0 > 0.0);
      } else {
        t0 = false;
      }

      t0 = ((CI_idx_10 == 0) && ((size_t)Q_idx_0 == 6ULL) && t0);
    }
  }

  out.mX[0] = t0;
  out.mX[1] = false;
  (void)sys;
  (void)t4;
  return 0;
}
