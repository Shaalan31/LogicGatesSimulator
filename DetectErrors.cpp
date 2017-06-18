#include "DetectErrors.h"
#include"ApplicationManager.h"
#include"Components\Component.h"


DetectErrors::DetectErrors(ApplicationManager*pApp):Action(pApp)
{
}
void DetectErrors::Undo() {}
void DetectErrors::Redo() {}
DetectErrors::~DetectErrors()
{
}
void DetectErrors::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Action:detecting errors");
	//Wait for User Input
	//pIn->GetPointClicked(xIn , yIn);
	//Clear Status Bar
	pOut->ClearStatusBar();
}
void DetectErrors::Execute()
{
	int check2 = 0;
	int check = 0;
	int check3 = 0;
	ReadActionParameters();
	if (!checkFloatingInputs())
		check2 = 1;
	if (!checkOutputFloating())
		check3 = 1;
	for (int i = 0; i < pManager->getCompcount(); i++)
	{
		if (pManager->getarrayofcomp()[i]->gettype() == Led)
			continue;
		for (int j = 0; j < pManager->getarrayofcomp()[i]->getOutputPin()->getCount(); j++)
		{
			if (!Check(pManager->getarrayofcomp()[i], pManager->getarrayofcomp()[i]->getOutputPin()->getConn()[j]->getDestPin()->getComponent()))
			{

				check = 1;
				break;
			}
		}
		if (check == 1)
			break;
	}
	if (check2 == 1 && check3 == 1&&check==1)
	{
		pManager->CreateNewWindow();
		pManager->GetSubOutput()->PrintString(100, 100, "All errors occured : 1st level(!switches) last level(!leds) Feedback exists ");
	}
	else if (check2 == 1)
	{
		//popup window with error
		//cant simulate
		pManager->CreateNewWindow();
		pManager->GetSubOutput()->PrintString(100, 100, "1st level not switches ");
	}
	else if (check2 == 1)
	{
		//popup window with error
		//cant simulate
		pManager->CreateNewWindow();
		pManager->GetSubOutput()->PrintString(100, 100, "last level not leds");
	}
	else if (check == 1)
	{
		pManager->CreateNewWindow();
		pManager->GetSubOutput()->PrintString(100, 100, "Feedback exists!!!! ");
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
bool DetectErrors::checkOutputFloating()
{
	for (int i = 0; i < pManager->getCompcount(); i++)
	{
		if (pManager->getarrayofcomp()[i]->gettype() == Led)
			continue;
		if (pManager->getarrayofcomp()[i]->getOutputPin()->getCount() == 0)
			return false;
	}
	return true;
}

bool DetectErrors::Check(Component*ptr, Component*ptr2)
{
	if (ptr2 == NULL)
		return true;
	if (ptr2->gettype() == Led)
		return true;
	for (int i = 0; i < ptr->getOutputPin()->getCount(); i++)

	{
		if (ptr == ptr2)
		{
			return false;
		}
		return Check(ptr, ptr2->getOutputPin()->getConn()[i]->getDestPin()->getComponent());
	}

}
bool DetectErrors::checkFloatingInputs()
{
	int countinputs=0;
	for (int i = 0; i < pManager->getCompcount(); i++)
	{
		countinputs = countinputs + pManager->getarrayofcomp()[i]->getnumofinputs();
	}
	if(countinputs>pManager->getConnCount())
		return false;
}