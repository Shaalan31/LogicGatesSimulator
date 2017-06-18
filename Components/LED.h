#pragma once
#ifndef _LED_H
#define _LED_H
/*
Class LED
-----------
*/
#include"Component.h"
#include"OutputPin.h"
#include "InputPin.h"

class LED :public Component
{
protected:
	InputPin* m_InputPin;
	STATUS stat;
	bool *y;
	
	
public:
	virtual void ControlSwitch(STATUS x);
	LED(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Draw(Output* pOut);	//Draws Switch
	int getXcoordiantescorner1();
	int getYcoordiantescorner1();
	int getXcoordiantescorner2();
	int getYcoordiantescorner2();
	bool checkArea(int x, int y);
	bool checkempty(int x, int y, GraphicsInfo GI);
	virtual void Operate();

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual void setInputPinStatus(STATUS s);
	virtual int GetInputPinStatus(int n);
	virtual void setSwitch() ;
	OutputPin* getOutputPin();
	InputPin* getInputPin();
	int getnumofinputs();
	void setInputPinStatus(int n, STATUS s);
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
#endif

