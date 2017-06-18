#include "Delete.h"
#include"ApplicationManager.h"


Delete::Delete(ApplicationManager *pApp) :Action(pApp)
{
}
void Delete::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Action:Deleting");

	//Wait for User Input
	//pIn->GetPointClicked(x, yIn);
	//Clear Status Bar
	//pOut->ClearStatusBar();
	///////////////////
}
void Delete::Execute()
{

	ReadActionParameters();
	int y3, x3, count;

	//int count = pManager->getCompcount();
	for (int i = 0; i < pManager->getConnCount(); i++)
	{
		if (pManager->getarrayconn()[i]->getselected() == true)
		{
			pManager->getarrayconn()[i]->removeInput();
			DelConn(pManager->getarrayconn()[i]);
			if (i != pManager->getConnCount())
			{
				while (pManager->getarrayconn()[i]->getselected() == true)
				{
					pManager->getarrayconn()[i]->removeInput();
					DelConn(pManager->getarrayconn()[i]);

					if (pManager->getarrayconn()[i] == NULL)
					{
						break;
					}
				}
			}
		}

	}
	for (int i = 0; i < pManager->getCompcount(); i++)
	{
		//if ((xIn >= pManager->getarrayofcomp()[i]->getXcoordiantescorner1()) && (yIn >= pManager->getarrayofcomp()[i]->getYcoordiantescorner1()) && (xIn <= pManager->getarrayofcomp()[i]->getXcoordiantescorner2()) && (yIn <= pManager->getarrayofcomp()[i]->getYcoordiantescorner2()))
		if (pManager->getarrayofcomp()[i]->getselected() == true)
		{
			while (pManager->getarrayofcomp()[i]->getOPin()->getCount() != 0)
			{
				pManager->getarrayofcomp()[i]->getOPin()->getConn()[0]->removeInput();
				DelConn(pManager->getarrayofcomp()[i]->getOPin()->getConn()[0]);
			}
			for (int j = pManager->getConnCount() - 1; j >= 0; j--)
			{
				/*count = pManager->getarrayconn()[j]->getCount();
				x3 = pManager->getarrayconn()[j]->getX()[count-1];
				y3 = pManager->getarrayconn()[j]->getY()[count-1];*/
				if (pManager->getarrayconn()[j]->getIPin(0)->getComponent() == pManager->getarrayofcomp()[i])
				{
					DelConn(pManager->getarrayconn()[j]);
					continue;
				}
				if (pManager->getarrayconn()[j]->getIPin(1)->getComponent() == pManager->getarrayofcomp()[i])
				{
					DelConn(pManager->getarrayconn()[j]);
				}
				if (pManager->getarrayconn()[j]->getIPin(1)->getComponent()->gettype() == XNOR3gate || pManager->getarrayconn()[j]->getIPin(1)->getComponent()->gettype() == XOR3gate || pManager->getarrayconn()[j]->getIPin(1)->getComponent()->gettype() == AND3gate)
				{
					if (pManager->getarrayconn()[j]->getIPin(2)->getComponent() == pManager->getarrayofcomp()[i])
					{
						DelConn(pManager->getarrayconn()[j]);
					}
				}
			}
			delete pManager->getarrayofcomp()[i];
			pManager->getarrayofcomp()[i] = pManager->getarrayofcomp()[(pManager->getCompcount()) - 1];
			pManager->getarrayofcomp()[(pManager->getCompcount()) - 1] = NULL;
			pManager->decrementcompcount();

			if (i != pManager->getCompcount())
			{
				while (pManager->getarrayofcomp()[i]->getselected() == true)
				{
					while (pManager->getarrayofcomp()[i]->getOPin()->getCount() != 0)
					{
						DelConn(pManager->getarrayofcomp()[i]->getOPin()->getConn()[0]);
					}
					for (int j = pManager->getConnCount(); j > 0; j--)
					{
						count = pManager->getarrayconn()[j]->getCount();
						x3 = pManager->getarrayconn()[j]->getX()[count - 1];
						y3 = pManager->getarrayconn()[j]->getY()[count - 1];
						if (pManager->getarrayofcomp()[i]->inside(x3, y3))
						{
							DelConn(pManager->getarrayconn()[j]);
						}
					}
					delete pManager->getarrayofcomp()[i];
					pManager->getarrayofcomp()[i] = pManager->getarrayofcomp()[(pManager->getCompcount()) - 1];
					pManager->getarrayofcomp()[(pManager->getCompcount()) - 1] = NULL;
					pManager->decrementcompcount();
					if (pManager->getarrayofcomp()[i] == NULL)
					{
						break;
					}
				}
			}

		}
	}
	for (int i = 0; i < pManager->getConnCount(); i++)
	{

	}
	return;

}

void Delete::Undo() {}
void Delete::Redo() {}


void Delete::DelConn(Connection * conn)
{
	for (int i = pManager->getConnCount(); i > 0; i--)
	{

		if (pManager->getarrayconn()[i - 1] == conn)
		{
			//pManager->getarrayconn()[i-1]->getDestPin()->getComponent();
			pManager->getarrayconn()[i - 1]->getOPin()->removeCon(pManager->getarrayconn()[i - 1]);
			delete pManager->getarrayconn()[i - 1];
			pManager->getarrayconn()[i - 1] = pManager->getarrayconn()[pManager->getConnCount() - 1];
			pManager->getarrayconn()[pManager->getConnCount() - 1] = NULL;
			pManager->decrmentConnCount();
			break;
		}


	}
}
Delete::~Delete()
{
}
