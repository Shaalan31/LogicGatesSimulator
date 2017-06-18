#pragma once
#include"Actions\Action.h"
#include"ApplicationManager.h"
class Exit :
	public Action
{
public:
	Exit(ApplicationManager *pApp);
	
	 void ReadActionParameters();

	
	 void Execute();

	
	 void Undo();

	
	 void Redo();
	~Exit();
};

