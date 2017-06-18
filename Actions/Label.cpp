#include "Label.h"



Label::Label(ApplicationManager *pApp) :Action(pApp)
{
	comp = NULL;
}
void Label::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Please click on the component where you want to add a label in the drawing area ");
	pIn->GetPointClicked(x1, y1);
	content = pIn->GetSrting(pOut);
	
}

void Label::Execute()
{
	ReadActionParameters();
	
	for (int i = 0; i < pManager->getCount(); i++)
	{
	
		if (pManager->getarrayofcomp()[i]->inside(x1, y1))
		{
			comp = pManager->getarrayofcomp()[i];
			pManager->getarrayofcomp()[i]->setLabel(content);
			return;
		}
	}
	for (int i = 0; i < pManager->getConnCount(); i++)
	{
		if (pManager->getarrayconn()[i]->isSelected(x1,y1))
		{
			comp = pManager->getarrayconn()[i];
			pManager->getarrayconn()[i]->setLabel(content);
			break;
		}
	}
	
}

void Label::Undo()
{
}

void Label::Redo()
{
}


Label::~Label()
{
}
