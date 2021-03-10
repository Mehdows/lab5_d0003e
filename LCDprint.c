/*
 * LCDprint.c
 *
 * Created: 2021-02-27 11:07:23
 *  Author: marcu
 */ 
#include "LCDprint.h"

void LCDInit(void) {
	
	/* Lowpower Waveform, no frame interrupt, no blanking. LCD Enable*/
	LCDCRA = (1 << LCDAB) | (1 << LCDEN);
	
	/* 300 microseconds & voltage 3.35 V.*/
	LCDCCR = (1 << LCDCC0) | (1 << LCDCC1) | (1 << LCDCC2) | (1 << LCDCC3);
	
	/* 1/3 bias, 1/4 duty cycle, 25 segments.*/
	LCDCRB = (1 << LCDCS) | (1<< LCDMUX0) | (1<< LCDMUX1) | (1 <<LCDPM0) | (1 <<LCDPM1) | (1 <<LCDPM2);
	
	/* N=16 & D=8 */
	LCDFRR = (1 << LCDCD0) | (1 << LCDCD1) | (1 << LCDCD2);
	
	printAt(00, 0);
	printAt(00, 2);
	printAt(00, 4);

}

//Writes character ch on position pos
void writeChar(char ch, int pos){
	// The start address on the LCD
	uint8_t *lcdAdress = (uint8_t *) 0xec;
	
	// To get the nibble
	uint8_t mask;
	
	// Sent to LCD
	uint8_t nibble = 0x0;
	
	//The numbers from 0-9
	uint16_t sccNumbers[10] = {0x1551, 0x0110, 0x1e11, 0x1b11, 0x0b50, 0x1b41, 0x1f41, 0x0111, 0x1f51, 0x0b51};
	
	
	//input char within range
	if (pos<0 || pos > 5){
		return;
	}
	
	//The number to use
	uint16_t nr = 0x0;
	
	//Lookup LCD segment control code (SCC) in LCD character table
	if(ch>= '0' || ch <= '9'){
		
		// Get the number from our array (sub with zero because its the first in the ascii table)
		nr = sccNumbers[ch - '0'];
	}
	
	//Point to the right position
	lcdAdress += pos >> 1;
	
	if(pos % 2 == 0){
		mask = 0xf0;
	}
	else {
		mask = 0x0f;
	}
	
	for(int i = 0; i < 4; i++){
		
		nibble = nr & 0xf;
		nr = nr >> 4;
		
		if(pos % 2 != 0){
			nibble = nibble << 4;
		}
		
		*lcdAdress = (*lcdAdress & mask) | nibble;
		
		lcdAdress += 5;
		
	}
	
}
void printAt(long num, int pos) {
	int pp = 0;
	pp = pos;
	writeChar( (num % 100) / 10 + '0', pp);
	pp++;

	writeChar( num % 10 + '0', pp);
}

void shiftLightsR(){
	LCDDR18 = 0x0;
	LCDDR8 = 0x1;
}

void shiftLightsL(){
	LCDDR18 = 0x1;
	LCDDR8 = 0x0;
}



