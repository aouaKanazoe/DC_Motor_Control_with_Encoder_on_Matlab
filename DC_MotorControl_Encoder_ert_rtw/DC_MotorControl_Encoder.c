/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DC_MotorControl_Encoder.c
 *
 * Code generated for Simulink model 'DC_MotorControl_Encoder'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Sun Aug 31 18:31:03 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "DC_MotorControl_Encoder.h"
#include "rtwtypes.h"
#include "DC_MotorControl_Encoder_private.h"
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_DC_MotorControl_Encoder_T DC_MotorControl_Encoder_B;

/* Block states (default storage) */
DW_DC_MotorControl_Encoder_T DC_MotorControl_Encoder_DW;

/* Real-time model */
static RT_MODEL_DC_MotorControl_Enco_T DC_MotorControl_Encoder_M_;
RT_MODEL_DC_MotorControl_Enco_T *const DC_MotorControl_Encoder_M =
  &DC_MotorControl_Encoder_M_;

/* Model step function */
void DC_MotorControl_Encoder_step(void)
{
  uint8_T rtb_ManualSwitch_idx_0;
  uint8_T rtb_ManualSwitch_idx_1;

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   */
  if (DC_MotorControl_Encoder_P.ManualSwitch_CurrentSetting == 1) {
    rtb_ManualSwitch_idx_0 = DC_MotorControl_Encoder_P.Constant_Value;
    rtb_ManualSwitch_idx_1 = DC_MotorControl_Encoder_P.Constant1_Value;
  } else {
    rtb_ManualSwitch_idx_0 = DC_MotorControl_Encoder_P.Constant3_Value;
    rtb_ManualSwitch_idx_1 = DC_MotorControl_Encoder_P.Constant4_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* MATLABSystem: '<Root>/IN1(input 1)' */
  writeDigitalPin(9, rtb_ManualSwitch_idx_0);

  /* MATLABSystem: '<Root>/IN2(input 2)' */
  writeDigitalPin(4, rtb_ManualSwitch_idx_1);

  /* MATLABSystem: '<Root>/PWM' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  DC_MotorControl_Encoder_DW.obj_ii.PWMDriverObj.MW_PWM_HANDLE =
    MW_PWM_GetHandle(5UL);
  MW_PWM_SetDutyCycle
    (DC_MotorControl_Encoder_DW.obj_ii.PWMDriverObj.MW_PWM_HANDLE, (real_T)
     DC_MotorControl_Encoder_P.Constant2_Value);

  /* MATLABSystem: '<Root>/Encoder' */
  if (DC_MotorControl_Encoder_DW.obj.TunablePropsChanged) {
    DC_MotorControl_Encoder_DW.obj.TunablePropsChanged = false;
  }

  /* MATLABSystem: '<Root>/Encoder' */
  MW_EncoderRead(DC_MotorControl_Encoder_DW.obj.Index,
                 &DC_MotorControl_Encoder_B.Encoder);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  DC_MotorControl_Encoder_M->Timing.taskTime0 =
    ((time_T)(++DC_MotorControl_Encoder_M->Timing.clockTick0)) *
    DC_MotorControl_Encoder_M->Timing.stepSize0;
}

/* Model initialize function */
void DC_MotorControl_Encoder_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(DC_MotorControl_Encoder_M, -1);
  DC_MotorControl_Encoder_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  DC_MotorControl_Encoder_M->Sizes.checksums[0] = (4213582402U);
  DC_MotorControl_Encoder_M->Sizes.checksums[1] = (1162472497U);
  DC_MotorControl_Encoder_M->Sizes.checksums[2] = (3929612552U);
  DC_MotorControl_Encoder_M->Sizes.checksums[3] = (3333221212U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    DC_MotorControl_Encoder_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(DC_MotorControl_Encoder_M->extModeInfo,
      &DC_MotorControl_Encoder_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(DC_MotorControl_Encoder_M->extModeInfo,
                        DC_MotorControl_Encoder_M->Sizes.checksums);
    rteiSetTFinalTicks(DC_MotorControl_Encoder_M->extModeInfo, -1);
  }

  /* Start for MATLABSystem: '<Root>/IN1(input 1)' */
  DC_MotorControl_Encoder_DW.obj_ib.matlabCodegenIsDeleted = false;
  DC_MotorControl_Encoder_DW.obj_ib.isInitialized = 1L;
  digitalIOSetup(9, 1);
  DC_MotorControl_Encoder_DW.obj_ib.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/IN2(input 2)' */
  DC_MotorControl_Encoder_DW.obj_i.matlabCodegenIsDeleted = false;
  DC_MotorControl_Encoder_DW.obj_i.isInitialized = 1L;
  digitalIOSetup(4, 1);
  DC_MotorControl_Encoder_DW.obj_i.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/PWM' */
  DC_MotorControl_Encoder_DW.obj_ii.matlabCodegenIsDeleted = false;
  DC_MotorControl_Encoder_DW.obj_ii.isInitialized = 1L;
  DC_MotorControl_Encoder_DW.obj_ii.PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(5UL,
    0.0, 0.0);
  DC_MotorControl_Encoder_DW.obj_ii.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Encoder' */
  DC_MotorControl_Encoder_DW.obj.Index = 0U;
  DC_MotorControl_Encoder_DW.obj.matlabCodegenIsDeleted = false;
  DC_MotorControl_Encoder_DW.obj.isInitialized = 1L;
  MW_EncoderSetup(2UL, 3UL, &DC_MotorControl_Encoder_DW.obj.Index);
  DC_MotorControl_Encoder_DW.obj.isSetupComplete = true;
  DC_MotorControl_Encoder_DW.obj.TunablePropsChanged = false;

  /* InitializeConditions for MATLABSystem: '<Root>/Encoder' */
  MW_EncoderReset(DC_MotorControl_Encoder_DW.obj.Index);
}

/* Model terminate function */
void DC_MotorControl_Encoder_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/IN1(input 1)' */
  if (!DC_MotorControl_Encoder_DW.obj_ib.matlabCodegenIsDeleted) {
    DC_MotorControl_Encoder_DW.obj_ib.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/IN1(input 1)' */

  /* Terminate for MATLABSystem: '<Root>/IN2(input 2)' */
  if (!DC_MotorControl_Encoder_DW.obj_i.matlabCodegenIsDeleted) {
    DC_MotorControl_Encoder_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/IN2(input 2)' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  if (!DC_MotorControl_Encoder_DW.obj_ii.matlabCodegenIsDeleted) {
    DC_MotorControl_Encoder_DW.obj_ii.matlabCodegenIsDeleted = true;
    if ((DC_MotorControl_Encoder_DW.obj_ii.isInitialized == 1L) &&
        DC_MotorControl_Encoder_DW.obj_ii.isSetupComplete) {
      DC_MotorControl_Encoder_DW.obj_ii.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(5UL);
      MW_PWM_SetDutyCycle
        (DC_MotorControl_Encoder_DW.obj_ii.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      DC_MotorControl_Encoder_DW.obj_ii.PWMDriverObj.MW_PWM_HANDLE =
        MW_PWM_GetHandle(5UL);
      MW_PWM_Close(DC_MotorControl_Encoder_DW.obj_ii.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */

  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!DC_MotorControl_Encoder_DW.obj.matlabCodegenIsDeleted) {
    DC_MotorControl_Encoder_DW.obj.matlabCodegenIsDeleted = true;
    if ((DC_MotorControl_Encoder_DW.obj.isInitialized == 1L) &&
        DC_MotorControl_Encoder_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
