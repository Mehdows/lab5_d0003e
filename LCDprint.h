/*
 * LCDprint.h
 *
 * Created: 2021-02-27 11:07:49
 *  Author: marcu
 */ 
#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>

void LCDInit(void);
void writeChar(char ch, int pos);
void printAt(long num, int pos);
void shiftLightsR();
void shiftLightsL();