/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Nicholas_DCDC_Buck/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_sys_struct.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_qx_p.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_externals.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Nicholas_DCDC_Buck_d41060f2_1_ds_qx_p(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmSparsityPattern out;
  (void)t1;
  out = t2->mQX_P;
  out.mNumCol = 8ULL;
  out.mNumRow = 8ULL;
  out.mJc[0] = 0;
  out.mJc[1] = 8;
  out.mJc[2] = 16;
  out.mJc[3] = 24;
  out.mJc[4] = 32;
  out.mJc[5] = 40;
  out.mJc[6] = 48;
  out.mJc[7] = 56;
  out.mJc[8] = 64;
  out.mIr[0] = 0;
  out.mIr[1] = 1;
  out.mIr[2] = 2;
  out.mIr[3] = 3;
  out.mIr[4] = 4;
  out.mIr[5] = 5;
  out.mIr[6] = 6;
  out.mIr[7] = 7;
  out.mIr[8] = 0;
  out.mIr[9] = 1;
  out.mIr[10] = 2;
  out.mIr[11] = 3;
  out.mIr[12] = 4;
  out.mIr[13] = 5;
  out.mIr[14] = 6;
  out.mIr[15] = 7;
  out.mIr[16] = 0;
  out.mIr[17] = 1;
  out.mIr[18] = 2;
  out.mIr[19] = 3;
  out.mIr[20] = 4;
  out.mIr[21] = 5;
  out.mIr[22] = 6;
  out.mIr[23] = 7;
  out.mIr[24] = 0;
  out.mIr[25] = 1;
  out.mIr[26] = 2;
  out.mIr[27] = 3;
  out.mIr[28] = 4;
  out.mIr[29] = 5;
  out.mIr[30] = 6;
  out.mIr[31] = 7;
  out.mIr[32] = 0;
  out.mIr[33] = 1;
  out.mIr[34] = 2;
  out.mIr[35] = 3;
  out.mIr[36] = 4;
  out.mIr[37] = 5;
  out.mIr[38] = 6;
  out.mIr[39] = 7;
  out.mIr[40] = 0;
  out.mIr[41] = 1;
  out.mIr[42] = 2;
  out.mIr[43] = 3;
  out.mIr[44] = 4;
  out.mIr[45] = 5;
  out.mIr[46] = 6;
  out.mIr[47] = 7;
  out.mIr[48] = 0;
  out.mIr[49] = 1;
  out.mIr[50] = 2;
  out.mIr[51] = 3;
  out.mIr[52] = 4;
  out.mIr[53] = 5;
  out.mIr[54] = 6;
  out.mIr[55] = 7;
  out.mIr[56] = 0;
  out.mIr[57] = 1;
  out.mIr[58] = 2;
  out.mIr[59] = 3;
  out.mIr[60] = 4;
  out.mIr[61] = 5;
  out.mIr[62] = 6;
  out.mIr[63] = 7;
  (void)sys;
  (void)t2;
  return 0;
}
