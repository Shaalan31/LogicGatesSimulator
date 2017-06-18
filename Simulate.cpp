#include "Simulate.h"
Simulate::Simulate(ApplicationManager *pApp):Action(pApp){}
Simulate::~Simulate(){}
 void Simulate::ReadActionParameters()
 {
	 //Get a Pointer to the Input / Output Interfaces
	 Output* pOut = pManager->GetOutput();
	 Input* pIn = pManager->GetInput();

	 //Print Action Message
	 pOut->PrintMsg("Action:Simulating");

	 //Wait for User Input
	 pIn->GetPointClicked(x, y);
	 //Clear Status Bar
	 pOut->ClearStatusBar();
	 ///////////////////
 }
 void Simulate::Execute()
 {
	 for (int i = 0; i < (pManager->getCompcount()); i++)
	 {
			 if (pManager->getarrayofcomp()[i]->gettype() == SWITCH)
			 {
				 //pManager->getarrayofcomp()[i]->setselected(1);
				 //pManager->UpdateInterface();
				 operating(pManager->getarrayofcomp()[i]);
			 }
			 else
				 continue;
	 }
	 pManager->UpdateInterface();
	 ReadActionParameters();
	 while (y >= (UI.ToolBarHeight ) && y < UI.height - UI.StatusBarHeight)
	 {
		 for (int i = 0; i < (pManager->getCompcount()); i++)
		 {
			 if (pManager->getarrayofcomp()[i]->inside(x, y))
			 {
				 if (pManager->getarrayofcomp()[i]->gettype() == SWITCH)
				 {
					 if (pManager->getarrayofcomp()[i]->getselected() == 0)
					 {
						 pManager->getarrayofcomp()[i]->setselected(1);
						 pManager->getarrayofcomp()[i]->setSwitch();
					 }
					 else
					 {
						 pManager->getarrayofcomp()[i]->setselected(0);
						 pManager->getarrayofcomp()[i]->setSwitch();

					 }
					 // change the output pin status here

					 
					 operating(pManager->getarrayofcomp()[i]);
					 pManager->UpdateInterface();
					 break;
				 }
				 else
					 continue;
			 }
		 }
		 ReadActionParameters();
	 }

 }

 void Simulate::Undo(){}
 void Simulate::Redo(){}
 void Simulate::operating(Component* componentPtr/*,bool operate)*/)
 {
	 if (componentPtr->gettype() == Led)
	 {
		 componentPtr->Operate();
		 return;
	 }
	 for (int i = 0; i < componentPtr->getOutputPin()->getCount(); i++)
	 {
		 //if (componentPtr->gettype() == SWITCH)
		 	 //operate = true;
		 //if(componentPtr->getOutputPin()->getarrayofconnections()[i]->getDestPin()->getComponent()
			 componentPtr->getOutputPin()->getConn()[i]->getDestPin()->setStatus(componentPtr->getOutputPin()->getStatus());
			 componentPtr->getOutputPin()->getConn()[i]->getDestPin()->getComponent()->Operate();
			 pManager->UpdateInterface();
			 operating(componentPtr->getOutputPin()->getConn()[i]->getDestPin()->getComponent());
			  
		 
	 }

 }
