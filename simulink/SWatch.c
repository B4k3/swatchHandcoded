/*
 * File: SWatch.c
 *
 * Code generated for Simulink model 'SWatch'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Thu Nov 12 14:52:00 2015
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SWatch.h"
#include "SWatch_private.h"

/* Named constants for Chart: '<S1>/SWatch' */
#define SWatch_IN_NO_ACTIVE_CHILD      ((uint8_T)0U)
#define SWatch_IN_alarmmode            ((uint8_T)1U)
#define SWatch_IN_sethours             ((uint8_T)1U)
#define SWatch_IN_setminutes           ((uint8_T)2U)
#define SWatch_IN_swatchmode           ((uint8_T)2U)
#define SWatch_IN_timecount            ((uint8_T)1U)
#define SWatch_IN_timemode             ((uint8_T)3U)
#define SWatch_IN_timesetmode          ((uint8_T)4U)
#define SWatch_event_Balarm            (5)
#define SWatch_event_Bminus            (2)
#define SWatch_event_Bplus             (1)
#define SWatch_event_Bstop             (6)
#define SWatch_event_Btime             (3)
#define SWatch_event_Btimeset          (4)
#define SWatch_event_tick              (0)

/* Forward declaration for local functions */
static void SWatch_Control(uint8_T *SWatch_Y_hours, uint8_T *SWatch_Y_minutes,
  uint8_T *SWatch_Y_seconds, uint8_T *SWatch_Y_tenths, uint8_T *SWatch_Y_mode,
  DW_SWatch_T *SWatch_DW);
static void SWatch_chartstep_c3_SWatch(uint8_T *SWatch_Y_hours, uint8_T
  *SWatch_Y_minutes, uint8_T *SWatch_Y_seconds, uint8_T *SWatch_Y_tenths,
  uint8_T *SWatch_Y_mode, DW_SWatch_T *SWatch_DW);

/* Function for Chart: '<S1>/SWatch' */
static void SWatch_Control(uint8_T *SWatch_Y_hours, uint8_T *SWatch_Y_minutes,
  uint8_T *SWatch_Y_seconds, uint8_T *SWatch_Y_tenths, uint8_T *SWatch_Y_mode,
  DW_SWatch_T *SWatch_DW)
{
  int32_T tmp;
  uint32_T qY;

  /* During 'Control': '<S3>:13' */
  if (SWatch_DW->sfEvent == SWatch_event_Btime) {
    /* Transition: '<S3>:45' */
    /* Exit Internal 'Control': '<S3>:13' */
    /* Exit Internal 'alarmmode': '<S3>:39' */
    SWatch_DW->is_alarmmode = SWatch_IN_NO_ACTIVE_CHILD;

    /* Exit Internal 'timesetmode': '<S3>:24' */
    SWatch_DW->is_timesetmode = SWatch_IN_NO_ACTIVE_CHILD;
    SWatch_DW->is_Control = SWatch_IN_timemode;

    /* Entry 'timemode': '<S3>:23' */
    *SWatch_Y_mode = 0U;
  } else {
    switch (SWatch_DW->is_Control) {
     case SWatch_IN_alarmmode:
      /* During 'alarmmode': '<S3>:39' */
      if (SWatch_DW->sfEvent == SWatch_event_Btimeset) {
        /* Transition: '<S3>:44' */
        /* Exit Internal 'alarmmode': '<S3>:39' */
        SWatch_DW->is_alarmmode = SWatch_IN_NO_ACTIVE_CHILD;
        SWatch_DW->is_Control = SWatch_IN_timesetmode;

        /* Entry 'timesetmode': '<S3>:24' */
        *SWatch_Y_mode = 1U;

        /* Entry Internal 'timesetmode': '<S3>:24' */
        /* Transition: '<S3>:62' */
        *SWatch_Y_minutes = SWatch_DW->minutes;
        SWatch_DW->is_timesetmode = SWatch_IN_sethours;

        /* Entry 'sethours': '<S3>:60' */
        *SWatch_Y_hours = SWatch_DW->hours;
      } else if (SWatch_DW->sfEvent == SWatch_event_Bstop) {
        /* Transition: '<S3>:49' */
        /* Exit Internal 'alarmmode': '<S3>:39' */
        SWatch_DW->is_alarmmode = SWatch_IN_NO_ACTIVE_CHILD;
        SWatch_DW->is_Control = SWatch_IN_swatchmode;

        /* Entry 'swatchmode': '<S3>:40' */
        *SWatch_Y_mode = 3U;
      } else if (SWatch_DW->is_alarmmode == SWatch_IN_sethours) {
        /* During 'sethours': '<S3>:73' */
        if (SWatch_DW->sfEvent == SWatch_event_Balarm) {
          /* Transition: '<S3>:78' */
          SWatch_DW->is_alarmmode = SWatch_IN_setminutes;

          /* Entry 'setminutes': '<S3>:82' */
          *SWatch_Y_minutes = SWatch_DW->Aminutes;
        } else if (SWatch_DW->sfEvent == SWatch_event_Bplus) {
          /* Transition: '<S3>:80' */
          tmp = (int32_T)(SWatch_DW->Ahours + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          SWatch_DW->Ahours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 24U * 24U));
          SWatch_DW->is_alarmmode = SWatch_IN_sethours;

          /* Entry 'sethours': '<S3>:73' */
          *SWatch_Y_hours = SWatch_DW->Ahours;
        } else if ((SWatch_DW->sfEvent == SWatch_event_Bminus) &&
                   (SWatch_DW->Ahours == 0)) {
          /* Transition: '<S3>:75' */
          SWatch_DW->Ahours = 23U;
          SWatch_DW->is_alarmmode = SWatch_IN_sethours;

          /* Entry 'sethours': '<S3>:73' */
          *SWatch_Y_hours = SWatch_DW->Ahours;
        } else {
          if (SWatch_DW->sfEvent == SWatch_event_Bminus) {
            /* Transition: '<S3>:81' */
            qY = SWatch_DW->Ahours - 1U;
            if (qY > SWatch_DW->Ahours) {
              qY = 0U;
            }

            SWatch_DW->Ahours = (uint8_T)qY;
            SWatch_DW->is_alarmmode = SWatch_IN_sethours;

            /* Entry 'sethours': '<S3>:73' */
            *SWatch_Y_hours = SWatch_DW->Ahours;
          }
        }
      } else {
        /* During 'setminutes': '<S3>:82' */
        if ((SWatch_DW->sfEvent == SWatch_event_Bminus) && (SWatch_DW->Aminutes ==
             0)) {
          /* Transition: '<S3>:76' */
          SWatch_DW->Aminutes = 59U;
          SWatch_DW->is_alarmmode = SWatch_IN_setminutes;

          /* Entry 'setminutes': '<S3>:82' */
          *SWatch_Y_minutes = SWatch_DW->Aminutes;
        } else if (SWatch_DW->sfEvent == SWatch_event_Balarm) {
          /* Transition: '<S3>:77' */
          SWatch_DW->is_alarmmode = SWatch_IN_sethours;

          /* Entry 'sethours': '<S3>:73' */
          *SWatch_Y_hours = SWatch_DW->Ahours;
        } else if (SWatch_DW->sfEvent == SWatch_event_Bplus) {
          /* Transition: '<S3>:74' */
          tmp = (int32_T)(SWatch_DW->Aminutes + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          SWatch_DW->Aminutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 60U * 60U));
          SWatch_DW->is_alarmmode = SWatch_IN_setminutes;

          /* Entry 'setminutes': '<S3>:82' */
          *SWatch_Y_minutes = SWatch_DW->Aminutes;
        } else {
          if (SWatch_DW->sfEvent == SWatch_event_Bminus) {
            /* Transition: '<S3>:72' */
            qY = SWatch_DW->Aminutes - 1U;
            if (qY > SWatch_DW->Aminutes) {
              qY = 0U;
            }

            SWatch_DW->Aminutes = (uint8_T)qY;
            SWatch_DW->is_alarmmode = SWatch_IN_setminutes;

            /* Entry 'setminutes': '<S3>:82' */
            *SWatch_Y_minutes = SWatch_DW->Aminutes;
          }
        }
      }
      break;

     case SWatch_IN_swatchmode:
      /* During 'swatchmode': '<S3>:40' */
      if (SWatch_DW->sfEvent == SWatch_event_Btimeset) {
        /* Transition: '<S3>:43' */
        SWatch_DW->is_Control = SWatch_IN_timesetmode;

        /* Entry 'timesetmode': '<S3>:24' */
        *SWatch_Y_mode = 1U;

        /* Entry Internal 'timesetmode': '<S3>:24' */
        /* Transition: '<S3>:62' */
        *SWatch_Y_minutes = SWatch_DW->minutes;
        SWatch_DW->is_timesetmode = SWatch_IN_sethours;

        /* Entry 'sethours': '<S3>:60' */
        *SWatch_Y_hours = SWatch_DW->hours;
      } else if (SWatch_DW->sfEvent == SWatch_event_Balarm) {
        /* Transition: '<S3>:46' */
        SWatch_DW->is_Control = SWatch_IN_alarmmode;

        /* Entry 'alarmmode': '<S3>:39' */
        *SWatch_Y_mode = 2U;

        /* Entry Internal 'alarmmode': '<S3>:39' */
        /* Transition: '<S3>:79' */
        *SWatch_Y_minutes = SWatch_DW->Aminutes;
        SWatch_DW->is_alarmmode = SWatch_IN_sethours;

        /* Entry 'sethours': '<S3>:73' */
        *SWatch_Y_hours = SWatch_DW->Ahours;
      } else {
        if (SWatch_DW->sfEvent == SWatch_event_tick) {
          /* Transition: '<S3>:59' */
          *SWatch_Y_tenths = SWatch_DW->tenths;
        }
      }
      break;

     case SWatch_IN_timemode:
      /* During 'timemode': '<S3>:23' */
      if (SWatch_DW->sfEvent == SWatch_event_Btimeset) {
        /* Transition: '<S3>:26' */
        SWatch_DW->is_Control = SWatch_IN_timesetmode;

        /* Entry 'timesetmode': '<S3>:24' */
        *SWatch_Y_mode = 1U;

        /* Entry Internal 'timesetmode': '<S3>:24' */
        /* Transition: '<S3>:62' */
        *SWatch_Y_minutes = SWatch_DW->minutes;
        SWatch_DW->is_timesetmode = SWatch_IN_sethours;

        /* Entry 'sethours': '<S3>:60' */
        *SWatch_Y_hours = SWatch_DW->hours;
      } else if (SWatch_DW->sfEvent == SWatch_event_Balarm) {
        /* Transition: '<S3>:48' */
        SWatch_DW->is_Control = SWatch_IN_alarmmode;

        /* Entry 'alarmmode': '<S3>:39' */
        *SWatch_Y_mode = 2U;

        /* Entry Internal 'alarmmode': '<S3>:39' */
        /* Transition: '<S3>:79' */
        *SWatch_Y_minutes = SWatch_DW->Aminutes;
        SWatch_DW->is_alarmmode = SWatch_IN_sethours;

        /* Entry 'sethours': '<S3>:73' */
        *SWatch_Y_hours = SWatch_DW->Ahours;
      } else if (SWatch_DW->sfEvent == SWatch_event_Bstop) {
        /* Transition: '<S3>:50' */
        SWatch_DW->is_Control = SWatch_IN_swatchmode;

        /* Entry 'swatchmode': '<S3>:40' */
        *SWatch_Y_mode = 3U;
      } else {
        if (SWatch_DW->sfEvent == SWatch_event_tick) {
          /* Transition: '<S3>:58' */
          *SWatch_Y_hours = SWatch_DW->hours;
          *SWatch_Y_minutes = SWatch_DW->minutes;
          *SWatch_Y_seconds = SWatch_DW->seconds;
        }
      }
      break;

     default:
      /* During 'timesetmode': '<S3>:24' */
      if (SWatch_DW->sfEvent == SWatch_event_Balarm) {
        /* Transition: '<S3>:47' */
        /* Exit Internal 'timesetmode': '<S3>:24' */
        SWatch_DW->is_timesetmode = SWatch_IN_NO_ACTIVE_CHILD;
        SWatch_DW->is_Control = SWatch_IN_alarmmode;

        /* Entry 'alarmmode': '<S3>:39' */
        *SWatch_Y_mode = 2U;

        /* Entry Internal 'alarmmode': '<S3>:39' */
        /* Transition: '<S3>:79' */
        *SWatch_Y_minutes = SWatch_DW->Aminutes;
        SWatch_DW->is_alarmmode = SWatch_IN_sethours;

        /* Entry 'sethours': '<S3>:73' */
        *SWatch_Y_hours = SWatch_DW->Ahours;
      } else if (SWatch_DW->sfEvent == SWatch_event_Bstop) {
        /* Transition: '<S3>:51' */
        /* Exit Internal 'timesetmode': '<S3>:24' */
        SWatch_DW->is_timesetmode = SWatch_IN_NO_ACTIVE_CHILD;
        SWatch_DW->is_Control = SWatch_IN_swatchmode;

        /* Entry 'swatchmode': '<S3>:40' */
        *SWatch_Y_mode = 3U;
      } else if (SWatch_DW->is_timesetmode == SWatch_IN_sethours) {
        /* During 'sethours': '<S3>:60' */
        if (SWatch_DW->sfEvent == SWatch_event_Btimeset) {
          /* Transition: '<S3>:64' */
          SWatch_DW->is_timesetmode = SWatch_IN_setminutes;

          /* Entry 'setminutes': '<S3>:61' */
          *SWatch_Y_minutes = SWatch_DW->minutes;
        } else if (SWatch_DW->sfEvent == SWatch_event_Bplus) {
          /* Transition: '<S3>:66' */
          tmp = (int32_T)(SWatch_DW->hours + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          SWatch_DW->hours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 24U * 24U));
          SWatch_DW->is_timesetmode = SWatch_IN_sethours;

          /* Entry 'sethours': '<S3>:60' */
          *SWatch_Y_hours = SWatch_DW->hours;
        } else if ((SWatch_DW->sfEvent == SWatch_event_Bminus) &&
                   (SWatch_DW->hours == 0)) {
          /* Transition: '<S3>:68' */
          SWatch_DW->hours = 23U;
          SWatch_DW->is_timesetmode = SWatch_IN_sethours;

          /* Entry 'sethours': '<S3>:60' */
          *SWatch_Y_hours = SWatch_DW->hours;
        } else {
          if (SWatch_DW->sfEvent == SWatch_event_Bminus) {
            /* Transition: '<S3>:70' */
            qY = SWatch_DW->hours - 1U;
            if (qY > SWatch_DW->hours) {
              qY = 0U;
            }

            SWatch_DW->hours = (uint8_T)qY;
            SWatch_DW->is_timesetmode = SWatch_IN_sethours;

            /* Entry 'sethours': '<S3>:60' */
            *SWatch_Y_hours = SWatch_DW->hours;
          }
        }
      } else {
        /* During 'setminutes': '<S3>:61' */
        if ((SWatch_DW->sfEvent == SWatch_event_Bminus) && (SWatch_DW->minutes ==
             0)) {
          /* Transition: '<S3>:69' */
          SWatch_DW->minutes = 59U;
          SWatch_DW->is_timesetmode = SWatch_IN_setminutes;

          /* Entry 'setminutes': '<S3>:61' */
          *SWatch_Y_minutes = SWatch_DW->minutes;
        } else if (SWatch_DW->sfEvent == SWatch_event_Btimeset) {
          /* Transition: '<S3>:65' */
          SWatch_DW->is_timesetmode = SWatch_IN_sethours;

          /* Entry 'sethours': '<S3>:60' */
          *SWatch_Y_hours = SWatch_DW->hours;
        } else if (SWatch_DW->sfEvent == SWatch_event_Bplus) {
          /* Transition: '<S3>:67' */
          tmp = (int32_T)(SWatch_DW->minutes + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          SWatch_DW->minutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 60U * 60U));
          SWatch_DW->is_timesetmode = SWatch_IN_setminutes;

          /* Entry 'setminutes': '<S3>:61' */
          *SWatch_Y_minutes = SWatch_DW->minutes;
        } else {
          if (SWatch_DW->sfEvent == SWatch_event_Bminus) {
            /* Transition: '<S3>:71' */
            qY = SWatch_DW->minutes - 1U;
            if (qY > SWatch_DW->minutes) {
              qY = 0U;
            }

            SWatch_DW->minutes = (uint8_T)qY;
            SWatch_DW->is_timesetmode = SWatch_IN_setminutes;

            /* Entry 'setminutes': '<S3>:61' */
            *SWatch_Y_minutes = SWatch_DW->minutes;
          }
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<S1>/SWatch' */
static void SWatch_chartstep_c3_SWatch(uint8_T *SWatch_Y_hours, uint8_T
  *SWatch_Y_minutes, uint8_T *SWatch_Y_seconds, uint8_T *SWatch_Y_tenths,
  uint8_T *SWatch_Y_mode, DW_SWatch_T *SWatch_DW)
{
  boolean_T guard1 = false;
  int32_T tmp;

  /* During: SWatch/SWatch */
  SWatch_Control(SWatch_Y_hours, SWatch_Y_minutes, SWatch_Y_seconds,
                 SWatch_Y_tenths, SWatch_Y_mode, SWatch_DW);

  /* During 'TimeCount': '<S3>:14' */
  /* During 'timecount': '<S3>:17' */
  if (SWatch_DW->sfEvent == SWatch_event_tick) {
    /* Transition: '<S3>:21' */
    tmp = (int32_T)(SWatch_DW->tenths + 1U);
    if ((uint32_T)tmp > 255U) {
      tmp = 255;
    }

    SWatch_DW->tenths = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)((uint8_T)
      tmp / 10U * 10U));
    if (SWatch_DW->tenths == 0) {
      /* Transition: '<S3>:29' */
      tmp = (int32_T)(SWatch_DW->seconds + 1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      SWatch_DW->seconds = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)((uint8_T)
        tmp / 60U * 60U));
      if (SWatch_DW->seconds == 0) {
        /* Transition: '<S3>:32' */
        tmp = (int32_T)(SWatch_DW->minutes + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        SWatch_DW->minutes = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
          ((uint8_T)tmp / 60U * 60U));
        if (SWatch_DW->minutes == 0) {
          /* Transition: '<S3>:37' */
          tmp = (int32_T)(SWatch_DW->hours + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          SWatch_DW->hours = (uint8_T)((uint32_T)(uint8_T)tmp - (uint8_T)
            ((uint8_T)tmp / 24U * 24U));

          /* Transition: '<S3>:38' */
          SWatch_DW->is_TimeCount = SWatch_IN_timecount;
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
      SWatch_DW->is_TimeCount = SWatch_IN_timecount;
    }
  }

  /* During 'AlarmMng': '<S3>:15' */
}

/* Model step function */
void SWatch_step(RT_MODEL_SWatch_T *const SWatch_M, boolean_T SWatch_U_Bplus,
                 boolean_T SWatch_U_Bminus, boolean_T SWatch_U_Btime, boolean_T
                 SWatch_U_Btimeset, boolean_T SWatch_U_Balarm, boolean_T
                 SWatch_U_Bswatch, uint8_T *SWatch_Y_hours, uint8_T
                 *SWatch_Y_minutes, uint8_T *SWatch_Y_seconds, uint8_T
                 *SWatch_Y_tenths, uint8_T *SWatch_Y_mode)
{
  DW_SWatch_T *SWatch_DW = ((DW_SWatch_T *) SWatch_M->ModelData.dwork);
  PrevZCX_SWatch_T *SWatch_PrevZCX = ((PrevZCX_SWatch_T *)
    SWatch_M->ModelData.prevZCSigState);
  uint8_T rtb_FixPtSum1;
  boolean_T rtb_DataTypeConversion;
  boolean_T zcEvent[7];
  boolean_T tmp;
  int32_T i;
  int8_T rtb_inputevents_idx_1;
  int8_T rtb_inputevents_idx_2;
  int8_T rtb_inputevents_idx_3;
  int8_T rtb_inputevents_idx_4;
  int8_T rtb_inputevents_idx_5;
  int8_T rtb_inputevents_idx_6;

  /* Outputs for Atomic SubSystem: '<Root>/SWatch' */
  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  UnitDelay: '<S2>/Output'
   */
  rtb_DataTypeConversion = (SWatch_DW->Output_DSTATE != 0);

  /* Sum: '<S4>/FixPt Sum1' incorporates:
   *  Constant: '<S4>/FixPt Constant'
   *  UnitDelay: '<S2>/Output'
   */
  rtb_FixPtSum1 = (uint8_T)(SWatch_DW->Output_DSTATE + 1U);

  /* Switch: '<S5>/FixPt Switch' incorporates:
   *  Constant: '<S5>/Constant'
   */
  if (rtb_FixPtSum1 > 1) {
    rtb_FixPtSum1 = 0U;
  }

  /* End of Switch: '<S5>/FixPt Switch' */

  /* Chart: '<S1>/SWatch' incorporates:
   *  TriggerPort: '<S3>/ input events '
   */
  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  UnitDelay: '<S2>/Output'
   */
  zcEvent[0] = (((SWatch_DW->Output_DSTATE != 0) !=
                 (SWatch_PrevZCX->SWatch_Trig_ZCE[0] == POS_ZCSIG)) &&
                (SWatch_PrevZCX->SWatch_Trig_ZCE[0] != UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/Bplus' */
  zcEvent[1] = (((SWatch_PrevZCX->SWatch_Trig_ZCE[1] == POS_ZCSIG) !=
                 SWatch_U_Bplus) && (SWatch_PrevZCX->SWatch_Trig_ZCE[1] !=
    UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/Bminus' */
  zcEvent[2] = (((SWatch_PrevZCX->SWatch_Trig_ZCE[2] == POS_ZCSIG) !=
                 SWatch_U_Bminus) && (SWatch_PrevZCX->SWatch_Trig_ZCE[2] !=
    UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/Btime' */
  zcEvent[3] = (((SWatch_PrevZCX->SWatch_Trig_ZCE[3] == POS_ZCSIG) !=
                 SWatch_U_Btime) && (SWatch_PrevZCX->SWatch_Trig_ZCE[3] !=
    UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/Btimeset' */
  zcEvent[4] = (((SWatch_PrevZCX->SWatch_Trig_ZCE[4] == POS_ZCSIG) !=
                 SWatch_U_Btimeset) && (SWatch_PrevZCX->SWatch_Trig_ZCE[4] !=
    UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/Balarm' */
  zcEvent[5] = (((SWatch_PrevZCX->SWatch_Trig_ZCE[5] == POS_ZCSIG) !=
                 SWatch_U_Balarm) && (SWatch_PrevZCX->SWatch_Trig_ZCE[5] !=
    UNINITIALIZED_ZCSIG));

  /* Inport: '<Root>/Bswatch' */
  zcEvent[6] = (((SWatch_PrevZCX->SWatch_Trig_ZCE[6] == POS_ZCSIG) !=
                 SWatch_U_Bswatch) && (SWatch_PrevZCX->SWatch_Trig_ZCE[6] !=
    UNINITIALIZED_ZCSIG));
  tmp = false;
  for (i = 0; i < 7; i++) {
    tmp = (tmp || zcEvent[i]);
  }

  if (tmp) {
    /* Inport: '<Root>/Bplus' */
    rtb_inputevents_idx_1 = (int8_T)(zcEvent[1] ? SWatch_U_Bplus ?
      RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT);

    /* Inport: '<Root>/Bminus' */
    rtb_inputevents_idx_2 = (int8_T)(zcEvent[2] ? SWatch_U_Bminus ?
      RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT);

    /* Inport: '<Root>/Btime' */
    rtb_inputevents_idx_3 = (int8_T)(zcEvent[3] ? SWatch_U_Btime ?
      RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT);

    /* Inport: '<Root>/Btimeset' */
    rtb_inputevents_idx_4 = (int8_T)(zcEvent[4] ? SWatch_U_Btimeset ?
      RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT);

    /* Inport: '<Root>/Balarm' */
    rtb_inputevents_idx_5 = (int8_T)(zcEvent[5] ? SWatch_U_Balarm ?
      RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT);

    /* Inport: '<Root>/Bswatch' */
    rtb_inputevents_idx_6 = (int8_T)(zcEvent[6] ? SWatch_U_Bswatch ?
      RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT);

    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  UnitDelay: '<S2>/Output'
     */
    /* Gateway: SWatch/SWatch */
    if ((int8_T)(zcEvent[0] ? SWatch_DW->Output_DSTATE != 0 ? RISING_ZCEVENT :
                 FALLING_ZCEVENT : NO_ZCEVENT) != 0) {
      /* Event: '<S3>:1' */
      SWatch_DW->sfEvent = SWatch_event_tick;
      SWatch_chartstep_c3_SWatch(SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_DW);
    }

    if (rtb_inputevents_idx_1 == 1) {
      /* Event: '<S3>:6' */
      SWatch_DW->sfEvent = SWatch_event_Bplus;
      SWatch_chartstep_c3_SWatch(SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_DW);
    }

    if (rtb_inputevents_idx_2 == 1) {
      /* Event: '<S3>:7' */
      SWatch_DW->sfEvent = SWatch_event_Bminus;
      SWatch_chartstep_c3_SWatch(SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_DW);
    }

    if (rtb_inputevents_idx_3 == 1) {
      /* Event: '<S3>:2' */
      SWatch_DW->sfEvent = SWatch_event_Btime;
      SWatch_chartstep_c3_SWatch(SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_DW);
    }

    if (rtb_inputevents_idx_4 == 1) {
      /* Event: '<S3>:3' */
      SWatch_DW->sfEvent = SWatch_event_Btimeset;
      SWatch_chartstep_c3_SWatch(SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_DW);
    }

    if (rtb_inputevents_idx_5 == 1) {
      /* Event: '<S3>:4' */
      SWatch_DW->sfEvent = SWatch_event_Balarm;
      SWatch_chartstep_c3_SWatch(SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_DW);
    }

    if (rtb_inputevents_idx_6 == 1) {
      /* Event: '<S3>:5' */
      SWatch_DW->sfEvent = SWatch_event_Bstop;
      SWatch_chartstep_c3_SWatch(SWatch_Y_hours, SWatch_Y_minutes,
        SWatch_Y_seconds, SWatch_Y_tenths, SWatch_Y_mode, SWatch_DW);
    }
  }

  SWatch_PrevZCX->SWatch_Trig_ZCE[0] = (uint8_T)(rtb_DataTypeConversion ?
    (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* Inport: '<Root>/Bplus' */
  SWatch_PrevZCX->SWatch_Trig_ZCE[1] = (uint8_T)(SWatch_U_Bplus ? (int32_T)
    POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* Inport: '<Root>/Bminus' */
  SWatch_PrevZCX->SWatch_Trig_ZCE[2] = (uint8_T)(SWatch_U_Bminus ? (int32_T)
    POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* Inport: '<Root>/Btime' */
  SWatch_PrevZCX->SWatch_Trig_ZCE[3] = (uint8_T)(SWatch_U_Btime ? (int32_T)
    POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* Inport: '<Root>/Btimeset' */
  SWatch_PrevZCX->SWatch_Trig_ZCE[4] = (uint8_T)(SWatch_U_Btimeset ? (int32_T)
    POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* Inport: '<Root>/Balarm' */
  SWatch_PrevZCX->SWatch_Trig_ZCE[5] = (uint8_T)(SWatch_U_Balarm ? (int32_T)
    POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* Inport: '<Root>/Bswatch' */
  SWatch_PrevZCX->SWatch_Trig_ZCE[6] = (uint8_T)(SWatch_U_Bswatch ? (int32_T)
    POS_ZCSIG : (int32_T)ZERO_ZCSIG);

  /* Update for UnitDelay: '<S2>/Output' */
  SWatch_DW->Output_DSTATE = rtb_FixPtSum1;

  /* End of Outputs for SubSystem: '<Root>/SWatch' */
}

/* Model initialize function */
void SWatch_initialize(RT_MODEL_SWatch_T *const SWatch_M, boolean_T
  *SWatch_U_Bplus, boolean_T *SWatch_U_Bminus, boolean_T *SWatch_U_Btime,
  boolean_T *SWatch_U_Btimeset, boolean_T *SWatch_U_Balarm, boolean_T
  *SWatch_U_Bswatch, uint8_T *SWatch_Y_hours, uint8_T *SWatch_Y_minutes, uint8_T
  *SWatch_Y_seconds, uint8_T *SWatch_Y_tenths, uint8_T *SWatch_Y_mode)
{
  DW_SWatch_T *SWatch_DW = ((DW_SWatch_T *) SWatch_M->ModelData.dwork);
  PrevZCX_SWatch_T *SWatch_PrevZCX = ((PrevZCX_SWatch_T *)
    SWatch_M->ModelData.prevZCSigState);

  /* Registration code */

  /* states (dwork) */
  (void) memset((void *)SWatch_DW, 0,
                sizeof(DW_SWatch_T));

  /* external inputs */
  (*SWatch_U_Bplus) = false;
  (*SWatch_U_Bminus) = false;
  (*SWatch_U_Btime) = false;
  (*SWatch_U_Btimeset) = false;
  (*SWatch_U_Balarm) = false;
  (*SWatch_U_Bswatch) = false;

  /* external outputs */
  (*SWatch_Y_hours) = 0U;
  (*SWatch_Y_minutes) = 0U;
  (*SWatch_Y_seconds) = 0U;
  (*SWatch_Y_tenths) = 0U;
  (*SWatch_Y_mode) = 0U;

  {
    int_T idx;
    for (idx = 0; idx < 7; idx++) {
      SWatch_PrevZCX->SWatch_Trig_ZCE[idx] = UNINITIALIZED_ZCSIG;
    }
  }

  /* InitializeConditions for Atomic SubSystem: '<Root>/SWatch' */
  /* InitializeConditions for Chart: '<S1>/SWatch' */
  SWatch_DW->is_alarmmode = SWatch_IN_NO_ACTIVE_CHILD;
  SWatch_DW->is_timesetmode = SWatch_IN_NO_ACTIVE_CHILD;

  /* Entry: SWatch/SWatch */
  /* Entry Internal: SWatch/SWatch */
  SWatch_DW->is_active_Control = 1U;

  /* Entry Internal 'Control': '<S3>:13' */
  /* Transition: '<S3>:25' */
  SWatch_DW->Ahours = 0U;
  SWatch_DW->Aminutes = 0U;
  SWatch_DW->is_Control = SWatch_IN_timemode;

  /* InitializeConditions for Outport: '<Root>/mode' incorporates:
   *  InitializeConditions for Chart: '<S1>/SWatch'
   */
  /* Entry 'timemode': '<S3>:23' */
  *SWatch_Y_mode = 0U;

  /* InitializeConditions for Chart: '<S1>/SWatch' */
  SWatch_DW->is_active_TimeCount = 1U;

  /* Entry Internal 'TimeCount': '<S3>:14' */
  /* Transition: '<S3>:18' */
  SWatch_DW->hours = 0U;
  SWatch_DW->minutes = 0U;
  SWatch_DW->seconds = 0U;
  SWatch_DW->tenths = 0U;
  SWatch_DW->is_TimeCount = SWatch_IN_timecount;
  SWatch_DW->is_active_AlarmMng = 1U;

  /* End of InitializeConditions for SubSystem: '<Root>/SWatch' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
