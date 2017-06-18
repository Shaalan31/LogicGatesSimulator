#include "ComplexBlocks.h"



ComplexBlocks::ComplexBlocks(Component ** arrayComp, Connection** arrayConn,int compCount,int connCount)
{

	NumLed = 0;
	NumSwitch = 0;
	for (int i = 0; i < compCount; i++)
		Comp[i] = arrayComp[i];
	for (int i = 0; i < connCount; i++)
		Conn[i] = arrayConn[i];

	for (int i = 0; i < compCount; i++)
	{
		if (arrayComp[i]->gettype() == SWITCH)
			arrayofSwitches[NumSwitch++] = arrayComp[i];
		else if (arrayComp[i]->gettype() == Led)
			arrayofLeds[NumLed++] = arrayComp[i];
	}

	m_Inputs = new InputPin[NumSwitch];
	for (int i = 0; i < NumSwitch; i++)
	{
		//y[i] = true;
		m_Inputs[i].setComponent(this);
	}
	m_Outputs = new OutputPin*[NumLed];
	for (int i = 0; i < NumLed; i++)
	{
		m_Outputs[i] = new OutputPin(5);
	}
	Ginfo.x1 = 500;
	Ginfo.x2 = 550;
	Ginfo.y1 = 500;
	Ginfo.y2 = 550;
}


ComplexBlocks::~ComplexBlocks()
{
}



void ComplexBlocks::setSwitch(){}
void ComplexBlocks::ControlSwitch(STATUS x){}
//ComponentType gettype(){}
OutputPin* ComplexBlocks::getOutputPin()
{
	return m_Outputs[0];
}
InputPin* ComplexBlocks::getInputPin()
{
	return m_Inputs;
}
int ComplexBlocks::getnumofinputs()
{
	return NumSwitch;
}
void ComplexBlocks::Operate(){}	//Calculates the output according to the inputs
void ComplexBlocks::Draw(Output* pOut){}	//for each component to Draw itself
int ComplexBlocks::getXcoordiantescorner1() { return Ginfo.x1; }
int ComplexBlocks::getYcoordiantescorner1() { return Ginfo.x2; }
int ComplexBlocks::getXcoordiantescorner2() { return Ginfo.y1; }
int ComplexBlocks::getYcoordiantescorner2() { return Ginfo.y2; }
bool ComplexBlocks::checkEmpty(int x, int y, GraphicsInfo GI) { return true; }

int ComplexBlocks::GetOutPinStatus() { return 0; }	//returns status of outputpin if LED, return -1
int ComplexBlocks::GetInputPinStatus(int n) { return 0; }	//returns status of Inputpin # n if SWITCH, return -1
void ComplexBlocks::setInputPinStatus(int n, STATUS s) { m_Inputs[n].setStatus(s); }	//set status of Inputpin # n, to be used by connection class.


int ComplexBlocks::getTaken() { return 0; }
void ComplexBlocks::changeInput(int dy){}
int ComplexBlocks::getYIn()
{
	return (50 / (NumSwitch-taken));
}

OutputPin* ComplexBlocks::getOPin() { return m_Outputs[0]; }
InputPin* ComplexBlocks::getIPin(int x) { return m_Inputs; }


InputPin* ComplexBlocks::whichInput()
{
	for (int i = 0; i < NumSwitch; i++)
	{
		if (y[i] == true)
			return &m_Inputs[i];
	}
}
void ComplexBlocks::decTaken(){}
bool* ComplexBlocks::getYarray() { return y; }
void ComplexBlocks::removeInput(){}