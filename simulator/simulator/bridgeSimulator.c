
/*
 * bridgeSimulator.S
 *
 * Created: 2021-03-11 10:58:22
 *  Author: marasp-9
 */ 
#include "bridgeSimulator.h"

#define second 1000000;

uint8_t Car_Ques_North    = 0x1,
		Car_Enters_North  = 0x2,
		Car_Ques_South    = 0x4,
		Car_Enters_South  = 0x8;

void qToBridge(int *carQ, int *greenLight, int *bridgeAmount){
	while (&greenLight == 1){
		carQ--;
		bridgeAmount++;
		usleep(second);		
	}
}

void offBridge(){
	while(bridgeAmount > 0){
		usleep(5*second);
		bridgeAmount--;	
	}
}

void userInput(bridgeSimulator *this){
	while (1){
		char c = getchar( );
		
		switch(c){
			case 'n':
			this->carQNorth++;
			writePort(this->sig, Car_Ques_North);
			break;
			case 's':
			this->carQSouth++;
			writePort(this->sig, Car_Ques_South);
			break;
			case 'e':
			//exit(-1);
			break;
		}
	}
}