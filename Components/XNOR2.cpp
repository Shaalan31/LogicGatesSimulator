#include "XNOR2.h"

XNOR2::XNOR2(const GraphicsInfo &r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	selected = false;
	type = XNOR2gate;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


	void XNOR2::Operate()
	{
		//caclulate the output status as the ANDing of the two input pins
		//Add you code here
		if (m_InputPins[0].getStatus() == LOW && m_InputPins[1].getStatus() == LOW)
			m_OutputPin.setStatus(HIGH);
		else if(m_InputPins[0].getStatus() == HIGH && m_InputPins[1].getStatus() == HIGH)
			m_OutputPin.setStatus(HIGH);
		else
			m_OutputPin.setStatus(LOW);
	}

	int XNOR2::getXcoordiantescorner1()
	{
		return m_GfxInfo.x1;
	}

	int XNOR2::getYcoordiantescorner1()
	{
		return m_GfxInfo.y1;
	}

	int XNOR2::getXcoordiantescorner2()
	{
		return m_GfxInfo.x2;
	}
	bool XNOR2::checkempty(int x, int y, GraphicsInfo GI)
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
	bool XNOR2::checkArea(int x, int y)
	{
		if ((x >= getXcoordiantescorner1()) && (y >= getYcoordiantescorner1()) && (x <= getXcoordiantescorner2()) && (y <= getYcoordiantescorner2()))
		{
			return true;
		}

		return false;
	}


	int XNOR2::getYcoordiantescorner2()
	{
		return m_GfxInfo.y2;
	}
	// Function Draw
	// Draws 2-input AND gate
	void XNOR2::Draw(Output* pOut)
	{
		//Call output class and pass gate drawing info to it.
		if (getselected() == 0)
			pOut->DrawXNOR(m_GfxInfo);
		else
			pOut->DrawXNOR(m_GfxInfo, 1);
		pOut->PrintString(getXcoordiantescorner1(), getYcoordiantescorner1() - 20, m_Label);
	}

	//returns status of outputpin
	int XNOR2::GetOutPinStatus()
	{
		return m_OutputPin.getStatus();
	}


	//returns status of Inputpin #n
	int XNOR2::GetInputPinStatus(int n)
	{
		return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
	}

	//Set status of an input pin ot HIGH or LOW
	void XNOR2::setInputPinStatus(int n, STATUS s)
	{
		m_InputPins[n - 1].setStatus(s);
	}

