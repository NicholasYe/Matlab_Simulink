/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Nicholas_DCDC_Buck/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_sys_struct.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_qx.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_externals.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Nicholas_DCDC_Buck_d41060f2_1_ds_qx(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t1, NeDsMethodOutput *t2)
{
  PmRealVector out;
  (void)t1;
  out = t2->mQX;
  out.mX[0] = 2.2222288889188888E-7;
  out.mX[1] = -0.00033333633333333337;
  out.mX[2] = -3.3333633333333341E-13;
  out.mX[3] = 3.3333633333333341E-13;
  out.mX[4] = -1.0000033336966695E-9;
  out.mX[5] = -1.0000033330299969E-9;
  out.mX[6] = -1.0000033666969667E-9;
  out.mX[7] = -1.0000033333633333E-9;
  out.mX[8] = -0.00033333633333333337;
  out.mX[9] = 3.0;
  out.mX[10] = 3.0000000000000004E-9;
  out.mX[11] = -3.0000000000000004E-9;
  out.mX[12] = 1.0000000000300027;
  out.mX[13] = 1.0000000000299967;
  out.mX[14] = 1.0000000000302998;
  out.mX[15] = 1.00000000003;
  out.mX[16] = -3.3333633333333341E-13;
  out.mX[17] = 3.0000000000000004E-9;
  out.mX[18] = 3.0000000000000002E-18;
  out.mX[19] = -3.0000000000000002E-18;
  out.mX[20] = 1.0000000000300029E-9;
  out.mX[21] = 1.0000000000299969E-9;
  out.mX[22] = 1.0000000000303E-9;
  out.mX[23] = 1.00000000003E-9;
  out.mX[24] = 3.3333633333333341E-13;
  out.mX[25] = -3.0000000000000004E-9;
  out.mX[26] = -3.0000000000000002E-18;
  out.mX[27] = 3.0000000000000002E-18;
  out.mX[28] = -1.0000000000300029E-9;
  out.mX[29] = -1.0000000000299969E-9;
  out.mX[30] = -1.0000000000303E-9;
  out.mX[31] = -1.00000000003E-9;
  out.mX[32] = -1.0000033336966695E-9;
  out.mX[33] = 1.0000000000300027;
  out.mX[34] = 1.0000000000300029E-9;
  out.mX[35] = -1.0000000000300029E-9;
  out.mX[36] = 6.0000000000200018;
  out.mX[37] = 5.00000000002;
  out.mX[38] = 3.0000000000201008;
  out.mX[39] = 5.0000000000200009;
  out.mX[40] = -1.0000033330299969E-9;
  out.mX[41] = 1.0000000000299967;
  out.mX[42] = 1.0000000000299969E-9;
  out.mX[43] = -1.0000000000299969E-9;
  out.mX[44] = 5.00000000002;
  out.mX[45] = 8.0000000000199982;
  out.mX[46] = 5.0000000000200986;
  out.mX[47] = 6.0000000000199991;
  out.mX[48] = -1.0000033666969667E-9;
  out.mX[49] = 1.0000000000302998;
  out.mX[50] = 1.0000000000303E-9;
  out.mX[51] = -1.0000000000303E-9;
  out.mX[52] = 3.0000000000201008;
  out.mX[53] = 5.0000000000200986;
  out.mX[54] = 6.0000000000202;
  out.mX[55] = 4.0000000000200995;
  out.mX[56] = -1.0000033333633333E-9;
  out.mX[57] = 1.00000000003;
  out.mX[58] = 1.00000000003E-9;
  out.mX[59] = -1.00000000003E-9;
  out.mX[60] = 5.0000000000200009;
  out.mX[61] = 6.0000000000199991;
  out.mX[62] = 4.0000000000200995;
  out.mX[63] = 7.00000000002;
  (void)sys;
  (void)t2;
  return 0;
}
