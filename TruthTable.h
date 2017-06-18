#pragma once
//#include "E:\college\OOP\PT Project S2016 - Logic Sim - student\Project Code Framework\Actions\Action.h"
//#include"Components\Component.h"
#include"Simulate.h"
class TruthTable :
	public Action
{
	int **arrayofInputs;
	int **arrayofOutputs;
	Component **arrayofSwitches;
	Component **arrayofLeds;
public:
	void operating(Component* componentPtr/*,bool operate)*/);
	TruthTable(ApplicationManager*pApp);
	~TruthTable();
	void Swap(Component*&ptr1, Component*&ptr2);
	virtual void ReadActionParameters();
	virtual void Execute();
	void BubbleSort(Component**array, int size);
	int Power(int ,int );
	virtual void Undo();
	virtual void Redo();
	string ConvertTableToString(int *array, int size);
	void PrintTable();
};

