/*
 * Lab4.c
 *
 * Created: 2021-02-27 10:24:04
 * Author : marcu
 */ 

#include <avr/io.h>

#include "TinyTimber.h"
#include "LCDprint.h"
#include "button.h"
#include "PulseCounter.h"

int main(void)
{
	Port port = initPort();
	GUI gui = initGUI();
	
	PulseCounter p1 = InitPulseCounter(0, 4, &port, &gui);
	PulseCounter p2 = InitPulseCounter(4, 6, &port, &gui);
	
	button b = initButton(&p1, &p2);
	
	INSTALL(&b, buttonInterrupt, IRQ_PCINT0);
	INSTALL(&b, buttonInterrupt, IRQ_PCINT1);
	
	return TINYTIMBER(&b, init, 0);
	
}

