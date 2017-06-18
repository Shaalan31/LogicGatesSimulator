#include "Select.h"
#include"ApplicationManager.h"


Select::Select(ApplicationManager *pApp):Action(pApp)
{
	countx = 0;
	county = 0;
}
void Select::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Action:Selecting");

	//Wait for User Input
	pIn->GetPointClicked(x3, y3);
	//Clear Status Bar
	pOut->ClearStatusBar();
	///////////////////
	/*pOut->PrintMsg("please press on the place you want to copy onto");
	pIn->GetPointClicked(xOut, yOut);
	pOut->ClearStatusBar();*/
}
void Select::Execute()
{
	
	ReadActionParameters();
	int x = countx - 1;
	int y = county - 1;
	while (y3 > 50)
	{
		for (int i = 0; i < (pManager->getCompcount()); i++)
		{
			//if ((xIn >= pManager->getarrayofcomp()[i]->getXcoordiantescorner1()) && (yIn >= pManager->getarrayofcomp()[i]->getYcoordiantescorner1()) && (xIn <= pManager->getarrayofcomp()[i]->getXcoordiantescorner2()) && (yIn <= pManager->getarrayofcomp()[i]->getYcoordiantescorner2()))
			if (pManager->getarrayofcomp()[i]->Inside(x3, y3))
			{
				if (pManager->getarrayofcomp()[i]->getselected() == false)
				{
					pManager->getarrayofcomp()[i]->setselected(true);
					break;
				}
				else
				{
					pManager->getarrayofcomp()[i]->setselected(false);
					break;
				}
			}
		}
		for (int i = 0; i < pManager->getConnCount(); i++)
		{
			if (pManager->getarrayconn()[i]->isSelected(x3, y3))
			{
				if (pManager->getarrayconn()[i]->getselected() == false)
					pManager->getarrayconn()[i]->setselected(true);
				else
					pManager->getarrayconn()[i]->setselected(false);
				break;
			}

		}
		pManager->UpdateInterface();
		ReadActionParameters();
	}
	pManager->UpdateInterface();
	/*pManager->GetOutput()->PrintMsg("Do you want the option of multiple selection ? ,if yes press c while selecting otherwise break the operation");
	char key;
	pManager->GetInput()->getwindowpointer()->WaitKeyPress(key);
	pManager->GetOutput()->ClearStatusBar();
	if (pManager->GetInput()->getwindowpointer()->WaitKeyPress(key) == 'c')
	{
		key = 'c';
		while (pManager->GetInput()->getwindowpointer()->WaitKeyPress(key))
		{
			ReadActionParameters();
			for (int i = 0; i < (pManager->getCompcount()); i++)
			{
				if (pManager->getarrayofcomp()[i]->Inside(xArray[countx--],yArray[county--]))
				{
					pManager->getarrayofcomp()[i]->setselected(true);
					break;
				}
			}

		}
	}*/
}
Select::~Select()
{
}
 void Select::Undo(){}
 void Select::Redo(){}