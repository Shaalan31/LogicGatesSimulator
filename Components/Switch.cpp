#include "Switch.h"

void Switch::ControlSwitch(STATUS x)
{
	stat = x;
	m_OutputPin.setStatus(x);

}

Switch::Switch(const GraphicsInfo &r_GfxInfo, int r_FanOut) :m_OutputPin(r_FanOut)
{
	selected = false;
	type = SWITCH;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

// Function to Draw Switch
void Switch::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if (getselected() == 0)
		pOut->DrawSWITCH(m_GfxInfo);
	else
		pOut->DrawSWITCH(m_GfxInfo, 1);
	pOut->PrintString(getXcoordiantescorner1(), getYcoordiantescorner1() - 20, m_Label);
}

int Switch::getXcoordiantescorner1()
{
	return m_GfxInfo.x1;
}

int Switch::getYcoordiantescorner1()
{
	return m_GfxInfo.y1;
}

int Switch::getXcoordiantescorner2()
{
	return m_GfxInfo.x2;
}

int Switch::getYcoordiantescorner2()
{
	return m_GfxInfo.y2;
}

bool Switch::checkArea(int x, int y)
{
	if ((x >= getXcoordiantescorner1()) && (y >= getYcoordiantescorner1()) && (x <= getXcoordiantescorner2()) && (y <= getYcoordiantescorner2()))
	{
		return true;
	}

	return false;
}

bool Switch::checkempty(int x, int y, GraphicsInfo GI)
{
	int xedge1, xedge2, yedge1, yedge2;
	xedge1 = x - 25;
	xedge2 = x + 25;
	yedge1 = y - 25;
	yedge2 = y + 25;
	if (((xedge1 >= GI.x1) && (xedge1 <= GI.x2)) || ((yedge2 >= GI.y1) && (yedge2 <= GI.y2)))
	{
		return false;
	}
	return true;
}

//returns status of outputpin
int Switch::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}
//Set status HIGH or LOW
void Switch::setSwitch()
{
	if (stat == HIGH)
		stat = LOW;
	else
		stat = HIGH;
	m_OutputPin.setStatus(stat);
}
void Switch::Operate(){}
//void Switch::setInputPinStatus(int n, STATUS s) {}
int Switch::GetInputPinStatus(int n) { return 0; }

//int Switch::GetInputPinStatus(int n) { return 0; }
OutputPin * Switch::getOutputPin()
{
	return &m_OutputPin;
}
InputPin * Switch::getInputPin()
{
	return nullptr;
}
int Switch::getnumofinputs()
{
	return 0;
}
void Switch::setInputPinStatus(int n, STATUS s)
{
}
int Switch::getMaxIn()
{
	return 0;
}
int Switch::getTaken()
{
	return 0;
}
void Switch::changeInput(int dy)
{
}
int Switch::getYIn()
{
	return 0;
}
OutputPin * Switch::getOPin()
{
	return &m_OutputPin;
}
InputPin * Switch::getIPin(int)
{
	return nullptr;
}

InputPin * Switch::whichInput()
{
	return nullptr;
}

void Switch::decTaken()
{
}

bool * Switch::getYarray()
{
	return nullptr;
}

void Switch::removeInput()
{
}
