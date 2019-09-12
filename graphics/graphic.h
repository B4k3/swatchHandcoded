#include "../libs/Widget.h"
#include "../libs/WidgetConfig.h"
#include "../libs/types.h"


void init_screen();
void draw_hours(uint8_T hours);
void draw_minutes(uint8_T minutes);
void draw_seconds(uint8_T seconds);
void draw_tenths(uint8_T tenths);
void switchMode(uint8_T mode);
void update_interface(uint8_T mode, uint8_T hours, uint8_T minutes, uint8_T seconds, uint8_T tenths);
