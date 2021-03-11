/*
 * simulator.c
 *
 * Created: 2021-03-09 13:05:44
 * Author : marasp-9
 */ 

//#include <avr/io.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "bridgeSimulator.h"
#include "signalHandler.h"


int main(void){
	
	
	signalHandler s = initSignalHandler();
	bridgeSimulator b = initBridgeSimulator(&s);
	
	init_serial_port(&s);


	while (1)
	{
		userInput(&b);
	}
	
}

