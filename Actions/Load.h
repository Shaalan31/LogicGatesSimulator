#pragma once
#include<fstream>
#include<iostream>
#include"Action.h"
#include"..\ApplicationManager.h"
using namespace std;

class Load :public Action
{
private:
	int comp_ID, count, x, y;
	string label;
	ComponentType type;
	ifstream file;
	int comptype;
	int Id1, Id2;
	Component *Comp1, *Comp2;
	string file_name;
public:
	Load(ApplicationManager*pApp);

	Load::~Load(void);

	void ReadActionParameters();

	void Execute();

	void Undo();

	void Redo();


	
};