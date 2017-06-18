#include "XNOR3.h"

XNOR3::XNOR3(const GraphicsInfo &r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	selected = false;
	type = XNOR3gate;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XNOR3::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	//Add you code here
	if (m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == HIGH && m_InputPins[2].getStatus() == HIGH)
		m_OutputPin.setStatus(HIGH);
	else if (m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == HIGH && m_InputPins[2].getStatus() == LOW)
		m_OutputPin.setStatus(HIGH);
	else if (m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == LOW && m_InputPins[2].getStatus() == HIGH)
		m_OutputPin.setStatus(HIGH);
	else if (m_InputPins[0].getStatus() == LOW && m_InputPins[1].getStatus() == HIGH && m_InputPins[2].getStatus() == HIGH)
		m_OutputPin.setStatus(HIGH);
	else if (m_InputPins[0].getStatus() == LOW && m_InputPins[1].getStatus() == LOW && m_InputPins[2].getStatus() == HIGH)
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
}
int XNOR3::getXcoordiantescorner1()
{
	return m_GfxInfo.x1;
}

int XNOR3::getYcoordiantescorner1()
{
	return m_GfxInfo.y1;
}

int XNOR3::getXcoordiantescorner2()
{
	return m_GfxInfo.x2;
}
bool XNOR3::checkempty(int x, int y, GraphicsInfo GI)
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
bool XNOR3::checkArea(int x, int y)
{
	if ((x >= getXcoordiantescorner1()) && (y >= getYcoordiantescorner1()) && (x <= getXcoordiantescorner2()) && (y <= getYcoordiantescorner2()))
	{
		return true;
	}

	return false;
}


int XNOR3::getYcoordiantescorner2()
{
	return m_GfxInfo.y2;
}

	// Function Draw
	// Draws 2-input AND gate
	void XNOR3::Draw(Output* pOut)
	{
		//Call output class and pass gate drawing info to it.
		pOut->DrawXNOR(m_GfxInfo);
		pOut->PrintMsg("REMEMBER TO MAKE IT 3 INPUT");
		pOut->PrintString(getXcoordiantescorner1(), getYcoordiantescorner1() - 20, m_Label);
	}

	//returns status of outputpin
	int XNOR3::GetOutPinStatus()
	{
		return m_OutputPin.getStatus();
	}


	//returns status of Inputpin #n
	int XNOR3::GetInputPinStatus(int n)
	{
		return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
	}

	//Set status of an input pin ot HIGH or LOW
	void XNOR3::setInputPinStatus(int n, STATUS s)
	{
		m_InputPins[n - 1].setStatus(s);
	}

