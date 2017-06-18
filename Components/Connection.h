#pragma once
#include "component.h"
#include "InputPin.h"
#include "OutputPin.h"

class Connection :	public Component
{
	//Component*	SrcCmpnt;	//Connection source component
	//Component*	DstCmpnt;	//Connection Destination component
	//int		DstPin;		//The Input pin to which this connection is linked
	OutputPin* SrcPin;	//The Source pin of this connection (an output pin of certain Component)
	InputPin* DstPin;	//The Destination pin of this connection (an input pin of certain Component)
	int x[20];
	int y[20];
	int count;
	int ID1;
	int ID2;
	int pin;
public:
	//Connection(const GraphicsInfo &r_GfxInfo, Component *pS=NULL,Component *pD=NULL, int Pin=0);
	Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin);
	int getYIn();
	virtual void Operate() ;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut);	//for each component to Draw itself
	int getTaken();
	int getMaxIn();
	int getXcoordiantescorner1();
	int getYcoordiantescorner1();
    int getXcoordiantescorner2();
	int getYcoordiantescorner2();
	bool isSelected(int x, int y);
	void setSourcePin(OutputPin *pSrcPin);
	void setDestPin(InputPin *pDstPin);
	OutputPin* getSourcePin();
	InputPin* getDestPin();
	void changeInput(int dy);
	//void changeInput(int dy);
//	int getMaxIn();

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual void setSwitch() ;
	int getS_ID();
	int getT_ID();
	int getPIN();
	void setPin();
	OutputPin* getOPin();
	InputPin* getIPin(int);
	int* getX();
	int* getY();
	void setX(int, int);
	void setY(int, int);
	void setCount(int);
	int getCount();
	bool between(int x1, int upper, int lower);
	virtual void ControlSwitch(STATUS x);
	OutputPin* getOutputPin();
	InputPin* getInputPin();
	int getnumofinputs();

	InputPin *whichInput();
	void removeInput();
	bool* getYarray();
	void decTaken();
	int Overlapping(Component* Comp, int &index);
	void revolveArround(Output* pOut, Component* Comp, int index, int overlap);

	void moveConnectionI(int dx, int dy);
	void moveConnectionO(int dx, int dy);

	int getSourceID(Component *Comp);
};
