#include "FeedBack.h"
#include"ApplicationManager.h"
//#include"Components\Component.h"


FeedBack::FeedBack(ApplicationManager*pApp):Action(pApp)
{
}


FeedBack::~FeedBack()
{
}

 void FeedBack::ReadActionParameters()
 {
	 //Get a Pointer to the Input / Output Interfaces
	 Output* pOut = pManager->GetOutput();
	 Input* pIn = pManager->GetInput();

	 //Print Action Message
	 pOut->PrintMsg("Action:Detecting Feedback");
	 //Wait for User Input
	 //pIn->GetPointClicked(xIn , yIn);
	 //Clear Status Bar
	 pOut->ClearStatusBar();
 }
 void FeedBack::Execute()
 {
	 ReadActionParameters();
	 int check=0;
	 int check2 = 0;
	 if (!checkFloatingInputs())
		 check2 = 1;
	 for (int i = 0; i < pManager->getCompcount(); i++)
	 {
		 for (int j = 0; j < pManager->getarrayofcomp()[i]->getOutputPin()->getCount(); j++)
		 {
			 if (!Check(pManager->getarrayofcomp()[i], pManager->getarrayofcomp()[i]->getOutputPin()->getConn()[j]->getDestPin()->getComponent()))

			 {
				 check = 1;
			 }
		 }

	 }
	 if (check == 0 && check2 == 0)
	 {
		 //everything is fine 
	 }
	 else
	 {
		 //pop window indicating error
	 }



 }
 bool FeedBack::Check(Component*ptr,Component*ptr2)
 {
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
 bool FeedBack::checkFloatingInputs()
 {
	 int countinputs;
	 for (int i = 0; i < pManager->getCompcount(); i++)
	 {
		 countinputs = countinputs + pManager->getarrayofcomp()[i]->getnumofinputs();
	 }
	 //if(countinputs>connectionscount)
	 return false;
 }



