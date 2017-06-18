#include "Gate.h"

void Gate::ControlSwitch(STATUS x)
{
}

void Gate::setSwitch()
{
}

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	y = new bool[m_Inputs];				//Associate all input pins to this gate
	for (int i = 0; i < m_Inputs; i++)
	{
		y[i] = true;
		m_InputPins[i].setComponent(this);
	}
	Taken = 0;
}

int Gate::getnumofinputs()
{
	return m_Inputs;
}

OutputPin * Gate::getOutputPin()
{
	return &m_OutputPin;
}

InputPin * Gate::getInputPin()
{
	return m_InputPins;
}


void Gate::incrementPin(int i)
{
	Taken += i;
}

void Gate::decrementPin(int i)
{
	Taken -= i;
}

int Gate::getYIn()
{
	y1 = m_InputPins[1].getComponent()->getYcoordiantescorner1();
	y2 = m_InputPins[1].getComponent()->getYcoordiantescorner2();
	y3 = (y1 + y2) / 2;

	if (m_Inputs == 1)
	{
		return y3;
	}
	if (y[0] == 1)
	{
		Taken++;
		y[0] = 0;
		return (y1 + y3) / 2;
	}
	if (y[1] == 1)
	{
		Taken++;
		y[1] = 0;
		return (y2 + y3) / 2;
	}
	if (y[2] == 1)
	{
		Taken++;
		y[1] = 0;
		return y3;
	}


	return 0;
}


int Gate::getTaken()
{
	return Taken;
}

int Gate::getMaxIn()
{
	return m_Inputs;
}

void Gate::changeInput(int dy)
{
	y1 += dy;
	y2 += dy;
	y3 += dy;
}

OutputPin*  Gate::getOPin()
{
	return &m_OutputPin;
}

InputPin * Gate::getIPin(int s = 0)
{
	return m_InputPins;
}

InputPin * Gate::whichInput()
{
	
	if (y[0] == 1)
	{
		return &m_InputPins[0];
	}
	if (y[1] == 1)
	{
		return &m_InputPins[1];
	}
	if (m_Inputs == 3)
	{
		if (y[2] == 1)
		{
			return &m_InputPins[2];
		}
	}
}

void Gate::removeInput()
{
}

bool * Gate::getYarray()
{
	return y;
}

void Gate::decTaken()
{
	Taken--;
}
