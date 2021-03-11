/*
 * button.h
 *
 * Created: 2021-03-01 09:17:24
 *  Author: marcu
 */ 
#ifndef BUTTON_H

#include <avr/io.h>
#include <stdbool.h>
#include "TinyTimber.h"
#include "PulseCounter.h"

#define TinyTime MSEC(250)

typedef struct{
	Object super;
	PulseCounter* C1;
	PulseCounter* C2;
	PulseCounter* Current;
	}button;
	
#define initButton(c1, c2){initObject(), c1, c2, c1}

void buttonInterrupt(button *this);
void hold();
void init();
void initJoy();

#endif
