#pragma once
#include "Actions\Action.h"
#include"Components\Component.h"
#include"Components\Connection.h"
class Validation :
	public Action
{
public:
	Validation(ApplicationManager*pApp);
	~Validation();
	virtual void ReadActionParameters();
	virtual void Execute();
	bool checkOutputFloating();
	bool checkFloatingInputs();
	virtual void Undo();
	virtual void Redo();
};

