#define uint8_t unsigned char
#define bool_t unsigned int

enum Signal{Tick,plusButton,minusButton,timeMode,timeSetMode,alarmMode,swatchMode,stopWatchStart,stopWatchStop};
enum State{TimeDisplay,TimeSet,StopWatch,AlarmSet};
enum StopwatchState{Running,Paused,Stopped};