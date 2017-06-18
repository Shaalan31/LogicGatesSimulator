#include "AddConnection.h"



AddConnection::AddConnection(ApplicationManager *pApp) :Action(pApp)
{
}

void AddConnection::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Adding connection, Please Select a source then a destination");


	pIn->GetPointClicked(x, y);


	pOut->ClearStatusBar();
}
void AddConnection::Execute()
{
	GraphicsInfo GInfo;
	int hazem = 1;
	while (hazem)
	{
		ReadActionParameters();
		for (int i = 0; i < pManager->getCompcount(); i++)
		{
			if (pManager->getarrayofcomp()[i]->inside(x, y) && pManager->getarrayofcomp()[i]->gettype() != Led)
			{
				source = pManager->getarrayofcomp()[i];
				hazem = 0;
				break;
			}
		}
	}
	hazem = 1;
	GInfo.x1 = x;
	GInfo.y1 = y;
	while (hazem)
	{
		ReadActionParameters();
		for (int i = 0; i < pManager->getCompcount(); i++)
		{
			if (pManager->getarrayofcomp()[i]->inside(x, y) && pManager->getarrayofcomp()[i]->gettype() != SWITCH)
			{
				Dest = pManager->getarrayofcomp()[i];
				if (pManager->getarrayofcomp()[i]->getTaken() == pManager->getarrayofcomp()[i]->getMaxIn())
				{
					pManager->GetOutput()->PrintMsg("Sorry this gate has max number of inputs");
					return;
				}
				hazem = 0;
				break;
			}
		}
	}
	GInfo.x2 = x;
	GInfo.y2 = y;
	//Sleep(2000);
	Connection *con = new Connection(GInfo, source->getOPin(), Dest->whichInput());
	source->getOPin()->ConnectTo(con);
	///call the mentioned funtion in the paper

	//con->getOPin()->ConnectTo(con);
	//Dest->getIPin(Dest->getTaken())->
	x = source->getXcoordiantescorner2();
	y = (source->getYcoordiantescorner2() + source->getYcoordiantescorner1()) / 2;
	int x1 = x;
	int y1 = y;
	int d, d1;
	int c = 1;
	//int q = 0;
	//int hazem = 0;
	con->setCount(c);
	con->setX(source->getXcoordiantescorner2(), 0);
	con->setY((source->getYcoordiantescorner2() + source->getYcoordiantescorner1()) / 2, 0);
	pManager->AddConnectiona(con);
	pManager->GetInput()->getwindowpointer()->SetPen(BLACK, 2);
	//pManager->GetInput()->getwindowpointer()->SetBuffering(1);
	pManager->GetOutput()->setBuffer(1);
	while (!Dest->inside(x, y))
	{
		pManager->GetOutput()->PrintMsg("Click on the path you want the connection to follow ");

		pManager->GetInput()->getwindowpointer()->GetButtonState(LEFT_BUTTON, x1, y1);
		if (pManager->GetInput()->getwindowpointer()->GetButtonState(LEFT_BUTTON, d, d1) == BUTTON_DOWN)
		{
			x = d;
			y = d1;
			con->setX(x, c);
			con->setY(y, c);
			c++;
			con->setCount(c);
			//c++;
			//Sleep(100);
			while (pManager->GetInput()->getwindowpointer()->GetButtonState(LEFT_BUTTON, d, d1) == BUTTON_DOWN)
			{
			}
		}

		if (x1 == x || y1 == y)
		{
			pManager->GetInput()->getwindowpointer()->DrawLine(x, y, x1, y1);
			//q++;
		}
		else
		{
			pManager->GetOutput()->drawline2(x, y, x1, y1, c, 0, 0);
			//hazem++;
		}

		//Sleep(50);



		pManager->GetInput()->getwindowpointer()->UpdateBuffer();
		pManager->UpdateInterface();
	}
	pManager->GetOutput()->setBuffer(0);
	//pManager->GetInput()->getwindowpointer()->SetBuffering(0);
	con->setX(Dest->getXcoordiantescorner1(), c - 1);
	//con->setY((Dest->getYcoordiantescorner2() + Dest->getYcoordiantescorner1()) / 2, c-1);
	con->setY(Dest->getYIn(), c - 1);
	pManager->UpdateInterface();
	/*for (int i = 0; i < pManager->getCount(); i++)
	{
	if (pManager->getarrayofcomp()[i]->inside(x, y))
	{
	x = pManager->getarrayofcomp()[i]->getGraphics().x2;
	y = (pManager->getarrayofcomp()[i]->getGraphics().y2 + pManager->getarrayofcomp()[i]->getGraphics().y1) / 2;
	}
	}*/

}
void AddConnection::Undo() {}
void AddConnection::Redo() {}
AddConnection::~AddConnection()
{
}
