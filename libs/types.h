#ifndef TYPES
#define TYPES

#define bool_t unsigned int

typedef enum {Tick, plusButton, minusButton, timeMode, timeSetMode, alarmMode, swatchMode, stopWatchStart, stopWatchStop} Signal;
typedef enum {TimeDisplay, TimeSet, StopWatch, AlarmSet} State;
typedef enum {Running,Paused,Stopped} StopwatchState;

typedef unsigned char boolean_T;
typedef signed char int8_T;
typedef unsigned char uint8_T;
typedef short int16_T;
typedef unsigned short uint16_T;
typedef int int32_T;
typedef unsigned int uint32_T;

#endif
