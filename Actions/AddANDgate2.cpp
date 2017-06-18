#include "AddANDgate2.h"
#include "..\ApplicationManager.h"

AddANDgate2::AddANDgate2(ApplicationManager *pApp):Action(pApp)
{
}

AddANDgate2::~AddANDgate2(void)
{
}

void AddANDgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input AND Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
	
}

void AddANDgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	
	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
	
	GInfo.x1 = Cx - Len/2;
	GInfo.x2 = Cx + Len/2;
	GInfo.y1 = Cy - Wdth/2;
	GInfo.y2 = Cy + Wdth/2;
	//////////////////////////////////////
	x1 = GInfo.x1;
	y1 = GInfo.y1;
	x2 = GInfo.x2;
	y2 = GInfo.y2;
	////////////////////////////////
	AND2 *pA=new AND2(GInfo, AND2_FANOUT); 
	Comp = pA;
	pManager->AddComponent(pA);
}

void AddANDgate2::Undo()
{
	pManager->get_Redo_Array()[pManager->get_count_redo()] = pManager->get_Undo_Array()[pManager->get_count_undo() - 1];
	pManager->get_Undo_Array()[pManager->get_count_undo() - 1] = NULL;
	pManager->increment_count_redo();
	pManager->decrement_count_undo();

	Cx = (Comp->getXcoordiantescorner1() + Comp->getXcoordiantescorner2()) / 2;
	Cy = (Comp->getYcoordiantescorner1() + Comp->getYcoordiantescorner2()) / 2;
	pManager->DelComponent(Comp);

}

void AddANDgate2::Redo()
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

	AND2 *pA = new AND2(GInfo, AND2_FANOUT);
	Comp = pA;
	pManager->AddComponent(pA);
}

