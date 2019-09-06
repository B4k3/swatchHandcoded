/*
 * File: SWatchCB.h
 *
 * Code generated for Simulink model 'SWatchCB'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Mon Nov 30 14:02:29 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWatchCB_h_
#define RTW_HEADER_SWatchCB_h_
#include <string.h>
#include <stddef.h>
#ifndef SWatchCB_COMMON_INCLUDES_
# define SWatchCB_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SWatchCB_COMMON_INCLUDES_ */

#include "SWatchCB_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* Block signals (auto storage) */
typedef struct {
  boolean_T DataTypeConversion;        /* '<S1>/Data Type Conversion' */
  boolean_T button_read;               /* '<S1>/button_read' */
  boolean_T button_read1;              /* '<S1>/button_read1' */
  boolean_T button_read2;              /* '<S1>/button_read2' */
  boolean_T button_read5;              /* '<S1>/button_read5' */
  boolean_T button_read4;              /* '<S1>/button_read4' */
  boolean_T button_read3;              /* '<S1>/button_read3' */
} B_SWatchCB_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int32_T sfEvent;                     /* '<S1>/SWatch' */
  int_T button_read_IWORK;             /* '<S1>/button_read' */
  int_T button_read1_IWORK;            /* '<S1>/button_read1' */
  int_T button_read2_IWORK;            /* '<S1>/button_read2' */
  int_T button_read5_IWORK;            /* '<S1>/button_read5' */
  int_T button_read4_IWORK;            /* '<S1>/button_read4' */
  int_T button_read3_IWORK;            /* '<S1>/button_read3' */
  uint8_T Output_DSTATE;               /* '<S2>/Output' */
  uint8_T is_Control;                  /* '<S1>/SWatch' */
  uint8_T is_active_Control;           /* '<S1>/SWatch' */
  uint8_T is_TimeCount;                /* '<S1>/SWatch' */
  uint8_T is_active_TimeCount;         /* '<S1>/SWatch' */
  uint8_T is_active_AlarmMng;          /* '<S1>/SWatch' */
  uint8_T hours;                       /* '<S1>/SWatch' */
  uint8_T minutes;                     /* '<S1>/SWatch' */
  uint8_T seconds;                     /* '<S1>/SWatch' */
  uint8_T tenths;                      /* '<S1>/SWatch' */
} DW_SWatchCB_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState SWatch_Trig_ZCE[7];       /* '<S1>/SWatch' */
} PrevZCX_SWatchCB_T;

/* Real-time Model Data Structure */
struct tag_RTM_SWatchCB_T {
  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    B_SWatchCB_T *blockIO;
    PrevZCX_SWatchCB_T *prevZCSigState;
    DW_SWatchCB_T *dwork;
  } ModelData;
};

/* Model entry point functions */
extern void SWatchCB_initialize(RT_MODEL_SWatchCB_T *const SWatchCB_M, uint8_T
  *SWatchCB_Y_hours, uint8_T *SWatchCB_Y_minutes, uint8_T *SWatchCB_Y_seconds,
  uint8_T *SWatchCB_Y_tenths, uint8_T *SWatchCB_Y_mode);
extern void SWatchCB_step(RT_MODEL_SWatchCB_T *const SWatchCB_M, uint8_T
  *SWatchCB_Y_hours, uint8_T *SWatchCB_Y_minutes, uint8_T *SWatchCB_Y_seconds,
  uint8_T *SWatchCB_Y_tenths, uint8_T *SWatchCB_Y_mode);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('NewWatchCB_Gen/SWatchCB')    - opens subsystem NewWatchCB_Gen/SWatchCB
 * hilite_system('NewWatchCB_Gen/SWatchCB/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'NewWatchCB_Gen'
 * '<S1>'   : 'NewWatchCB_Gen/SWatchCB'
 * '<S2>'   : 'NewWatchCB_Gen/SWatchCB/Counter Limited'
 * '<S3>'   : 'NewWatchCB_Gen/SWatchCB/SWatch'
 * '<S4>'   : 'NewWatchCB_Gen/SWatchCB/Counter Limited/Increment Real World'
 * '<S5>'   : 'NewWatchCB_Gen/SWatchCB/Counter Limited/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_SWatchCB_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
