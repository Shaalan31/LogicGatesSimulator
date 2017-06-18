#pragma once
//#include "E:\college\OOP\PT Project S2016 - Logic Sim - student\Project Code Framework\Actions\Action.h"
#include"Actions\Action.h"
class Move :
	public Action
{
	int x, y;
public:
	Move(ApplicationManager *pApp);
	~Move();
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

