/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'modifiedPMSM_Model'.
 *
 * Model version                  : 2.24
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Mar  6 10:13:18 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include <stddef.h>
#include <stdio.h>            /* This example main program uses printf/fflush */
#include "modifiedPMSM_Model.h"        /* Model header file */

/*
 * Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */

  /* Check for overrun */
  if (OverrunFlag) {
    rtmSetErrorStatus(modifiedPMSM_Model_M, "Overrun");
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
  /* Set model inputs here */

  /* Step the model */
  modifiedPMSM_Model_step();

  /* Get model outputs here */

  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

/*
 * The example main function illustrates what is required by your
 * application code to initialize, execute, and terminate the generated code.
 * Attaching rt_OneStep to a real-time clock is target specific. This example
 * illustrates how you do this relative to initializing the model.
 */
int_T main(int_T argc, const char *argv[])
{
  /* Unused arguments */
  (void)(argc);
  (void)(argv);

  /* Initialize model */
  modifiedPMSM_Model_initialize();

  double simulationTime = 1;
  double currentTime = 0;
  double timeStep = 2.5E-7;

  // ADDED for sine wave
  const float pi = 3.1415926535;
  const double sine_amplitude = 0.5;
  const double vertical_shift = 0.5;
  const double phase_offset_2 = 1.0 * 2.0 * pi / 3.0; //120 degree phase offset in radians 
  const double phase_offset_3 = 2.0 * 2.0 * pi / 3.0;

  /* Simulating the model step behavior (in non real-time) to
   *  simulate model behavior at stop time.
   */
   // export .csv
  FILE* file = fopen("sine_wave_data.csv", "w");
  if (file == NULL) {
      printf("error opening file");
      return -1;
  }

  fprintf(file, "Time, ThetaOutput, OmegaOutput, TmOutput, WmOutput, labcOutput0, labcOutput1, labcOutput2\n");

  /* Simulating the model step behavior (in non real-time) to
   *  simulate model behavior at stop time.
   */
  int loop_counter = 0;
  while ((rtmGetErrorStatus(modifiedPMSM_Model_M) == (NULL)) && currentTime < simulationTime) {

      double Sine_Input = 10.0 * currentTime; // 10 rad/s

      /* Set duty cycles in the external input structure */
      for (int i = 0; i < 3; i++) {
          modifiedPMSM_Model_U.DutyCycles[i] = sine_amplitude * sin(Sine_Input + ((i + 1) * 2.0 * pi / 3)) + vertical_shift;
      }

      /* Step the model with external inputs */
      modifiedPMSM_Model_step(&modifiedPMSM_Model_U);


      if (loop_counter % 1000 == 0) {
          printf("Debug: labcOutput values - %f, %f, %f\n", modifiedPMSM_Model_Y.labcOutput[0], modifiedPMSM_Model_Y.labcOutput[1], modifiedPMSM_Model_Y.labcOutput[2]);
          fprintf(file, "%f,%f,%f,%f,%f,%f\n",
              /* for showing the duty cycle sine wave in the excel file */
              //currentTime, modifiedPMSM_Model_U.DutyCycles[0], modifiedPMSM_Model_U.DutyCycles[1], modifiedPMSM_Model_U.DutyCycles[2]);

              /* for showing the outputs in the excel file */
              currentTime, modifiedPMSM_Model_Y.ThetaOutput, modifiedPMSM_Model_Y.OmegaOutput, modifiedPMSM_Model_Y.TmOutput, modifiedPMSM_Model_Y.WmOutput, modifiedPMSM_Model_Y.labcOutput[0], modifiedPMSM_Model_Y.labcOutput[1], modifiedPMSM_Model_Y.labcOutput[2]);
      }
      rt_OneStep();
      currentTime += timeStep;
      loop_counter += 1;

  }

  fclose(file);


  /* Terminate model */
  modifiedPMSM_Model_terminate();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
