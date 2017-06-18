#include "LED.h"

void LED::ControlSwitch(STATUS x)
{
}
LED::LED(const GraphicsInfo &r_GfxInfo, int r_FanOut)
{
	selected = false;
	type = Led;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	m_InputPin = new InputPin[1];
	y = new bool[1];
	y[0] = true;
	m_InputPin[0].setComponent(this);
}

// Function to Draw Switch
void LED::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if (getselected() == 0)
		pOut->DrawLED(m_GfxInfo);
	else
		pOut->DrawLED(m_GfxInfo, 1);
	pOut->PrintString(getXcoordiantescorner1(), getYcoordiantescorner1()-20, m_Label);
}

int LED::getXcoordiantescorner1()
{
	return m_GfxInfo.x1;
}

int LED::getYcoordiantescorner1()
{
	return m_GfxInfo.y1;
}

int LED::getXcoordiantescorner2()
{
	return m_GfxInfo.x2;
}

int LED::getYcoordiantescorner2()
{
	return m_GfxInfo.y2;
}

bool LED::checkArea(int x, int y)
{
	if ((x >= getXcoordiantescorner1()) && (y >= getYcoordiantescorner1()) && (x <= getXcoordiantescorner2()) && (y <= getYcoordiantescorner2()))
	{
		return true;
	}

	return false;
}

bool LED::checkempty(int x, int y, GraphicsInfo GI)
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

void LED::setInputPinStatus(STATUS s)
{
	stat = s;
}
void LED::Operate() 
{
	stat = m_InputPin[0].getStatus();

}
int LED::GetInputPinStatus(int n)
{
	if (stat == HIGH)
		return 1;
	if (stat == LOW)
		return 0;
}
void LED::setSwitch()
{
}
OutputPin * LED::getOutputPin()
{
	return nullptr;
}
InputPin * LED::getInputPin()
{
	return m_InputPin;
}
int LED::getnumofinputs()
{
	return 1;
}
void LED::setInputPinStatus(int n, STATUS s)
{
}
int LED::getMaxIn()
{
	return 0;
}
int LED::getTaken()
{
	return 1;
}
void LED::changeInput(int dy)
{
}
int LED::getYIn()
{
	return (m_GfxInfo.y1+m_GfxInfo.y2)/2;
}
OutputPin * LED::getOPin()
{
	return nullptr;
}
InputPin * LED::getIPin(int)
{
	return &m_InputPin[0];
}
InputPin * LED::whichInput()
{
	return m_InputPin;
}
void LED::decTaken()
{
}
bool * LED::getYarray()
{
	return y;
}
void LED::removeInput()
{

}
int LED::GetOutPinStatus() { return 0 ; }