#define CLASS(class_) typedef struct class_ class_;\ struct class_{
#define METHODS };
#define END_CLASS
#define SUBCLASS(class_, superclass_) \CLASS(class_) \superclass_ super;
#define swatchGetState(me_)		((me_)->state_)



enum Signal{Tick,plusButton,minusButton,timeMode,timeSetMode,alarmMode,swatchMode,stopWatchStart,stopWatchStop};
enum State{TimeDisplay,TimeSet,StopWatch,AlarmSet};

