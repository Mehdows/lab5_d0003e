/*
 * interrupt.h
 *
 * Created: 2021-03-09 09:37:53
 *  Author: marasp-9
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include "TinyTimber.h"
#include "Controller.h"
#include "avr/io.h"
#include <stdint.h>
#include "GUI.h"

#define BAUD 9600
#define FOSC 8000000UL

#define UBRR (((FOSC / (BAUD * 16UL))) - 1)

typedef struct{
	Object super;
	Controller* c;
} Interrupt;


#define initInterrupt(controller) {initObject(), controller};


void signalInterrupt(Interrupt* self);
void initUSART();
void initInterrupts();

#endif /* INTERRUPT_H_ */