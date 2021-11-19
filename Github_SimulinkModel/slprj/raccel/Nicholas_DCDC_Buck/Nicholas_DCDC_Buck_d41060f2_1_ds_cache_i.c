/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Nicholas_DCDC_Buck/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_sys_struct.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_cache_i.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_externals.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Nicholas_DCDC_Buck_d41060f2_1_ds_cache_i(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmIntVector out;
  real_T D_idx_0;
  real_T D_idx_1;
  real_T T_idx_0;
  real_T U_idx_0;
  int32_T M_idx_0;
  int32_T M_idx_1;
  int32_T M_idx_10;
  int32_T M_idx_11;
  int32_T M_idx_2;
  int32_T M_idx_3;
  int32_T M_idx_4;
  int32_T M_idx_5;
  int32_T M_idx_6;
  int32_T M_idx_7;
  int32_T M_idx_8;
  int32_T M_idx_9;
  int32_T Q_idx_0;
  Q_idx_0 = t1->mQ.mX[0];
  M_idx_0 = t1->mM.mX[0];
  M_idx_1 = t1->mM.mX[1];
  M_idx_2 = t1->mM.mX[2];
  M_idx_3 = t1->mM.mX[3];
  M_idx_4 = t1->mM.mX[4];
  M_idx_5 = t1->mM.mX[5];
  M_idx_6 = t1->mM.mX[6];
  M_idx_7 = t1->mM.mX[7];
  M_idx_8 = t1->mM.mX[8];
  M_idx_9 = t1->mM.mX[9];
  M_idx_10 = t1->mM.mX[10];
  M_idx_11 = t1->mM.mX[11];
  T_idx_0 = t1->mT.mX[0];
  U_idx_0 = t1->mU.mX[0];
  D_idx_0 = t1->mD.mX[0];
  D_idx_1 = t1->mD.mX[1];
  out = t2->mCACHE_I;
  out.mX[0] = (int32_T)(M_idx_0 != 0);
  out.mX[1] = (int32_T)(M_idx_1 != 0);
  out.mX[2] = (int32_T)(M_idx_2 != 0);
  out.mX[3] = (int32_T)(M_idx_3 != 0);
  out.mX[4] = (int32_T)(U_idx_0 > 0.7);
  out.mX[5] = (int32_T)(U_idx_0 < 0.3);
  out.mX[6] = 0;
  out.mX[7] = 0;
  out.mX[8] = 0;
  out.mX[9] = 0;
  out.mX[10] = (int32_T)((T_idx_0 - D_idx_0 > 5.0000000000000004E-8) && ((size_t)
    Q_idx_0 == 6ULL));
  out.mX[11] = (int32_T)((U_idx_0 < 0.3) && ((size_t)Q_idx_0 == 5ULL));
  out.mX[12] = (int32_T)(M_idx_4 != 0);
  out.mX[13] = (int32_T)((T_idx_0 - D_idx_1 > 5.0000000000000004E-8) && ((size_t)
    Q_idx_0 == 3ULL));
  out.mX[14] = (int32_T)((U_idx_0 > 0.7) && ((size_t)Q_idx_0 == 2ULL));
  out.mX[15] = (int32_T)((U_idx_0 >= 0.5) && ((size_t)Q_idx_0 == 1ULL));
  out.mX[16] = (int32_T)((U_idx_0 < 0.5) && ((size_t)Q_idx_0 == 1ULL));
  out.mX[17] = (int32_T)(M_idx_5 != 0);
  out.mX[18] = (int32_T)(M_idx_6 != 0);
  out.mX[19] = (int32_T)(M_idx_7 != 0);
  out.mX[20] = (int32_T)(M_idx_8 != 0);
  out.mX[21] = (int32_T)(M_idx_9 != 0);
  out.mX[22] = (int32_T)(M_idx_10 != 0);
  out.mX[23] = (int32_T)(M_idx_11 != 0);
  (void)sys;
  (void)t2;
  return 0;
}
