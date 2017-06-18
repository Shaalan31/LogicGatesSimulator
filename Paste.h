#pragma once
//#include "E:\college\OOP\PT Project S2016 - Logic Sim - student\Project Code Framework\Actions\Action.h
#include"Actions\Action.h"
#include"Components\AND2.h"
#include"Components\AND3.h"
#include"Components\NAND2.h"
#include"Components\NOR2.h"
#include"Components\NOR3.h"
#include"Components\OR2.h"
#include"Components\XNOR2.h"
#include"Components\XNOR3.h"
#include"Components\XOR2.h"
#include"Components\XOR3.h"
#include"Components\Connection.h"
class Paste :
	public Action
{
	int x, y;
public:
	Paste(ApplicationManager *pApp);
	~Paste();
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
	void DelConn(Connection* conn);
};

