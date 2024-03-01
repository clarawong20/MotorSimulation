/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: modifiedPMSM_Model.c
 *
 * Code generated for Simulink model 'modifiedPMSM_Model'.
 *
 * Model version                  : 2.21
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Fri Feb 16 17:19:11 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "modifiedPMSM_Model.h"
#include <math.h>
#include <emmintrin.h>
#include "rtwtypes.h"
#include "modifiedPMSM_Model_private.h"

/* Block signals (default storage) */
B_modifiedPMSM_Model_T modifiedPMSM_Model_B;

/* Continuous states */
X_modifiedPMSM_Model_T modifiedPMSM_Model_X;

/* External inputs (root inport signals with default storage) */
ExtU_modifiedPMSM_Model_T modifiedPMSM_Model_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_modifiedPMSM_Model_T modifiedPMSM_Model_Y;

/* Periodic continuous states */
PeriodicIndX_modifiedPMSM_Mod_T modifiedPMSM_Model_PeriodicIndX;
PeriodicRngX_modifiedPMSM_Mod_T modifiedPMSM_Model_PeriodicRngX;

/* Real-time model */
static RT_MODEL_modifiedPMSM_Model_T modifiedPMSM_Model_M_;
RT_MODEL_modifiedPMSM_Model_T *const modifiedPMSM_Model_M =
  &modifiedPMSM_Model_M_;

/* State reduction function */
void local_stateReduction(real_T* x, int_T* p, int_T n, real_T* r)
{
  int_T i, j;
  for (i = 0, j = 0; i < n; ++i, ++j) {
    int_T k = p[i];
    real_T lb = r[j++];
    real_T xk = x[k]-lb;
    real_T rk = r[j]-lb;
    int_T q = (int_T) floor(xk/rk);
    if (q) {
      x[k] = xk-q*rk+lb;
    }
  }
}

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  modifiedPMSM_Model_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  modifiedPMSM_Model_step();
  modifiedPMSM_Model_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  modifiedPMSM_Model_step();
  modifiedPMSM_Model_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  modifiedPMSM_Model_step();
  modifiedPMSM_Model_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  local_stateReduction(rtsiGetContStates(si), rtsiGetPeriodicContStateIndices(si),
                       1,
                       rtsiGetPeriodicContStateRanges(si));
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void modifiedPMSM_Model_step(const ExtU_modifiedPMSM_Model_T *externalInputs)
{
  real_T rtb_TmpSignalConversionAtGain_j[3];
  real_T rtb_alpha_beta[2];
  real_T rtb_Gain;
  real_T rtb_Gain1;
  real_T rtb_Product1_d;
  real_T rtb_Product1_mi;
  real_T rtb_Product1_p;
  real_T rtb_Product2_n;
  real_T rtb_Product3_g;
  int32_T i;
  boolean_T rtb_RelationalOperator2;
  if (rtmIsMajorTimeStep(modifiedPMSM_Model_M)) {
    /* set solver stop time */
    if (!(modifiedPMSM_Model_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&modifiedPMSM_Model_M->solverInfo,
                            ((modifiedPMSM_Model_M->Timing.clockTickH0 + 1) *
        modifiedPMSM_Model_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&modifiedPMSM_Model_M->solverInfo,
                            ((modifiedPMSM_Model_M->Timing.clockTick0 + 1) *
        modifiedPMSM_Model_M->Timing.stepSize0 +
        modifiedPMSM_Model_M->Timing.clockTickH0 *
        modifiedPMSM_Model_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(modifiedPMSM_Model_M)) {
    modifiedPMSM_Model_M->Timing.t[0] = rtsiGetT
      (&modifiedPMSM_Model_M->solverInfo);
  }

  /* Gain: '<S4>/Gain1' incorporates:
   *  Constant: '<S4>/Constant'
   *  Integrator: '<S1>/Integrator'
   *  Sum: '<S4>/Sum'
   */
  rtb_Gain1 = (modifiedPMSM_Model_X.Integrator_CSTATE - 0.167) * 1000.0;

  /* Trigonometry: '<S8>/Trigonometric Function1' incorporates:
   *  Integrator: '<S1>/Integrator3'
   */
  rtb_Product3_g = cos(modifiedPMSM_Model_X.Integrator3_CSTATE);

  /* Gain: '<S4>/Gain' incorporates:
   *  Integrator: '<S1>/Integrator1'
   */
  rtb_Gain = 500.0 * modifiedPMSM_Model_X.Integrator1_CSTATE;

  /* Trigonometry: '<S8>/Trigonometric Function' incorporates:
   *  Integrator: '<S1>/Integrator3'
   */
  rtb_Product2_n = sin(modifiedPMSM_Model_X.Integrator3_CSTATE);

  /* SignalConversion generated from: '<S6>/Gain1' incorporates:
   *  Product: '<S6>/Product'
   *  Product: '<S6>/Product1'
   *  Product: '<S6>/Product2'
   *  Product: '<S6>/Product3'
   *  Sum: '<S6>/Sum'
   *  Sum: '<S6>/Sum1'
   */
  rtb_Product1_p = rtb_Gain1 * rtb_Product3_g - rtb_Gain * rtb_Product2_n;
  rtb_Product1_mi = rtb_Gain1 * rtb_Product2_n + rtb_Product3_g * rtb_Gain;
  for (i = 0; i <= 0; i += 2) {
    /* Gain: '<S6>/Gain1' */
    _mm_storeu_pd(&rtb_TmpSignalConversionAtGain_j[i], _mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&modifiedPMSM_Model_ConstP.Gain1_Gain_p[i + 3]), _mm_set1_pd
       (rtb_Product1_mi)), _mm_mul_pd(_mm_loadu_pd
      (&modifiedPMSM_Model_ConstP.Gain1_Gain_p[i]), _mm_set1_pd(rtb_Product1_p))));
  }

  /* Gain: '<S6>/Gain1' */
  for (i = 2; i < 3; i++) {
    rtb_TmpSignalConversionAtGain_j[i] =
      modifiedPMSM_Model_ConstP.Gain1_Gain_p[i + 3] * rtb_Product1_mi +
      modifiedPMSM_Model_ConstP.Gain1_Gain_p[i] * rtb_Product1_p;
  }

  /* SignalGenerator: '<S12>/Signal Generator' incorporates:
   *  Clock: '<Root>/Clock'
   */
  rtb_Product1_p = 40000.0 * modifiedPMSM_Model_M->Timing.t[0];

  /* Abs: '<S12>/Abs' incorporates:
   *  SignalGenerator: '<S12>/Signal Generator'
   */
  rtb_Product1_d = fabs(1.0 - (rtb_Product1_p - floor(rtb_Product1_p)) * 2.0);

  /* RelationalOperator: '<S2>/Relational Operator' incorporates:
   *  Inport: '<Root>/Duty Cycles'
   */
  rtb_RelationalOperator2 = (modifiedPMSM_Model_U.DutyCycles[0] > rtb_Product1_d);

  /* Product: '<S13>/Product1' incorporates:
   *  CombinatorialLogic: '<S13>/Leg'
   *  Constant: '<Root>/VDC'
   *  Constant: '<S16>/Constant'
   *  Logic: '<S9>/NOT'
   *  RelationalOperator: '<S16>/Compare'
   */
  rtb_Product1_p = modifiedPMSM_Model_ConstP.pooled2[((((uint32_T)
    (rtb_TmpSignalConversionAtGain_j[0] > 0.0) << 1) + rtb_RelationalOperator2) <<
    1) + (uint32_T)!rtb_RelationalOperator2] * 800.0;

  /* RelationalOperator: '<S2>/Relational Operator1' incorporates:
   *  Inport: '<Root>/Duty Cycles'
   */
  rtb_RelationalOperator2 = (modifiedPMSM_Model_U.DutyCycles[1] > rtb_Product1_d);

  /* Product: '<S14>/Product1' incorporates:
   *  CombinatorialLogic: '<S14>/Leg'
   *  Constant: '<Root>/VDC'
   *  Constant: '<S17>/Constant'
   *  Logic: '<S10>/NOT'
   *  RelationalOperator: '<S17>/Compare'
   */
  rtb_Product1_mi = modifiedPMSM_Model_ConstP.pooled2[((((uint32_T)
    (rtb_TmpSignalConversionAtGain_j[1] > 0.0) << 1) + rtb_RelationalOperator2) <<
    1) + (uint32_T)!rtb_RelationalOperator2] * 800.0;

  /* RelationalOperator: '<S2>/Relational Operator2' incorporates:
   *  Inport: '<Root>/Duty Cycles'
   */
  rtb_RelationalOperator2 = (modifiedPMSM_Model_U.DutyCycles[2] > rtb_Product1_d);

  /* SignalConversion generated from: '<S1>/Gain1' incorporates:
   *  CombinatorialLogic: '<S15>/Leg'
   *  Constant: '<Root>/VDC'
   *  Constant: '<S18>/Constant'
   *  Logic: '<S11>/NOT'
   *  Product: '<S15>/Product1'
   *  RelationalOperator: '<S18>/Compare'
   */
  rtb_Product1_d = modifiedPMSM_Model_ConstP.pooled2[((((uint32_T)
    (rtb_TmpSignalConversionAtGain_j[2] > 0.0) << 1) + rtb_RelationalOperator2) <<
    1) + (uint32_T)!rtb_RelationalOperator2] * 800.0;
  for (i = 0; i <= 0; i += 2) {
    /* Gain: '<S1>/Gain1' incorporates:
     *  SignalConversion generated from: '<S1>/Gain1'
     */
    _mm_storeu_pd(&rtb_TmpSignalConversionAtGain_j[i], _mm_add_pd(_mm_add_pd
      (_mm_mul_pd(_mm_loadu_pd(&modifiedPMSM_Model_ConstP.Gain1_Gain_b[i + 3]),
                  _mm_set1_pd(rtb_Product1_mi)), _mm_mul_pd(_mm_loadu_pd
      (&modifiedPMSM_Model_ConstP.Gain1_Gain_b[i]), _mm_set1_pd(rtb_Product1_p))),
      _mm_mul_pd(_mm_loadu_pd(&modifiedPMSM_Model_ConstP.Gain1_Gain_b[i + 6]),
                 _mm_set1_pd(rtb_Product1_d))));
  }

  /* Gain: '<S1>/Gain1' incorporates:
   *  SignalConversion generated from: '<S1>/Gain1'
   */
  for (i = 2; i < 3; i++) {
    rtb_TmpSignalConversionAtGain_j[i] =
      (modifiedPMSM_Model_ConstP.Gain1_Gain_b[i + 3] * rtb_Product1_mi +
       modifiedPMSM_Model_ConstP.Gain1_Gain_b[i] * rtb_Product1_p) +
      modifiedPMSM_Model_ConstP.Gain1_Gain_b[i + 6] * rtb_Product1_d;
  }

  /* Gain: '<S5>/Gain3' */
  rtb_Product1_p = rtb_TmpSignalConversionAtGain_j[1];
  rtb_Product1_mi = rtb_TmpSignalConversionAtGain_j[0];
  rtb_Product1_d = rtb_TmpSignalConversionAtGain_j[2];
  for (i = 0; i <= 0; i += 2) {
    /* Gain: '<S5>/Gain3' */
    _mm_storeu_pd(&rtb_alpha_beta[i], _mm_add_pd(_mm_add_pd(_mm_mul_pd
      (_mm_loadu_pd(&modifiedPMSM_Model_ConstP.Gain3_Gain[i + 2]), _mm_set1_pd
       (rtb_Product1_p)), _mm_mul_pd(_mm_loadu_pd
      (&modifiedPMSM_Model_ConstP.Gain3_Gain[i]), _mm_set1_pd(rtb_Product1_mi))),
      _mm_mul_pd(_mm_loadu_pd(&modifiedPMSM_Model_ConstP.Gain3_Gain[i + 4]),
                 _mm_set1_pd(rtb_Product1_d))));
  }

  /* MATLAB Function: '<S1>/dq-PMSM' incorporates:
   *  Constant: '<S1>/Constant'
   *  Gain: '<S1>/Gain'
   *  Integrator: '<S1>/Integrator'
   *  Integrator: '<S1>/Integrator1'
   *  Integrator: '<S1>/Integrator2'
   *  Product: '<S5>/Product'
   *  Product: '<S5>/Product1'
   *  Product: '<S5>/Product2'
   *  Product: '<S5>/Product3'
   *  Sum: '<S5>/Sum'
   *  Sum: '<S5>/Sum1'
   */
  modifiedPMSM_Model_B.dTheta = 4.0 * modifiedPMSM_Model_X.Integrator2_CSTATE;
  modifiedPMSM_Model_B.dPsid = ((rtb_alpha_beta[0] * rtb_Product3_g +
    rtb_alpha_beta[1] * rtb_Product2_n) - 0.06 * rtb_Gain1) +
    modifiedPMSM_Model_B.dTheta * modifiedPMSM_Model_X.Integrator1_CSTATE;
  modifiedPMSM_Model_B.dPsiq = ((rtb_Product3_g * rtb_alpha_beta[1] -
    rtb_alpha_beta[0] * rtb_Product2_n) - 0.06 * rtb_Gain) -
    modifiedPMSM_Model_B.dTheta * modifiedPMSM_Model_X.Integrator_CSTATE;
  modifiedPMSM_Model_B.dOmega = (((modifiedPMSM_Model_X.Integrator_CSTATE *
    rtb_Gain - modifiedPMSM_Model_X.Integrator1_CSTATE * rtb_Gain1) * 6.0 - 0.01
    * modifiedPMSM_Model_X.Integrator2_CSTATE) - 0.5 *
    modifiedPMSM_Model_X.Integrator2_CSTATE) / 0.1;

  /* Outport: '<Root>/Output' incorporates:
   *  Integrator: '<S1>/Integrator3'
   */
  modifiedPMSM_Model_Y.ThetaOutput = modifiedPMSM_Model_X.Integrator3_CSTATE;
  if (rtmIsMajorTimeStep(modifiedPMSM_Model_M)) {
    rt_ertODEUpdateContinuousStates(&modifiedPMSM_Model_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++modifiedPMSM_Model_M->Timing.clockTick0)) {
      ++modifiedPMSM_Model_M->Timing.clockTickH0;
    }

    modifiedPMSM_Model_M->Timing.t[0] = rtsiGetSolverStopTime
      (&modifiedPMSM_Model_M->solverInfo);

    {
      /* Update absolute timer for sample time: [2.5E-7s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 2.5E-7, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      modifiedPMSM_Model_M->Timing.clockTick1++;
      if (!modifiedPMSM_Model_M->Timing.clockTick1) {
        modifiedPMSM_Model_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void modifiedPMSM_Model_derivatives(void)
{
  XDot_modifiedPMSM_Model_T *_rtXdot;
  _rtXdot = ((XDot_modifiedPMSM_Model_T *) modifiedPMSM_Model_M->derivs);

  /* Derivatives for Integrator: '<S1>/Integrator' */
  _rtXdot->Integrator_CSTATE = modifiedPMSM_Model_B.dPsid;

  /* Derivatives for Integrator: '<S1>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = modifiedPMSM_Model_B.dTheta;

  /* Derivatives for Integrator: '<S1>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = modifiedPMSM_Model_B.dPsiq;

  /* Derivatives for Integrator: '<S1>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = modifiedPMSM_Model_B.dOmega;
}

/* Model initialize function */
void modifiedPMSM_Model_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&modifiedPMSM_Model_M->solverInfo,
                          &modifiedPMSM_Model_M->Timing.simTimeStep);
    rtsiSetTPtr(&modifiedPMSM_Model_M->solverInfo, &rtmGetTPtr
                (modifiedPMSM_Model_M));
    rtsiSetStepSizePtr(&modifiedPMSM_Model_M->solverInfo,
                       &modifiedPMSM_Model_M->Timing.stepSize0);
    rtsiSetdXPtr(&modifiedPMSM_Model_M->solverInfo,
                 &modifiedPMSM_Model_M->derivs);
    rtsiSetContStatesPtr(&modifiedPMSM_Model_M->solverInfo, (real_T **)
                         &modifiedPMSM_Model_M->contStates);
    rtsiSetNumContStatesPtr(&modifiedPMSM_Model_M->solverInfo,
      &modifiedPMSM_Model_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&modifiedPMSM_Model_M->solverInfo,
      &modifiedPMSM_Model_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&modifiedPMSM_Model_M->solverInfo,
      &modifiedPMSM_Model_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&modifiedPMSM_Model_M->solverInfo,
      &modifiedPMSM_Model_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&modifiedPMSM_Model_M->solverInfo, (&rtmGetErrorStatus
      (modifiedPMSM_Model_M)));
    rtsiSetRTModelPtr(&modifiedPMSM_Model_M->solverInfo, modifiedPMSM_Model_M);
  }

  rtsiSetSimTimeStep(&modifiedPMSM_Model_M->solverInfo, MAJOR_TIME_STEP);
  modifiedPMSM_Model_M->intgData.y = modifiedPMSM_Model_M->odeY;
  modifiedPMSM_Model_M->intgData.f[0] = modifiedPMSM_Model_M->odeF[0];
  modifiedPMSM_Model_M->intgData.f[1] = modifiedPMSM_Model_M->odeF[1];
  modifiedPMSM_Model_M->intgData.f[2] = modifiedPMSM_Model_M->odeF[2];
  modifiedPMSM_Model_M->intgData.f[3] = modifiedPMSM_Model_M->odeF[3];
  modifiedPMSM_Model_M->contStates = ((X_modifiedPMSM_Model_T *)
    &modifiedPMSM_Model_X);
  modifiedPMSM_Model_M->periodicContStateIndices = ((int_T*)
    modifiedPMSM_Model_PeriodicIndX);
  modifiedPMSM_Model_M->periodicContStateRanges = ((real_T*)
    modifiedPMSM_Model_PeriodicRngX);
  rtsiSetSolverData(&modifiedPMSM_Model_M->solverInfo, (void *)
                    &modifiedPMSM_Model_M->intgData);
  rtsiSetIsMinorTimeStepWithModeChange(&modifiedPMSM_Model_M->solverInfo, false);
  rtsiSetSolverName(&modifiedPMSM_Model_M->solverInfo,"ode4");
  rtmSetTPtr(modifiedPMSM_Model_M, &modifiedPMSM_Model_M->Timing.tArray[0]);
  modifiedPMSM_Model_M->Timing.stepSize0 = 2.5E-7;

  /* InitializeConditions for Integrator: '<S1>/Integrator' */
  modifiedPMSM_Model_X.Integrator_CSTATE = 0.10647988780002234;

  /* InitializeConditions for Integrator: '<S1>/Integrator3' */
  modifiedPMSM_Model_X.Integrator3_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S1>/Integrator1' */
  modifiedPMSM_Model_X.Integrator1_CSTATE = 0.23468574471835618;

  /* InitializeConditions for Integrator: '<S1>/Integrator2' */
  modifiedPMSM_Model_X.Integrator2_CSTATE = 314.15926535897933;

  /* InitializeConditions for root-level periodic continuous states */
  {
    int_T rootPeriodicContStateIndices[1] = { 1 };

    real_T rootPeriodicContStateRanges[2] = { -3.1415926535897931,
      3.1415926535897931 };

    (void) memcpy((void*)modifiedPMSM_Model_PeriodicIndX,
                  rootPeriodicContStateIndices,
                  1*sizeof(int_T));
    (void) memcpy((void*)modifiedPMSM_Model_PeriodicRngX,
                  rootPeriodicContStateRanges,
                  2*sizeof(real_T));
  }
}

/* Model terminate function */
void modifiedPMSM_Model_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
