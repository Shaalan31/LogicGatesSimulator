#include "Copy.h"
#include"..\ApplicationManager.h"


Copy::Copy(ApplicationManager *pApp):Action(pApp)
{
}
void Copy::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Action:Copying");

	//Wait for User Input
	//pIn->GetPointClicked(xIn , yIn);
	//Clear Status Bar
	pOut->ClearStatusBar();
	///////////////////
	/*pOut->PrintMsg("please press on the place you want to copy onto");
	pIn->GetPointClicked(xOut, yOut);
	pOut->ClearStatusBar();*/
}
void Copy::Execute()
{
	//Output*pOut;
	//int index;
	ReadActionParameters();

	for (int i = 0; i < (pManager->getCompcount()); i++)
	{
		//if ((xIn >= pManager->getarrayofcomp()[i]->getXcoordiantescorner1()) && (yIn >= pManager->getarrayofcomp()[i]->getYcoordiantescorner1()) && (xIn <= pManager->getarrayofcomp()[i]->getXcoordiantescorner2()) && (yIn <= pManager->getarrayofcomp()[i]->getYcoordiantescorner2()))
		//if(pManager->getarrayofcomp()[i]->Inside(xIn,yIn))
		if(pManager->getarrayofcomp()[i]->getselected()==1)
		{
			for (int j = 0; j < (pManager->getCompcount()); j++)
			{
				pManager->getarrayofcomp()[j]->setcut(false);
				pManager->getarrayofcomp()[j]->setcopy(false);
			}
			pManager->getarrayofcomp()[i]->setcopy(true);
			//pManager->getarrayofcomp()[i]->setselected(true);
			copycomp = pManager->getarrayofcomp()[i];
		//	index = i;
			//break;
		}
	}
/*	int check = 0;
	for (int i = 0; i < (pManager->getCompcount()); i++)
	{
		if ((xOut >= pManager->getarrayofcomp()[i]->getXcoordiantescorner1()) && (yOut >= pManager->getarrayofcomp()[i]->getYcoordiantescorner1()) && (xOut <= pManager->getarrayofcomp()[i]->getXcoordiantescorner2()) && (yOut <= pManager->getarrayofcomp()[i]->getYcoordiantescorner2()))
		{
			check = 1;
			break;
		}
	}
	if (check == 0)
	{
		pManager->getarrayofcomp()[index]->Draw(pOut);
	}
	else
	{
		pOut->PrintMsg("You have clicked on a wrong location , the opertaion has been cancelled");
	}*/
	return;

}
void Copy::Undo(){}
void Copy::Redo(){}

Copy::~Copy()
{
}
