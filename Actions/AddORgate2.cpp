#include "AddORgate2.h"
#include "..\ApplicationManager.h"

AddORgate2::AddORgate2(ApplicationManager *pApp) :Action(pApp)
{
}

AddORgate2::~AddORgate2(void)
{
}

void AddORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input OR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddORgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.OR2_Width;
	int Wdth = UI.OR2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	OR2 *pA = new OR2(GInfo, AND2_FANOUT);
	Comp = pA;
	pManager->AddComponent(pA);
}

void AddORgate2::Undo()
{
	pManager->get_Redo_Array()[pManager->get_count_redo()] = pManager->get_Undo_Array()[pManager->get_count_undo() - 1];
	pManager->get_Undo_Array()[pManager->get_count_undo() - 1] = NULL;
	pManager->increment_count_redo();
	pManager->decrement_count_undo();
	Cx = (Comp->getXcoordiantescorner1() + Comp->getXcoordiantescorner2()) / 2;
	Cy = (Comp->getYcoordiantescorner1() + Comp->getYcoordiantescorner2()) / 2;
	pManager->DelComponent(Comp);

}

void AddORgate2::Redo()
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
	OR2 *pA = new OR2(GInfo, AND2_FANOUT);
	Comp = pA;
	pManager->AddComponent(pA);
}


