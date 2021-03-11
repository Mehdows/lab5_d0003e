
/*
 * PulseCounter.h
 *
 * Created: 2021-03-02 10:11:38
 *  Author: marcu
 */ 
#ifndef PULSECOUNTER_H
#define PULSECOUNTER_H

#include "TinyTimber.h"
#include "LCDprint.h"
#include "GUI.h"
#include "Port.h"

#define lenght 2
#define TinyTime MSEC(250)

typedef struct{
	Object super;
	uint8_t state;
	uint8_t reset;
	bool on;
	GUI* gui;
	uint8_t pos;
	uint8_t pin;
	Port* p;
	bool active;
}PulseCounter;
	
#define InitPulseCounter(pos, portPos, p, g){initObject(), 0, 0, 0, g, pos, portPos, p, false}

void increment(PulseCounter *this);
void decrement(PulseCounter *this);
void resetState(PulseCounter *this);
void shiftRight(PulseCounter *this);
void shiftLeft(PulseCounter *this);
void hold(PulseCounter *this);
void pulseGen(PulseCounter *this);

#endif