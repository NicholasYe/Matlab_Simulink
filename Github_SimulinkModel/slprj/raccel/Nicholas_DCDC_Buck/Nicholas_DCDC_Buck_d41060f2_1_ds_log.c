/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'Nicholas_DCDC_Buck/Solver Configuration'.
 */

#include "ne_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_sys_struct.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_log.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_externals.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_ds_external_struct.h"
#include "ssc_ml_fun.h"

int32_T Nicholas_DCDC_Buck_d41060f2_1_ds_log(const NeDynamicSystem *sys, const
  NeDynamicSystemInput *t7, NeDsMethodOutput *t8)
{
  PmRealVector out;
  real_T DC_Voltage_Source_i;
  real_T D_idx_0;
  real_T D_idx_1;
  real_T Diode_n_v;
  real_T Diode_v;
  real_T Gate_Driver_G_v;
  real_T Gate_Driver_i;
  real_T NPN_Bipolar_Transistor_base_resistor_n_v;
  real_T NPN_Bipolar_Transistor_capacitor_bc_n_v;
  real_T NPN_Bipolar_Transistor_capacitor_bc_v;
  real_T NPN_Bipolar_Transistor_capacitor_be_n_v;
  real_T NPN_Bipolar_Transistor_capacitor_be_v;
  real_T NPN_Bipolar_Transistor_transistor_ic;
  real_T NPN_Bipolar_Transistor_transistor_ie;
  real_T U_idx_0;
  real_T X_idx_0;
  real_T X_idx_1;
  real_T X_idx_2;
  real_T X_idx_3;
  real_T X_idx_4;
  real_T X_idx_5;
  real_T X_idx_6;
  real_T X_idx_7;
  real_T piece0;
  real_T t1;
  real_T t2;
  real_T t3;
  real_T t4;
  real_T zc_int3;
  int32_T M_idx_12;
  int32_T M_idx_13;
  int32_T M_idx_14;
  int32_T M_idx_15;
  int32_T Q_idx_0;
  Q_idx_0 = t7->mQ.mX[0];
  M_idx_12 = t7->mM.mX[12];
  M_idx_13 = t7->mM.mX[13];
  M_idx_14 = t7->mM.mX[14];
  M_idx_15 = t7->mM.mX[15];
  U_idx_0 = t7->mU.mX[0];
  X_idx_0 = t7->mX.mX[0];
  X_idx_1 = t7->mX.mX[1];
  X_idx_2 = t7->mX.mX[2];
  X_idx_3 = t7->mX.mX[3];
  X_idx_4 = t7->mX.mX[4];
  X_idx_5 = t7->mX.mX[5];
  X_idx_6 = t7->mX.mX[6];
  X_idx_7 = t7->mX.mX[7];
  D_idx_0 = t7->mD.mX[0];
  D_idx_1 = t7->mD.mX[1];
  out = t8->mLOG;
  DC_Voltage_Source_i = ((X_idx_4 + X_idx_5) + X_idx_6) + X_idx_7;
  Diode_n_v = (((((-X_idx_3 + X_idx_4 * 0.010001) + X_idx_5 *
                  0.0099990000000000009) + X_idx_6 * 0.0101) + X_idx_7 * 0.01) +
               X_idx_2) + 100.0;
  Diode_v = (((((-X_idx_2 + X_idx_4 * -0.010001) + X_idx_5 *
                -0.0099990000000000009) + X_idx_6 * -0.0101) + X_idx_7 * -0.01)
             + X_idx_3) + -100.0;
  Gate_Driver_G_v = ((((X_idx_4 * 1.010001 + X_idx_5 * 1.01) + X_idx_6 * 0.01) +
                      X_idx_7 * 1.01) + X_idx_2) + 100.0;
  Gate_Driver_i = (-X_idx_4 + -X_idx_5) + -X_idx_7;
  t1 = ((((((-X_idx_0 + -X_idx_3) + X_idx_4 * 0.010001) + X_idx_5 *
           0.0099990000000000009) + X_idx_6 * 0.0101) + X_idx_7 * 0.01) +
        X_idx_2) + 100.0;
  NPN_Bipolar_Transistor_base_resistor_n_v = ((((X_idx_4 * 0.010001 + X_idx_5 *
    0.01) + X_idx_6 * 0.01) + X_idx_7 * 0.01) + X_idx_2) + 100.0;
  NPN_Bipolar_Transistor_capacitor_bc_n_v = (((X_idx_4 * 0.01 + X_idx_5 * 0.01)
    + X_idx_6 * 0.01) + X_idx_7 * 0.01) + 100.0;
  NPN_Bipolar_Transistor_capacitor_bc_v = X_idx_4 * 1.0E-6 + X_idx_2;
  NPN_Bipolar_Transistor_capacitor_be_n_v = (((((-X_idx_3 + X_idx_4 * 0.010001)
    + X_idx_5 * 0.0099990000000000009) + X_idx_6 * 0.01) + X_idx_7 * 0.01) +
    X_idx_2) + 100.0;
  NPN_Bipolar_Transistor_capacitor_be_v = X_idx_5 * 1.0E-6 + X_idx_3;
  NPN_Bipolar_Transistor_transistor_ic = (-X_idx_5 + -X_idx_6) + -X_idx_7;
  NPN_Bipolar_Transistor_transistor_ie = X_idx_5 + X_idx_6;
  t2 = X_idx_0 * 0.00033333333333333332;
  t3 = Diode_n_v - X_idx_0;
  t4 = NPN_Bipolar_Transistor_capacitor_be_v * 38.921701457926758;
  zc_int3 = NPN_Bipolar_Transistor_capacitor_bc_v * 38.921701457926758;
  if (M_idx_12 != 0) {
    piece0 = (t4 - 39.0) * 2.3538526683701997E+17;
  } else if (M_idx_13 != 0) {
    piece0 = (t4 + 40.0) * 1.1548224173015786E-17;
  } else {
    piece0 = exp(t4);
  }

  t4 = -(-(piece0 * 1.9907674850572683E-11) + 1.9907674850572683E-11);
  if (M_idx_14 != 0) {
    piece0 = (zc_int3 - 39.0) * 2.3538526683701997E+17;
  } else if (M_idx_15 != 0) {
    piece0 = (zc_int3 + 40.0) * 1.1548224173015786E-17;
  } else {
    piece0 = exp(zc_int3);
  }

  out.mX[0] = 1.0000000000000001E-7 + (((((((X_idx_0 * -0.00033333433333333334 +
    X_idx_2 * 1.0E-9) + X_idx_3 * -1.0E-9) + X_idx_4 * 1.0001E-11) + X_idx_5 *
    9.9990000000000021E-12) + X_idx_6 * 1.0100000000000001E-11) + X_idx_7 *
    1.0000000000000001E-11) + X_idx_1);
  out.mX[1] = X_idx_0;
  out.mX[2] = X_idx_0;
  out.mX[3] = X_idx_0;
  out.mX[4] = 0.0;
  out.mX[5] = DC_Voltage_Source_i;
  out.mX[6] = 1.0000000000000001E-7 + (((((((X_idx_0 * -1.0E-9 + X_idx_2 *
    1.0E-9) + X_idx_3 * -1.0E-9) + X_idx_4 * 1.0000000000100009) + X_idx_5 *
    1.0000000000099989) + X_idx_6 * 1.0000000000101) + X_idx_7 * 1.00000000001)
    + X_idx_1);
  out.mX[7] = Diode_n_v;
  out.mX[8] = Diode_v;
  out.mX[9] = ((((((((X_idx_0 * -1.0E-9 + X_idx_2 * 1.0E-9) + X_idx_3 * -1.0E-9)
                    + X_idx_4 * 1.0000000000100009) + X_idx_5 *
                   1.0000000000099989) + X_idx_6 * 1.0000000000101) + X_idx_7 *
                 1.00000000001) + X_idx_1) + 1.0000000000000001E-7) * Diode_v;
  out.mX[10] = D_idx_0;
  out.mX[11] = D_idx_1;
  out.mX[12] = Gate_Driver_i * Gate_Driver_i * 0.002 * 1000.0;
  out.mX[13] = Gate_Driver_G_v;
  out.mX[14] = Diode_n_v;
  out.mX[15] = Gate_Driver_i;
  out.mX[16] = U_idx_0;
  out.mX[17] = (real_T)(size_t)Q_idx_0;
  out.mX[18] = 1.0000000000000001E-7 + (((((((X_idx_0 * -1.0E-9 + X_idx_2 *
    1.0E-9) + X_idx_3 * -1.0E-9) + X_idx_4 * 1.0001E-11) + X_idx_5 *
    9.9990000000000021E-12) + X_idx_6 * 1.0100000000000001E-11) + X_idx_7 *
    1.0000000000000001E-11) + X_idx_1);
  out.mX[19] = X_idx_0;
  out.mX[20] = Diode_n_v;
  out.mX[21] = t1;
  out.mX[22] = X_idx_1;
  out.mX[23] = t1 * t1 * 1.0000000000000002E-12;
  out.mX[24] = Gate_Driver_G_v;
  out.mX[25] = Diode_n_v;
  out.mX[26] = -Gate_Driver_i;
  out.mX[27] = NPN_Bipolar_Transistor_base_resistor_n_v;
  out.mX[28] = Gate_Driver_G_v;
  out.mX[29] = -Gate_Driver_i;
  out.mX[30] = Gate_Driver_i * Gate_Driver_i;
  out.mX[31] = X_idx_4;
  out.mX[32] = NPN_Bipolar_Transistor_capacitor_bc_n_v;
  out.mX[33] = NPN_Bipolar_Transistor_base_resistor_n_v;
  out.mX[34] = NPN_Bipolar_Transistor_capacitor_bc_v;
  out.mX[35] = X_idx_2;
  out.mX[36] = X_idx_4 * X_idx_4 * 1.0E-9;
  out.mX[37] = X_idx_5;
  out.mX[38] = NPN_Bipolar_Transistor_capacitor_be_n_v;
  out.mX[39] = NPN_Bipolar_Transistor_base_resistor_n_v;
  out.mX[40] = NPN_Bipolar_Transistor_capacitor_be_v;
  out.mX[41] = X_idx_3;
  out.mX[42] = X_idx_5 * X_idx_5 * 1.0E-9;
  out.mX[43] = -DC_Voltage_Source_i;
  out.mX[44] = NPN_Bipolar_Transistor_capacitor_bc_n_v;
  out.mX[45] = DC_Voltage_Source_i * -0.01;
  out.mX[46] = DC_Voltage_Source_i * DC_Voltage_Source_i * 0.01;
  out.mX[47] = X_idx_6;
  out.mX[48] = NPN_Bipolar_Transistor_capacitor_be_n_v;
  out.mX[49] = Diode_n_v;
  out.mX[50] = X_idx_6 * 0.0001;
  out.mX[51] = X_idx_6 * X_idx_6 * 0.0001;
  out.mX[52] = NPN_Bipolar_Transistor_base_resistor_n_v;
  out.mX[53] = t4;
  out.mX[54] = -(-(piece0 * 1.9907674850572683E-11) + 1.9907674850572683E-11);
  out.mX[55] = X_idx_7;
  out.mX[56] = NPN_Bipolar_Transistor_transistor_ic;
  out.mX[57] = NPN_Bipolar_Transistor_transistor_ie;
  out.mX[58] = NPN_Bipolar_Transistor_capacitor_be_n_v;
  out.mX[59] = NPN_Bipolar_Transistor_capacitor_bc_n_v;
  out.mX[60] = (-NPN_Bipolar_Transistor_capacitor_be_v *
                NPN_Bipolar_Transistor_transistor_ie -
                NPN_Bipolar_Transistor_capacitor_bc_v *
                NPN_Bipolar_Transistor_transistor_ic) * 0.001 * 1000.0;
  out.mX[61] = NPN_Bipolar_Transistor_capacitor_bc_v;
  out.mX[62] = NPN_Bipolar_Transistor_capacitor_be_v;
  out.mX[63] = t2;
  out.mX[64] = X_idx_0;
  out.mX[65] = t2 * 3000.0;
  out.mX[66] = t2 * t2 * 3.0;
  out.mX[67] = U_idx_0;
  out.mX[68] = X_idx_0;
  out.mX[69] = X_idx_0;
  out.mX[70] = t3;
  out.mX[71] = X_idx_0;
  out.mX[72] = Diode_n_v;
  out.mX[73] = t3;
  out.mX[74] = X_idx_0;
  (void)sys;
  (void)t8;
  return 0;
}
