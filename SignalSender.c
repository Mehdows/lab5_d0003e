/*
 * SignalSender.h
 *
 * Created: 2021-03-09 10:03:30
 *  Author: marasp-9
 */ 


#include "SignalSender.h"

void greenSouth(SignalSender* this){
	UDR0 = SouthGreen;
}

void greenNorth(SignalSender* this){
	UDR0 = NorthGreen;	
}

void totalStop(SignalSender* this){
	UDR0 = TotalStop;
}