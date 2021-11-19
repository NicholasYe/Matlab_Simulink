/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Nicholas_DCDC_Buck/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_sys_struct.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_update2_i.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_externals.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Nicholas_DCDC_Buck_d41060f2_1_ds_update2_i(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t4, NeDsMethodOutput *t5)
{
  PmIntVector out;
  real_T D_idx_0;
  real_T D_idx_1;
  real_T T_idx_0;
  real_T U_idx_0;
  size_t t0;
  int32_T CI_idx_10;
  int32_T CI_idx_11;
  int32_T CI_idx_13;
  int32_T CI_idx_14;
  int32_T CI_idx_15;
  int32_T CI_idx_16;
  int32_T Q_idx_0;
  int32_T Q_idx_1;
  boolean_T t1;
  Q_idx_0 = t4->mQ.mX[0];
  Q_idx_1 = t4->mQ.mX[1];
  T_idx_0 = t4->mT.mX[0];
  U_idx_0 = t4->mU.mX[0];
  D_idx_0 = t4->mD.mX[0];
  D_idx_1 = t4->mD.mX[1];
  CI_idx_10 = t4->mCI.mX[10];
  CI_idx_11 = t4->mCI.mX[11];
  CI_idx_13 = t4->mCI.mX[13];
  CI_idx_14 = t4->mCI.mX[14];
  CI_idx_15 = t4->mCI.mX[15];
  CI_idx_16 = t4->mCI.mX[16];
  out = t5->mUPDATE2_I;
  if ((CI_idx_16 == 0) && (U_idx_0 < 0.0) && ((size_t)Q_idx_0 == 1ULL)) {
    t0 = 2ULL;
  } else if ((CI_idx_15 == 0) && (U_idx_0 > 0.0) && ((size_t)Q_idx_0 == 1ULL)) {
    t0 = 5ULL;
  } else if ((CI_idx_14 == 0) && (U_idx_0 > 0.0) && ((size_t)Q_idx_0 == 2ULL)) {
    t0 = 3ULL;
  } else {
    if ((!(fabs(-D_idx_1) == pmf_get_inf())) && (!(-D_idx_1 != -D_idx_1))) {
      t1 = (T_idx_0 > 0.0);
    } else {
      t1 = false;
    }

    if ((CI_idx_13 == 0) && ((size_t)Q_idx_0 == 3ULL) && t1) {
      t0 = 5ULL;
    } else if ((CI_idx_11 == 0) && (U_idx_0 < 0.0) && ((size_t)Q_idx_0 == 5ULL))
    {
      t0 = 6ULL;
    } else {
      if ((!(fabs(-D_idx_0) == pmf_get_inf())) && (!(-D_idx_0 != -D_idx_0))) {
        t1 = (T_idx_0 > 0.0);
      } else {
        t1 = false;
      }

      if ((CI_idx_10 == 0) && ((size_t)Q_idx_0 == 6ULL) && t1) {
        t0 = 2ULL;
      } else {
        t0 = (size_t)Q_idx_0;
      }
    }
  }

  out.mX[0] = (int32_T)t0;
  out.mX[1] = (int32_T)(Q_idx_1 != 0);
  (void)sys;
  (void)t5;
  return 0;
}
