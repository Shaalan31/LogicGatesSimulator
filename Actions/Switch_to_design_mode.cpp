#include "Switch_to_design_mode.h"
#include"..\ApplicationManager.h"

Switch_to_design_mode::Switch_to_design_mode(ApplicationManager*pApp):Action(pApp){}

Switch_to_design_mode::~Switch_to_design_mode(){}
/////////////////////////////////////////////////////////////
void Switch_to_design_mode::ReadActionParameters() 
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Action:Switching back to design mode");

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void Switch_to_design_mode::Execute()
{
	ReadActionParameters();
	UI.AppMode = DESIGN;
	pManager->GetOutput()->CreateDesignToolBar();
}

void Switch_to_design_mode::Undo()
{
}

void Switch_to_design_mode::Redo()
{
}

