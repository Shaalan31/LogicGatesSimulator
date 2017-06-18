#include "Validation.h"
#include"ApplicationManager.h"



Validation::Validation(ApplicationManager*pApp):Action(pApp)
{
}


Validation::~Validation()
{
}
 void Validation::Undo(){}
 void Validation::Redo(){}
void Validation::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Action:Validating");
	//Wait for User Input
	//pIn->GetPointClicked(xIn , yIn);
	//Clear Status Bar
	pOut->ClearStatusBar();
}
void Validation::Execute()
{
	int check1 = 0;
	int check2 = 0;
	ReadActionParameters();
	if (!checkFloatingInputs())
		check1 = 1;
	if (!checkOutputFloating())
		check2 = 1;
	if (check1 == 1 && check2 == 1)
	{
		pManager->CreateNewWindow();
		pManager->GetSubOutput()->PrintString(100, 100, "There are floating inputs you cant simulate please connect every pin \n there are floating outputs you cant connect a circuit please get out ");
	}
	else if (check1 == 1)
	{
		//popup window with error
		//cant simulate
		pManager->CreateNewWindow();
		pManager->GetSubOutput()->PrintString(100, 100, "There are floating inputs you cant simulate please connect every pin ");
	}
	else if (check2 == 1)
	{
		//popup window with error
		//cant simulate
		pManager->CreateNewWindow();
		pManager->GetSubOutput()->PrintString(100, 100, "There are floating outputs you cant simulate please connect every pin ");
	}
	else
	{
		pManager->CreateNewWindow();
		pManager->GetSubOutput()->PrintString(100, 100, "The circuit is validated ya gamed awyy shokran 3la gamalak  ");

		//circuit is validated

	}
	int x3, y1;
	pManager->GetSubInput()->GetPointClicked(x3, y1);
	pManager->GetSubOutput()->~SubOutput();
}

bool  Validation::checkFloatingInputs()
{
	int countinputs=0;
	for (int i = 0; i < pManager->getCompcount(); i++)
	{
		countinputs = countinputs + pManager->getarrayofcomp()[i]->getnumofinputs();
	}
	if(countinputs>pManager->getConnCount())
		return false;
	return true;
}

bool Validation::checkOutputFloating()
{
	for (int i = 0; i < pManager->getCompcount(); i++)
	{
		if (pManager->getarrayofcomp()[i]->gettype() == Led)
			continue;
		if (pManager->getarrayofcomp()[i]->getOutputPin()->getCount()==0)
			return false;
	}
	return true;
}