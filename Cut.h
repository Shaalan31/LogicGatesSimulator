#pragma once
//#include "E:\college\OOP\PT Project S2016 - Logic Sim - student\Project Code Framework\Actions\Action.h"
#include"Actions\Action.h"
class Cut :
	public Action
{
	int x, y;
public:
	Cut(ApplicationManager *pApp);
	~Cut();
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

