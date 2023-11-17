/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: modifiedPMSM_Model_data.c
 *
 * Code generated for Simulink model 'modifiedPMSM_Model'.
 *
 * Model version                  : 2.14
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Fri Nov 17 16:35:33 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "modifiedPMSM_Model.h"

/* Constant parameters (default storage) */
const ConstP_modifiedPMSM_Model_T modifiedPMSM_Model_ConstP = {
  /* Expression: C32
   * Referenced by: '<S6>/Gain1'
   */
  { 1.0, -0.5, -0.5, 0.0, 0.8660254037844386, -0.8660254037844386 },

  /* Pooled Parameter (Expression: [1;0;1;0.5;0;0;1;0.5])
   * Referenced by:
   *   '<S13>/Leg'
   *   '<S14>/Leg'
   *   '<S15>/Leg'
   */
  { 1.0, 0.0, 1.0, 0.5, 0.0, 0.0, 1.0, 0.5 },

  /* Expression: C33
   * Referenced by: '<S1>/Gain1'
   */
  { 0.66666666666666663, -0.33333333333333331, -0.33333333333333331,
    -0.33333333333333331, 0.66666666666666663, -0.33333333333333326,
    -0.33333333333333331, -0.33333333333333326, 0.66666666666666663 },

  /* Expression: C32inv
   * Referenced by: '<S5>/Gain3'
   */
  { 0.66666666666666663, 0.0, -0.33333333333333331, 0.57735026918962573,
    -0.33333333333333331, -0.57735026918962573 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
