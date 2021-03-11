
/*
 * GUI.c
 *
 * Created: 2021-03-03 11:31:24
 *  Author: marcu
 */ 
#include "GUI.h"
void updateGUI0(GUI *this, uint8_t state){
	printAt(state, 0);
}

void updateGUI2(GUI *this, uint8_t state){
	printAt(state, 2);
}

void updateGUI4(GUI *this, uint8_t state){
	printAt(state, 4);
}

void GUIShift(GUI *this){
	if (this->on){
		this->on = !this->on;
		shiftLightsR();
	}
	else{
		this->on = !this->on;
		shiftLightsL();
	}
}