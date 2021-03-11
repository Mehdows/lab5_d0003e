
/*
 * GUI.h
 *
 * Created: 2021-03-03 11:34:58
 *  Author: marcus
 */ 
#ifndef GUI_H
#define GUI_H

#include "TinyTimber.h"
#include "LCDprint.h"
typedef struct{
	Object super;
	bool on;
	}GUI;
#define initGUI(){initObject(), false}
	
void updateGUI0(GUI *this, uint8_t state);
void updateGUI2(GUI *this, uint8_t state);
void updateGUI4(GUI *this, uint8_t state);
void GUIShift(GUI *this);

#endif

	