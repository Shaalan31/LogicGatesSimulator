#pragma once
//#include "E:\college\OOP\PT Project S2016 - Logic Sim - student\Project Code Framework\Actions\Action.h"
#include"Actions\Action.h"
#include"Components\Connection.h"
class FeedBack :
	public Action
{
public:
	FeedBack(ApplicationManager*pApp);
	~FeedBack();
	virtual void ReadActionParameters();
	virtual void Execute();
	bool Check(Component*ptr,Component*ptr2);
	bool checkFloatingInputs();
};

