#include "handcoded.h";
#include "../libs/types.h";
uint8_T abs_hours;		// absolute hour count
uint8_T abs_minutes;	// absolute minutes count
uint8_T abs_seconds;	// absolute seconds count
uint8_T abs_tenths;		// absolute tenths count
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
void SwatchDispatch(Swatch *me){
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
}




void SwatchInit(Swatch *me)
{
	me->state_ = TimeDisplay;
    me->swatch_state = Stopped;
    me->hours  = 0;
    me->minutes= 0;
    me->seconds= 0;
    me->tenths = 0;
    me->alarm_hours = 0;
    me->alarm_minutes = 0;
    me->stopwatch_hours = 0;
    me->stopwatch_minutes = 0;
    me->stopwatch_seconds = 0;
    me->stopwatch_tenths = 0;
}

void SwatchTran_(Swatch *me, State nextstate)
{   
    me->old_state = me->state_;
	me->state_ = nextstate;
}


/*Entry state*/
void Swatch_Entry(Swatch *me){
    me->stopwatch_hours = 0;
    me->stopwatch_minutes = 0;
    me->stopwatch_seconds = 0;
    me->stopwatch_tenths = 0;
}


void Time_Entry(Swatch *me){
    me->hours  = abs_hours;
    me->minutes= abs_minutes;
    me->seconds= abs_seconds;
    me->tenths = abs_tenths;
}

void Alarm_Entry(Swatch *me){
    me->alarm_hours  = abs_hours;
    me->alarm_minutes= abs_minutes;
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

void TimeSet_Entry(Swatch *me){

}

