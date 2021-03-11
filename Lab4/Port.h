
/*
 * Port.h
 *
 * Created: 2021-03-03 15:08:17
 *  Author: marcu
 */ 
#include <avr/io.h>
#include "TinyTimber.h"

typedef struct{
	Object super;
	}Port;

#define initPort(p){initObject(), p}
	
void invertPort(Port *this, uint8_t port);
void resetPort(Port *this, uint8_t port);