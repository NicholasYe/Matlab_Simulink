#ifndef RTW_HEADER_Nicholas_DCDC_Buck_h_
#define RTW_HEADER_Nicholas_DCDC_Buck_h_
#include <string.h>
#include <stddef.h>
#include <float.h>
#include "rtw_modelmap_simtarget.h"
#ifndef Nicholas_DCDC_Buck_COMMON_INCLUDES_
#define Nicholas_DCDC_Buck_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#include "nesl_rtw.h"
#include "Nicholas_DCDC_Buck_d41060f2_1_gateway.h"
#endif
#include "Nicholas_DCDC_Buck_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME Nicholas_DCDC_Buck
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (4) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (8)   
#elif NCSTATES != 8
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T lrjd2s3wzf ; real_T ms13at0w2f [ 4 ] ; real_T
pgyquly34j [ 29 ] ; real_T aoib3gdygq [ 2 ] ; } B ; typedef struct { real_T
lzqjz5xkfi [ 2 ] ; real_T bxat0p1hh2 [ 28 ] ; real_T iygbt3dhiw ; real_T
h1luq02p0d ; int64_T ojrdgltdr5 ; void * dh43lcbaln ; void * n1pn1b4isz ;
void * i5puujzelw ; void * eisx51xo2k ; void * dgvokso3o0 ; void * icaypvch4x
; void * p5jryn5z3x ; void * o5o0pcluu0 ; void * brbcz5yufv ; void *
comnpykqro ; struct { void * LoggedData [ 2 ] ; } bufzmc1x0i ; int32_T
kin5u534sr ; int32_T ndxegwkwlx ; int_T g34sz5deau [ 17 ] ; int_T iwxuojrfte
; int32_T bq10vwdwoo ; boolean_T gqkx053ven ; boolean_T nhswjatgiz ; } DW ;
typedef struct { real_T fqg3sarkwh [ 8 ] ; } X ; typedef struct { real_T
fqg3sarkwh [ 8 ] ; } XDot ; typedef struct { boolean_T fqg3sarkwh [ 8 ] ; }
XDis ; typedef struct { real_T fqg3sarkwh [ 8 ] ; } CStateAbsTol ; typedef
struct { real_T fqg3sarkwh [ 8 ] ; } CXPtMin ; typedef struct { real_T
fqg3sarkwh [ 8 ] ; } CXPtMax ; typedef struct { real_T kwvhbenamf ; real_T
mo5vrxnw42 ; real_T jdkjztgx2g ; real_T au25viknlx ; real_T egqz4nos2i ;
real_T f3wn5ir1ub ; real_T mpk4tf2clz ; real_T lsogxnw2yi ; real_T gvqkdxr2e5
; real_T po1rllkqxn ; real_T iguqnlnrh2 ; real_T n02ynxafc2 ; real_T
lou3s22ntz ; real_T dqlcmxazti ; real_T fm0nxepmdu ; real_T ccmct5vtjm ;
real_T eqge4fsvul ; } ZCV ; typedef struct { int_T ir [ 6 ] ; int_T jc [ 9 ]
; real_T pr [ 6 ] ; } MassMatrix ; typedef struct { rtwCAPI_ModelMappingInfo
mmi ; } DataMapInfo ; struct P_ { real_T PulseGenerator_Amp ; real_T
PulseGenerator_Period ; real_T PulseGenerator_Duty ; real_T
PulseGenerator_PhaseDelay ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern MassMatrix rtMassMatrix ; extern P rtP ; extern mxArray *
mr_Nicholas_DCDC_Buck_GetDWork ( ) ; extern void
mr_Nicholas_DCDC_Buck_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_Nicholas_DCDC_Buck_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * Nicholas_DCDC_Buck_GetCAPIStaticMap ( void )
; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
