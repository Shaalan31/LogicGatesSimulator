#ifndef _Switch_H
#define _Switch_H
/*
Class Switch
-----------
*/
#include"OutputPin.h"
#include "InputPin.h"
#include"Component.h"

class Switch :public Component
{
protected:
	OutputPin m_OutputPin;
	STATUS stat;
public:
	virtual void ControlSwitch(STATUS x);
	Switch(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Draw(Output* pOut);	//Draws Switch
	int getXcoordiantescorner1();
	int getYcoordiantescorner1();
	int getXcoordiantescorner2();
	int getYcoordiantescorner2();
	bool checkArea(int x, int y);
	bool checkempty(int x, int y, GraphicsInfo GI);
	virtual void Operate();
	virtual void setSwitch();
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual void setInputPinStatus(int n, STATUS s);
	virtual int GetInputPinStatus(int n);

	OutputPin* getOutputPin();
	InputPin* getInputPin();
	int getnumofinputs();
//	void setInputPinStatus(int n, STATUS s);
	int getMaxIn();
	int getTaken();
	void changeInput(int dy);
	int getYIn();
	OutputPin* getOPin();
	InputPin* getIPin(int);




	InputPin* whichInput();
	void decTaken();
	bool* getYarray();
	void removeInput();
};
#endif#pragma once
