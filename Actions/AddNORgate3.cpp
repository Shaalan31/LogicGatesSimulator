#include "AddNORgate3.h"
#include "..\ApplicationManager.h"

AddNORgate3::AddNORgate3(ApplicationManager *pApp) :Action(pApp)
{
}

AddNORgate3::~AddNORgate3(void)
{
}

void AddNORgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input NOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNORgate3::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.NOR3_Width;
	int Wdth = UI.NOR3_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	NOR3 *pA = new NOR3(GInfo, AND2_FANOUT);
	Comp = pA;
	pManager->AddComponent(pA);
}

void AddNORgate3::Undo()
{
	pManager->get_Redo_Array()[pManager->get_count_redo()] = pManager->get_Undo_Array()[pManager->get_count_undo() - 1];
	pManager->get_Undo_Array()[pManager->get_count_undo() - 1] = NULL;
	pManager->increment_count_redo();
	pManager->decrement_count_undo();
	Cx = (Comp->getXcoordiantescorner1() + Comp->getXcoordiantescorner2()) / 2;
	Cy = (Comp->getYcoordiantescorner1() + Comp->getYcoordiantescorner2()) / 2;
	pManager->DelComponent(Comp);
}

void AddNORgate3::Redo()
{
	pManager->get_Undo_Array()[pManager->get_count_undo()] = pManager->get_Redo_Array()[pManager->get_count_redo() - 1];
	pManager->get_Redo_Array()[pManager->get_count_redo() - 1] = NULL;
	pManager->increment_count_undo();
	pManager->decrement_count_redo();

	GraphicsInfo GInfo;
	GInfo.x1 = Cx - 25;
	GInfo.x2 = Cx + 25;
	GInfo.y1 = Cy - 25;
	GInfo.y2 = Cy + 25;
	NOR3 *pA = new NOR3(GInfo, AND2_FANOUT);
	Comp = pA;
	pManager->AddComponent(pA);
}





