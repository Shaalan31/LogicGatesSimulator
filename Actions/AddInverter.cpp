#include "AddInverter.h"
#include "..\ApplicationManager.h"
#include"..\Components\INVERTER.h"

AddInverter::AddInverter(ApplicationManager *pApp) :Action(pApp)
{
}

AddInverter::~AddInverter(void)
{
}



void AddInverter::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Not Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddInverter::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	//////////////////////////////////////
	x1 = GInfo.x1;
	y1 = GInfo.y1;
	x2 = GInfo.x2;
	y2 = GInfo.y2;
	////////////////////////////////
	INVERTER *pA = new INVERTER(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}

void AddInverter::Undo()
{}

void AddInverter::Redo()
{}
