#pragma once
//#include "C:\Users\Omar\Documents\Visual Studio 2015\Projects\PT Project S2016 - Logic Sim - student\Project Code Framework\Actions\Action.h"
#include"Action.h"
#include"..\ApplicationManager.h"
#include"..\Components\Connection.h"
//#include"Components\Gate.h"
class AddConnection :public Action
{
	int x, y;
	Component *source;
	Component *Dest;
	
	
public:
	AddConnection(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
	void Undo();
	void Redo();
	~AddConnection();
};

