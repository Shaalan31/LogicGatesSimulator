#pragma once
//#include "C:\Users\Win 8.1\Desktop\PT Project S2016 - Logic Sim - student\Project Code Framework\Components\Gate.h"
#include"Gate.h"
class BUFFER :
	public Gate
{
public:
	BUFFER(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate
	int getXcoordiantescorner1();
	int getYcoordiantescorner1();
	int getXcoordiantescorner2();
	int getYcoordiantescorner2();
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	bool checkArea(int x, int y);
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	bool checkempty(int x, int y, GraphicsInfo GI);
};

