#include "Connection.h"

Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin):Component(r_GfxInfo)	
	
{
	selected = false;
	SrcPin = pSrcPin;
	DstPin = pDstPin;
	count = 0;
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}

void Connection::changeInput(int dy)
{
}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	pOut->DrawConnection(m_GfxInfo, x, y,count, GetOutPinStatus(),selected); 
	pOut->PrintString(x[count / 2], y[(count+1) / 2], m_Label);
	


}

int Connection::getTaken()
{
	return 0;
}

int Connection::getMaxIn()
{
	return 0;
}

int Connection::getXcoordiantescorner1()
{
	return 0;
}

int Connection::getYcoordiantescorner1()
{
	return 0;
}

int Connection::getXcoordiantescorner2()
{
	return 0;
}

int Connection::getYcoordiantescorner2()
{
	return 0;
}

bool Connection::isSelected(int x1, int y1)
{
	bool xEqual;
	bool yEqual;
	bool xMid;
	bool yMid;
	for (int i = 1; i <= count; i++)
	{
		//xEqual = (x1 == x[i - 1] || x1 == x[i]);
		//yEqual = (y1 == y[i - 1] || y1 == y[i]);
		xEqual = between(x1, x[i - 1] + 5, x[i - 1] - 5) || between(x1, x[i] + 5, x[i] - 5);
		yEqual = between(y1, y[i - 1] + 5, y[i - 1] - 5) || between(y1, y[i] + 5, y[i] - 5);
		xMid = (x[i - 1]>x1 && x[i] < x1) || (x[i - 1]<x1 && x[i]>x1);
		yMid = (y[i - 1]>y1 && y[i] < y1) || (y[i - 1]<y1 && y[i]>y1);
		if((xEqual && yMid) || (yEqual && xMid))
			return (xEqual && yMid) || (yEqual && xMid);
	}
	return false;
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

void Connection::setSwitch()
{
}

int Connection::getS_ID()
{
	return ID1;
}

int Connection::getT_ID()
{
	return ID2;
}

int Connection::getPIN()
{
	return pin;
}

void Connection::setPin()
{
}

OutputPin*  Connection::getOPin()
{
	return SrcPin;
}

InputPin * Connection::getIPin(int s = 0)
{
	return DstPin;
}

int * Connection::getX()
{
	return x;
}

int * Connection::getY()
{
	return y;
}

void Connection::setX(int x2, int c)
{
	x[c] = x2;
}

void Connection::setY(int y2, int c)
{
	y[c] = y2;
}
int Connection::getYIn()
{
	return 0;
}
void Connection::setCount(int c)
{
	count = c;
}

int Connection::getCount()
{
	return count;
}

bool Connection::between(int x1, int upper, int lower)
{
	return (x1<upper && x1>lower);
}

void Connection::ControlSwitch(STATUS x)
{
}

OutputPin * Connection::getOutputPin()
{
	return nullptr;
}

InputPin * Connection::getInputPin()
{
	return DstPin;
}

int Connection::getnumofinputs()
{
	return 0;
}

InputPin * Connection::whichInput()
{
	return DstPin;
}

void Connection::removeInput()
{
	for (int i = 0; i < DstPin->getComponent()->getMaxIn(); i++)
	{
		if (DstPin == &DstPin->getComponent()->getIPin(0)[i])
		{
			DstPin->getComponent()->getYarray()[i] = true;
			DstPin->getComponent()->decTaken();
		}
	}
}

bool * Connection::getYarray()
{
	return nullptr;
}

void Connection::decTaken()
{
}

int Connection::Overlapping(Component * Comp, int & index)
{
	for (int i = 0; i < count - 1; i++)
	{
		index = i;
		if (between(x[i], Comp->getXcoordiantescorner1(), Comp->getXcoordiantescorner2()) && between(Comp->getYcoordiantescorner1(), y[i], y[i + 1]))
			return 1;
		if (between(x[i], Comp->getXcoordiantescorner1(), Comp->getXcoordiantescorner2()) && between(y[i + 1], Comp->getYcoordiantescorner1(), Comp->getYcoordiantescorner2()))
			return 2;
		if (between(y[i], Comp->getYcoordiantescorner1(), Comp->getYcoordiantescorner2()) && between(Comp->getXcoordiantescorner1(), x[i], x[i + 1]))
			return 3;

	}
	return 0;
}

void Connection::revolveArround(Output * pOut, Component * Comp, int index, int overlap)
{
	if (overlap != 1 && overlap != 2 && overlap != 3)
		return;
	int x1 = x[index];
	int x2 = x[index + 1];
	int y1 = y[index];
	int y2 = y[index];
	int y3, x3;
	//int xOld, yOld;
	if (overlap == 1)
	{
		if (y1 < y2)
		{
			/*while (!Comp->inside(x1, y1))
			{
			yOld = y1;
			y1++;
			}
			y1 = yOld;*/
			y1 = Comp->getYcoordiantescorner1();
			y2 = y1 + 50;

		}
		else
		{
			/*while (!Comp->inside(x1, y1))
			{
			yOld = y1;
			y1--;
			}
			y1 = yOld;*/
			y1 = Comp->getYcoordiantescorner2();
			y2 = y1 - 50;
		}

		y3 = (y1 + y2) / 2;
		x3 = Comp->getXcoordiantescorner2();
		pOut->drawline2(x3, y3, x1, y1, 0, stat, selected);
		pOut->drawline2(x3, y3, x2, y2, 0, stat, selected);
	}
	if (overlap == 2)
	{
		if (y1 < y2)
		{
			/*while (!Comp->inside(x1, y1))
			{
			xOld = x1;
			y1++;
			}
			y1 = xOld;*/
			//y2 = y1 + 50;
			y1 = Comp->getYcoordiantescorner1();
		}
		else
		{
			/*while (!Comp->inside(x1, y1))
			{
			yOld = y1;
			y1--;
			}
			y1 = yOld;
			//y2 = y1 - 50;*/
			y1 = Comp->getYcoordiantescorner2();
		}
		if (x1 < x2)
		{
			/*while (!Comp->inside(x2, y2))
			{
			xOld = x2;
			x2--;
			}
			x2 = xOld;
			//y1 = y2 - 50;*/
			x2 = Comp->getXcoordiantescorner2();
		}
		else
		{
			/*while (!Comp->inside(x2, y2))
			{
			xOld = x2;
			x2++;
			}
			x2 = xOld;
			//y1 = y2 - 50;*/
			x2 = Comp->getXcoordiantescorner1();
		}
		pOut->drawline2(x2, y2, x1, y1, 0, stat, selected);
	}
	if (overlap == 3)
	{
		if (x1 < x2)
		{
			/*while (!Comp->inside(x2, y2))
			{
			xOld = x2;
			x2--;
			}
			x2 = xOld;*/
			x2 = Comp->getXcoordiantescorner2();
			x1 = x2 - 50;
		}
		else
		{
			/*while (!Comp->inside(x2, y2))
			{
			xOld = x2;
			x2++;
			}
			x2 = xOld;*/
			x2 = Comp->getXcoordiantescorner1();
			x1 = x2 + 50;
		}
		x3 = (x1 + x2) / 2;
		y3 = Comp->getXcoordiantescorner2();
		pOut->drawline2(x1, y1, x3, y3, 0, stat, selected);
		pOut->drawline2(x2, y2, x3, y3, 0, stat, selected);
	}
}

int getMaxIn()
{
	return 0;
}


void Connection::moveConnectionI(int dx, int dy)
{
	x[count-1] += dx;
	y[count-1] += dy;
}

void Connection::moveConnectionO(int dx, int dy)
{
	x[0] += dx;
	y[0] += dy;
}

int Connection::getSourceID(Component * Comp)
{
	for (int i = 0; i < Comp->getOPin()->getCount(); i++)
	{
		if (Comp->getOPin()->getConn()[i] == this)
			return Comp->getID();
	}
	return -1;
}
