#include "handcoded.h"
#include "../libs/types.h"
#include "../libs/Event.h"
uint8_T abs_hours;		// absolute hour count
uint8_T abs_minutes;	// absolute minutes count
uint8_T abs_seconds;	// absolute seconds count
uint8_T abs_tenths;		// absolute tenths count

uint8_T alarm_hours;
uint8_T alarm_minutes;

uint8_T stopwatch_hours;
uint8_T d_stopwatch_hours;
uint8_T stopwatch_minutes;
uint8_T d_stopwatch_minutes;
uint8_T stopwatch_seconds;
uint8_T d_stopwatch_seconds;
uint8_T stopwatch_tenths;
uint8_T d_stopwatch_tenths;

bool_t  Events_Button[8];

bool_t timeset_status;

/*Entry state*/
void Swatch_Entry(Swatch *me){
    stopwatch_hours = 0;
    stopwatch_minutes = 0;
    stopwatch_seconds = 0;
    stopwatch_tenths = 0;
}


void Time_Entry(Swatch *me){
   // hours  = abs_hours;
    //minutes= abs_minutes;
    //seconds= abs_seconds;
    //tenths = abs_tenths;
}

void Alarm_Entry(Swatch *me){
    //alarm_hours  = abs_hours;
    //alarm_minutes= abs_minutes;
}

void TimeSet_Entry(Swatch *me,uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths){
	*d_hours = abs_hours;
	*d_minutes = abs_minutes;
	*d_seconds = abs_seconds;
	*d_tenths = abs_tenths;
	timeset_status=0;
}

void Time_During(Swatch *me,uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths){
	*d_hours = abs_hours;
	*d_minutes = abs_minutes;
	*d_seconds = abs_seconds;
	*d_tenths = abs_tenths;
	//debuginfo(d_hours,d_minutes,d_seconds,d_tenths);
}
void Swatch_During(Swatch *me,uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths){
	debuginfo(0,0,d_stopwatch_seconds,stopwatch_seconds);
	*d_hours = d_stopwatch_hours;
	*d_minutes = d_stopwatch_minutes;
	*d_seconds = d_stopwatch_seconds;
	*d_tenths = d_stopwatch_tenths;
}
void Alarm_During(Swatch *me,uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths){
	*d_hours = alarm_hours;
	*d_minutes = alarm_minutes;
}
void TimeSet_During(Swatch *me,uint8_T *d_hours, uint8_T *d_minutes, uint8_T *d_seconds, uint8_T *d_tenths){
	*d_hours = abs_hours;
	*d_minutes = abs_minutes;
	*d_seconds = abs_seconds;
	*d_tenths = abs_tenths;
}
// update timestamp every tick
void time_count(Swatch *me) {
	//debuginfo(1,1,1,abs_seconds);
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
	if(me->swatch_state != Stopped){
		stopwatch_tenths = (stopwatch_tenths+1) % 10;

			if(stopwatch_tenths == 0) {
				stopwatch_seconds = (stopwatch_seconds+1) % 60;

				if(stopwatch_seconds == 0) {
					stopwatch_minutes = (stopwatch_minutes+1) % 60;

					if(stopwatch_minutes == 0) {
						stopwatch_hours = (stopwatch_hours+1) % 24;
					}
				}
			}
	}
	if(me->swatch_state == Running){
		d_stopwatch_hours = stopwatch_hours;
		d_stopwatch_minutes = stopwatch_minutes;
		d_stopwatch_seconds = stopwatch_seconds;
		d_stopwatch_tenths = stopwatch_tenths;
	}
}

void time_set_plus(){
	if(timeset_status)
		abs_minutes = (abs_minutes == 59)?0:abs_minutes+1;
	else
		abs_hours = (abs_hours == 23)?0:abs_hours+1;
}

void time_set_minus(){
	if(timeset_status)
			abs_minutes = (abs_minutes == 0)?59:abs_minutes-1;
		else
			abs_hours = (abs_hours == 0)?23:abs_hours-1;
}

void alarm_set_plus(){
	if(timeset_status)
		alarm_hours = (alarm_hours == 59)?0:alarm_hours+1;
	else
		alarm_hours = (alarm_hours == 23)?0:alarm_hours+1;
}

void alarm_set_minus(){
	if(timeset_status)
		alarm_hours = (alarm_hours == 0)?59:alarm_hours-1;
		else
			alarm_hours = (alarm_hours == 0)?23:alarm_hours-1;
}

void stopwatch_reset(){
	 stopwatch_hours = 0;
	stopwatch_minutes = 0;
	stopwatch_seconds = 0;
	stopwatch_tenths = 0;
}

void stopwatch_tran(Swatch *me,StopwatchState state){
	me->swatch_state = state;
}

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

void resetButtonState(){
	uint8_T i;
	for (i = 0; i < 6; i++)
	{
		Events_Button[i]=0;
	};
}

void stopwatch_dispatch(Swatch *me,Signal signal){
	switch(me->swatch_state){
	case Running:
		switch(signal){
		case plusButton:
			stopwatch_tran(me,Paused);
			break;
		case minusButton:
			stopwatch_tran(me,Stopped);
			break;
		}
		break;
	case Stopped:
		switch(signal){
		case plusButton:
			stopwatch_tran(me,Running);
			break;
		case minusButton:
			stopwatch_reset();
			break;
		}
		break;
	case Paused:
		switch(signal){
		case plusButton:
			stopwatch_tran(me,Running);
			break;
		case minusButton:
			stopwatch_tran(me,Stopped);
			break;
		}
		break;
	}
}

void SwatchDispatch(Swatch *me,uint8_T *h,uint8_T *m,uint8_T *s,uint8_T *t){
    switch (me->state_)
    {
    case TimeDisplay:
    	Time_During(me,h,m,s,t);
        switch (decodesignal(Events_Button))
        {
        case timeSetMode:
            SwatchTran_(me, TimeSet);
            TimeSet_Entry(me,h,m,s,t);
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
    	TimeSet_During(me,h,m,s,t);
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
        	time_set_plus();
            break;
        case minusButton:
        	time_set_minus();
            break;
        case timeSetMode:
			timeset_status = (timeset_status == 0)?1:0;
			break;
        }
        break;
    case AlarmSet:
    	Alarm_During(me,h,m,s,t);
        switch (decodesignal(Events_Button))
        {
        case timeMode:
            SwatchTran_(me, TimeDisplay);
            Time_Entry(me);
            break;
        case timeSetMode:
            SwatchTran_(me, TimeSet);
            TimeSet_Entry(me,h,m,s,t);
            break;
        case swatchMode:
            SwatchTran_(me, StopWatch);
            Swatch_Entry(me);
            break;
        case plusButton:
        	alarm_set_plus();
            break;
        case minusButton:
        	alarm_set_minus();
            break;
        }
        break;
    case StopWatch:
    	Swatch_During(me,h,m,s,t);
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
            TimeSet_Entry(me,h,m,s,t);
            break;
        case plusButton:
        	stopwatch_dispatch(me,plusButton);
            break;
        case minusButton:
        	stopwatch_dispatch(me,minusButton);
            break;
        }
        break;
    }

    time_count(me);
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

void parse_events(){
	if (IsEvent(PLUS)) 			Events_Button[0] = 1;
	if (IsEvent(MINUS)) 		Events_Button[1] = 1;
	if (IsEvent(TIMEMODE)) 		Events_Button[2] = 1;
	if (IsEvent(TIMESETMODE)) 	Events_Button[3] = 1;
	if (IsEvent(ALARMMODE)) 	Events_Button[4] = 1;
	if (IsEvent(SWATCHMODE)) 	Events_Button[5] = 1;
	ClearEvents();
}



