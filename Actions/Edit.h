#pragma once
//#include "Actions\Action.h"
#include"Action.h"
#include"..\Components\Component.h"
class Edit :public Action
{
	int x, y;
	Component *Comp;
public:
	Edit(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
	void Undo() ;
	void Redo();
	~Edit();
};

