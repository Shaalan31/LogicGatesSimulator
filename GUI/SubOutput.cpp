#include "SubOutput.h"
#include"..\Components\Connection.h"
SubOutput::~SubOutput()
{
	delete pWind;
}
window * SubOutput::getwindowpointer()
{
	return pWind;
}
SubOutput::SubOutput()
{
	//Initialize user interface parameters
	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;

	//Create the drawing window
	pWind = CreateWind(1000, 1000, UI.wx, UI.wy);
	ChangeTitle("Sub Window");

}

SubInput* SubOutput::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	SubInput* pIn = new SubInput(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* SubOutput::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void SubOutput::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
void SubOutput::PrintMsg(string msg) const
{
//	ClearStatusBar();	//Clear Status bar to print message on it
						// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
void SubOutput::PrintChar(string msg, int pos)
{
	//ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25 + pos * 4;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void SubOutput::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode




//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//


void SubOutput::setBuffer(bool y)
{
	if (y)
	{
		pWind->SetBuffering(y);
		//CreateDesignToolBar();
		//CreateStatusBar();
	}
	else
		pWind->SetBuffering(0);
}

void SubOutput::ClearTruthTable() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}

void SubOutput::ClearErrors() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
void SubOutput::PrintString(int iX, int iY, string s)
{
	//string s;
	//s = pIn->GetSrting(pOut);
	//if(s!="")
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(iX, iY, s);
}


