/*
 * WidgetConfig.c
 *
 *  Created on: 21/ott/2015
 *      Author: admim
 */

#include "Widget.h"
#include "WidgetConfig.h"
#include "../graphics/pictures.h"
#include "../graphics/graphic.h"
#include <stdio.h>
#include "stm32f4_discovery_lcd.h"
#include "fonts.h"

ButtonIcon buttontime = {
		icontime_on, icontime_off, TIMEMODE
};

ButtonIcon buttontimeset = {
		icontimeset_on, icontimeset_off, TIMESETMODE
};

ButtonIcon buttonalarm = {
		iconalarm_on, iconalarm_off, ALARMMODE
};

ButtonIcon buttonswatch = {
		iconswatch_on, iconswatch_off, SWATCHMODE
};

ButtonIcon buttonplus = {
		0, 0, PLUS
};

ButtonIcon buttonminus = {
		0, 0, MINUS
};

Text txt = {
		&Font32x48, White
};

Image backg = {
	ImageBuffer
};

const Widget MyWatchScr[NUMWIDGETS] = {
		{0, 0, 320, 240, BACKGROUND, (void *)&backg},				//0
		{30, 188, 39, 43, BUTTONICON, (void *)&buttontime},			//1
		{98, 188, 39, 43, BUTTONICON, (void *)&buttontimeset},		//2
		{169, 188, 38, 43, BUTTONICON, (void *)&buttonalarm},		//3
		{244, 188, 35, 43, BUTTONICON, (void *)&buttonswatch},		//4
		{270, 30, 40, 40, BUTTONICON, (void *)&buttonplus},			//5
		{270, 105, 40, 40, BUTTONICON, (void *)&buttonminus},		//6
//		{26, 76, 100, 32, RECTANGLE, (void *)&rectangle}
		{29, 70, 40, 40, TEXT, (void *)&txt},						//7
		{80, 70, 40, 40, TEXT, (void *)&txt},						//8
		{130, 70, 40, 40, TEXT, (void *)&txt},						//9
		{180, 70, 40, 40, TEXT, (void *)&txt},						//10
		{70, 70, 40, 40, TEXT, (void *)&txt},						//11
		{120, 70, 40, 40, TEXT, (void *)&txt},						//12
		{170, 70, 40, 40, TEXT, (void *)&txt},						//13
};

