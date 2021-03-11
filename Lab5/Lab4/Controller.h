/*
 * Controller.h
 *
 * Created: 2021-03-09 09:38:10
 *  Author: marasp-9
 */ 


#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#include "TinyTimber.h"
#include "GUI.h"
#include "SignalSender.h"

typedef struct{
	Object super;
	GUI* g;
	SignalSender* s;
	uint8_t northQ;
	uint8_t southQ;
	uint8_t CarsOnBridge;
	bool nFlag; //True = North, False = South
	bool sFlag;
	bool pointer;
}Controller;

#define initController(g,s){initObject(), g, s, 0, 0, 0, 0, 0, 0};
	
void carCounter(Controller* this, uint8_t input);
void flagCheck(Controller* this);
void addToBridge(Controller* this, uint8_t add);
#endif /* CONTROLLER_H_ */