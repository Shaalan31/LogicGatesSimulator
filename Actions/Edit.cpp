#include "Edit.h"
#include"..\ApplicationManager.h"


Edit::Edit(ApplicationManager *pApp):Action(pApp)
{
	Comp = NULL;
}

void Edit::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Action:Editing label");

	//Wait for User Input
	pIn->GetPointClicked(x, y);
	//Clear Status Bar
	pOut->ClearStatusBar();
	///////////////////
}
void Edit::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	string s;
	ReadActionParameters();
	for (int i = 0; i < pManager->getCompcount(); i++)
	{
		if (pManager->getarrayofcomp()[i]->inside(x, y))
		{
			s = pIn->editString(pOut, pManager->getarrayofcomp()[i]->getLabel());
			pManager->getarrayofcomp()[i]->setLabel(s);
			break;
		}
	}
	for (int i = 0; i < pManager->getConnCount(); i++)
	{
		if (0)//ADD HERE A CONDITION TO CHECK THAT IF THE CLICK IS INSIDE 
		{
			s = pIn->editString(pOut, pManager->getarrayconn()[i]->getLabel());
			pManager->getarrayconn()[i]->setLabel(s);
			break;
		}
	}
}
void Edit::Undo()
{}
void Edit::Redo()
{}

Edit::~Edit()
{
}
