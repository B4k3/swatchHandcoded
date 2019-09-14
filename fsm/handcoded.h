#ifndef FSM
#define FSM

#include "../config/config.h"
#include "../libs/types.h"


//---------------STRUCTURES AND METHODS---------------
CLASS(Swatch)
	State old_state;
	State state_;
	StopwatchState swatch_state;
	//enum State source_;
METHODS
	Swatch *SwatchCtor_(Swatch *me);
	void SwatchXtor_(Swatch *me);

	void SwatchInit(Swatch *me);
	void SwatchDispatch(Swatch *me,State mode,uint8_T *h,uint8_T *m,uint8_T *s,uint8_T *t);
	void SwatchTran_(Swatch *me, State nextstate);

	Signal decodesignal(bool_t *Events_Button);
	void resetButtonState(bool_t *Events_Button);
END_CLASS

#endif
