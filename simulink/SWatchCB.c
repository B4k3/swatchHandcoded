/*
 * File: SWatchCB.c
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

#include "SWatchCB.h"
#include "SWatchCB_private.h"

/* Named constants for Chart: '<S1>/SWatch' */
#define SWatchCB_IN_alarmmode          ((uint8_T)1U)
#define SWatchCB_IN_swatchmode         ((uint8_T)2U)
#define SWatchCB_IN_timecount          ((uint8_T)1U)
#define SWatchCB_IN_timemode           ((uint8_T)3U)
#define SWatchCB_IN_timesetmode        ((uint8_T)4U)
#define SWatchCB_event_Balarm          (5)
#define SWatchCB_event_Bminus          (2)
#define SWatchCB_event_Bplus           (1)
#define SWatchCB_event_Bstop           (6)
#define SWatchCB_event_Btime           (3)
#define SWatchCB_event_Btimeset        (4)
#define SWatchCB_event_tick            (0)

/* user code (top of source file) */
#include "Event.h"
#include "WidgetConfig.h"

/* Forward declaration for local functions */
static void SWatchCB_chartstep_c3_SWatchCB(uint8_T *SWatchCB_Y_hours, uint8_T
  *SWatchCB_Y_minutes, uint8_T *SWatchCB_Y_seconds, uint8_T *SWatchCB_Y_tenths,
  uint8_T *SWatchCB_Y_mode, DW_SWatchCB_T *SWatchCB_DW);

/* Function for Chart: '<S1>/SWatch' */
static void SWatchCB_chartstep_c3_SWatchCB(uint8_T *SWatchCB_Y_hours, uint8_T
  *SWatchCB_Y_minutes, uint8_T *SWatchCB_Y_seconds, uint8_T *SWatchCB_Y_tenths,
  uint8_T *SWatchCB_Y_mode, DW_SWatchCB_T *SWatchCB_DW)
{
  boolean_T guard1 = false;
  int32_T tmp;

  /* During: SWatchCB/SWatch */
  /* During 'Control': '<S3>:13' */
  if (SWatchCB_DW->sfEvent == SWatchCB_event_Btime) {
    /* Transition: '<S3>:45' */
    /* Exit Internal 'Control': '<S3>:13' */
    SWatchCB_DW->is_Control = SWatchCB_IN_timemode;

    /* Entry 'timemode': '<S3>:23' */
    *SWatchCB_Y_mode = 0U;
  } else {
    switch (SWatchCB_DW->is_Control) {
     case SWatchCB_IN_alarmmode:
      /* During 'alarmmode': '<S3>:39' */
      if (SWatchCB_DW->sfEvent == SWatchCB_event_Btimeset) {
        /* Transition: '<S3>:44' */
        SWatchCB_DW->is_Control = SWatchCB_IN_timesetmode;

        /* Entry 'timesetmode': '<S3>:24' */
        *SWatchCB_Y_mode = 1U;
      } else {
        if (SWatchCB_DW->sfEvent == SWatchCB_event_Bstop) {
          /* Transition: '<S3>:49' */
          SWatchCB_DW->is_Control = SWatchCB_IN_swatchmode;

          /* Entry 'swatchmode': '<S3>:40' */
          *SWatchCB_Y_mode = 3U;
        }
      }
      break;

     case SWatchCB_IN_swatchmode:
      /* During 'swatchmode': '<S3>:40' */
      if (SWatchCB_DW->sfEvent == SWatchCB_event_Btimeset) {
        /* Transition: '<S3>:43' */
        SWatchCB_DW->is_Control = SWatchCB_IN_timesetmode;

        /* Entry 'timesetmode': '<S3>:24' */
        *SWatchCB_Y_mode = 1U;
      } else if (SWatchCB_DW->sfEvent == SWatchCB_event_Balarm) {
        /* Transition: '<S3>:46' */
        SWatchCB_DW->is_Control = SWatchCB_IN_alarmmode;

        /* Entry 'alarmmode': '<S3>:39' */
        *SWatchCB_Y_mode = 2U;
      } else {
        if (SWatchCB_DW->sfEvent == SWatchCB_event_tick) {
          /* Transition: '<S3>:59' */
          *SWatchCB_Y_tenths = SWatchCB_DW->tenths;
        }
      }
      break;

     case SWatchCB_IN_timemode:
      /* During 'timemode': '<S3>:23' */
      if (SWatchCB_DW->sfEvent == SWatchCB_event_Btimeset) {
        /* Transition: '<S3>:26' */
        SWatchCB_DW->is_Control = SWatchCB_IN_timesetmode;

        /* Entry 'timesetmode': '<S3>:24' */
        *SWatchCB_Y_mode = 1U;
      } else if (SWatchCB_DW->sfEvent == SWatchCB_event_Balarm) {
        /* Transition: '<S3>:48' */
        SWatchCB_DW->is_Control = SWatchCB_IN_alarmmode;

        /* Entry 'alarmmode': '<S3>:39' */
        *SWatchCB_Y_mode = 2U;
      } else if (SWatchCB_DW->sfEvent == SWatchCB_event_Bstop) {
        /* Transition: '<S3>:50' */
        SWatchCB_DW->is_Control = SWatchCB_IN_swatchmode;

        /* Entry 'swatchmode': '<S3>:40' */
        *SWatchCB_Y_mode = 3U;
      } else {
        if (SWatchCB_DW->sfEvent == SWatchCB_event_tick) {
          /* Transition: '<S3>:58' */
          *SWatchCB_Y_hours = SWatchCB_DW->hours;
          *SWatchCB_Y_minutes = SWatchCB_DW->minutes;
          *SWatchCB_Y_seconds = SWatchCB_DW->seconds;
        }
      }
      break;

     default:
      /* During 'timesetmode': '<S3>:24' */
      if (SWatchCB_DW->sfEvent == SWatchCB_event_Balarm) {
        /* Transition: '<S3>:47' */
        SWatchCB_DW->is_Control = SWatchCB_IN_alarmmode;

        /* Entry 'alarmmode': '<S3>:39' */
        *SWatchCB_Y_mode = 2U;
      } else {
        if (SWatchCB_DW->sfEvent == SWatchCB_event_Bstop) {
          /* Transition: '<S3>:51' */
          SWatchCB_DW->is_Control = SWatchCB_IN_swatchmode;

          /* Entry 'swatchmode': '<S3>:40' */
          *SWatchCB_Y_mode = 3U;
        }
      }
      break;
    }
  }

  /* During 'TimeCount': '<S3>:14' */
  /* During 'timecount': '<S3>:17' */
  if (SWatchCB_DW->sfEvent == SWatchCB_event_tick) {
    /* Transition: '<S3>:21' */
    tmp = (int32_T)(SWatchCB_DW->tenths + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    SWatchCB_DW->tenths = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)((uint8_T)
      tmp / 10U * 10U));
    if (SWatchCB_DW->tenths == 0) {
      /* Transition: '<S3>:29' */
      tmp = (int32_T)(SWatchCB_DW->seconds + 1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      SWatchCB_DW->seconds = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
        ((uint8_T)tmp / 60U * 60U));
      if (SWatchCB_DW->seconds == 0) {
        /* Transition: '<S3>:32' */
        tmp = (int32_T)(SWatchCB_DW->minutes + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        SWatchCB_DW->minutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
          ((uint8_T)tmp / 60U * 60U));
        if (SWatchCB_DW->minutes == 0) {
          /* Transition: '<S3>:37' */
          tmp = (int32_T)(SWatchCB_DW->hours + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          SWatchCB_DW->hours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 24U * 24U));

          /* Transition: '<S3>:38' */
          SWatchCB_DW->is_TimeCount = SWatchCB_IN_timecount;
        } else {
          /* Transition: '<S3>:33' */
          guard1 = true;
        }
      } else {
        /* Transition: '<S3>:30' */
        guard1 = true;
      }
    } else {
      /* Transition: '<S3>:22' */
      guard1 = true;
    }

    if (guard1) {
      /* Transition: '<S3>:35' */
      SWatchCB_DW->is_TimeCount = SWatchCB_IN_timecount;
    }
  }

  /* During 'AlarmMng': '<S3>:15' */
}

/* Model step function */
void SWatchCB_step(RT_MODEL_SWatchCB_T *const SWatchCB_M, uint8_T
                   *SWatchCB_Y_hours, uint8_T *SWatchCB_Y_minutes, uint8_T
                   *SWatchCB_Y_seconds, uint8_T *SWatchCB_Y_tenths, uint8_T
                   *SWatchCB_Y_mode)
{
  B_SWatchCB_T *SWatchCB_B = ((B_SWatchCB_T *) SWatchCB_M->ModelData.blockIO);
  DW_SWatchCB_T *SWatchCB_DW = ((DW_SWatchCB_T *) SWatchCB_M->ModelData.dwork);
  PrevZCX_SWatchCB_T *SWatchCB_PrevZCX = ((PrevZCX_SWatchCB_T *)
    SWatchCB_M->ModelData.prevZCSigState);
  uint8_T rtb_FixPtSum1;
  boolean_T zcEvent[7];
  boolean_T tmp;
  int32_T i;
  int8_T rtb_inputevents_idx_1;
  int8_T rtb_inputevents_idx_2;
  int8_T rtb_inputevents_idx_3;
  int8_T rtb_inputevents_idx_4;
  int8_T rtb_inputevents_idx_5;
  int8_T rtb_inputevents_idx_6;

  /* UnitDelay: '<S2>/Output' */
  rtb_FixPtSum1 = SWatchCB_DW->Output_DSTATE;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  UnitDelay: '<S2>/Output'
   */
  SWatchCB_B->DataTypeConversion = (SWatchCB_DW->Output_DSTATE != 0);

  /* S-Function Block: <S1>/button_read */
  /* Button event name PLUS */
  SWatchCB_B->button_read = IsEvent( PLUS );

  /* S-Function Block: <S1>/button_read1 */
  /* Button event name MINUS */
  SWatchCB_B->button_read1 = IsEvent( MINUS );

  /* S-Function Block: <S1>/button_read2 */
  /* Button event name TIMEMODE */
  SWatchCB_B->button_read2 = IsEvent( TIMEMODE );

  /* S-Function Block: <S1>/button_read5 */
  /* Button event name TIMESETMODE */
  SWatchCB_B->button_read5 = IsEvent( TIMESETMODE );

  /* S-Function Block: <S1>/button_read4 */
  /* Button event name ALARMMODE */
  SWatchCB_B->button_read4 = IsEvent( ALARMMODE );

  /* S-Function Block: <S1>/button_read3 */
  /* Button event name SWATCHMODE */
  SWatchCB_B->button_read3 = IsEvent( SWATCHMODE );

  /* Chart: '<S1>/SWatch' incorporates:
   *  TriggerPort: '<S3>/ input events '
   */
  zcEvent[0] = (((SWatchCB_PrevZCX->SWatch_Trig_ZCE[0] == POS_ZCSIG) !=
                 SWatchCB_B->DataTypeConversion) &&
                (SWatchCB_PrevZCX->SWatch_Trig_ZCE[0] != UNINITIALIZED_ZCSIG));
  zcEvent[1] = (((SWatchCB_PrevZCX->SWatch_Trig_ZCE[1] == POS_ZCSIG) !=
                 SWatchCB_B->button_read) && (SWatchCB_PrevZCX->SWatch_Trig_ZCE
    [1] != UNINITIALIZED_ZCSIG));
  zcEvent[2] = (((SWatchCB_PrevZCX->SWatch_Trig_ZCE[2] == POS_ZCSIG) !=
                 SWatchCB_B->button_read1) && (SWatchCB_PrevZCX->
    SWatch_Trig_ZCE[2] != UNINITIALIZED_ZCSIG));
  zcEvent[3] = (((SWatchCB_PrevZCX->SWatch_Trig_ZCE[3] == POS_ZCSIG) !=
                 SWatchCB_B->button_read2) && (SWatchCB_PrevZCX->
    SWatch_Trig_ZCE[3] != UNINITIALIZED_ZCSIG));
  zcEvent[4] = (((SWatchCB_PrevZCX->SWatch_Trig_ZCE[4] == POS_ZCSIG) !=
                 SWatchCB_B->button_read5) && (SWatchCB_PrevZCX->
    SWatch_Trig_ZCE[4] != UNINITIALIZED_ZCSIG));
  zcEvent[5] = (((SWatchCB_PrevZCX->SWatch_Trig_ZCE[5] == POS_ZCSIG) !=
                 SWatchCB_B->button_read4) && (SWatchCB_PrevZCX->
    SWatch_Trig_ZCE[5] != UNINITIALIZED_ZCSIG));
  zcEvent[6] = (((SWatchCB_PrevZCX->SWatch_Trig_ZCE[6] == POS_ZCSIG) !=
                 SWatchCB_B->button_read3) && (SWatchCB_PrevZCX->
    SWatch_Trig_ZCE[6] != UNINITIALIZED_ZCSIG));
  tmp = false;
  for (i = 0; i < 7; i++) {
    tmp = (tmp || zcEvent[i]);
  }

  if (tmp) {
    rtb_inputevents_idx_1 = (int8_T)(zcEvent[1] ? SWatchCB_B->button_read ?
      RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT);
    rtb_inputevents_idx_2 = (int8_T)(zcEvent[2] ? SWatchCB_B->button_read1 ?
      RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT);
    rtb_inputevents_idx_3 = (int8_T)(zcEvent[3] ? SWatchCB_B->button_read2 ?
      RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT);
    rtb_inputevents_idx_4 = (int8_T)(zcEvent[4] ? SWatchCB_B->button_read5 ?
      RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT);
    rtb_inputevents_idx_5 = (int8_T)(zcEvent[5] ? SWatchCB_B->button_read4 ?
      RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT);
    rtb_inputevents_idx_6 = (int8_T)(zcEvent[6] ? SWatchCB_B->button_read3 ?
      RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT);

    /* Gateway: SWatchCB/SWatch */
    if ((int8_T)(zcEvent[0] ? SWatchCB_B->DataTypeConversion ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      /* Event: '<S3>:1' */
      SWatchCB_DW->sfEvent = SWatchCB_event_tick;
      SWatchCB_chartstep_c3_SWatchCB(SWatchCB_Y_hours, SWatchCB_Y_minutes,
        SWatchCB_Y_seconds, SWatchCB_Y_tenths, SWatchCB_Y_mode, SWatchCB_DW);
    }

    if (rtb_inputevents_idx_1 == 1) {
      /* Event: '<S3>:6' */
      SWatchCB_DW->sfEvent = SWatchCB_event_Bplus;
      SWatchCB_chartstep_c3_SWatchCB(SWatchCB_Y_hours, SWatchCB_Y_minutes,
        SWatchCB_Y_seconds, SWatchCB_Y_tenths, SWatchCB_Y_mode, SWatchCB_DW);
    }

    if (rtb_inputevents_idx_2 == 1) {
      /* Event: '<S3>:7' */
      SWatchCB_DW->sfEvent = SWatchCB_event_Bminus;
      SWatchCB_chartstep_c3_SWatchCB(SWatchCB_Y_hours, SWatchCB_Y_minutes,
        SWatchCB_Y_seconds, SWatchCB_Y_tenths, SWatchCB_Y_mode, SWatchCB_DW);
    }

    if (rtb_inputevents_idx_3 == 1) {
      /* Event: '<S3>:2' */
      SWatchCB_DW->sfEvent = SWatchCB_event_Btime;
      SWatchCB_chartstep_c3_SWatchCB(SWatchCB_Y_hours, SWatchCB_Y_minutes,
        SWatchCB_Y_seconds, SWatchCB_Y_tenths, SWatchCB_Y_mode, SWatchCB_DW);
    }

    if (rtb_inputevents_idx_4 == 1) {
      /* Event: '<S3>:3' */
      SWatchCB_DW->sfEvent = SWatchCB_event_Btimeset;
      SWatchCB_chartstep_c3_SWatchCB(SWatchCB_Y_hours, SWatchCB_Y_minutes,
        SWatchCB_Y_seconds, SWatchCB_Y_tenths, SWatchCB_Y_mode, SWatchCB_DW);
    }

    if (rtb_inputevents_idx_5 == 1) {
      /* Event: '<S3>:4' */
      SWatchCB_DW->sfEvent = SWatchCB_event_Balarm;
      SWatchCB_chartstep_c3_SWatchCB(SWatchCB_Y_hours, SWatchCB_Y_minutes,
        SWatchCB_Y_seconds, SWatchCB_Y_tenths, SWatchCB_Y_mode, SWatchCB_DW);
    }

    if (rtb_inputevents_idx_6 == 1) {
      /* Event: '<S3>:5' */
      SWatchCB_DW->sfEvent = SWatchCB_event_Bstop;
      SWatchCB_chartstep_c3_SWatchCB(SWatchCB_Y_hours, SWatchCB_Y_minutes,
        SWatchCB_Y_seconds, SWatchCB_Y_tenths, SWatchCB_Y_mode, SWatchCB_DW);
    }
  }

  SWatchCB_PrevZCX->SWatch_Trig_ZCE[0] = (uint8_T)
    (SWatchCB_B->DataTypeConversion ? (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);
  SWatchCB_PrevZCX->SWatch_Trig_ZCE[1] = (uint8_T)(SWatchCB_B->button_read ?
    (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);
  SWatchCB_PrevZCX->SWatch_Trig_ZCE[2] = (uint8_T)(SWatchCB_B->button_read1 ?
    (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);
  SWatchCB_PrevZCX->SWatch_Trig_ZCE[3] = (uint8_T)(SWatchCB_B->button_read2 ?
    (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);
  SWatchCB_PrevZCX->SWatch_Trig_ZCE[4] = (uint8_T)(SWatchCB_B->button_read5 ?
    (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);
  SWatchCB_PrevZCX->SWatch_Trig_ZCE[5] = (uint8_T)(SWatchCB_B->button_read4 ?
    (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);
  SWatchCB_PrevZCX->SWatch_Trig_ZCE[6] = (uint8_T)(SWatchCB_B->button_read3 ?
    (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* Sum: '<S4>/FixPt Sum1' incorporates:
   *  Constant: '<S4>/FixPt Constant'
   */
  rtb_FixPtSum1++;

  /* Switch: '<S5>/FixPt Switch' */
  if (rtb_FixPtSum1 > 1) {
    /* Update for UnitDelay: '<S2>/Output' incorporates:
     *  Constant: '<S5>/Constant'
     */
    SWatchCB_DW->Output_DSTATE = 0U;
  } else {
    /* Update for UnitDelay: '<S2>/Output' */
    SWatchCB_DW->Output_DSTATE = rtb_FixPtSum1;
  }

  /* End of Switch: '<S5>/FixPt Switch' */
}

/* Model initialize function */
void SWatchCB_initialize(RT_MODEL_SWatchCB_T *const SWatchCB_M, uint8_T
  *SWatchCB_Y_hours, uint8_T *SWatchCB_Y_minutes, uint8_T *SWatchCB_Y_seconds,
  uint8_T *SWatchCB_Y_tenths, uint8_T *SWatchCB_Y_mode)
{
  B_SWatchCB_T *SWatchCB_B = ((B_SWatchCB_T *) SWatchCB_M->ModelData.blockIO);
  DW_SWatchCB_T *SWatchCB_DW = ((DW_SWatchCB_T *) SWatchCB_M->ModelData.dwork);
  PrevZCX_SWatchCB_T *SWatchCB_PrevZCX = ((PrevZCX_SWatchCB_T *)
    SWatchCB_M->ModelData.prevZCSigState);

  /* Registration code */

  /* block I/O */
  (void) memset(((void *) SWatchCB_B), 0,
                sizeof(B_SWatchCB_T));

  /* states (dwork) */
  (void) memset((void *)SWatchCB_DW, 0,
                sizeof(DW_SWatchCB_T));

  /* external outputs */
  (*SWatchCB_Y_hours) = 0U;
  (*SWatchCB_Y_minutes) = 0U;
  (*SWatchCB_Y_seconds) = 0U;
  (*SWatchCB_Y_tenths) = 0U;
  (*SWatchCB_Y_mode) = 0U;

  {
    int_T idx;
    for (idx = 0; idx < 7; idx++) {
      SWatchCB_PrevZCX->SWatch_Trig_ZCE[idx] = UNINITIALIZED_ZCSIG;
    }
  }

  /* InitializeConditions for Chart: '<S1>/SWatch' */
  /* Entry: SWatchCB/SWatch */
  /* Entry Internal: SWatchCB/SWatch */
  SWatchCB_DW->is_active_Control = 1U;

  /* Entry Internal 'Control': '<S3>:13' */
  /* Transition: '<S3>:25' */
  SWatchCB_DW->is_Control = SWatchCB_IN_timemode;

  /* InitializeConditions for Outport: '<Root>/mode' incorporates:
   *  InitializeConditions for Chart: '<S1>/SWatch'
   */
  /* Entry 'timemode': '<S3>:23' */
  *SWatchCB_Y_mode = 0U;

  /* InitializeConditions for Chart: '<S1>/SWatch' */
  SWatchCB_DW->is_active_TimeCount = 1U;

  /* Entry Internal 'TimeCount': '<S3>:14' */
  /* Transition: '<S3>:18' */
  SWatchCB_DW->hours = 0U;
  SWatchCB_DW->minutes = 0U;
  SWatchCB_DW->seconds = 0U;
  SWatchCB_DW->tenths = 0U;
  SWatchCB_DW->is_TimeCount = SWatchCB_IN_timecount;
  SWatchCB_DW->is_active_AlarmMng = 1U;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
