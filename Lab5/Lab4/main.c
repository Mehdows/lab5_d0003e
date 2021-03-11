/*
 * Lab4.c
 *
 * Created: 2021-03-09 09:07:49
 * Author : marasp-9
 */ 

#include <avr/io.h>
#include "TinyTimber.h"
#include "GUI.h"
#include "Controller.h"
#include "interrupt.h"
#include "LCDprint.h"

int main(void)
{
	initInterrupts();
	initUSART();
	LCDInit();
	
	SignalSender s = initSignalSender();
	GUI G = initGUI();
	Controller C = initController(&G, &s);
	Interrupt i = initInterrupt(&C);
	
	
	
	INSTALL(&i, signalInterrupt, IRQ_USART0_RX);
	TINYTIMBER(NULL, NULL, NULL);
}

