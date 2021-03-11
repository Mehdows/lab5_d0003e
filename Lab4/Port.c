
/*
 * Port.c
 *
 * Created: 2021-03-03 15:08:05
 *  Author: marcu
 */ 
#include "Port.h"

void invertPort(Port *this, uint8_t port){
	PORTE ^= (1<<port);
}
void resetPort(Port *this, uint8_t port){
	PORTE &= ~(1<<port);
}