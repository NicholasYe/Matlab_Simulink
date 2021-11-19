#include "rt_logging_mmi.h"
#include "Nicholas_DCDC_Buck_capi.h"
#include <math.h>
#include "Nicholas_DCDC_Buck.h"
#include "Nicholas_DCDC_Buck_private.h"
#include "Nicholas_DCDC_Buck_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 3 , & stopRequested ) ; }
rtExtModeShutdown ( 3 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "9.6 (R2021b) 14-May-2021" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 } ; const char * raccelLoadInputsAndAperiodicHitTimes (
SimStruct * S , const char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; MassMatrix rtMassMatrix ; static SimStruct model_S
; SimStruct * const rtS = & model_S ; void MdlInitialize ( void ) { int_T
tmp_e ; int_T tmp_g ; int_T tmp_i ; int_T tmp_j ; int_T tmp_m ; int_T tmp_p ;
boolean_T tmp ; tmp = false ; if ( tmp ) { tmp_p = strcmp ( ssGetSolverName (
rtS ) , "daessc" ) ; tmp_e = strcmp ( ssGetSolverName ( rtS ) , "ode14x" ) ;
tmp_i = strcmp ( ssGetSolverName ( rtS ) , "ode15s" ) ; tmp_m = strcmp (
ssGetSolverName ( rtS ) , "ode1be" ) ; tmp_g = strcmp ( ssGetSolverName ( rtS
) , "ode23t" ) ; tmp_j = strcmp ( ssGetSolverName ( rtS ) , "odeN" ) ; if ( (
boolean_T ) ( ( tmp_p != 0 ) & ( tmp_e != 0 ) & ( tmp_i != 0 ) & ( tmp_m != 0
) & ( tmp_g != 0 ) & ( tmp_j != 0 ) ) ) { ssSetErrorStatus ( rtS ,
 "Detected inconsistent solvers in the model reference hierarchy. Model built with daessc requires one of {daessc, ode14x, ode15s, ode1be, ode23t, odeN} solvers to run. Use one of the required solvers in the top model."
) ; } } { static int_T modelMassMatrixIr [ 6 ] = { 0 , 1 , 2 , 5 , 3 , 5 } ;
static int_T modelMassMatrixJc [ 9 ] = { 0 , 1 , 2 , 4 , 6 , 6 , 6 , 6 , 6 }
; static real_T modelMassMatrixPr [ 6 ] = { 1.0 , 1.0 , 1.0 , 1.0 , 1.0 , 1.0
} ; ( void ) memcpy ( rtMassMatrix . ir , modelMassMatrixIr , 6 * sizeof (
int_T ) ) ; ( void ) memcpy ( rtMassMatrix . jc , modelMassMatrixJc , 9 *
sizeof ( int_T ) ) ; ( void ) memcpy ( rtMassMatrix . pr , modelMassMatrixPr
, 6 * sizeof ( real_T ) ) ; } } void MdlEnable ( void ) { rtDW . kin5u534sr =
1 ; _ssSetSampleHit ( rtS , 2 , 1 ) ; _ssSetTaskTime ( rtS , 2 , ssGetT ( rtS
) ) ; _ssSetVarNextHitTime ( rtS , 0 , ssGetT ( rtS ) ) ; ; } void MdlStart (
void ) { CXPtMax * _rtXPerturbMax ; CXPtMin * _rtXPerturbMin ;
NeModelParameters modelParameters ; NeModelParameters modelParameters_p ;
NeslSimulationData * simulationData ; NeslSimulator * tmp ;
NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree * diagnosticTree
; NeuDiagnosticTree * diagnosticTree_e ; NeuDiagnosticTree * diagnosticTree_p
; char * msg ; char * msg_e ; char * msg_p ; real_T tmp_m [ 4 ] ; real_T time
; real_T tmp_e ; int32_T tmp_i ; int_T tmp_g [ 2 ] ; boolean_T tmp_p ;
boolean_T val ; { bool externalInputIsInDatasetFormat = false ; void *
pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} _rtXPerturbMax = ( ( CXPtMax * ) ssGetJacobianPerturbationBoundsMaxVec (
rtS ) ) ; _rtXPerturbMin = ( ( CXPtMin * )
ssGetJacobianPerturbationBoundsMinVec ( rtS ) ) ; tmp = nesl_lease_simulator
( "Nicholas_DCDC_Buck/Solver Configuration_1" , 0 , 0 ) ; rtDW . dh43lcbaln =
( void * ) tmp ; tmp_p = pointer_is_null ( rtDW . dh43lcbaln ) ; if ( tmp_p )
{ Nicholas_DCDC_Buck_d41060f2_1_gateway ( ) ; tmp = nesl_lease_simulator (
"Nicholas_DCDC_Buck/Solver Configuration_1" , 0 , 0 ) ; rtDW . dh43lcbaln = (
void * ) tmp ; } slsaSaveRawMemoryForSimTargetOP ( rtS ,
"Nicholas_DCDC_Buck/Solver Configuration_100" , ( void * * ) ( & rtDW .
dh43lcbaln ) , 0U * sizeof ( real_T ) , nesl_save_simdata ,
nesl_restore_simdata ) ; simulationData = nesl_create_simulation_data ( ) ;
rtDW . n1pn1b4isz = ( void * ) simulationData ; diagnosticManager =
rtw_create_diagnostics ( ) ; rtDW . i5puujzelw = ( void * ) diagnosticManager
; modelParameters . mSolverType = NE_SOLVER_TYPE_DAE ; modelParameters .
mSolverTolerance = 0.001 ; modelParameters . mVariableStepSolver = true ;
modelParameters . mIsUsingODEN = false ; modelParameters . mFixedStepSize =
0.001 ; modelParameters . mStartTime = 0.0 ; modelParameters .
mLoadInitialState = false ; modelParameters . mUseSimState = false ;
modelParameters . mLinTrimCompile = false ; modelParameters . mLoggingMode =
SSC_LOGGING_NONE ; modelParameters . mRTWModifiedTimeStamp = 5.57875547E+8 ;
modelParameters . mZcDisabled = false ; tmp_e = 0.001 ; modelParameters .
mSolverTolerance = tmp_e ; tmp_e = 0.0 ; modelParameters . mFixedStepSize =
tmp_e ; tmp_p = true ; modelParameters . mVariableStepSolver = tmp_p ; tmp_p
= false ; modelParameters . mIsUsingODEN = tmp_p ; val = false ; tmp_p =
slIsRapidAcceleratorSimulating ( ) ; if ( tmp_p ) { tmp_p =
ssGetGlobalInitialStatesAvailable ( rtS ) ; val = ( tmp_p &&
ssIsFirstInitCond ( rtS ) ) ; } modelParameters . mLoadInitialState = val ;
modelParameters . mZcDisabled = false ; diagnosticManager = (
NeuDiagnosticManager * ) rtDW . i5puujzelw ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_i =
nesl_initialize_simulator ( ( NeslSimulator * ) rtDW . dh43lcbaln , &
modelParameters , diagnosticManager ) ; if ( tmp_i != 0 ) { tmp_p =
error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp_p ) { msg =
rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg ) ; } }
simulationData = ( NeslSimulationData * ) rtDW . n1pn1b4isz ; time = ssGetT (
rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 8 ;
simulationData -> mData -> mContStates . mX = & rtX . fqg3sarkwh [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 28 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . bxat0p1hh2 [ 0 ] ; simulationData -> mData ->
mModeVector . mN = 17 ; simulationData -> mData -> mModeVector . mX = & rtDW
. g34sz5deau [ 0 ] ; tmp_p = ( ssIsMajorTimeStep ( rtS ) &&
ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData -> mData
-> mFoundZcEvents = tmp_p ; simulationData -> mData -> mIsMajorTimeStep =
ssIsMajorTimeStep ( rtS ) ; tmp_p = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags .
solverAssertCheck == 1U ) ; simulationData -> mData -> mIsSolverAssertCheck =
tmp_p ; tmp_p = ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp_p ; tmp_p = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp_p ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
tmp_p = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp_p ; tmp_p = ssGetIsOkayToUpdateMode ( rtS ) ;
simulationData -> mData -> mIsOkayToUpdateMode = tmp_p ; tmp_g [ 0 ] = 0 ;
tmp_m [ 0 ] = rtB . ms13at0w2f [ 0 ] ; tmp_m [ 1 ] = rtB . ms13at0w2f [ 1 ] ;
tmp_m [ 2 ] = rtB . ms13at0w2f [ 2 ] ; tmp_m [ 3 ] = rtB . ms13at0w2f [ 3 ] ;
tmp_g [ 1 ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_m [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 2 ; simulationData -> mData -> mInputOffsets
. mX = & tmp_g [ 0 ] ; simulationData -> mData -> mNumjacDxLo . mN = 8 ;
simulationData -> mData -> mNumjacDxLo . mX = & _rtXPerturbMin -> fqg3sarkwh
[ 0 ] ; simulationData -> mData -> mNumjacDxHi . mN = 8 ; simulationData ->
mData -> mNumjacDxHi . mX = & _rtXPerturbMax -> fqg3sarkwh [ 0 ] ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . i5puujzelw ;
diagnosticTree_p = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW
. dh43lcbaln , NESL_SIM_NUMJAC_DX_BOUNDS , simulationData , diagnosticManager
) ; if ( tmp_i != 0 ) { tmp_p = error_buffer_is_empty ( ssGetErrorStatus (
rtS ) ) ; if ( tmp_p ) { msg_p = rtw_diagnostics_msg ( diagnosticTree_p ) ;
ssSetErrorStatus ( rtS , msg_p ) ; } } tmp = nesl_lease_simulator (
"Nicholas_DCDC_Buck/Solver Configuration_1" , 1 , 0 ) ; rtDW . icaypvch4x = (
void * ) tmp ; tmp_p = pointer_is_null ( rtDW . icaypvch4x ) ; if ( tmp_p ) {
Nicholas_DCDC_Buck_d41060f2_1_gateway ( ) ; tmp = nesl_lease_simulator (
"Nicholas_DCDC_Buck/Solver Configuration_1" , 1 , 0 ) ; rtDW . icaypvch4x = (
void * ) tmp ; } slsaSaveRawMemoryForSimTargetOP ( rtS ,
"Nicholas_DCDC_Buck/Solver Configuration_110" , ( void * * ) ( & rtDW .
icaypvch4x ) , 0U * sizeof ( real_T ) , nesl_save_simdata ,
nesl_restore_simdata ) ; simulationData = nesl_create_simulation_data ( ) ;
rtDW . p5jryn5z3x = ( void * ) simulationData ; diagnosticManager =
rtw_create_diagnostics ( ) ; rtDW . o5o0pcluu0 = ( void * ) diagnosticManager
; modelParameters_p . mSolverType = NE_SOLVER_TYPE_DAE ; modelParameters_p .
mSolverTolerance = 0.001 ; modelParameters_p . mVariableStepSolver = true ;
modelParameters_p . mIsUsingODEN = false ; modelParameters_p . mFixedStepSize
= 0.001 ; modelParameters_p . mStartTime = 0.0 ; modelParameters_p .
mLoadInitialState = false ; modelParameters_p . mUseSimState = false ;
modelParameters_p . mLinTrimCompile = false ; modelParameters_p .
mLoggingMode = SSC_LOGGING_NONE ; modelParameters_p . mRTWModifiedTimeStamp =
5.57875547E+8 ; modelParameters_p . mZcDisabled = false ; tmp_e = 0.001 ;
modelParameters_p . mSolverTolerance = tmp_e ; tmp_e = 0.0 ;
modelParameters_p . mFixedStepSize = tmp_e ; tmp_p = true ; modelParameters_p
. mVariableStepSolver = tmp_p ; tmp_p = false ; modelParameters_p .
mIsUsingODEN = tmp_p ; val = false ; tmp_p = slIsRapidAcceleratorSimulating (
) ; if ( tmp_p ) { tmp_p = ssGetGlobalInitialStatesAvailable ( rtS ) ; val =
( tmp_p && ssIsFirstInitCond ( rtS ) ) ; } modelParameters_p .
mLoadInitialState = val ; modelParameters_p . mZcDisabled = false ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . o5o0pcluu0 ;
diagnosticTree_e = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = nesl_initialize_simulator ( ( NeslSimulator * )
rtDW . icaypvch4x , & modelParameters_p , diagnosticManager ) ; if ( tmp_i !=
0 ) { tmp_p = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp_p
) { msg_e = rtw_diagnostics_msg ( diagnosticTree_e ) ; ssSetErrorStatus ( rtS
, msg_e ) ; } } MdlInitialize ( ) ; MdlEnable ( ) ; } void MdlOutputs ( int_T
tid ) { NeslSimulationData * simulationData ; NeuDiagnosticManager *
diagnosticManager ; NeuDiagnosticTree * diagnosticTree ; NeuDiagnosticTree *
diagnosticTree_p ; char * msg ; char * msg_p ; real_T tmp_m [ 33 ] ; real_T
tmp_p [ 4 ] ; real_T ratio ; real_T taskTimeV ; real_T time ; real_T time_p ;
int32_T tmp_i ; int_T tmp_g [ 3 ] ; int_T tmp_e [ 2 ] ; uint32_T numCycles ;
boolean_T tmp ; if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { taskTimeV =
ssGetTaskTime ( rtS , 2 ) ; if ( ssGetTNextWasAdjusted ( rtS , 2 ) ) { rtDW .
iygbt3dhiw = _ssGetVarNextHitTime ( rtS , 0 ) ; } if ( rtDW . kin5u534sr != 0
) { rtDW . kin5u534sr = 0 ; if ( taskTimeV >= rtP . PulseGenerator_PhaseDelay
) { ratio = ( taskTimeV - rtP . PulseGenerator_PhaseDelay ) / rtP .
PulseGenerator_Period ; numCycles = ( uint32_T ) muDoubleScalarFloor ( ratio
) ; if ( muDoubleScalarAbs ( ( real_T ) ( numCycles + 1U ) - ratio ) <
DBL_EPSILON * ratio ) { numCycles ++ ; } rtDW . ojrdgltdr5 = numCycles ;
ratio = ( ( real_T ) numCycles * rtP . PulseGenerator_Period + rtP .
PulseGenerator_PhaseDelay ) + rtP . PulseGenerator_Duty * rtP .
PulseGenerator_Period / 100.0 ; if ( taskTimeV < ratio ) { rtDW . ndxegwkwlx
= 1 ; rtDW . iygbt3dhiw = ratio ; } else { rtDW . ndxegwkwlx = 0 ; rtDW .
iygbt3dhiw = ( real_T ) ( numCycles + 1U ) * rtP . PulseGenerator_Period +
rtP . PulseGenerator_PhaseDelay ; } } else { rtDW . ojrdgltdr5 = rtP .
PulseGenerator_PhaseDelay != 0.0 ? - 1 : 0 ; rtDW . ndxegwkwlx = 0 ; rtDW .
iygbt3dhiw = rtP . PulseGenerator_PhaseDelay ; } } else if ( rtDW .
iygbt3dhiw <= taskTimeV ) { if ( rtDW . ndxegwkwlx == 1 ) { rtDW . ndxegwkwlx
= 0 ; rtDW . iygbt3dhiw = ( real_T ) ( rtDW . ojrdgltdr5 + 1LL ) * rtP .
PulseGenerator_Period + rtP . PulseGenerator_PhaseDelay ; } else { rtDW .
ojrdgltdr5 ++ ; rtDW . ndxegwkwlx = 1 ; rtDW . iygbt3dhiw = ( rtP .
PulseGenerator_Duty * rtP . PulseGenerator_Period * 0.01 + ( real_T ) rtDW .
ojrdgltdr5 * rtP . PulseGenerator_Period ) + rtP . PulseGenerator_PhaseDelay
; } } _ssSetVarNextHitTime ( rtS , 0 , rtDW . iygbt3dhiw ) ; if ( rtDW .
ndxegwkwlx == 1 ) { rtB . lrjd2s3wzf = rtP . PulseGenerator_Amp ; } else {
rtB . lrjd2s3wzf = 0.0 ; } } rtB . ms13at0w2f [ 0 ] = rtB . lrjd2s3wzf ; rtB
. ms13at0w2f [ 1 ] = 0.0 ; rtB . ms13at0w2f [ 2 ] = 0.0 ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . lzqjz5xkfi [ 0 ] = ! ( rtB . ms13at0w2f
[ 0 ] == rtDW . lzqjz5xkfi [ 1 ] ) ; rtDW . lzqjz5xkfi [ 1 ] = rtB .
ms13at0w2f [ 0 ] ; } rtB . ms13at0w2f [ 0 ] = rtDW . lzqjz5xkfi [ 1 ] ; rtB .
ms13at0w2f [ 3 ] = rtDW . lzqjz5xkfi [ 0 ] ; simulationData = (
NeslSimulationData * ) rtDW . n1pn1b4isz ; time = ssGetT ( rtS ) ;
simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData -> mTime
. mX = & time ; simulationData -> mData -> mContStates . mN = 8 ;
simulationData -> mData -> mContStates . mX = & rtX . fqg3sarkwh [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 28 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . bxat0p1hh2 [ 0 ] ; simulationData -> mData ->
mModeVector . mN = 17 ; simulationData -> mData -> mModeVector . mX = & rtDW
. g34sz5deau [ 0 ] ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo
( rtS ) -> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents =
tmp ; simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS )
; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp ; tmp = ssGetIsOkayToUpdateMode ( rtS ) ;
simulationData -> mData -> mIsOkayToUpdateMode = tmp ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . ms13at0w2f [ 0 ] ; tmp_p [ 1 ] = rtB . ms13at0w2f [ 1 ] ;
tmp_p [ 2 ] = rtB . ms13at0w2f [ 2 ] ; tmp_p [ 3 ] = rtB . ms13at0w2f [ 3 ] ;
tmp_e [ 1 ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_p [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 2 ; simulationData -> mData -> mInputOffsets
. mX = & tmp_e [ 0 ] ; simulationData -> mData -> mOutputs . mN = 29 ;
simulationData -> mData -> mOutputs . mX = & rtB . pgyquly34j [ 0 ] ;
simulationData -> mData -> mSampleHits . mN = 0 ; simulationData -> mData ->
mSampleHits . mX = NULL ; simulationData -> mData -> mIsFundamentalSampleHit
= false ; simulationData -> mData -> mTolerances . mN = 0 ; simulationData ->
mData -> mTolerances . mX = NULL ; simulationData -> mData ->
mCstateHasChanged = false ; diagnosticManager = ( NeuDiagnosticManager * )
rtDW . i5puujzelw ; diagnosticTree = neu_diagnostic_manager_get_initial_tree
( diagnosticManager ) ; tmp_i = ne_simulator_method ( ( NeslSimulator * )
rtDW . dh43lcbaln , NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ;
if ( tmp_i != 0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) )
; if ( tmp ) { msg = rtw_diagnostics_msg ( diagnosticTree ) ;
ssSetErrorStatus ( rtS , msg ) ; } } if ( ssIsMajorTimeStep ( rtS ) &&
simulationData -> mData -> mCstateHasChanged ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } simulationData = (
NeslSimulationData * ) rtDW . p5jryn5z3x ; time_p = ssGetT ( rtS ) ;
simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData -> mTime
. mX = & time_p ; simulationData -> mData -> mContStates . mN = 0 ;
simulationData -> mData -> mContStates . mX = NULL ; simulationData -> mData
-> mDiscStates . mN = 0 ; simulationData -> mData -> mDiscStates . mX = &
rtDW . h1luq02p0d ; simulationData -> mData -> mModeVector . mN = 0 ;
simulationData -> mData -> mModeVector . mX = & rtDW . iwxuojrfte ; tmp = (
ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents
) ; simulationData -> mData -> mFoundZcEvents = tmp ; simulationData -> mData
-> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr (
rtS ) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; tmp = ssIsSolverCheckingCIC ( rtS ) ;
simulationData -> mData -> mIsSolverCheckingCIC = tmp ; simulationData ->
mData -> mIsComputingJacobian = false ; simulationData -> mData ->
mIsEvaluatingF0 = false ; tmp = ssIsSolverRequestingReset ( rtS ) ;
simulationData -> mData -> mIsSolverRequestingReset = tmp ; tmp =
ssGetIsOkayToUpdateMode ( rtS ) ; simulationData -> mData ->
mIsOkayToUpdateMode = tmp ; tmp_g [ 0 ] = 0 ; tmp_m [ 0 ] = rtB . ms13at0w2f
[ 0 ] ; tmp_m [ 1 ] = rtB . ms13at0w2f [ 1 ] ; tmp_m [ 2 ] = rtB . ms13at0w2f
[ 2 ] ; tmp_m [ 3 ] = rtB . ms13at0w2f [ 3 ] ; tmp_g [ 1 ] = 4 ; memcpy ( &
tmp_m [ 4 ] , & rtB . pgyquly34j [ 0 ] , 29U * sizeof ( real_T ) ) ; tmp_g [
2 ] = 33 ; simulationData -> mData -> mInputValues . mN = 33 ; simulationData
-> mData -> mInputValues . mX = & tmp_m [ 0 ] ; simulationData -> mData ->
mInputOffsets . mN = 3 ; simulationData -> mData -> mInputOffsets . mX = &
tmp_g [ 0 ] ; simulationData -> mData -> mOutputs . mN = 2 ; simulationData
-> mData -> mOutputs . mX = & rtB . aoib3gdygq [ 0 ] ; simulationData ->
mData -> mSampleHits . mN = 0 ; simulationData -> mData -> mSampleHits . mX =
NULL ; simulationData -> mData -> mIsFundamentalSampleHit = false ;
simulationData -> mData -> mTolerances . mN = 0 ; simulationData -> mData ->
mTolerances . mX = NULL ; simulationData -> mData -> mCstateHasChanged =
false ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . o5o0pcluu0 ;
diagnosticTree_p = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW
. icaypvch4x , NESL_SIM_OUTPUTS , simulationData , diagnosticManager ) ; if (
tmp_i != 0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if
( tmp ) { msg_p = rtw_diagnostics_msg ( diagnosticTree_p ) ; ssSetErrorStatus
( rtS , msg_p ) ; } } if ( ssIsMajorTimeStep ( rtS ) && simulationData ->
mData -> mCstateHasChanged ) { ssSetBlockStateForSolverChangedAtMajorStep (
rtS ) ; } UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) {
NeslSimulationData * simulationData ; NeuDiagnosticManager *
diagnosticManager ; NeuDiagnosticTree * diagnosticTree ; char * msg ; real_T
tmp_p [ 4 ] ; real_T time ; int32_T tmp_i ; int_T tmp_e [ 2 ] ; boolean_T tmp
; simulationData = ( NeslSimulationData * ) rtDW . n1pn1b4isz ; time = ssGetT
( rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 8 ;
simulationData -> mData -> mContStates . mX = & rtX . fqg3sarkwh [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 28 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . bxat0p1hh2 [ 0 ] ; simulationData -> mData ->
mModeVector . mN = 17 ; simulationData -> mData -> mModeVector . mX = & rtDW
. g34sz5deau [ 0 ] ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo
( rtS ) -> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents =
tmp ; simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS )
; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp ; tmp = ssGetIsOkayToUpdateMode ( rtS ) ;
simulationData -> mData -> mIsOkayToUpdateMode = tmp ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . ms13at0w2f [ 0 ] ; tmp_p [ 1 ] = rtB . ms13at0w2f [ 1 ] ;
tmp_p [ 2 ] = rtB . ms13at0w2f [ 2 ] ; tmp_p [ 3 ] = rtB . ms13at0w2f [ 3 ] ;
tmp_e [ 1 ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_p [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 2 ; simulationData -> mData -> mInputOffsets
. mX = & tmp_e [ 0 ] ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW .
i5puujzelw ; diagnosticTree = neu_diagnostic_manager_get_initial_tree (
diagnosticManager ) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW
. dh43lcbaln , NESL_SIM_UPDATE , simulationData , diagnosticManager ) ; if (
tmp_i != 0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if
( tmp ) { msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus (
rtS , msg ) ; } } UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) {
NeslSimulationData * simulationData ; NeuDiagnosticManager *
diagnosticManager ; NeuDiagnosticTree * diagnosticTree ; XDot * _rtXdot ;
char * msg ; real_T tmp_p [ 4 ] ; real_T time ; int32_T tmp_i ; int_T tmp_e [
2 ] ; boolean_T tmp ; _rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ;
simulationData = ( NeslSimulationData * ) rtDW . n1pn1b4isz ; time = ssGetT (
rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 8 ;
simulationData -> mData -> mContStates . mX = & rtX . fqg3sarkwh [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 28 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . bxat0p1hh2 [ 0 ] ; simulationData -> mData ->
mModeVector . mN = 17 ; simulationData -> mData -> mModeVector . mX = & rtDW
. g34sz5deau [ 0 ] ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo
( rtS ) -> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents =
tmp ; simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS )
; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp ; tmp = ssGetIsOkayToUpdateMode ( rtS ) ;
simulationData -> mData -> mIsOkayToUpdateMode = tmp ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . ms13at0w2f [ 0 ] ; tmp_p [ 1 ] = rtB . ms13at0w2f [ 1 ] ;
tmp_p [ 2 ] = rtB . ms13at0w2f [ 2 ] ; tmp_p [ 3 ] = rtB . ms13at0w2f [ 3 ] ;
tmp_e [ 1 ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_p [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 2 ; simulationData -> mData -> mInputOffsets
. mX = & tmp_e [ 0 ] ; simulationData -> mData -> mDx . mN = 8 ;
simulationData -> mData -> mDx . mX = & _rtXdot -> fqg3sarkwh [ 0 ] ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . i5puujzelw ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW . dh43lcbaln ,
NESL_SIM_DERIVATIVES , simulationData , diagnosticManager ) ; if ( tmp_i != 0
) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) {
msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg )
; } } } void MdlProjection ( void ) { NeslSimulationData * simulationData ;
NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree * diagnosticTree
; char * msg ; real_T tmp_p [ 4 ] ; real_T time ; int32_T tmp_i ; int_T tmp_e
[ 2 ] ; boolean_T tmp ; simulationData = ( NeslSimulationData * ) rtDW .
n1pn1b4isz ; time = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN =
1 ; simulationData -> mData -> mTime . mX = & time ; simulationData -> mData
-> mContStates . mN = 8 ; simulationData -> mData -> mContStates . mX = & rtX
. fqg3sarkwh [ 0 ] ; simulationData -> mData -> mDiscStates . mN = 28 ;
simulationData -> mData -> mDiscStates . mX = & rtDW . bxat0p1hh2 [ 0 ] ;
simulationData -> mData -> mModeVector . mN = 17 ; simulationData -> mData ->
mModeVector . mX = & rtDW . g34sz5deau [ 0 ] ; tmp = ( ssIsMajorTimeStep (
rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData
-> mData -> mFoundZcEvents = tmp ; simulationData -> mData ->
mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr ( rtS
) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; tmp = ssIsSolverCheckingCIC ( rtS ) ;
simulationData -> mData -> mIsSolverCheckingCIC = tmp ; tmp =
ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData ->
mIsComputingJacobian = tmp ; simulationData -> mData -> mIsEvaluatingF0 = (
ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ; tmp = ssIsSolverRequestingReset
( rtS ) ; simulationData -> mData -> mIsSolverRequestingReset = tmp ; tmp =
ssGetIsOkayToUpdateMode ( rtS ) ; simulationData -> mData ->
mIsOkayToUpdateMode = tmp ; tmp_e [ 0 ] = 0 ; tmp_p [ 0 ] = rtB . ms13at0w2f
[ 0 ] ; tmp_p [ 1 ] = rtB . ms13at0w2f [ 1 ] ; tmp_p [ 2 ] = rtB . ms13at0w2f
[ 2 ] ; tmp_p [ 3 ] = rtB . ms13at0w2f [ 3 ] ; tmp_e [ 1 ] = 4 ;
simulationData -> mData -> mInputValues . mN = 4 ; simulationData -> mData ->
mInputValues . mX = & tmp_p [ 0 ] ; simulationData -> mData -> mInputOffsets
. mN = 2 ; simulationData -> mData -> mInputOffsets . mX = & tmp_e [ 0 ] ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . i5puujzelw ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW . dh43lcbaln ,
NESL_SIM_PROJECTION , simulationData , diagnosticManager ) ; if ( tmp_i != 0
) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) {
msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg )
; } } } void MdlForcingFunction ( void ) { NeslSimulationData *
simulationData ; NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree
* diagnosticTree ; XDot * _rtXdot ; char * msg ; real_T tmp_p [ 4 ] ; real_T
time ; int32_T tmp_i ; int_T tmp_e [ 2 ] ; boolean_T tmp ; _rtXdot = ( ( XDot
* ) ssGetdX ( rtS ) ) ; simulationData = ( NeslSimulationData * ) rtDW .
n1pn1b4isz ; time = ssGetT ( rtS ) ; simulationData -> mData -> mTime . mN =
1 ; simulationData -> mData -> mTime . mX = & time ; simulationData -> mData
-> mContStates . mN = 8 ; simulationData -> mData -> mContStates . mX = & rtX
. fqg3sarkwh [ 0 ] ; simulationData -> mData -> mDiscStates . mN = 28 ;
simulationData -> mData -> mDiscStates . mX = & rtDW . bxat0p1hh2 [ 0 ] ;
simulationData -> mData -> mModeVector . mN = 17 ; simulationData -> mData ->
mModeVector . mX = & rtDW . g34sz5deau [ 0 ] ; tmp = ( ssIsMajorTimeStep (
rtS ) && ssGetRTWSolverInfo ( rtS ) -> foundContZcEvents ) ; simulationData
-> mData -> mFoundZcEvents = tmp ; simulationData -> mData ->
mIsMajorTimeStep = ssIsMajorTimeStep ( rtS ) ; tmp = ( ssGetMdlInfoPtr ( rtS
) -> mdlFlags . solverAssertCheck == 1U ) ; simulationData -> mData ->
mIsSolverAssertCheck = tmp ; tmp = ssIsSolverCheckingCIC ( rtS ) ;
simulationData -> mData -> mIsSolverCheckingCIC = tmp ; tmp =
ssIsSolverComputingJacobian ( rtS ) ; simulationData -> mData ->
mIsComputingJacobian = tmp ; simulationData -> mData -> mIsEvaluatingF0 = (
ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ; tmp = ssIsSolverRequestingReset
( rtS ) ; simulationData -> mData -> mIsSolverRequestingReset = tmp ; tmp =
ssGetIsOkayToUpdateMode ( rtS ) ; simulationData -> mData ->
mIsOkayToUpdateMode = tmp ; tmp_e [ 0 ] = 0 ; tmp_p [ 0 ] = rtB . ms13at0w2f
[ 0 ] ; tmp_p [ 1 ] = rtB . ms13at0w2f [ 1 ] ; tmp_p [ 2 ] = rtB . ms13at0w2f
[ 2 ] ; tmp_p [ 3 ] = rtB . ms13at0w2f [ 3 ] ; tmp_e [ 1 ] = 4 ;
simulationData -> mData -> mInputValues . mN = 4 ; simulationData -> mData ->
mInputValues . mX = & tmp_p [ 0 ] ; simulationData -> mData -> mInputOffsets
. mN = 2 ; simulationData -> mData -> mInputOffsets . mX = & tmp_e [ 0 ] ;
simulationData -> mData -> mDx . mN = 8 ; simulationData -> mData -> mDx . mX
= & _rtXdot -> fqg3sarkwh [ 0 ] ; diagnosticManager = ( NeuDiagnosticManager
* ) rtDW . i5puujzelw ; diagnosticTree =
neu_diagnostic_manager_get_initial_tree ( diagnosticManager ) ; tmp_i =
ne_simulator_method ( ( NeslSimulator * ) rtDW . dh43lcbaln ,
NESL_SIM_FORCINGFUNCTION , simulationData , diagnosticManager ) ; if ( tmp_i
!= 0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp
) { msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS ,
msg ) ; } } } void MdlMassMatrix ( void ) { NeslSimulationData *
simulationData ; NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree
* diagnosticTree ; char * msg ; real_T tmp_p [ 4 ] ; real_T time ; real_T *
tmp_i ; real_T * tmp_m ; int32_T tmp_g ; int_T tmp_e [ 2 ] ; boolean_T tmp ;
simulationData = ( NeslSimulationData * ) rtDW . n1pn1b4isz ; time = ssGetT (
rtS ) ; simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData
-> mTime . mX = & time ; simulationData -> mData -> mContStates . mN = 8 ;
simulationData -> mData -> mContStates . mX = & rtX . fqg3sarkwh [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 28 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . bxat0p1hh2 [ 0 ] ; simulationData -> mData ->
mModeVector . mN = 17 ; simulationData -> mData -> mModeVector . mX = & rtDW
. g34sz5deau [ 0 ] ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo
( rtS ) -> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents =
tmp ; simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS )
; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp ; tmp = ssGetIsOkayToUpdateMode ( rtS ) ;
simulationData -> mData -> mIsOkayToUpdateMode = tmp ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . ms13at0w2f [ 0 ] ; tmp_p [ 1 ] = rtB . ms13at0w2f [ 1 ] ;
tmp_p [ 2 ] = rtB . ms13at0w2f [ 2 ] ; tmp_p [ 3 ] = rtB . ms13at0w2f [ 3 ] ;
tmp_e [ 1 ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_p [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 2 ; simulationData -> mData -> mInputOffsets
. mX = & tmp_e [ 0 ] ; tmp_i = rtMassMatrix . pr ; tmp_m =
double_pointer_shift ( tmp_i , rtDW . bq10vwdwoo ) ; simulationData -> mData
-> mMassMatrixPr . mN = 6 ; simulationData -> mData -> mMassMatrixPr . mX =
tmp_m ; diagnosticManager = ( NeuDiagnosticManager * ) rtDW . i5puujzelw ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; tmp_g = ne_simulator_method ( ( NeslSimulator * ) rtDW . dh43lcbaln ,
NESL_SIM_MASSMATRIX , simulationData , diagnosticManager ) ; if ( tmp_g != 0
) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) {
msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg )
; } } } void MdlZeroCrossings ( void ) { NeslSimulationData * simulationData
; NeuDiagnosticManager * diagnosticManager ; NeuDiagnosticTree *
diagnosticTree ; ZCV * _rtZCSV ; char * msg ; real_T tmp_p [ 4 ] ; real_T
time ; int32_T tmp_i ; int_T tmp_e [ 2 ] ; boolean_T tmp ; _rtZCSV = ( ( ZCV
* ) ssGetSolverZcSignalVector ( rtS ) ) ; simulationData = (
NeslSimulationData * ) rtDW . n1pn1b4isz ; time = ssGetT ( rtS ) ;
simulationData -> mData -> mTime . mN = 1 ; simulationData -> mData -> mTime
. mX = & time ; simulationData -> mData -> mContStates . mN = 8 ;
simulationData -> mData -> mContStates . mX = & rtX . fqg3sarkwh [ 0 ] ;
simulationData -> mData -> mDiscStates . mN = 28 ; simulationData -> mData ->
mDiscStates . mX = & rtDW . bxat0p1hh2 [ 0 ] ; simulationData -> mData ->
mModeVector . mN = 17 ; simulationData -> mData -> mModeVector . mX = & rtDW
. g34sz5deau [ 0 ] ; tmp = ( ssIsMajorTimeStep ( rtS ) && ssGetRTWSolverInfo
( rtS ) -> foundContZcEvents ) ; simulationData -> mData -> mFoundZcEvents =
tmp ; simulationData -> mData -> mIsMajorTimeStep = ssIsMajorTimeStep ( rtS )
; tmp = ( ssGetMdlInfoPtr ( rtS ) -> mdlFlags . solverAssertCheck == 1U ) ;
simulationData -> mData -> mIsSolverAssertCheck = tmp ; tmp =
ssIsSolverCheckingCIC ( rtS ) ; simulationData -> mData ->
mIsSolverCheckingCIC = tmp ; tmp = ssIsSolverComputingJacobian ( rtS ) ;
simulationData -> mData -> mIsComputingJacobian = tmp ; simulationData ->
mData -> mIsEvaluatingF0 = ( ssGetEvaluatingF0ForJacobian ( rtS ) != 0 ) ;
tmp = ssIsSolverRequestingReset ( rtS ) ; simulationData -> mData ->
mIsSolverRequestingReset = tmp ; tmp = ssGetIsOkayToUpdateMode ( rtS ) ;
simulationData -> mData -> mIsOkayToUpdateMode = tmp ; tmp_e [ 0 ] = 0 ;
tmp_p [ 0 ] = rtB . ms13at0w2f [ 0 ] ; tmp_p [ 1 ] = rtB . ms13at0w2f [ 1 ] ;
tmp_p [ 2 ] = rtB . ms13at0w2f [ 2 ] ; tmp_p [ 3 ] = rtB . ms13at0w2f [ 3 ] ;
tmp_e [ 1 ] = 4 ; simulationData -> mData -> mInputValues . mN = 4 ;
simulationData -> mData -> mInputValues . mX = & tmp_p [ 0 ] ; simulationData
-> mData -> mInputOffsets . mN = 2 ; simulationData -> mData -> mInputOffsets
. mX = & tmp_e [ 0 ] ; simulationData -> mData -> mNonSampledZCs . mN = 17 ;
simulationData -> mData -> mNonSampledZCs . mX = & _rtZCSV -> kwvhbenamf ;
diagnosticManager = ( NeuDiagnosticManager * ) rtDW . i5puujzelw ;
diagnosticTree = neu_diagnostic_manager_get_initial_tree ( diagnosticManager
) ; tmp_i = ne_simulator_method ( ( NeslSimulator * ) rtDW . dh43lcbaln ,
NESL_SIM_ZEROCROSSINGS , simulationData , diagnosticManager ) ; if ( tmp_i !=
0 ) { tmp = error_buffer_is_empty ( ssGetErrorStatus ( rtS ) ) ; if ( tmp ) {
msg = rtw_diagnostics_msg ( diagnosticTree ) ; ssSetErrorStatus ( rtS , msg )
; } } } void MdlTerminate ( void ) { neu_destroy_diagnostic_manager ( (
NeuDiagnosticManager * ) rtDW . i5puujzelw ) ; nesl_destroy_simulation_data (
( NeslSimulationData * ) rtDW . n1pn1b4isz ) ; nesl_erase_simulator (
"Nicholas_DCDC_Buck/Solver Configuration_1" ) ; nesl_destroy_registry ( ) ;
neu_destroy_diagnostic_manager ( ( NeuDiagnosticManager * ) rtDW . o5o0pcluu0
) ; nesl_destroy_simulation_data ( ( NeslSimulationData * ) rtDW . p5jryn5z3x
) ; nesl_erase_simulator ( "Nicholas_DCDC_Buck/Solver Configuration_1" ) ;
nesl_destroy_registry ( ) ; } static void
mr_Nicholas_DCDC_Buck_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) ; static void
mr_Nicholas_DCDC_Buck_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_Nicholas_DCDC_Buck_restoreDataFromMxArray ( void *
destData , const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ;
static void mr_Nicholas_DCDC_Buck_restoreDataFromMxArray ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_Nicholas_DCDC_Buck_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex
i , int j , uint_T bitVal ) ; static void
mr_Nicholas_DCDC_Buck_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex
i , int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_Nicholas_DCDC_Buck_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_Nicholas_DCDC_Buck_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_Nicholas_DCDC_Buck_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
; static void mr_Nicholas_DCDC_Buck_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_Nicholas_DCDC_Buck_restoreDataFromMxArrayWithOffset ( void * destData
, const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void
mr_Nicholas_DCDC_Buck_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_Nicholas_DCDC_Buck_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static
void mr_Nicholas_DCDC_Buck_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( double ) fieldVal ) ) ; } static uint_T
mr_Nicholas_DCDC_Buck_extractBitFieldFromCellArrayWithOffset ( const mxArray
* srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_Nicholas_DCDC_Buck_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_Nicholas_DCDC_Buck_GetDWork ( ) {
static const char * ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX"
, } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_Nicholas_DCDC_Buck_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) &
( rtB ) , sizeof ( rtB ) ) ; { static const char * rtdwDataFieldNames [ 12 ]
= { "rtDW.lzqjz5xkfi" , "rtDW.bxat0p1hh2" , "rtDW.iygbt3dhiw" ,
"rtDW.h1luq02p0d" , "rtDW.ojrdgltdr5" , "rtDW.kin5u534sr" , "rtDW.ndxegwkwlx"
, "rtDW.g34sz5deau" , "rtDW.iwxuojrfte" , "rtDW.bq10vwdwoo" ,
"rtDW.gqkx053ven" , "rtDW.nhswjatgiz" , } ; mxArray * rtdwData =
mxCreateStructMatrix ( 1 , 1 , 12 , rtdwDataFieldNames ) ;
mr_Nicholas_DCDC_Buck_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void *
) & ( rtDW . lzqjz5xkfi ) , sizeof ( rtDW . lzqjz5xkfi ) ) ;
mr_Nicholas_DCDC_Buck_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void *
) & ( rtDW . bxat0p1hh2 ) , sizeof ( rtDW . bxat0p1hh2 ) ) ;
mr_Nicholas_DCDC_Buck_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void *
) & ( rtDW . iygbt3dhiw ) , sizeof ( rtDW . iygbt3dhiw ) ) ;
mr_Nicholas_DCDC_Buck_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void *
) & ( rtDW . h1luq02p0d ) , sizeof ( rtDW . h1luq02p0d ) ) ;
mr_Nicholas_DCDC_Buck_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void *
) & ( rtDW . ojrdgltdr5 ) , sizeof ( rtDW . ojrdgltdr5 ) ) ;
mr_Nicholas_DCDC_Buck_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void *
) & ( rtDW . kin5u534sr ) , sizeof ( rtDW . kin5u534sr ) ) ;
mr_Nicholas_DCDC_Buck_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void *
) & ( rtDW . ndxegwkwlx ) , sizeof ( rtDW . ndxegwkwlx ) ) ;
mr_Nicholas_DCDC_Buck_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void *
) & ( rtDW . g34sz5deau ) , sizeof ( rtDW . g34sz5deau ) ) ;
mr_Nicholas_DCDC_Buck_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void *
) & ( rtDW . iwxuojrfte ) , sizeof ( rtDW . iwxuojrfte ) ) ;
mr_Nicholas_DCDC_Buck_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void *
) & ( rtDW . bq10vwdwoo ) , sizeof ( rtDW . bq10vwdwoo ) ) ;
mr_Nicholas_DCDC_Buck_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void *
) & ( rtDW . gqkx053ven ) , sizeof ( rtDW . gqkx053ven ) ) ;
mr_Nicholas_DCDC_Buck_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void *
) & ( rtDW . nhswjatgiz ) , sizeof ( rtDW . nhswjatgiz ) ) ;
mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void
mr_Nicholas_DCDC_Buck_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_Nicholas_DCDC_Buck_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW ,
0 , 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber (
ssDW , 0 , 1 ) ; mr_Nicholas_DCDC_Buck_restoreDataFromMxArray ( ( void * ) &
( rtDW . lzqjz5xkfi ) , rtdwData , 0 , 0 , sizeof ( rtDW . lzqjz5xkfi ) ) ;
mr_Nicholas_DCDC_Buck_restoreDataFromMxArray ( ( void * ) & ( rtDW .
bxat0p1hh2 ) , rtdwData , 0 , 1 , sizeof ( rtDW . bxat0p1hh2 ) ) ;
mr_Nicholas_DCDC_Buck_restoreDataFromMxArray ( ( void * ) & ( rtDW .
iygbt3dhiw ) , rtdwData , 0 , 2 , sizeof ( rtDW . iygbt3dhiw ) ) ;
mr_Nicholas_DCDC_Buck_restoreDataFromMxArray ( ( void * ) & ( rtDW .
h1luq02p0d ) , rtdwData , 0 , 3 , sizeof ( rtDW . h1luq02p0d ) ) ;
mr_Nicholas_DCDC_Buck_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ojrdgltdr5 ) , rtdwData , 0 , 4 , sizeof ( rtDW . ojrdgltdr5 ) ) ;
mr_Nicholas_DCDC_Buck_restoreDataFromMxArray ( ( void * ) & ( rtDW .
kin5u534sr ) , rtdwData , 0 , 5 , sizeof ( rtDW . kin5u534sr ) ) ;
mr_Nicholas_DCDC_Buck_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ndxegwkwlx ) , rtdwData , 0 , 6 , sizeof ( rtDW . ndxegwkwlx ) ) ;
mr_Nicholas_DCDC_Buck_restoreDataFromMxArray ( ( void * ) & ( rtDW .
g34sz5deau ) , rtdwData , 0 , 7 , sizeof ( rtDW . g34sz5deau ) ) ;
mr_Nicholas_DCDC_Buck_restoreDataFromMxArray ( ( void * ) & ( rtDW .
iwxuojrfte ) , rtdwData , 0 , 8 , sizeof ( rtDW . iwxuojrfte ) ) ;
mr_Nicholas_DCDC_Buck_restoreDataFromMxArray ( ( void * ) & ( rtDW .
bq10vwdwoo ) , rtdwData , 0 , 9 , sizeof ( rtDW . bq10vwdwoo ) ) ;
mr_Nicholas_DCDC_Buck_restoreDataFromMxArray ( ( void * ) & ( rtDW .
gqkx053ven ) , rtdwData , 0 , 10 , sizeof ( rtDW . gqkx053ven ) ) ;
mr_Nicholas_DCDC_Buck_restoreDataFromMxArray ( ( void * ) & ( rtDW .
nhswjatgiz ) , rtdwData , 0 , 11 , sizeof ( rtDW . nhswjatgiz ) ) ; } }
mxArray * mr_Nicholas_DCDC_Buck_GetSimStateDisallowedBlocks ( ) { mxArray *
data = mxCreateCellMatrix ( 5 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static
const char * blockType [ 5 ] = { "SimscapeExecutionBlock" ,
"SimscapeExecutionBlock" , "Scope" , "SimscapeExecutionBlock" ,
"SimscapeExecutionBlock" , } ; static const char * blockPath [ 5 ] = {
"Nicholas_DCDC_Buck/Solver Configuration/EVAL_KEY/STATE_1" ,
"Nicholas_DCDC_Buck/Solver Configuration/EVAL_KEY/OUTPUT_1_0" ,
"Nicholas_DCDC_Buck/Scope" ,
"Nicholas_DCDC_Buck/Solver Configuration/EVAL_KEY/OUTPUT_1_0" ,
"Nicholas_DCDC_Buck/Solver Configuration/EVAL_KEY/STATE_1" , } ; static const
int reason [ 5 ] = { 0 , 0 , 0 , 5 , 5 , } ; for ( subs [ 0 ] = 0 ; subs [ 0
] < 5 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset = mxCalcSingleSubscript
( data , 2 , subs ) ; mxSetCell ( data , offset , mxCreateString ( blockType
[ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ; offset = mxCalcSingleSubscript ( data ,
2 , subs ) ; mxSetCell ( data , offset , mxCreateString ( blockPath [ subs [
0 ] ] ) ) ; subs [ 1 ] = 2 ; offset = mxCalcSingleSubscript ( data , 2 , subs
) ; mxSetCell ( data , offset , mxCreateDoubleScalar ( ( double ) reason [
subs [ 0 ] ] ) ) ; } } return data ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 8 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 3 ) ; ssSetNumBlocks ( rtS , 19 ) ;
ssSetNumBlockIO ( rtS , 4 ) ; ssSetNumBlockParams ( rtS , 4 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.0 ) ; ssSetSampleTime ( rtS , 2 , - 2.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ;
ssSetOffsetTime ( rtS , 2 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 2355432598U ) ; ssSetChecksumVal ( rtS , 1 ,
1593011340U ) ; ssSetChecksumVal ( rtS , 2 , 1307211559U ) ; ssSetChecksumVal
( rtS , 3 , 1301567197U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; ( void ) memset ( ( char * ) rtS , 0 ,
sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0 , sizeof
( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr ( rtS , & mdlInfo ) ;
ssSetExecutionInfo ( rtS , executionInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { rtDW . bq10vwdwoo = 0 ; } { static
DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 ,
sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 21 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; }
Nicholas_DCDC_Buck_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive
( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "Nicholas_DCDC_Buck" ) ;
ssSetPath ( rtS , "Nicholas_DCDC_Buck" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 100.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 2 , 28 } ; static int_T rt_LoggedStateNumDimensions
[ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 2 , 28 } ;
static boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 } ; static BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = {
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }
; static RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { (
NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , (
NULL ) , ( NULL ) , ( NULL ) } ; static const char_T * rt_LoggedStateLabels [
] = { "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "Discrete" , "Discrete" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = { "Nicholas_DCDC_Buck/Capacitor" ,
"Nicholas_DCDC_Buck/Inductor" , "Nicholas_DCDC_Buck/NPN Bipolar Transistor" ,
"Nicholas_DCDC_Buck/NPN Bipolar Transistor" ,
"Nicholas_DCDC_Buck/NPN Bipolar Transistor" ,
"Nicholas_DCDC_Buck/NPN Bipolar Transistor" ,
"Nicholas_DCDC_Buck/NPN Bipolar Transistor" ,
"Nicholas_DCDC_Buck/NPN Bipolar Transistor" ,
"Nicholas_DCDC_Buck/Solver\nConfiguration/EVAL_KEY/INPUT_1_1_1" ,
"Nicholas_DCDC_Buck/Solver\nConfiguration/EVAL_KEY/STATE_1" } ; static const
char_T * rt_LoggedStateNames [ ] = { "Nicholas_DCDC_Buck.Capacitor.vc" ,
"Nicholas_DCDC_Buck.Inductor.i_L" ,
"Nicholas_DCDC_Buck.NPN_Bipolar_Transistor.capacitor_bc.vc" ,
"Nicholas_DCDC_Buck.NPN_Bipolar_Transistor.capacitor_be.vc" ,
"Nicholas_DCDC_Buck.NPN_Bipolar_Transistor.capacitor_bc.i" ,
"Nicholas_DCDC_Buck.NPN_Bipolar_Transistor.capacitor_be.i" ,
"Nicholas_DCDC_Buck.NPN_Bipolar_Transistor.emitter_resistor.i" ,
"Nicholas_DCDC_Buck.NPN_Bipolar_Transistor.transistor.ib" , "Discrete" ,
"Discrete" } ; static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 ,
1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } ,
{ 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } } ; static int_T rt_LoggedStateIdxList [ ] = { 0 , 0 ,
1 } ; static RTWLogSignalInfo rt_LoggedStateSignalInfo = { 10 ,
rt_LoggedStateWidths , rt_LoggedStateNumDimensions , rt_LoggedStateDimensions
, rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 10 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . fqg3sarkwh [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . fqg3sarkwh [ 1 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . fqg3sarkwh [ 2 ] ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . fqg3sarkwh [ 3 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . fqg3sarkwh [ 4 ] ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . fqg3sarkwh [ 5 ] ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . fqg3sarkwh [ 6 ] ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . fqg3sarkwh [ 7 ] ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) rtDW . lzqjz5xkfi ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) rtDW . bxat0p1hh2 ; } rtliSetLogT
( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS )
, "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "xFinal" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static struct _ssSFcnModelMethods3 mdlMethods3
; static struct _ssSFcnModelMethods2 mdlMethods2 ; static boolean_T
contStatesDisabled [ 8 ] ; static real_T absTol [ 8 ] = { 0.001 , 0.001 ,
0.001 , 0.001 , 0.001 , 0.001 , 0.001 , 0.001 } ; static uint8_T
absTolControl [ 8 ] = { 1U , 1U , 1U , 1U , 1U , 1U , 1U , 1U } ; static
real_T contStateJacPerturbBoundMinVec [ 8 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 8 ] ; static uint8_T zcAttributes [ 17 ] = {
( ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P | ZC_EVENT_N2P ) , (
ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P | ZC_EVENT_N2P ) , ( ZC_EVENT_P2Z
| ZC_EVENT_P2N | ZC_EVENT_Z2P | ZC_EVENT_N2P ) , ( ZC_EVENT_P2Z |
ZC_EVENT_P2N | ZC_EVENT_Z2P | ZC_EVENT_N2P ) , ( ZC_EVENT_P2Z | ZC_EVENT_P2N
| ZC_EVENT_Z2P | ZC_EVENT_N2P ) , ( ZC_EVENT_P2Z | ZC_EVENT_P2N |
ZC_EVENT_Z2P | ZC_EVENT_N2P ) , ( ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P
| ZC_EVENT_N2P ) , ( ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) , ( ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P | ZC_EVENT_N2P
) , ( ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P | ZC_EVENT_N2P ) , (
ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P | ZC_EVENT_N2P ) , ( ZC_EVENT_P2Z
| ZC_EVENT_P2N | ZC_EVENT_Z2P | ZC_EVENT_N2P ) , ( ZC_EVENT_P2Z |
ZC_EVENT_P2N | ZC_EVENT_Z2P | ZC_EVENT_N2P ) , ( ZC_EVENT_P2Z | ZC_EVENT_P2N
| ZC_EVENT_Z2P | ZC_EVENT_N2P ) , ( ZC_EVENT_P2Z | ZC_EVENT_P2N |
ZC_EVENT_Z2P | ZC_EVENT_N2P ) , ( ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P
| ZC_EVENT_N2P ) , ( ZC_EVENT_P2Z | ZC_EVENT_P2N | ZC_EVENT_Z2P |
ZC_EVENT_N2P ) } ; static ssNonContDerivSigInfo nonContDerivSigInfo [ 1 ] = {
{ 1 * sizeof ( real_T ) , ( char * ) ( & rtB . lrjd2s3wzf ) , ( NULL ) } } ;
{ int i ; for ( i = 0 ; i < 8 ; ++ i ) { contStateJacPerturbBoundMinVec [ i ]
= 0 ; contStateJacPerturbBoundMaxVec [ i ] = rtGetInf ( ) ; } }
ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ;
ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ;
ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 2.0 ) ;
ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 1 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 1 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "daessc" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ;
_ssSetSolverUpdateJacobianAtReset ( rtS , true ) ; ssSetAbsTolVector ( rtS ,
absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 1 ) ; (
void ) memset ( ( void * ) & mdlMethods2 , 0 , sizeof ( mdlMethods2 ) ) ;
ssSetModelMethods2 ( rtS , & mdlMethods2 ) ; ( void ) memset ( ( void * ) &
mdlMethods3 , 0 , sizeof ( mdlMethods3 ) ) ; ssSetModelMethods3 ( rtS , &
mdlMethods3 ) ; ssSetModelProjection ( rtS , MdlProjection ) ;
ssSetMassMatrixType ( rtS , ( ssMatrixType ) 3 ) ; ssSetMassMatrixNzMax ( rtS
, 6 ) ; ssSetModelMassMatrix ( rtS , MdlMassMatrix ) ;
ssSetModelForcingFunction ( rtS , MdlForcingFunction ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 3 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 6 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 17 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 17 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; { int_T
* ir = rtMassMatrix . ir ; int_T * jc = rtMassMatrix . jc ; real_T * pr =
rtMassMatrix . pr ; ssSetMassMatrixIr ( rtS , ir ) ; ssSetMassMatrixJc ( rtS
, jc ) ; ssSetMassMatrixPr ( rtS , pr ) ; ( void ) memset ( ( void * ) ir , 0
, 6 * sizeof ( int_T ) ) ; ( void ) memset ( ( void * ) jc , 0 , ( 8 + 1 ) *
sizeof ( int_T ) ) ; ( void ) memset ( ( void * ) pr , 0 , 6 * sizeof (
real_T ) ) ; } } ssSetChecksumVal ( rtS , 0 , 2355432598U ) ;
ssSetChecksumVal ( rtS , 1 , 1593011340U ) ; ssSetChecksumVal ( rtS , 2 ,
1307211559U ) ; ssSetChecksumVal ( rtS , 3 , 1301567197U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 1 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_Nicholas_DCDC_Buck_GetSimStateDisallowedBlocks ) ;
slsaGetWorkFcnForSimTargetOP ( rtS , mr_Nicholas_DCDC_Buck_GetDWork ) ;
slsaSetWorkFcnForSimTargetOP ( rtS , mr_Nicholas_DCDC_Buck_SetDWork ) ;
rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if ( ssGetErrorStatus ( rtS ) )
{ return rtS ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = - 1 ; void MdlOutputsParameterSampleTime
( int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
