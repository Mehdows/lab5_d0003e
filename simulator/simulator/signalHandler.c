
/*
 * signalHandler.c
 *
 * Created: 2021-03-11 10:57:37
 *  Author: marasp-9
 */ 

#include "signalHandler.h"



static struct termios portAttr;




void writePort(signalHandler *this, uint8_t data){
	write(this->serialPORT, &data, 1);
}



void init_serial_port(signalHandler *this){
	
	this->serialPORT = open("/dev/ttyS0", O_RDWR);
	
	if (this->serialPORT == -1) printf("ERROR PORT INIT FAILED!!!!!!");
	
	tcgetattr(this->serialPORT, &portAttr);
	fcntl(this->serialPORT, F_SETFL, O_NONBLOCK);
	
	cfsetospeed(&portAttr, B9600);
	cfsetispeed(&portAttr, B9600);
}


