#include "../config/config.h"
#include "../libs/types.h"


//---------------STRUCTURES AND METHODS---------------
CLASS(Swatch)
	State old_state;
	State state_;

	uint8_T hours;
	uint8_T minutes;
	uint8_T seconds;
	uint8_T tenths;

	uint8_T alarm_hours;
	uint8_T alarm_minutes;

	uint8_T stopwatch_hours;
	uint8_T stopwatch_minutes;
	uint8_T stopwatch_seconds;
	uint8_T stopwatch_tenths;

	StopwatchState swatch_state;
	//enum State source_;
METHODS
	Swatch *SwatchCtor_(Swatch *me);
	void SwatchXtor_(Swatch *me);

	void SwatchInit(Swatch *me);
	void SwatchDispatch(Swatch *me);
	void SwatchTran_(Swatch *me, State nextstate);

	Signal decodesignal(bool_t *Events_Button);
END_CLASS
