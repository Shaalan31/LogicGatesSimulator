#pragma once
#include "Actions\Action.h"
#include"Components\Connection.h"
class DetectErrors :
	public Action
{
public:
	DetectErrors(ApplicationManager*pApp);
	~DetectErrors();
	virtual void ReadActionParameters();
	virtual void Execute();
	bool checkOutputFloating();
	bool checkFloatingInputs();
	bool Check(Component*ptr, Component*ptr2);
	void Undo();
	void Redo();
};

