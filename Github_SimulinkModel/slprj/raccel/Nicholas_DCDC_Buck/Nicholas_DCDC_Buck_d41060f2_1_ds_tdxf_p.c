/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Nicholas_DCDC_Buck/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_sys_struct.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_tdxf_p.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_externals.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Nicholas_DCDC_Buck_d41060f2_1_ds_tdxf_p(const NeDynamicSystem *sys,
  const NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mTDXF_P;
  out.mNumCol = 8ULL;
  out.mNumRow = 8ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 3;
  out.mJc[2] = 6;
  out.mJc[3] = 13;
  out.mJc[4] = 20;
  out.mJc[5] = 27;
  out.mJc[6] = 34;
  out.mJc[7] = 39;
  out.mJc[8] = 45;
  out.mIr[0] = 0;
  out.mIr[1] = 1;
  out.mIr[2] = 4;
  out.mIr[3] = 0;
  out.mIr[4] = 1;
  out.mIr[5] = 4;
  out.mIr[6] = 0;
  out.mIr[7] = 1;
  out.mIr[8] = 2;
  out.mIr[9] = 4;
  out.mIr[10] = 5;
  out.mIr[11] = 6;
  out.mIr[12] = 7;
  out.mIr[13] = 0;
  out.mIr[14] = 1;
  out.mIr[15] = 3;
  out.mIr[16] = 4;
  out.mIr[17] = 5;
  out.mIr[18] = 6;
  out.mIr[19] = 7;
  out.mIr[20] = 0;
  out.mIr[21] = 1;
  out.mIr[22] = 2;
  out.mIr[23] = 4;
  out.mIr[24] = 5;
  out.mIr[25] = 6;
  out.mIr[26] = 7;
  out.mIr[27] = 0;
  out.mIr[28] = 1;
  out.mIr[29] = 3;
  out.mIr[30] = 4;
  out.mIr[31] = 5;
  out.mIr[32] = 6;
  out.mIr[33] = 7;
  out.mIr[34] = 0;
  out.mIr[35] = 1;
  out.mIr[36] = 4;
  out.mIr[37] = 5;
  out.mIr[38] = 6;
  out.mIr[39] = 0;
  out.mIr[40] = 1;
  out.mIr[41] = 4;
  out.mIr[42] = 5;
  out.mIr[43] = 6;
  out.mIr[44] = 7;
  (void)sys;
  (void)t2;
  return 0;
}
