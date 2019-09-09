#define uint8_t unsigned char
#define bool_t unsigned int

enum Signal{Tick,
plusButton,
minusButton,
timeMode,
timeSetMode,
alarmMode,
swatchMode,
stopWatchStart,
stopWatchStop};

enum State{TimeDisplay,
TimeSet,
StopWatch,
AlarmSet};
enum StopwatchState{Running,
Paused,
Stopped};

typedef unsigned char boolean_T;
typedef signed char int8_T;
typedef unsigned char uint8_T;
typedef short int16_T;
typedef unsigned short uint16_T;
typedef int int32_T;
typedef unsigned int uint32_T;
