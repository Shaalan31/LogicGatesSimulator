#include "Cut.h"
#include"ApplicationManager.h"
Cut::Cut(ApplicationManager * pApp):Action(pApp)
{
}
void Cut::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Action:Cutting");

	//Wait for User Input
	//pIn->GetPointClicked(x, y);
	//Clear Status Bar
	pOut->ClearStatusBar();
	///////////////////
}
void Cut::Execute()
{
	
	//int index;
	ReadActionParameters();
	for (int i = 0; i < (pManager->getCompcount()); i++)
	{
		//if ((x >= pManager->getarrayofcomp()[i]->getXcoordiantescorner1()) && (y >= pManager->getarrayofcomp()[i]->getYcoordiantescorner1()) && (x <= pManager->getarrayofcomp()[i]->getXcoordiantescorner2()) && (y <= pManager->getarrayofcomp()[i]->getYcoordiantescorner2()))
		//if (pManager->getarrayofcomp()[i]->Inside(x, y))
		if (pManager->getarrayofcomp()[i]->getselected() == 1)
		{
			for (int j = 0; j < (pManager->getCompcount()); j++)
			{
				pManager->getarrayofcomp()[j]->setcopy(false);
				pManager->getarrayofcomp()[j]->setcut(false);
			}
			pManager->getarrayofcomp()[i]->setcut(true);
			//pManager->getarrayofcomp()[i]->setselected(true);
			//index = i;
			//break;
		}
	}
}
Cut::~Cut()
{
}

 void Cut::Undo(){}
 void Cut::Redo(){}