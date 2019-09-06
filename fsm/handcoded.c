#include "handcoded.h";
void SwatchDispatch(Swatch *me){
    switch (me->state_)
    {
    case TimeDisplay:
        switch (decodesignal())
        {
        case timeSetMode:
            SwatchTran_(me, TimeSet);
            break;
        case alarmMode:
            SwatchTran_(me, AlarmSet);
            break;
        case swatchMode:
            SwatchTran_(me, StopWatch);
            break;
        }
        break;
    case TimeSet:
        switch (decodesignal())
        {
        case timeMode:
            SwatchTran_(me, TimeDisplay);
            break;
        case alarmMode:
            SwatchTran_(me, AlarmSet);
            break;
        case swatchMode:
            SwatchTran_(me, StopWatch);
            break;
        case plusButton:
            break;
        case minusButton:
            break;
        }
        break;
    case AlarmSet:
        switch (decodesignal())
        {
        case timeMode:
            SwatchTran_(me, TimeDisplay);
            break;
        case timeSetMode:
            SwatchTran_(me, TimeSet);
            break;
        case swatchMode:
            SwatchTran_(me, StopWatch);
            break;
        case plusButton:
            break;
        case minusButton:
            break;
        }
        break;
    case StopWatch:
        switch (decodesignal())
        {
        case timeMode:
            SwatchTran_(me, TimeDisplay);
            break;
        case alarmMode:
            SwatchTran_(me, AlarmSet);
            break;
        case timeSetMode:
            SwatchTran_(me, TimeSet);
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
	me->state = nextstate;
}




