#include "Paste.h"
#include"ApplicationManager.h"
Paste::Paste(ApplicationManager *pApp):Action(pApp)
{

}
Paste::~Paste()
{

}
 void Paste::ReadActionParameters()
 {
	 //Get a Pointer to the Input / Output Interfaces
	 Output* pOut = pManager->GetOutput();
	 Input* pIn = pManager->GetInput();

	 //Print Action Message
	 pOut->PrintMsg("Action:Pasting");

	 //Wait for User Input
	 pIn->GetPointClicked(x, y);
	 //Clear Status Bar
	 pOut->ClearStatusBar();
	 ///////////////////
 }
 void Paste::Execute()
 {
	 int once2 = 0;
	 int dx, dy;
	 int dx2, dy2;
	 int x2, y2;
	 int check = 0;
	 int checkcopy= 0;
	 int cutcopy= 0;
	 int once = 0;
	 ReadActionParameters();
	 for (int i = 0; i < (pManager->getCompcount()); i++)
	 {
		 if (!(pManager->getarrayofcomp()[i]->checkEmpty(x, y, pManager->getarrayofcomp()[i]->getGraphics())))
		 {
			 pManager->GetOutput()->PrintMsg("This area is occupied the action is cancelled please take care ");
			 check = 1;
			 break;
		 }
	 }
	 if (check == 0)
	 {
		 for (int i = 0; i < (pManager->getCompcount()); i++)
		 {
			 if (pManager->getarrayofcomp()[i]->getcopy() == 1)
			 {
				 if (once2 == 0)
				 {
					 dx = x - (pManager->getarrayofcomp()[i]->getGraphics().x2 + pManager->getarrayofcomp()[i]->getGraphics().x1) / 2;
					 dy = y - (pManager->getarrayofcomp()[i]->getGraphics().y2 + pManager->getarrayofcomp()[i]->getGraphics().y1) / 2;
					 once2 = 1;
				 }
			
				 checkcopy = 1;
				 if (pManager->getarrayofcomp()[i]->gettype() == AND2gate)
				 {
					 //pManager->ExecuteAction(ADD_AND_GATE_2);
					 int Len = UI.AND2_Width;
					 int Wdth = UI.AND2_Height;

					 GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate


					 GInfo.x1 = (pManager->getarrayofcomp()[i]->getGraphics().x1 + dx);
					 GInfo.x2 = (pManager->getarrayofcomp()[i]->getGraphics().x2 + dx);
					 GInfo.y1 = (pManager->getarrayofcomp()[i]->getGraphics().y1 + dy);
					 GInfo.y2 = (pManager->getarrayofcomp()[i]->getGraphics().y2 + dy);
					 AND2 *pA = new AND2(GInfo, AND2_FANOUT);
					 pManager->AddComponent(pA);
					 //break;
				 }
				 else if (pManager->getarrayofcomp()[i]->gettype() == AND3gate)
				 {
					 //pManager->ExecuteAction(ADD_AND_GATE_3);
					 //break;
					 int Len = UI.AND2_Width;
					 int Wdth = UI.AND2_Height;

					 GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

					 GInfo.x1 = (pManager->getarrayofcomp()[i]->getGraphics().x1 + dx);
					 GInfo.x2 = (pManager->getarrayofcomp()[i]->getGraphics().x2 + dx);
					 GInfo.y1 = (pManager->getarrayofcomp()[i]->getGraphics().y1 + dy);
					 GInfo.y2 = (pManager->getarrayofcomp()[i]->getGraphics().y2 + dy);
					 AND3 *pA = new AND3(GInfo, AND2_FANOUT);
					 pManager->AddComponent(pA);
				 }
				 else if (pManager->getarrayofcomp()[i]->gettype() ==OR2gate )
				 {
					 //pManager->ExecuteAction(ADD_OR_GATE_2);
					 //break;
					 int Len = UI.AND2_Width;
					 int Wdth = UI.AND2_Height;

					 GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
					 GInfo.x1 = (pManager->getarrayofcomp()[i]->getGraphics().x1 + dx);
					 GInfo.x2 = (pManager->getarrayofcomp()[i]->getGraphics().x2 + dx);
					 GInfo.y1 = (pManager->getarrayofcomp()[i]->getGraphics().y1 + dy);
					 GInfo.y2 = (pManager->getarrayofcomp()[i]->getGraphics().y2 + dy);


					 OR2 *pA = new OR2(GInfo, AND2_FANOUT);
					 pManager->AddComponent(pA);
				 }
				 else if (pManager->getarrayofcomp()[i]->gettype() == NOR2gate)
				 {
					 //pManager->ExecuteAction(ADD_NOR_GATE_2);
					 //break;
					 int Len = UI.AND2_Width;
					 int Wdth = UI.AND2_Height;

					 GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate


					 GInfo.x1 = (pManager->getarrayofcomp()[i]->getGraphics().x1 + dx);
					 GInfo.x2 = (pManager->getarrayofcomp()[i]->getGraphics().x2 + dx);
					 GInfo.y1 = (pManager->getarrayofcomp()[i]->getGraphics().y1 + dy);
					 GInfo.y2 = (pManager->getarrayofcomp()[i]->getGraphics().y2 + dy);
					 NOR2 *pA = new NOR2(GInfo, AND2_FANOUT);
					 pManager->AddComponent(pA);
				 }
				 else if (pManager->getarrayofcomp()[i]->gettype() == NAND2gate)
				 {
					 //pManager->ExecuteAction(ADD_NAND_GATE_2);
					 //break;
					 int Len = UI.AND2_Width;
					 int Wdth = UI.AND2_Height;

					 GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

					 GInfo.x1 = (pManager->getarrayofcomp()[i]->getGraphics().x1 + dx);
					 GInfo.x2 = (pManager->getarrayofcomp()[i]->getGraphics().x2 + dx);
					 GInfo.y1 = (pManager->getarrayofcomp()[i]->getGraphics().y1 + dy);
					 GInfo.y2 = (pManager->getarrayofcomp()[i]->getGraphics().y2 + dy);
					 NAND2 *pA = new NAND2(GInfo, AND2_FANOUT);
					 pManager->AddComponent(pA);
				 }
				 else if (pManager->getarrayofcomp()[i]->gettype() == XOR2gate)
				 {
					 //pManager->ExecuteAction(ADD_XOR_GATE_2);
					 //break;
					 int Len = UI.AND2_Width;
					 int Wdth = UI.AND2_Height;

					 GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

					 GInfo.x1 = (pManager->getarrayofcomp()[i]->getGraphics().x1 + dx);
					 GInfo.x2 = (pManager->getarrayofcomp()[i]->getGraphics().x2 + dx);
					 GInfo.y1 = (pManager->getarrayofcomp()[i]->getGraphics().y1 + dy);
					 GInfo.y2 = (pManager->getarrayofcomp()[i]->getGraphics().y2 + dy);
					 XOR2 *pA = new XOR2(GInfo, AND2_FANOUT);
					 pManager->AddComponent(pA);
				 }
				 else if (pManager->getarrayofcomp()[i]->gettype() == XNOR2gate)
				 {
					 //pManager->ExecuteAction(ADD_XNOR_GATE_2);
					 //break;
					 int Len = UI.AND2_Width;
					 int Wdth = UI.AND2_Height;

					 GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

					 GInfo.x1 = (pManager->getarrayofcomp()[i]->getGraphics().x1 + dx);
					 GInfo.x2 = (pManager->getarrayofcomp()[i]->getGraphics().x2 + dx);
					 GInfo.y1 = (pManager->getarrayofcomp()[i]->getGraphics().y1 + dy);
					 GInfo.y2 = (pManager->getarrayofcomp()[i]->getGraphics().y2 + dy);
					 XNOR2 *pA = new XNOR2(GInfo, AND2_FANOUT);
					 pManager->AddComponent(pA);
				 }
				 else if (pManager->getarrayofcomp()[i]->gettype() == XOR3gate)
				 {
					 //pManager->ExecuteAction(ADD_XOR_GATE_3);
					 //break;
					 int Len = UI.AND2_Width;
					 int Wdth = UI.AND2_Height;

					 GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
					 GInfo.x1 = (pManager->getarrayofcomp()[i]->getGraphics().x1 + dx);
					 GInfo.x2 = (pManager->getarrayofcomp()[i]->getGraphics().x2 + dx);
					 GInfo.y1 = (pManager->getarrayofcomp()[i]->getGraphics().y1 + dy);
					 GInfo.y2 = (pManager->getarrayofcomp()[i]->getGraphics().y2 + dy);
					 XOR3 *pA = new XOR3(GInfo, AND2_FANOUT);
					 pManager->AddComponent(pA);
				 }
				 else // (pManager->getarrayofcomp()[i]->gettype() == NOR3gate)
				 {
					 //pManager->ExecuteAction(ADD_NOR_GATE_3);
					// break;
					 int Len = UI.AND2_Width;
					 int Wdth = UI.AND2_Height;

					 GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

					 GInfo.x1 = (pManager->getarrayofcomp()[i]->getGraphics().x1 + dx);
					 GInfo.x2 = (pManager->getarrayofcomp()[i]->getGraphics().x2 + dx);
					 GInfo.y1 = (pManager->getarrayofcomp()[i]->getGraphics().y1 + dy);
					 GInfo.y2 = (pManager->getarrayofcomp()[i]->getGraphics().y2 + dy);
					 NOR3 *pA = new NOR3(GInfo, AND2_FANOUT);
					 pManager->AddComponent(pA);
				 }
			 }
		 }
		 if (checkcopy == 0)
		 {
			 for (int i = 0; i < (pManager->getCompcount()); i++)
			 {
				 if (pManager->getarrayofcomp()[i]->getcut() == 1)
				 {
					 if (once == 0)
					 {
						 dx2 = x - (pManager->getarrayofcomp()[i]->getGraphics().x2 + pManager->getarrayofcomp()[i]->getGraphics().x1) / 2;
						 dy2 = y - (pManager->getarrayofcomp()[i]->getGraphics().y2 + pManager->getarrayofcomp()[i]->getGraphics().y1) / 2;
						 once = 1;
					 }
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
					 }
					 pManager->getarrayofcomp()[i]->setGraphicsInfo(((pManager->getarrayofcomp()[i]->getGraphics().x1)+dx2)- 25, ((pManager->getarrayofcomp()[i]->getGraphics().y1)+dy2) - 25,((pManager->getarrayofcomp()[i]->getGraphics().x2)+dx2) + 25, ((pManager->getarrayofcomp()[i]->getGraphics().y2)+dy2) + 25);
					// break;
				 }
			 }
		 }
	 }
 }


 void Paste::DelConn(Connection * conn)
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
 void Paste::Undo(){}
  void Paste::Redo(){}