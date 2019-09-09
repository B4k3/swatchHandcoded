#include "../libs/Widget.h"
#include "../libs/WidgetConfig.h"

#include "graphic.h"


uint8_t dHours 	 = 0;
uint8_t dMinutes = 0;
uint8_t dSeconds = 0;
uint8_t dTenths	 = 0;


void init_screen(){
	WPrint(&MyWatchScr[SEP1STR], ":");
	WPrint(&MyWatchScr[SEP2STR], ":");
}

void draw_hour(uint8_t hours){
	char str[3];

	if(dHours != hours){
		decode_twodigitnumber(hours,str);
		Wclear(&MyWatchScr[HRSSTR]);
		WPrint(&MyWatchScr[HRSSTR], hours);
		dHours = hours;
	}
}

void draw_minutes(uint8_t minutes){
	char str[3];

	if(dMinutes != minutes){
		decode_twodigitnumber(minutes,str);
		Wclear(&MyWatchScr[MINSTR]);
		WPrint(&MyWatchScr[MINSTR], minutes);
		dMinutes = minutes;
	}
}

void draw_seconds(uint8_t seconds){
	char str[3];

	if(dSeconds != seconds){
		decode_twodigitnumber(seconds,str);
		Wclear(&MyWatchScr[SECSTR]);
		WPrint(&MyWatchScr[SECSTR], seconds);
		dSeconds = seconds;
	}
}

void draw_tenths(uint8_t tenths){
	char str[2];
	decode_singledigitnumber(tenths,str);
	Wclear(&MyWatchScr[TTSSTR]);
	WPrint(&MyWatchScr[TTSSTR], tenths);
	dTenths = tenths;
}

void decode_twodigitnumber(uint8_t digit,char* str){
	str[2]=0;
	str[0]=digit/10+'0';
	str[1]=digit%10+'0';
}

void decode_singledigitnumber(uint8_t digit,char* str){
	str[1] = 0;
	str[0] = digit%10+'0';
}

void switchMode(){}




