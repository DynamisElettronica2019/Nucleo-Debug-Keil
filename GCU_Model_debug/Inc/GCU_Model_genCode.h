/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: GCU_Model_genCode.h
 *
 * Code generated for Simulink model 'GCU_Model_genCode'.
 *
 * Model version                  : 1.44
 * Simulink Coder version         : 8.14 (R2018a) 06-Feb-2018
 * C/C++ source code generated on : Mon Apr  1 11:41:47 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_GCU_Model_genCode_h_
#define RTW_HEADER_GCU_Model_genCode_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#ifndef GCU_Model_genCode_COMMON_INCLUDES_
# define GCU_Model_genCode_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* GCU_Model_genCode_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

#ifndef DEFINED_TYPEDEF_FOR_aac_params_
#define DEFINED_TYPEDEF_FOR_aac_params_

typedef enum {
  RAMP_START = 0,                      /* Default value */
  RAMP_END,
  RAMP_TIME,
  RPM_LIMIT_1_2,
  RPM_LIMIT_2_3,
  RPM_LIMIT_3_4,
  RPM_LIMIT_4_5,
  SPEED_LIMIT_1_2,
  SPEED_LIMIT_2_3,
  SPEED_LIMIT_3_4,
  SPEED_LIMIT_4_5
} aac_params;

#endif

#ifndef DEFINED_TYPEDEF_FOR_aac_values_
#define DEFINED_TYPEDEF_FOR_aac_values_

typedef enum {
  RPM = 0,                             /* Default value */
  WHEEL_SPEED,
  APPS
} aac_values;

#endif

#ifndef DEFINED_TYPEDEF_FOR_timings_
#define DEFINED_TYPEDEF_FOR_timings_

typedef enum {
  DEFAULT_DELAY = 20,                  /* Default value */
  DEFAULT_UP_REBOUND = 15,
  DEFAULT_UP_BRAKE = 20,
  DEFAULT_UP_PUSH_1_2 = 115,
  DEFAULT_UP_PUSH_2_3 = 100,
  DEFAULT_UP_PUSH_3_4 = 100,
  DEFAULT_UP_PUSH_4_5 = 100,
  DEFAULT_CLUTCH = 70,
  DEFAULT_DN_PUSH = 100,
  DEFAULT_DN_BRAKE = 15,
  DEFAULT_DN_REBOUND = 20,
  DEFAULT_NT_CLUTCH_DELAY = 20,
  DEFAULT_NT_REBOUND_1_N = 15,
  DEFAULT_NT_REBOUND_2_N = 15,
  DEFAULT_NT_BRAKE_1_N = 35,
  DEFAULT_NT_BRAKE_2_N = 35,
  DEFAULT_NT_PUSH_1_N = 22,
  DEFAULT_NT_PUSH_2_N = 25,
  DEFAULT_NT_CLUTCH_1_N = 300,
  DEFAULT_NT_CLUTCH_2_N = 300,
  DEFAULT_DOWN_TIME_CHECK = 500,
  DEFAULT_UP_TIME_CHECK = 500,
  DEFAULT_MAX_TRIES = 2
} timings;

#endif

/* Block signals and states (default storage) for system '<S2>/TractionValue' */
typedef struct {
  uint16_T Divide;                     /* '<S11>/Divide' */
  uint16_T UnitDelay_DSTATE;           /* '<S11>/Unit Delay' */
  uint8_T PackCanUart[10];             /* '<S14>/PackCanUart' */
  uint8_T PackCanUart_g[10];           /* '<S15>/PackCanUart' */
} DW_TractionValue;

/* Block signals and states (default storage) for system '<S9>/Efi_setRpmLimiter' */
typedef struct {
  uint8_T EfiSetRPMLimiter;            /* '<S12>/Efi SetRPMLimiter' */
} DW_Efi_setRpmLimiter;

/* Block signals and states (default storage) for system '<S9>/Efi_unsetRpmLimiter' */
typedef struct {
  uint8_T EfiUnSetRPMLimiter;          /* '<S13>/Efi UnSetRPMLimiter' */
} DW_Efi_unsetRpmLimiter;

/* Block signals and states (default storage) for system '<S2>/AAC_ExternalValues' */
typedef struct {
  uint16_T UnitDelay_DSTATE[3];        /* '<S8>/Unit Delay' */
} DW_AAC_ExternalValues;

/* Block signals and states (default storage) for system '<S17>/SetCut' */
typedef struct {
  uint8_T EfiSetBlip;                  /* '<S24>/Efi SetBlip' */
} DW_SetCut;

/* Block signals and states (default storage) for system '<S17>/UnsetCut' */
typedef struct {
  uint8_T EfiUnSetBlip;                /* '<S26>/Efi UnSetBlip' */
} DW_UnsetCut;

/* Block signals and states (default storage) for system '<S20>/Gearmotor_turnRight' */
typedef struct {
  uint8_T GearMotorTurnRight_o1;       /* '<S34>/GearMotor Turn Right' */
  uint8_T GearMotorTurnRight_o2;       /* '<S34>/GearMotor Turn Right' */
  uint8_T GearMotorTurnRight_o3;       /* '<S34>/GearMotor Turn Right' */
} DW_Gearmotor_turnRight;

/* Block signals and states (default storage) for system '<S20>/Gearmotor_brake' */
typedef struct {
  uint8_T GearMotorBrake_o1;           /* '<S31>/GearMotor Brake' */
  uint8_T GearMotorBrake_o2;           /* '<S31>/GearMotor Brake' */
  uint8_T GearMotorBrake_o3;           /* '<S31>/GearMotor Brake' */
} DW_Gearmotor_brake;

/* Block signals and states (default storage) for system '<S18>/EngineControl_Start' */
typedef struct {
  uint8_T EngineControlStart;          /* '<S28>/EngineControl Start' */
} DW_EngineControl_Start;

/* Block signals and states (default storage) for system '<S19>/sendUpdatesSW' */
typedef struct {
  uint8_T PackCanUart[10];             /* '<S30>/PackCanUart' */
} DW_sendUpdatesSW;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  DW_sendUpdatesSW sendUpdatesSW_e;    /* '<S19>/sendUpdatesSW' */
  DW_EngineControl_Start EngineControl_Start_h;/* '<S18>/EngineControl_Start' */
  DW_Gearmotor_brake Gearmotor_brake_c;/* '<S20>/Gearmotor_brake' */
  DW_Gearmotor_turnRight Gearmotor_turnRight_f;/* '<S20>/Gearmotor_turnRight' */
  DW_UnsetCut UnsetRPMLimiter_c;       /* '<S17>/UnsetRPMLimiter' */
  DW_SetCut SetRPMLimiter_e;           /* '<S17>/SetRPMLimiter' */
  DW_UnsetCut UnsetCut_i;              /* '<S17>/UnsetCut' */
  DW_SetCut SetCut_p;                  /* '<S17>/SetCut' */
  DW_AAC_ExternalValues AAC_ExternalValues_f;/* '<S2>/AAC_ExternalValues' */
  DW_Efi_unsetRpmLimiter Efi_unsetRpmLimiter_f;/* '<S9>/Efi_unsetRpmLimiter' */
  DW_Efi_setRpmLimiter Efi_setRpmLimiter_b;/* '<S9>/Efi_setRpmLimiter' */
  DW_TractionValue TractionValue_h;    /* '<S2>/TractionValue' */
  real_T message;                      /* '<S5>/AccelerationRoutine' */
  real_T count;                        /* '<S5>/AccelerationRoutine' */
  real_T aac_clutchValue;              /* '<S3>/GCULogic' */
  real_T aac_clutchStep;               /* '<S3>/GCULogic' */
  int32_T aac_parameters[11];          /* '<S3>/GCULogic' */
  int32_T sfEvent;                     /* '<S3>/GCULogic' */
  int32_T aac_dtRelease;               /* '<S3>/GCULogic' */
  int32_T ticksCounter;                /* '<S3>/GCULogic' */
  uint32_T alive;                      /* '<S3>/GCULogic' */
  uint16_T RateTransition1[3];         /* '<Root>/Rate Transition1' */
  uint16_T RateTransition2[2];         /* '<Root>/Rate Transition2' */
  uint16_T RateTransition4[2];         /* '<Root>/Rate Transition4' */
  uint16_T RateTransition8[2];         /* '<Root>/Rate Transition8' */
  uint16_T shiftCommand[2];            /* '<S2>/MessageEvaluation' */
  uint16_T aacCommand[2];              /* '<S2>/MessageEvaluation' */
  uint16_T modeCommand[2];             /* '<S2>/MessageEvaluation' */
  uint16_T Assignment[3];              /* '<S8>/Assignment' */
  uint16_T TmpSignalConversionAtPack_Uart_[10];
  volatile uint16_T RateTransition1_Buffer[6];/* '<Root>/Rate Transition1' */
  volatile uint16_T RateTransition2_Buffer[4];/* '<Root>/Rate Transition2' */
  volatile uint16_T RateTransition4_Buffer[4];/* '<Root>/Rate Transition4' */
  volatile uint16_T RateTransition8_Buffer[4];/* '<Root>/Rate Transition8' */
  volatile uint16_T RateTransition11_Buffer0[3];/* '<Root>/Rate Transition11' */
  volatile uint16_T RateTransition14_Buffer0[2];/* '<Root>/Rate Transition14' */
  volatile uint16_T RateTransition17_Buffer0[2];/* '<Root>/Rate Transition17' */
  uint16_T id;                         /* '<S5>/AccelerationRoutine' */
  uint16_T firstInt;                   /* '<S5>/AccelerationRoutine' */
  uint16_T secondInt;                  /* '<S5>/AccelerationRoutine' */
  uint16_T accFb;                      /* '<S3>/GCULogic' */
  uint16_T valCode;                    /* '<S3>/GCULogic' */
  uint16_T value;                      /* '<S3>/GCULogic' */
  uint16_T UnpackCanUart_o1;           /* '<S2>/UnpackCanUart' */
  uint16_T UnpackCanUart_o2;           /* '<S2>/UnpackCanUart' */
  uint16_T UnpackCanUart_o3;           /* '<S2>/UnpackCanUart' */
  uint16_T UnpackCanUart_o4;           /* '<S2>/UnpackCanUart' */
  uint16_T UnpackCanUart_o5;           /* '<S2>/UnpackCanUart' */
  uint16_T currGear;                   /* '<S2>/MessageEvaluation' */
  uint16_T Assignment_e;               /* '<S11>/Assignment' */
  uint16_T rpm;                        /* '<S5>/AccelerationRoutine' */
  uint16_T wheelSpeed;                 /* '<S5>/AccelerationRoutine' */
  uint16_T currGear_m;                 /* '<S5>/AccelerationRoutine' */
  uint16_T lastAacCom;                 /* '<S3>/GCULogic' */
  uint16_T lastShiftCom;               /* '<S3>/GCULogic' */
  uint16_T lastModeCom;                /* '<S3>/GCULogic' */
  uint16_T aacCounter;                 /* '<S3>/GCULogic' */
  volatile int8_T RateTransition1_ActiveBufIdx;/* '<Root>/Rate Transition1' */
  volatile int8_T RateTransition2_ActiveBufIdx;/* '<Root>/Rate Transition2' */
  volatile int8_T RateTransition4_ActiveBufIdx;/* '<Root>/Rate Transition4' */
  volatile int8_T RateTransition5_ActiveBufIdx;/* '<Root>/Rate Transition5' */
  volatile int8_T RateTransition8_ActiveBufIdx;/* '<Root>/Rate Transition8' */
  volatile int8_T RateTransition11_semaphoreTaken;/* '<Root>/Rate Transition11' */
  volatile int8_T RateTransition14_semaphoreTaken;/* '<Root>/Rate Transition14' */
  volatile int8_T RateTransition17_semaphoreTaken;/* '<Root>/Rate Transition17' */
  volatile int8_T RateTransition15_semaphoreTaken;/* '<Root>/Rate Transition15' */
  uint8_T RateTransition5[2];          /* '<Root>/Rate Transition5' */
  uint8_T MultiportSwitch[10];         /* '<Root>/Multiport Switch' */
  uint8_T PackCanUart[10];             /* '<S5>/PackCanUart' */
  uint8_T clutchCommand[2];            /* '<S2>/MessageEvaluation' */
  uint8_T Pack_Uart_Message1[20];      /* '<S1>/Pack_Uart_Message1' */
  volatile uint8_T RateTransition5_Buffer[4];/* '<Root>/Rate Transition5' */
  volatile uint8_T RateTransition15_Buffer0[2];/* '<Root>/Rate Transition15' */
  uint8_T RateTransition;              /* '<Root>/Rate Transition' */
  uint8_T RateTransition3;             /* '<Root>/Rate Transition3' */
  uint8_T RateTransition7;             /* '<Root>/Rate Transition7' */
  uint8_T RateTransition6;             /* '<Root>/Rate Transition6' */
  uint8_T Cast_a;                      /* '<Root>/Cast' */
  uint8_T Merge2;                      /* '<S17>/Merge2' */
  uint8_T Pin_H;                       /* '<S20>/Pin_H' */
  uint8_T Pin_In1;                     /* '<S20>/Pin_In1' */
  uint8_T clutchCurrVal;               /* '<S3>/GCULogic' */
  uint8_T EngineControlStop;           /* '<S29>/EngineControl Stop' */
  uint8_T GearMotorTurnLeft_o1;        /* '<S33>/GearMotor Turn Left' */
  uint8_T GearMotorTurnLeft_o2;        /* '<S33>/GearMotor Turn Left' */
  uint8_T GearMotorTurnLeft_o3;        /* '<S33>/GearMotor Turn Left' */
  uint8_T GearMotorRelease;            /* '<S32>/GearMotor Release' */
  uint8_T Minus;                       /* '<S22>/Minus' */
  uint8_T startEngCommand;             /* '<S2>/MessageEvaluation' */
  volatile uint8_T RateTransition_Buffer0;/* '<Root>/Rate Transition' */
  volatile uint8_T RateTransition3_Buffer0;/* '<Root>/Rate Transition3' */
  volatile uint8_T RateTransition_Buffer0_g;/* '<S7>/Rate Transition' */
  uint8_T is_c3_GCU_Model_genCode;     /* '<S5>/AccelerationRoutine' */
  uint8_T lastGearPin;                 /* '<S5>/AccelerationRoutine' */
  uint8_T is_active_c1_GCU_Model_genCode;/* '<S3>/GCULogic' */
  uint8_T is_MODES;                    /* '<S3>/GCULogic' */
  uint8_T is_active_MODES;             /* '<S3>/GCULogic' */
  uint8_T is_ACCELERATION;             /* '<S3>/GCULogic' */
  uint8_T is_AAC;                      /* '<S3>/GCULogic' */
  uint8_T is_ACTIVE;                   /* '<S3>/GCULogic' */
  uint8_T is_NEUTRAL_STATE;            /* '<S3>/GCULogic' */
  uint8_T is_active_NEUTRAL_STATE;     /* '<S3>/GCULogic' */
  uint8_T is_GEARSHIFT;                /* '<S3>/GCULogic' */
  uint8_T is_active_GEARSHIFT;         /* '<S3>/GCULogic' */
  uint8_T is_UPSHIFTING;               /* '<S3>/GCULogic' */
  uint8_T is_UP_REBOUND;               /* '<S3>/GCULogic' */
  uint8_T is_UP_PUSH;                  /* '<S3>/GCULogic' */
  uint8_T is_UP_START;                 /* '<S3>/GCULogic' */
  uint8_T is_DOWNSHIFTING;             /* '<S3>/GCULogic' */
  uint8_T is_DOWN_START;               /* '<S3>/GCULogic' */
  uint8_T is_DOWN_BRAKE;               /* '<S3>/GCULogic' */
  uint8_T is_START_ENGINE;             /* '<S3>/GCULogic' */
  uint8_T is_active_START_ENGINE;      /* '<S3>/GCULogic' */
  uint8_T lastShift;                   /* '<S3>/GCULogic' */
  uint8_T lastClutchCom;               /* '<S3>/GCULogic' */
  uint8_T lastCom;                     /* '<S3>/GCULogic' */
  uint8_T startCounter;                /* '<S3>/GCULogic' */
  uint8_T is_active_c2_GCU_Model_genCode;/* '<S2>/MessageEvaluation' */
  uint8_T is_c2_GCU_Model_genCode;     /* '<S2>/MessageEvaluation' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Triggered_Subsystem1_Trig_ZCE;/* '<S7>/Triggered_Subsystem1' */
  ZCSigState Triggered_Subsystem_Trig_ZCE;/* '<S7>/Triggered_Subsystem' */
} PrevZCX;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: GCU_TRACTION_CONTROL_EFI_ID_Val
   * Referenced by: '<S14>/GCU_TRACTION_CONTROL_EFI_ID'
   */
  uint16_T GCU_TRACTION_CONTROL_EFI_ID_Val;

  /* Pooled Parameter (Expression: 793)
   * Referenced by:
   *   '<S15>/GCU_FEEDBACK_ID'
   *   '<S30>/GCU_FEEDBACK_ID'
   */
  uint16_T pooled2;

  /* Computed Parameter: TRACTION_CODE_Value
   * Referenced by: '<S11>/TRACTION_CODE'
   */
  uint16_T TRACTION_CODE_Value;
} ConstP;

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint8_T UART_debug[10];              /* '<Root>/UART_debug' */
  real_T SelectMode;                   /* '<Root>/SelectMode' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T debugValues[10];            /* '<Root>/debugValues  ' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* External data declarations for dependent source files */
extern const uint16_T GCU_Model_genCode_U16GND;/* uint16_T ground */

/* Constant parameters (default storage) */
extern const ConstP rtConstP;

/* Model entry point functions */
extern void GCU_Model_genCode_initialize(void);
extern void GCU_Model_genCode_step0(void);
extern void GCU_Model_genCode_step1(void);
extern void GCU_Model_genCode_step2(void);
extern void GCU_Model_genCode_step3(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope1' : Unused code path elimination
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
 * '<Root>' : 'GCU_Model_genCode'
 * '<S1>'   : 'GCU_Model_genCode/Debug '
 * '<S2>'   : 'GCU_Model_genCode/GCU_CAN'
 * '<S3>'   : 'GCU_Model_genCode/GCU_timer'
 * '<S4>'   : 'GCU_Model_genCode/Initialize Function'
 * '<S5>'   : 'GCU_Model_genCode/Simulink_Debug'
 * '<S6>'   : 'GCU_Model_genCode/Triggered Subsystem'
 * '<S7>'   : 'GCU_Model_genCode/rpmPin_update'
 * '<S8>'   : 'GCU_Model_genCode/GCU_CAN/AAC_ExternalValues'
 * '<S9>'   : 'GCU_Model_genCode/GCU_CAN/EfiRPMLimiter'
 * '<S10>'  : 'GCU_Model_genCode/GCU_CAN/MessageEvaluation'
 * '<S11>'  : 'GCU_Model_genCode/GCU_CAN/TractionValue'
 * '<S12>'  : 'GCU_Model_genCode/GCU_CAN/EfiRPMLimiter/Efi_setRpmLimiter'
 * '<S13>'  : 'GCU_Model_genCode/GCU_CAN/EfiRPMLimiter/Efi_unsetRpmLimiter'
 * '<S14>'  : 'GCU_Model_genCode/GCU_CAN/TractionValue/Efi_setTraction'
 * '<S15>'  : 'GCU_Model_genCode/GCU_CAN/TractionValue/sendUpdatesSW'
 * '<S16>'  : 'GCU_Model_genCode/GCU_timer/ClutchMotor'
 * '<S17>'  : 'GCU_Model_genCode/GCU_timer/Efi'
 * '<S18>'  : 'GCU_Model_genCode/GCU_timer/EngineControl'
 * '<S19>'  : 'GCU_Model_genCode/GCU_timer/GCULogic'
 * '<S20>'  : 'GCU_Model_genCode/GCU_timer/GearMotor1'
 * '<S21>'  : 'GCU_Model_genCode/GCU_timer/ClutchMotor/ClutchMotor Init '
 * '<S22>'  : 'GCU_Model_genCode/GCU_timer/ClutchMotor/ClutchMotor SetPosition '
 * '<S23>'  : 'GCU_Model_genCode/GCU_timer/Efi/Init'
 * '<S24>'  : 'GCU_Model_genCode/GCU_timer/Efi/SetCut'
 * '<S25>'  : 'GCU_Model_genCode/GCU_timer/Efi/SetRPMLimiter'
 * '<S26>'  : 'GCU_Model_genCode/GCU_timer/Efi/UnsetCut'
 * '<S27>'  : 'GCU_Model_genCode/GCU_timer/Efi/UnsetRPMLimiter'
 * '<S28>'  : 'GCU_Model_genCode/GCU_timer/EngineControl/EngineControl_Start'
 * '<S29>'  : 'GCU_Model_genCode/GCU_timer/EngineControl/EngineControl_Stop'
 * '<S30>'  : 'GCU_Model_genCode/GCU_timer/GCULogic/sendUpdatesSW'
 * '<S31>'  : 'GCU_Model_genCode/GCU_timer/GearMotor1/Gearmotor_brake'
 * '<S32>'  : 'GCU_Model_genCode/GCU_timer/GearMotor1/Gearmotor_release'
 * '<S33>'  : 'GCU_Model_genCode/GCU_timer/GearMotor1/Gearmotor_turnLeft'
 * '<S34>'  : 'GCU_Model_genCode/GCU_timer/GearMotor1/Gearmotor_turnRight'
 * '<S35>'  : 'GCU_Model_genCode/Simulink_Debug/AccelerationRoutine'
 * '<S36>'  : 'GCU_Model_genCode/rpmPin_update/Triggered_Subsystem'
 * '<S37>'  : 'GCU_Model_genCode/rpmPin_update/Triggered_Subsystem1'
 */
#endif                                 /* RTW_HEADER_GCU_Model_genCode_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
