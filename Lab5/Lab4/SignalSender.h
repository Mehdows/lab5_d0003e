/*
 * SignalSender.h
 *
 * Created: 2021-03-09 10:03:17
 *  Author: marasp-9
 */ 


#ifndef SIGNALSENDER_H_
#define SIGNALSENDER_H_

#include <stdint.h>

#include "TinyTimber.h"
#include "avr/io.h"



#define TotalStop 0xA
#define NorthGreen 0x9
#define SouthGreen 0x6

typedef	struct{
	Object super;
}SignalSender;

#define initSignalSender(){initObject()};

void greenNorth(SignalSender* this);
void greenSouth(SignalSender* this);
void totalStop(SignalSender* this);

#endif /* SIGNALSENDER_H_ */