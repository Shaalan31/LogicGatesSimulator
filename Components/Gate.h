#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"

class Gate:public Component
{
protected:
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	int m_Inputs;		//No. of input pins of that Gate.
	int Taken;			//No. of pins actually taken
	bool *y;	//y axis of the input
	int y1;
	int y2;
	int y3;
public:
	virtual void ControlSwitch(STATUS x);
	virtual void setSwitch();
	Gate(int r_Inputs, int r_FanOut);
	int getnumofinputs();
	OutputPin* getOutputPin();
	InputPin* getInputPin();
	void incrementPin(int i = 1);
	void decrementPin(int i = 1);
	int getYIn();
	int getTaken();
	int getMaxIn();
	void changeInput(int dy);
	OutputPin* getOPin();
	InputPin* getIPin(int);

	InputPin *whichInput();
	void removeInput();
	bool* getYarray();
	void decTaken();
};

#endif
