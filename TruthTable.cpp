#include "TruthTable.h"
#include"ApplicationManager.h"
#include<sstream>

TruthTable::TruthTable(ApplicationManager*pApp):Action(pApp)
{
}
TruthTable::~TruthTable()
{
}
void TruthTable::ReadActionParameters()
{

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Action:Creating Truth Table");
	//Wait for User Input
	//pIn->GetPointClicked(xIn , yIn);
	//Clear Status Bar
	pOut->ClearStatusBar();
}
void TruthTable::operating(Component* componentPtr/*,bool operate)*/)
{
	if (componentPtr->gettype() == Led)
	{
		componentPtr->Operate();
		return;
	}
	for (int i = 0; i < componentPtr->getOutputPin()->getCount(); i++)
	{
		//if (componentPtr->gettype() == SWITCH)
		//operate = true;
		//if(componentPtr->getOutputPin()->getarrayofconnections()[i]->getDestPin()->getComponent()
		componentPtr->getOutputPin()->getConn()[i]->getDestPin()->setStatus(componentPtr->getOutputPin()->getStatus());
		componentPtr->getOutputPin()->getConn()[i]->getDestPin()->getComponent()->Operate();
		pManager->UpdateInterface();
		operating(componentPtr->getOutputPin()->getConn()[i]->getDestPin()->getComponent());


	}

}
///////////////////////////////////////////////////////////////

string TruthTable::ConvertTableToString(int *array, int size)
{
	stringstream ss;
	for (int i = 0; i < size; i++)
	{
		ss << array[i]<<"\t \t  	";
	}
	return ss.str();
}
void TruthTable::PrintTable()
{
	pManager->CreateNewWindow();
	int numberofinputs;
	int numberofoutputs;
	int countswitch = 0;
	int countled = 0;
	for (int i = 0; i < pManager->getCompcount(); i++)
	{
		if (pManager->getarrayofcomp()[i]->gettype() == SWITCH)
			countswitch++;
		if (pManager->getarrayofcomp()[i]->gettype() == Led)
			countled++;
	}
	//string s;
	numberofinputs = countswitch;
	numberofoutputs = countled;
	int x = 50;
	int y = 50;
	int y2 = 50;
	for (int i = 0; i < Power(2, numberofinputs); i++)
	{
		string s;
		s = ConvertTableToString(arrayofInputs[i], numberofinputs);
		pManager->GetSubOutput()->PrintString(x, y+=20, s);
	}
	pManager->GetSubOutput()->getwindowpointer()->DrawLine(x + (22*numberofinputs), y2, x + 50, y+50);
	int x1 = x + (23*numberofinputs);

	for (int j = 0; j < Power(2, numberofinputs); j++)
	{
		string s;
		s = ConvertTableToString(arrayofOutputs[j], numberofoutputs);
		pManager->GetSubOutput()->PrintString(x1, y2 += 20, s);
	}
	int x3, y1;
	pManager->GetSubInput()->GetPointClicked(x3, y1);
	pManager->GetSubOutput()->~SubOutput();

}
//////////////////////////////////////////////////////////////
void TruthTable::Execute()
{
	int numberofinputs;
	int numberofoutputs;
	int countswitch=0;
	int countled=0;
	for (int i = 0; i < pManager->getCompcount(); i++)
	{
		if (pManager->getarrayofcomp()[i]->gettype() == SWITCH)
			countswitch++;
		if (pManager->getarrayofcomp()[i]->gettype() == Led)
			countled++;
	}
	numberofinputs = countswitch;
	numberofoutputs = countled;
	arrayofLeds = new Component*[countled];
	arrayofSwitches = new Component*[countswitch];
	int x = countswitch-1;
	int y = countled-1;
	for (int i = 0; i < pManager->getCompcount(); i++)
	{
		if (pManager->getarrayofcomp()[i]->gettype() == SWITCH)
			arrayofSwitches[x--] = pManager->getarrayofcomp()[i];
		if (pManager->getarrayofcomp()[i]->gettype() == Led)
			arrayofLeds[y--] = pManager->getarrayofcomp()[i];
	}
	arrayofInputs = new int*[Power(2, numberofinputs)];
	arrayofOutputs = new int*[Power(2, numberofinputs)];
	for (int i = 0; i <Power(2, numberofinputs); i++)
	{
		arrayofInputs[i] = new int[numberofinputs];
		arrayofOutputs[i] = new int[numberofoutputs];
	}
	BubbleSort(arrayofSwitches, countswitch);
	ReadActionParameters();
	int x2,y2;
	int remainder;
	for (int i = 0; i < Power(2, numberofinputs); i++)
	{
		x2 = i;
		y2 = numberofinputs;
		for (int j = numberofinputs; j > 0;j--)
		{
			remainder=x2 % 2;
			arrayofInputs[i][j-1]=remainder;
			x2 = x2 / 2;
		}
	}
	STATUS s;
	for (int i = 0; i < countswitch; i++)
	{
		arrayofSwitches[i]->ControlSwitch(LOW);
		operating(arrayofSwitches[i]);
	}
	for (int n = 0; n < countled; n++)
	{
		arrayofOutputs[0][n] = arrayofLeds[n]->GetOutPinStatus();
	}

	BubbleSort(arrayofLeds, countled);
	//////////////////////////////////////
	for (int i = 1; i < Power(2, numberofinputs); i++)
	{
		for (int j = 0; j < numberofinputs; j++)
		{
			if (arrayofInputs[i][j] != arrayofInputs[i - 1][j])
			{
				if (arrayofInputs[i][j] == 1)
					s = HIGH;
				else
					s = LOW;
				
				arrayofSwitches[j]->ControlSwitch(s);
				operating(arrayofSwitches[j]);
			}
		}
			for (int n = 0; n < countled; n++)
			{
				arrayofOutputs[i][n] = arrayofLeds[n]->GetInputPinStatus(0);
			}	
		
	}
	//int hazem = 0;
	PrintTable();
}
int TruthTable::Power(int y,int x)
{
	
	for (int i = 1; i < x; i++)
	{
		y = y*2;
	}
	return y;
}
void TruthTable::Swap(Component *&ptr1, Component *&ptr2)
{
	Component*temp;
	temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
}
void TruthTable::BubbleSort(Component**array, int size)
{
	bool swapped = true;
	while (swapped)
	{
		swapped = false;
		for (int i = 1; i <= size-1; i++)
		{
			if ((array[i - 1]->getGraphics().y2) > (array[i]->getGraphics().y2))
			{
				Swap(array[i - 1], array[i]);
				swapped = true;
			}
		}
	}


}
void TruthTable::Undo()
{}

void TruthTable::Redo(){}
