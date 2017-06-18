#pragma once
#include "Action.h"
class Switch_to_design_mode :public Action
{
public:
	Switch_to_design_mode(ApplicationManager*pApp);
	~Switch_to_design_mode();
	virtual void ReadActionParameters();
	virtual void Execute();
	void Undo();
	void Redo();
};

