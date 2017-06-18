#ifndef _COMPONENT_H
#define _COMPONENT_H
#include"OutputPin.h"
#include "..\Defs.h"
#include "..\GUI\Output.h"
#include"InputPin.h"
//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	
	bool copycheck;
	bool cutcheck;
	Connection *InputConnection;
	int ID;
protected:
	string m_Label;
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	ComponentType type;
	bool selected;
	bool marked;
	static int count;
public:
	virtual void setSwitch()=0;
	virtual void ControlSwitch(STATUS x) = 0;
	ComponentType gettype();
	virtual OutputPin* getOutputPin()=0;
	virtual InputPin* getInputPin() = 0;
	virtual int getnumofinputs()=0;
	void setGraphicsInfo(int x1,int y1,int x2,int y2);
	bool Inside(int x, int y);
	bool getcopy();
	bool getcut();
	bool getselected();
	bool getmarked();
	void setcopy(bool x);
	void setcut(bool x);
	void setmarked(bool x);
	void setselected(bool x);
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	virtual int getXcoordiantescorner1() = 0;
	virtual int getYcoordiantescorner1() = 0;
	virtual int getXcoordiantescorner2() = 0;
	virtual int getYcoordiantescorner2() = 0;
	bool checkEmpty(int x, int y, GraphicsInfo GI) ;
	virtual GraphicsInfo getGraphics() ;
	//virtual bool checkempty(int x, int y, GraphicsInfo GI) = 0;
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1
	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	Component();	
	
	//Destructor must be virtual
	virtual ~Component();

	void setConnection(Connection *Con);
	Connection *getConnection();
	//void setGraphicsInfo(int x1, int y1, int x2, int y2);
	virtual void setLabel(string);
	bool inside(int, int);
	virtual int getMaxIn() = 0;
	virtual int getTaken() = 0;
	virtual void changeInput(int dy) = 0;
	virtual int getYIn() = 0;
	int getID();
	string getLabel();
	virtual OutputPin* getOPin() = 0;
	virtual InputPin* getIPin(int) = 0;


	virtual InputPin* whichInput() = 0;
	virtual void decTaken() = 0;
	virtual bool* getYarray() = 0;
	virtual void removeInput() = 0;
	void setID(int);
};

#endif
