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


void decode_twodigitnumber(uint8_T digit,char *str){
	str[2]=0;
	str[0]=digit/10+'0';
	str[1]=digit%10+'0';
}

void decode_singledigitnumber(uint8_T digit,char *str){
	str[1] = 0;
	str[0] = digit%10+'0';
}

void drawUpdate(State old, State new_state){
	//debuginfo(0,0,showTenths,showSeconds);
	switch(old){
	case TimeDisplay:
		DrawOff(&MyWatchScr[1]);
		break;
	case TimeSet:
		DrawOff(&MyWatchScr[2]);
		break;
	case StopWatch:
		DrawOff(&MyWatchScr[4]);
		break;
	case AlarmSet:
		DrawOff(&MyWatchScr[3]);
		break;
	}
	switch(new_state){
	case TimeDisplay:
		DrawOn(&MyWatchScr[1]);
		break;
	case TimeSet:
		DrawOn(&MyWatchScr[2]);
		break;
	case StopWatch:
		DrawOn(&MyWatchScr[4]);
		break;
	case AlarmSet:
		DrawOn(&MyWatchScr[3]);
		break;
	}
}

void init_screen(){
	DrawInit(MyWatchScr);
	LCD_SetTextColor(Black);
	LCD_SetBackColor(Black);
	LCD_DrawFullRect(28, 62, 200, 56);
	WPrint(&MyWatchScr[SEP1STR], ":");
	WPrint(&MyWatchScr[SEP2STR], ":");
	update_interface(TimeDisplay,0,0,0,0);
	DrawOn(&MyWatchScr[1]);
}

void draw_hours(uint8_T hours){
	char str[3];

	if(dHours != hours){
		decode_twodigitnumber(hours,str);
		Wclear(&MyWatchScr[HRSSTR]);
		WPrint(&MyWatchScr[HRSSTR], str);
		dHours = hours;
	}
}

void draw_minutes(uint8_T minutes){
	char str[3];

	if(dMinutes != minutes){
		decode_twodigitnumber(minutes,str);
		Wclear(&MyWatchScr[MINSTR]);
		WPrint(&MyWatchScr[MINSTR], str);
		dMinutes = minutes;
	}
}

void draw_seconds(uint8_T seconds){
	char str[3];

	if(dSeconds != seconds){
		decode_twodigitnumber(seconds,str);
		Wclear(&MyWatchScr[SECSTR]);
		WPrint(&MyWatchScr[SECSTR], str);
		dSeconds = seconds;
	}
}

void draw_tenths(uint8_T tenths){
	char str[2];

	//if(dTenths != tenths){
	decode_singledigitnumber(tenths,str);
	Wclear(&MyWatchScr[TTSSTR]);
	WPrint(&MyWatchScr[TTSSTR], str);
	dTenths = tenths;
	//}
}

void show_tenth(){
	showTenths = 1;
	WPrint(&MyWatchScr[SEP3STR], ".");
}

void hide_tenth(){
	showTenths = 0;
	Wclear(&MyWatchScr[SEP3STR]);
	Wclear(&MyWatchScr[TTSSTR]);
}

void show_seconds(){
	showSeconds = 1;
	WPrint(&MyWatchScr[SEP2STR], ":");
}

void hide_seconds(){
	showSeconds = 0;
	Wclear(&MyWatchScr[SEP2STR]);
	Wclear(&MyWatchScr[SECSTR]);
}

void switchMode(State state){
	State old_mode = actual_mode;
	switch(state){
		case StopWatch:
			actual_mode = StopWatch;
			if(showTenths == 0){
				show_tenth();
			}
			if(showSeconds == 0){
				show_seconds();
			}
			break;
		case TimeDisplay:
			actual_mode = TimeDisplay;
			if(showTenths == 1){
				hide_tenth();
			}
			if(showSeconds == 0){
				show_seconds();
			}
			break;
		case TimeSet:
			actual_mode = TimeSet;
			if(showTenths == 1){
				hide_tenth();
			}
			if(showSeconds == 1){
				hide_seconds();
			}
			break;
		case AlarmSet:
			actual_mode = AlarmSet;
			if(showTenths == 1){
				hide_tenth();
			}
			if(showSeconds == 1){
				hide_seconds();
			}
			break;
	}
	drawUpdate(old_mode,actual_mode);
}

void update_interface(State state, uint8_T hours, uint8_T minutes, uint8_T seconds, uint8_T tenths){
	if(state != actual_mode)
		switchMode(state);
	draw_hours(hours);
	draw_minutes(minutes);
	if(showSeconds == 1)
		draw_seconds(seconds);
	if(showTenths == 1)
		draw_tenths(tenths);

}




