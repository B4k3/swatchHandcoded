#include "../libs/Widget.h"
#include "graphic.h"

uint8_t dHours 	 = 0;
uint8_t dMinutes = 0;
uint8_t dSeconds = 0;
uint8_t dTenths	 = 0;


void init_screen(){

}

void draw_hour(uint8_t hours){
	if(dHours != hours){

		dHours = hours;
	}
}

void draw_minutes(uint8_t minutes){
	if(dMinutes != minutes){

		dMinutes = minutes;
	}
}

void draw_seconds(uint8_t seconds){
	if(dSeconds != seconds){

		dSeconds = seconds;
	}
}

void draw_tenths(uint8_t tenths){


	dTenths = tenths;

}

