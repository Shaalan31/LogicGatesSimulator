#pragma once
//#include "Components\Component.h"
#include "Components\InputPin.h"
#include "Components\OutputPin.h"
#include"Components\\Connection.h"
class ComplexBlocks :public Component
{
private:
	Component **Comp;
	Connection **Conn;
	InputPin *m_Inputs;
	OutputPin **m_Outputs;
	Component **arrayofSwitches;
	Component **arrayofLeds;
	int NumSwitch;
	int NumLed;
	GraphicsInfo Ginfo;
	bool *y;
	int taken;
public:
	ComplexBlocks(Component **,Connection**, int compCount, int connCount);
	~ComplexBlocks();
	void incrTaken();

	void setSwitch();
	void ControlSwitch(STATUS x);
	//ComponentType gettype();
	OutputPin* getOutputPin();
	InputPin* getInputPin();
	int getnumofinputs();
	void Operate();	//Calculates the output according to the inputs
	void Draw(Output* pOut);	//for each component to Draw itself
	int getXcoordiantescorner1() ;
	int getYcoordiantescorner1() ;
	int getXcoordiantescorner2() ;
	int getYcoordiantescorner2() ;
	bool checkEmpty(int x, int y, GraphicsInfo GI);
	
	bool checkempty(int x, int y, GraphicsInfo GI);
	int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	

	int getTaken();
	void changeInput(int dy);
	int getYIn();
	
	OutputPin* getOPin();
	InputPin* getIPin(int);


	InputPin* whichInput();
	void decTaken();
	bool* getYarray();
	void removeInput();

	void operating(Component* componentPtr);
};

