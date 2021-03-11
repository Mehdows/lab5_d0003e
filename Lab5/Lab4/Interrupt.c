
/*
 * interrupt.c
 *
 * Created: 2021-03-09 09:36:16
 *  Author: marasp-9
 */ 
#include "interrupt.h"

void signalInterrupt(Interrupt* this){
	uint8_t data = UDR0;
	
	ASYNC(this->c, carCounter, data);
}


void initInterrupts(){
	
	EIFR = 0xC0;
	
	EIMSK = 0xC0;
	
}


void initUSART(){
	
	UBRR0H = UBRR >> 8;
	UBRR0L = UBRR;
	
	UCSR0B = (1<<RXCIE0)|(1<<RXEN0)|(1<<TXEN0);
	
	UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
	
	
}