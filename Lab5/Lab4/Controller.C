
/*
 * Controller.C
 *
 * Created: 2021-03-09 09:24:38
 *  Author: marasp-9
 */ 
#include "Controller.h"

#define WAIT SEC(5)

void carCounter(Controller* this, uint8_t input){
	
	if (input & 1){ // Car enters bridge from north
		this->northQ++;
		this->nFlag = 1; 
		
		ASYNC(this, flagCheck, 0);
		ASYNC(this->g, updateGUI0, this->northQ); 
	}
	else if ((input >> 1) & 1){ // Car enters bridge from north
		this->CarsOnBridge++;
		this->northQ--;
		this->pointer = 0;
		ASYNC(this, addToBridge, 1);
		if (this->northQ == 0) {
			this->nFlag = 0; 
			ASYNC(this->s, totalStop, 0);
			AFTER(WAIT, this, flagCheck, 0);
		}
		else if (this->CarsOnBridge == 5) ASYNC(this, flagCheck, 0);
		
		ASYNC(this->g, updateGUI0, this->northQ);
	}
	else if ((input >> 2) & 1 ){ // Car enters Q from south
		this->southQ++;
		this->sFlag = 1;
		
		ASYNC(this, flagCheck, 0);
		ASYNC(this->g, updateGUI4, this->southQ);
	}
	else if ((input >> 3) & 1){ // Car enters bridge from south
		this->CarsOnBridge++;
		this->southQ--;
		this->pointer = 1;
		ASYNC(this, addToBridge, 1);
		if (this->southQ == 0) {
			this->sFlag = 0;
			ASYNC(this->s, totalStop, 0);
			AFTER(WAIT, this, flagCheck, 0);
		}
		else if (this->CarsOnBridge == 5) ASYNC(this, flagCheck, 0);
		
		ASYNC(this->g, updateGUI4, this->southQ);
	}
}


void flagCheck(Controller* this){
	
	if(this->nFlag == 0 && this->sFlag == 0){ // both queue empty
		ASYNC(this->s, totalStop, 0);
	}
	else if(this->nFlag == 1 && this->sFlag == 0){ // both queue empty
		ASYNC(this->s, greenNorth, 0);
	}
	else if(this->nFlag == 0 && this->sFlag == 1){ // both queue empty
		ASYNC(this->s, greenSouth, 0);
	}
	else if(this->nFlag == 1 && this->sFlag == 1){
		
		if (this->pointer){
			ASYNC(this->s, totalStop, 0);
			AFTER(WAIT, this->s, greenNorth, 0);
		}
		else{
			ASYNC(this->s, totalStop, 0);
			AFTER(WAIT, this->s, greenSouth, 0);
		}
		this->pointer = !this->pointer;
	}
}



void addToBridge(Controller* this, uint8_t add){
	
	if(add == 1){
		ASYNC(this->g, updateGUI2, this->CarsOnBridge);
		AFTER(WAIT, this, addToBridge, 0);
	}
	else{
		this->CarsOnBridge--;
		ASYNC(this->g, updateGUI2, this->CarsOnBridge);
		//if(this->CarsOnBridge == 0) ASYNC(this, flagCheck, 0);
	}
}