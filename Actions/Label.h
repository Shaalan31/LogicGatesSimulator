#pragma once
using namespace std;
//#include"..\ApplicationManager.h"
#include"..\ApplicationManager.h"
#include"Action.h"
#include<iostream>
class Label :public Action
{
	int x1, x2, y1, y2;
	string content;
	Component *comp;
public:
	Label(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
	void Undo();
	void Redo();
	~Label();
};

