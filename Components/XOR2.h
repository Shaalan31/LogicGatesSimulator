#ifndef _XOR2_H
#define _XOR2_H

/*
Class XOR2
-----------
represent the 2-input XOR gate
*/

#include"Gate.h"

class XOR2 :public Gate
{
public:
	XOR2(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate
	int	getXcoordiantescorner1();
	int	getYcoordiantescorner1();
	int	getXcoordiantescorner2();
	int	getYcoordiantescorner2();
	bool checkArea(int x, int y);
	bool checkempty(int x, int y, GraphicsInfo GI);
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

};

#endif#pragma once
