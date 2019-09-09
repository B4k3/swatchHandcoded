#include "../config/config.h"
#include "../libs/types.h"


//---------------STRUCTURES AND METHODS---------------
CLASS(Swatch)
	enum State old_state;
	enum State state_;

	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;
	uint8_t tenths;

	uint8_t alarm_hours;
	uint8_t alarm_minutes;

	uint8_t stopwatch_hours;
	uint8_t stopwatch_minutes;
	uint8_t stopwatch_seconds;
	uint8_t stopwatch_tenths;

	StopwatchState swatch_state;
	//enum State source_;
METHODS
	Swatch *SwatchCtor_(Swatch *me);
	void SwatchXtor_(Swatch *me);

	void SwatchInit(Swatch *me);
	void SwatchDispatch(Swatch *me);
	void SwatchTran_(Swatch *me, enum State nextstate);

	State Swatch_top(Swatch *me, enum Event const *e);
	Signal decodesignal(boolean_T d[]);
END_CLASS