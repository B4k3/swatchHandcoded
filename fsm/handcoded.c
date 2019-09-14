#include "handcoded.h"
#include "../libs/types.h"
uint8_T abs_hours;		// absolute hour count
uint8_T abs_minutes;	// absolute minutes count
uint8_T abs_seconds;	// absolute seconds count
uint8_T abs_tenths;		// absolute tenths count

uint8_T alarm_hours;
uint8_T alarm_minutes;

uint8_T stopwatch_hours;
uint8_T stopwatch_minutes;
uint8_T stopwatch_seconds;
uint8_T stopwatch_tenths;

bool_t  Events_Button[8];


Signal decodesignal(bool_t *Events_Button){
	uint8_T i;
    for (i = 0; i < 6; i++)
    {
        if(Events_Button[i])
            break;
    };
    switch (i)
    {
    case (0):
        return plusButton;
        break;
    case (1):
        return minusButton;
        break;
    case (2):
        return timeMode;
        break;
    case (3):
        return timeSetMode;
        break;
    case (4):
        return alarmMode;
        break;
    case (5):
        return swatchMode;
        break; 
    case (6):
        return stopWatchStart;
        break;
    case (7):
        return stopWatchStop;
        break; 
    default:
        break;
    }
    
}

void resetButtonState(bool_t *Events_Button){
	uint8_T i;
	for (i = 0; i < 6; i++)
	{
		Events_Button[i]=0;
	};
}

void SwatchDispatch(Swatch *me,State mode,uint8_T *h,uint8_T *m,uint8_T *s,uint8_T *t){
    switch (me->state_)
    {
    case TimeDisplay:
        switch (decodesignal(Events_Button))
        {
        case timeSetMode:
            SwatchTran_(me, TimeSet);
            TimeSet_Entry(me);
            break;
        case alarmMode:
            SwatchTran_(me, AlarmSet);
            Alarm_Entry(me);
            break;
        case swatchMode:
            SwatchTran_(me, StopWatch);
            Swatch_Entry(me);
            break;
        }
        break;
    case TimeSet:
        switch (decodesignal(Events_Button))
        {
        case timeMode:
            SwatchTran_(me, TimeDisplay);
            Time_Entry(me);
            break;
        case alarmMode:
            SwatchTran_(me, AlarmSet);
            Alarm_Entry(me);
            break;
        case swatchMode:
            SwatchTran_(me, StopWatch);
            Swatch_Entry(me);
            break;
        case plusButton:
            break;
        case minusButton:
            break;
        }
        break;
    case AlarmSet:
        switch (decodesignal(Events_Button))
        {
        case timeMode:
            SwatchTran_(me, TimeDisplay);
            Time_Entry(me);
            break;
        case timeSetMode:
            SwatchTran_(me, TimeSet);
            TimeSet_Entry(me);
            break;
        case swatchMode:
            SwatchTran_(me, StopWatch);
            Swatch_Entry(me);
            break;
        case plusButton:
            break;
        case minusButton:
            break;
        }
        break;
    case StopWatch:
        switch (decodesignal(Events_Button))
        {
        case timeMode:
            SwatchTran_(me, TimeDisplay);
            Time_Entry(me);
            break;
        case alarmMode:
            SwatchTran_(me, AlarmSet);
            Alarm_Entry(me);
            break;
        case timeSetMode:
            SwatchTran_(me, TimeSet);
            TimeSet_Entry(me);
            break;
        case plusButton:
            break;
        case minusButton:
            break;
        }
        break;
    }

    time_count();
}




void SwatchInit(Swatch *me)
{
	me->state_ = TimeDisplay;
    me->swatch_state = Stopped;
    abs_hours  = 0;
    abs_minutes= 0;
    abs_seconds= 0;
    abs_tenths = 0;
    alarm_hours = 0;
    alarm_minutes = 0;
    stopwatch_hours = 0;
    stopwatch_minutes = 0;
    stopwatch_seconds = 0;
    stopwatch_tenths = 0;
}

void SwatchTran_(Swatch *me, State nextstate)
{   
    me->old_state = me->state_;
	me->state_ = nextstate;
}


/*Entry state*/
void Swatch_Entry(Swatch *me){
    stopwatch_hours = 0;
    stopwatch_minutes = 0;
    stopwatch_seconds = 0;
    stopwatch_tenths = 0;
}


void Time_Entry(Swatch *me){
    hours  = abs_hours;
    minutes= abs_minutes;
    seconds= abs_seconds;
    tenths = abs_tenths;
}

void Alarm_Entry(Swatch *me){
    alarm_hours  = abs_hours;
    alarm_minutes= abs_minutes;
}

void TimeSet_Entry(Swatch *me,uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths){
	d_hours = abs_hours;
	d_minutes = abs_minutes;
	d_seconds = abs_seconds;
	d_tenths = abs_tenths;
}

void Time_During(Swatch *me,uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths){
	d_hours = abs_hours;
	d_minutes = abs_minutes;
	d_seconds = abs_seconds;
	d_tenths = abs_tenths;
}
void Swatch_During(Swatch *me,uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths){
	d_hours = stopwatch_hours;
	d_minutes = stopwatch_minutes;
	d_seconds = stopwatch_seconds;
	d_tenths = stopwatch_tenths;
}
void Alarm_During(Swatch *me,uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths){
	d_hours = alarm_hours;
	d_minutes = alarm_minutes;
}
void TimeSet_During(Swatch *me,uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths){
	d_hours = abs_hours;
	d_minutes = abs_minutes;
	d_seconds = abs_seconds;
	d_tenths = abs_tenths;
}
// update timestamp every tick
void time_count() {
	abs_tenths = (abs_tenths+1) % 10;
	
	if(abs_tenths == 0) {
		abs_seconds = (abs_seconds+1) % 60;
		
		if(abs_seconds == 0) {
			abs_minutes = (abs_minutes+1) % 60;
			
			if(abs_minutes == 0) {
				abs_hours = (abs_hours+1) % 24;
			}
		}
	}
}





