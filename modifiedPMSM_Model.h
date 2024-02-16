/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: modifiedPMSM_Model.h
 *
 * Code generated for Simulink model 'modifiedPMSM_Model'.
 *
 * Model version                  : 2.19
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Jan 24 12:24:01 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_modifiedPMSM_Model_h_
#define RTW_HEADER_modifiedPMSM_Model_h_
#ifndef modifiedPMSM_Model_COMMON_INCLUDES_
#define modifiedPMSM_Model_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* modifiedPMSM_Model_COMMON_INCLUDES_ */

#include "modifiedPMSM_Model_types.h"
#include <string.h>
#include <math.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T dPsid;                        /* '<S1>/dq-PMSM' */
  real_T dPsiq;                        /* '<S1>/dq-PMSM' */
  real_T dOmega;                       /* '<S1>/dq-PMSM' */
  real_T dTheta;                       /* '<S1>/dq-PMSM' */
} B_modifiedPMSM_Model_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
  real_T Integrator3_CSTATE;           /* '<S1>/Integrator3' */
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S1>/Integrator2' */
} X_modifiedPMSM_Model_T;

/* Periodic continuous state vector (global) */
typedef int_T PeriodicIndX_modifiedPMSM_Mod_T[1];
typedef real_T PeriodicRngX_modifiedPMSM_Mod_T[2];

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S1>/Integrator' */
  real_T Integrator3_CSTATE;           /* '<S1>/Integrator3' */
  real_T Integrator1_CSTATE;           /* '<S1>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S1>/Integrator2' */
} XDot_modifiedPMSM_Model_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S1>/Integrator' */
  boolean_T Integrator3_CSTATE;        /* '<S1>/Integrator3' */
  boolean_T Integrator1_CSTATE;        /* '<S1>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S1>/Integrator2' */
} XDis_modifiedPMSM_Model_T;

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
} ODE4_IntgData;

#endif

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: C32
   * Referenced by: '<S6>/Gain1'
   */
  real_T Gain1_Gain_p[6];

  /* Pooled Parameter (Expression: [1;0;1;0.5;0;0;1;0.5])
   * Referenced by:
   *   '<S13>/Leg'
   *   '<S14>/Leg'
   *   '<S15>/Leg'
   */
  real_T pooled2[8];

  /* Expression: C33
   * Referenced by: '<S1>/Gain1'
   */
  real_T Gain1_Gain_b[9];

  /* Expression: C32inv
   * Referenced by: '<S5>/Gain3'
   */
  real_T Gain3_Gain[6];
} ConstP_modifiedPMSM_Model_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T ThetaOutput;                  /* '<Root>/Output' */
  real_T SineWave1;
  real_T SineWave2;
  real_T SineWave3;
} ExtY_modifiedPMSM_Model_T;

/* Real-time Model Data Structure */
struct tag_RTM_modifiedPMSM_Model_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_modifiedPMSM_Model_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_modifiedPMSM_Model_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[4];
  real_T odeF[4][4];
  ODE4_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals (default storage) */
extern B_modifiedPMSM_Model_T modifiedPMSM_Model_B;

/* Continuous states (default storage) */
extern X_modifiedPMSM_Model_T modifiedPMSM_Model_X;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_modifiedPMSM_Model_T modifiedPMSM_Model_Y;

/* Constant parameters (default storage) */
extern const ConstP_modifiedPMSM_Model_T modifiedPMSM_Model_ConstP;

/* Model entry point functions */
extern void modifiedPMSM_Model_initialize(void);
extern void modifiedPMSM_Model_step(void);
extern void modifiedPMSM_Model_terminate(void);

/* Real-time Model object */
extern RT_MODEL_modifiedPMSM_Model_T *const modifiedPMSM_Model_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Iabc' : Unused code path elimination
 * Block '<Root>/Omega(rpm)' : Unused code path elimination
 * Block '<Root>/Position' : Unused code path elimination
 * Block '<Root>/Pulse Generator' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Speed(rpm)' : Unused code path elimination
 * Block '<S3>/Sum' : Unused code path elimination
 * Block '<S13>/Data Type Conversion' : Unused code path elimination
 * Block '<S13>/Product2' : Unused code path elimination
 * Block '<S14>/Data Type Conversion' : Unused code path elimination
 * Block '<S14>/Product2' : Unused code path elimination
 * Block '<S15>/Data Type Conversion' : Unused code path elimination
 * Block '<S15>/Product2' : Unused code path elimination
 * Block '<S2>/Data Type Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'modifiedPMSM_Model'
 * '<S1>'   : 'modifiedPMSM_Model/PMSM'
 * '<S2>'   : 'modifiedPMSM_Model/SPWM'
 * '<S3>'   : 'modifiedPMSM_Model/VSI'
 * '<S4>'   : 'modifiedPMSM_Model/PMSM/MagCircuit'
 * '<S5>'   : 'modifiedPMSM_Model/PMSM/abc to dq'
 * '<S6>'   : 'modifiedPMSM_Model/PMSM/dq to abc'
 * '<S7>'   : 'modifiedPMSM_Model/PMSM/dq-PMSM'
 * '<S8>'   : 'modifiedPMSM_Model/PMSM/sin_cos'
 * '<S9>'   : 'modifiedPMSM_Model/SPWM/S1'
 * '<S10>'  : 'modifiedPMSM_Model/SPWM/S2'
 * '<S11>'  : 'modifiedPMSM_Model/SPWM/S3'
 * '<S12>'  : 'modifiedPMSM_Model/SPWM/carrier'
 * '<S13>'  : 'modifiedPMSM_Model/VSI/V1'
 * '<S14>'  : 'modifiedPMSM_Model/VSI/V2'
 * '<S15>'  : 'modifiedPMSM_Model/VSI/V3'
 * '<S16>'  : 'modifiedPMSM_Model/VSI/V1/Compare To Zero'
 * '<S17>'  : 'modifiedPMSM_Model/VSI/V2/Compare To Zero'
 * '<S18>'  : 'modifiedPMSM_Model/VSI/V3/Compare To Zero'
 */
#endif                                 /* RTW_HEADER_modifiedPMSM_Model_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
