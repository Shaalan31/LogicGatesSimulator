#pragma once
//#include "E:\college\OOP\PT Project S2016 - Logic Sim - student\Project Code Framework\Actions\Action.h"
#include"Actions\Action.h"
class Select :
	public Action
{
	//int x, y;
	int xArray[200];
	int yArray[200];
	int countx;
	int county;
	int y3;
	int x3;
public:
	Select(ApplicationManager *pApp);
	~Select();
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

