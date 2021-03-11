/*
 * button.c
 *
 * Created: 2021-03-01 09:04:56
 *  Author: marcus
 */ 
#include "button.h"

void buttonInterrupt(button *this){
	

	if (~PINB & (1 << 6)) { // Up
		ASYNC(this->Current, increment, NULL);
	}
	else if (~PINB & (1 << 7)) { // Down
		ASYNC(this->Current, decrement, NULL);
	}
	else if (~PINB & (1 << 4)){ // middle
		ASYNC(this->Current, resetState, NULL);
	}
	else if (~PINE & (1 << 3)){ // RIGHT
		if(this->Current == this->C1)ASYNC(this->Current->gui, GUIShift, 0);
		this->Current = this->C2;
		
	}
	else if (~PINE & (1 << 2)){ //LEFT
		if(this->Current == this->C2)ASYNC(this->Current->gui, GUIShift, 0);
		this->Current = this->C1;
	}
	
	AFTER(MSEC(250), this->Current, hold, this);
	
	
}

void init(button *this){
	
	ASYNC(this->C1->gui, updateGUI0, this->C1->state);
	ASYNC(this->C2->gui, updateGUI4, this->C2->state);
	initJoy();
	LCDInit();
	LCDDR18 = 0x0;
	LCDDR8 = 0x1;
}

void initJoy(){
	DDRB = DDRB & ~((1<<7) | (1<<6) | (1<<4));
	DDRE = DDRE & ~((1<<2) | (1<<3));
	PORTB = PORTB | ((1<<7) | (1<<6) | (1<<4));
	PORTE = PORTE | ((1<<2) | (1<<3));
	
	// Enables external interrupt and sets the interrupt to PCINT15..8
	EIMSK |= (1 << PCIE1) | (1 << PCIE0);
	
	// Enables interrupt on PCINT15
	PCMSK1 |= (1 << PCINT15)|(1 << PCINT14)|(1 << PCINT12);
	PCMSK0 |= (1 << PCINT3)|(1 << PCINT2);
	
	// Sets interrupt control to generate an interruption on a falling edge
	EICRA |= (1 << ISC01);
	
	
}