#include "../libs/Widget.h"
#include "../libs/WidgetConfig.h"
#include "../libs/types.h"
#include "graphic.h"


uint8_T dHours 	 = 99;
uint8_T dMinutes = 99;
uint8_T dSeconds = 9;
uint8_T dTenths	 = 9;
State actual_mode = TimeDisplay;

bool_t showTenths 	= 0;
bool_t showSeconds	= 1;


void decode_twodigitnumber(uint8_T digit,char* str){
	str[2]=0;
	str[0]=digit/10+'0';
	str[1]=digit%10+'0';
}

void decode_singledigitnumber(uint8_T digit,char* str){
	str[1] = 0;
	str[0] = digit%10+'0';
}


void init_screen(){
	WPrint(&MyWatchScr[SEP1STR], ":");
	WPrint(&MyWatchScr[SEP2STR], ":");
	update_interface(TimeDisplay,1,1,1,1);
}

void draw_hours(uint8_T hours){
	char str[3];

	if(dHours != hours){
		decode_twodigitnumber(hours,str);
		//Wclear(&MyWatchScr[HRSSTR]);
		WPrint(&MyWatchScr[HRSSTR], str);
		dHours = hours;
	}
}

void draw_minutes(uint8_T minutes){
	char str[3];

	if(dMinutes != minutes){
		decode_twodigitnumber(minutes,str);
		//Wclear(&MyWatchScr[MINSTR]);
		WPrint(&MyWatchScr[MINSTR], str);
		dMinutes = minutes;
	}
}

void draw_seconds(uint8_T seconds){
	char str[3];

	if(dSeconds != seconds){
		decode_twodigitnumber(seconds,str);
		//Wclear(&MyWatchScr[SECSTR]);
		WPrint(&MyWatchScr[SECSTR], str);
		dSeconds = seconds;
	}
}

void draw_tenths(uint8_T tenths){
	char str[2];
	decode_singledigitnumber(tenths,str);
	//Wclear(&MyWatchScr[TTSSTR]);
	WPrint(&MyWatchScr[TTSSTR], str);
	dTenths = tenths;
}

void show_tenth(){
	showTenths = 1;
	WPrint(&MyWatchScr[SEP3STR], ".");
}

void hide_tenth(){
	showTenths = 0;
	//Wclear(&MyWatchScr[SEP3STR]);
	//Wclear(&MyWatchScr[TTSSTR]);
}

void show_seconds(){
	showSeconds = 1;
	WPrint(&MyWatchScr[SEP2STR], ":");
}

void hide_seconds(){
	showSeconds = 0;
	//Wclear(&MyWatchScr[SEP2STR]);
	//Wclear(&MyWatchScr[SECSTR]);
}

void switchMode(uint8_t mode){
	switch(mode){
		case StopWatch:
			actual_mode = StopWatch;
			if(showTenths){
				hide_tenth();
			}
			if(!showSeconds){
				show_seconds();
			}
			break;
		case TimeDisplay:
			actual_mode = TimeDisplay;
			if(showTenths){
				hide_tenth();
			}
			if(!showSeconds){
				show_seconds();
			}
			break;
		case TimeSet:
			actual_mode = TimeSet;
			if(showTenths){
				hide_tenth();
			}
			if(showSeconds){
				hide_seconds();
			}
			break;
		case AlarmSet:
			actual_mode = AlarmSet;
			if(!showTenths){
				show_tenth();
			}
			if(showSeconds){
				hide_seconds();
			}
			break;
	}
}

void update_interface(State mode, uint8_t hours, uint8_t minutes, uint8_t seconds, uint8_t tenths){
	if(mode != actual_mode)
		switchMode(mode);
	draw_hours(hours);
	draw_minutes(minutes);
	if(showSeconds)
		draw_seconds(seconds);
	if(showTenths)
		draw_tenths(tenths);
}




