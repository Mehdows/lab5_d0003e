
/*
 * PulseCounter.c
 *
 * Created: 2021-03-02 10:11:04
 *  Author: marcu
 */ 
 #include "PulseCounter.h"
 void increment(PulseCounter *this){
	 if(this->state < 99) this->state++;
	 if(!this->active) ASYNC(this, pulseGen, 0);
	 
	 if (this->pos == 4){
		 ASYNC((this->gui), updateGUI4, this->state);
	 }
	 else {
		 ASYNC(this->gui, updateGUI0, this->state);
	 }
  }
  
 void decrement(PulseCounter *this){
	 if(this->state > 0){
		 this->state--;
	 }
	 if (this->pos == 4){
		 ASYNC((this->gui), updateGUI4, this->state);
	 }
	 else {
		 ASYNC(this->gui, updateGUI0, this->state);
	 }
 }
  
  void resetState(PulseCounter *this){
	  if (this->state==0)
	  {
		  this->state = this->reset;
	  }
	  else{
		this->reset = this->state;
		this->state = 0;  
	  }
	  if (!this->active) ASYNC(this, pulseGen, 0);
	  
	  if (this->pos == 4){
		  ASYNC((this->gui), updateGUI4, this->state);
	  }
	  else {
		  ASYNC(this->gui, updateGUI0, this->state);
	  }
    }
	
	
void hold(PulseCounter *this){
		if (~PINB & (1 << 6))
		{
			ASYNC(this, increment, NULL);
			AFTER(TinyTime, this, hold, 0);
		}
		else if (~PINB & (1 << 7))
		{
			ASYNC(this, decrement, NULL);
			AFTER(TinyTime, this, hold, 0);
		}
	}

void pulseGen(PulseCounter *this){
	
	if(this->state > 0){
		this->active = true;
		ASYNC(this->gui, invertPort, this->pin);
		AFTER(USEC(500000/this->state), this, pulseGen, 0);
	}
	else
	{
		this->active = false;
		ASYNC(this->gui, resetPort, this->pin);
	}
	
	
}
