
/*
 * signalHandler.h
 *
 * Created: 2021-03-11 10:57:52
 *  Author: marasp-9
 */ 
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



typedef struct{
	int serialPORT;
	}signalHandler;

#define initSignalHandler(){0};
	
void writePort(signalHandler *this, uint8_t data);
void init_serial_port(signalHandler *this);