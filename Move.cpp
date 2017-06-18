#include "Move.h"
#include"ApplicationManager.h"
Move::Move(ApplicationManager*pApp) :Action(pApp)
{
}
void Move::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Action:Moving");

	//Wait for User Input
	//pIn->GetPointClicked(xArray[countx++], yArray[county++])
	//Clear Status Bar
	pOut->ClearStatusBar();


}
void Move::Execute()
{
	int x, y;
	int x1, y1;
	int dx, dy;
	int check = 0;
	int count, x3, y3;
	ReadActionParameters();
	bool z = 1;
	//pManager->GetInput()->getwindowpointer()->GetMouseClick(x1, y1);
	//x = x1;
	//y = y1;
	int z1, z2, w1, w2;
	pManager->GetOutput()->setBuffer(1);
	while (z)
	{
		while (pManager->GetInput()->getwindowpointer()->GetButtonState(LEFT_BUTTON, x, y) == BUTTON_DOWN)
		{
			if (check == 0)
			{
				x1 = x;
				y1 = y;
			}
			dx = x - x1;
			dy = y - y1;
			//		pManager->GetInput()->getwindowpointer()->WaitMouseClick(x, y);
			//if (check != 1)

			y1 = y;
			x1 = x;

			//int index;
			for (int i = 0; i < (pManager->getCompcount()); i++)
			{
				//if ((xIn >= pManager->getarrayofcomp()[i]->getXcoordiantescorner1()) && (yIn >= pManager->getarrayofcomp()[i]->getYcoordiantescorner1()) && (xIn <= pManager->getarrayofcomp()[i]->getXcoordiantescorner2()) && (yIn <= pManager->getarrayofcomp()[i]->getYcoordiantescorner2()))

				if (pManager->getarrayofcomp()[i]->getselected() == 1)
				{
					//pManager->getarrayofcomp()[i]->setselected(true);
					//check = 1;
					//index = i;
					for (int j = 0; j < pManager->getConnCount(); j++)
					{
						if (pManager->getarrayconn()[j]->getDestPin()->getComponent() == pManager->getarrayofcomp()[i])
						{
							pManager->getarrayconn()[j]->moveConnectionI(dx, dy);
						}
					}
					if (pManager->getarrayofcomp()[i]->gettype() != Led)
					{
						for (int j = 0; j < pManager->getarrayofcomp()[i]->getOPin()->getCount(); j++)
						{
							pManager->getarrayofcomp()[i]->getOPin()->getConn()[j]->moveConnectionO(dx, dy);
						}
					}
					z1 = pManager->getarrayofcomp()[i]->getGraphics().x1;
					z2 = pManager->getarrayofcomp()[i]->getGraphics().x2;
					w1 = pManager->getarrayofcomp()[i]->getGraphics().y1;
					w2 = pManager->getarrayofcomp()[i]->getGraphics().y2;
					pManager->getarrayofcomp()[i]->setGraphicsInfo(z1 + dx, w1 + dy, z2 + dx, w2 + dy);

					//break;
				}

				/*else
				{
				pManager->GetOutput()->PrintMsg("There is no component where you clicked , the operation is cancelled");
				break;
				}*/
			}
			pManager->GetInput()->getwindowpointer()->UpdateBuffer();
			pManager->UpdateInterface();
			z = 0;
			check++;
		}
	}
	pManager->GetOutput()->setBuffer(0);
}
void Move::Undo()
{
}
void Move::Redo()
{
}
Move::~Move()
{
}
