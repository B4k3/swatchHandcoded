#include "../libs/types.h"


void init_screen();
void draw_hours(uint8_t hours);
void draw_minutes(uint8_t minutes);
void draw_seconds(uint8_t seconds);
void draw_tenths(uint8_t tenths);
void switchMode(uint8_t mode);
void update_interface(uint8_t mode, uint8_t hours, uint8_t minutes, uint8_t seconds, uint8_t tenths);
