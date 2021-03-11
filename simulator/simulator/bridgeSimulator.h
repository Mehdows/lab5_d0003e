/*
 * bridgeHandler.h
 *
 * Created: 2021-03-11 10:59:00
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
	signalHandler *sig;
	int carQNorth;
	int carQSouth;
	int bridgeCount;
	int redLightNorth;
	int greenLightNorth;
	int redLightSouth;
	int greenLightSouth;
	
	}bridgeSimulator;

#define initBridgeSimulator(s){s, 0, 0, 0, 1, 0, 1, 0};
	
void userInput(bridgeSimulator *this);