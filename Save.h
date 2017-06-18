#pragma once
#include"fstream"
#include"iostream"
#include"Actions\Action.h"
#include"ApplicationManager.h"
//#include"ApplicationManager.h"
//#include "C:\Users\Win 8.1\Desktop\PT Project S2016 - Logic Sim - student\Project Code Framework\Actions\Action.h"
using namespace std;
class Save :
	public Action
{
	int x;
	int y;
	ofstream Saved;
public:
	Save(ApplicationManager*);
	void ReadActionParameters();
	void Execute();
	void Undo();
	void Redo();
	~Save();
};

