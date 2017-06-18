#include "Switch_to_simulation_mode.h"
#include"..\ApplicationManager.h"

Switch_to_simulation_mode::Switch_to_simulation_mode(ApplicationManager*pApp) :Action(pApp) {}

Switch_to_simulation_mode::~Switch_to_simulation_mode(){}
/////////////////////////////////////////////////////////////
void Switch_to_simulation_mode::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Action:Switching back to simulation mode");

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void Switch_to_simulation_mode::Execute()
{
	ReadActionParameters();
	UI.AppMode = SIMULATION;
	pManager->GetOutput()->CreateSimulationToolBar();
}

void Switch_to_simulation_mode::Undo()
{
}

void Switch_to_simulation_mode::Redo()
{
}
