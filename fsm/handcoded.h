#include "../config/config.h"



CLASS(Swatch)
	enum State state_;
	//enum State source_;
METHODS
	Swatch *SwatchCtor_(Swatch *me);
	void SwatchXtor_(Swatch *me);

	void SwatchInit(Swatch *me);
	void SwatchDispatch(Swatch *me);
	void SwatchTran_(Swatch *me);

	State Swatch_top(Swatch *me, Event const *e);
