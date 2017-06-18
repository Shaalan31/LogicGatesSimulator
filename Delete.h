#pragma once
//#include "E:\college\OOP\PT Project S2016 - Logic Sim - student\Project Code Framework\Actions\Action.h"
#include"Actions\Action.h"
#include"Components\Connection.h"
class Delete :
	public Action
{
public:
	Delete(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	void DelConn(Connection* conn);
	~Delete();
};

