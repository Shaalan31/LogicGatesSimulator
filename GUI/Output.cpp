#include "Output.h"
#include"..\Components\Connection.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

							//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;

	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
						// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
void Output::PrintChar(string msg, int pos)
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
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

							//You can draw the tool bar icons in any way you want.

							//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_Buff] = "images\\Menu\\Menu_BUFF.jpg";
	MenuItemImages[ITM_INV] = "images\\Menu\\Menu_NOT.jpg";
	MenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND.jpg";
	MenuItemImages[ITM_OR2] = "images\\Menu\\Menu_OR.jpg";
	MenuItemImages[ITM_NAND2] = "images\\Menu\\Menu_NAND.jpg";
	MenuItemImages[ITM_NOR2] = "images\\Menu\\Menu_NOR.jpg";
	MenuItemImages[ITM_XOR2] = "images\\Menu\\Menu_XOR.jpg";
	MenuItemImages[ITM_XNOR2] = "images\\Menu\\Menu_XNOR.jpg";
	MenuItemImages[ITM_AND3] = "images\\Menu\\Menu_AND3.jpg";
	MenuItemImages[ITM_NOR3] = "images\\Menu\\Menu_NOR3.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Menu\\Menu_XOR3.jpg";
	MenuItemImages[ITM_Switch] = "images\\Menu\\Menu_Switch.jpg";
	MenuItemImages[ITM_LED] = "images\\Menu\\Menu_LED.jpg";
	MenuItemImages[ITM_Wire] = "images\\Menu\\Menu_WIRE.jpg";
	MenuItemImages[ITM_Undo] = "images\\Menu\\Menu_Undo.jpg";
	MenuItemImages[ITM_Redo] = "images\\Menu\\Menu_Redo.jpg";
	MenuItemImages[ITM_Cut] = "images\\Menu\\Menu_CUT.jpg";
	MenuItemImages[ITM_Copy] = "images\\Menu\\Menu_COPY.jpg";
	MenuItemImages[ITM_Paste] = "images\\Menu\\Menu_PASTE.jpg";
	MenuItemImages[ITM_Select] = "images\\Menu\\Menu_Select.jpg";
	MenuItemImages[ITM_Move] = "images\\Menu\\Menu_Move.jpg";
	MenuItemImages[ITM_Help] = "images\\Menu\\Menu_HELP.jpg";
	MenuItemImages[ITM_Label] = "images\\Menu\\Menu_Label.jpg";
	MenuItemImages[ITM_Open] = "images\\Menu\\Menu_OPEN.jpg";
	MenuItemImages[ITM_Save] = "images\\Menu\\Menu_SAVE.jpg";
	MenuItemImages[ITM_Delete] = "images\\Menu\\Menu_DELETE.jpg";
	MenuItemImages[ITM_EDIT] = "images\\Menu\\Menu_Clear.jpg";
	MenuItemImages[Sim] = "images\\Menu\\Menu_Simulate.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i<ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
	UI.AppMode = SIMULATION;	//Simulation Mode

								//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)
	string MenuSimImages[ITM_SIM_CNT];
	MenuSimImages[ITM_VAL] = "images\\Menu\\Menu_Validation.jpg";
	MenuSimImages[ITM_SIM] = "images\\Menu\\Menu_SIM.jpg";
	MenuSimImages[ITM_TRUTH] = "images\\Menu\\Menu_TT.jpg";
	MenuSimImages[ITM_PROB] = "images\\Menu\\Menu_Prob.jpg";
	MenuSimImages[ITM_DSN] = "images\\Menu\\Menu_Desgin.jpg";
	for (int i = 0; i<ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuSimImages[i], i*UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	//Draw a line under the simulation bar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);


}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_AND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info

	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_OR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_OR2.jpg";
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawNAND(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NAND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NAND2.jpg";
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawNOT(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_INVERTER_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_INVERTER.jpg";
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR2.jpg";
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXNOR(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XNOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XNOR2.jpg";
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawNOR(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR2.jpg";
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawBUFF(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_BUFFER_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_BUFFER.jpg";
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_XOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_XOR3.jpg";
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_AND3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_AND3.jpg";
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_NOR3_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_NOR3.jpg";
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawWIRE(GraphicsInfo r_GfxInfo, bool selected) const
{
	int x1, x2, y1, y2;
	x1 = r_GfxInfo.x1;
	x2 = r_GfxInfo.x2;
	y1 = r_GfxInfo.y1;
	y2 = r_GfxInfo.y2;
	if (x1 > x2)
	{
		int x3 = x1;
		x1 = x2;
		x2 = x3;
	}
	if (y1 > y2)
	{
		int y3 = y1;
		y1 = y2;
		y2 = y3;
	}
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\GATE_Dot.jpg";
	else
		GateImage = "Images\\Gates\\GATE_Dot.jpg";
	while (x1<x2)
	{
		pWind->DrawImage(GateImage, x1, r_GfxInfo.y1, 1, 1);
		x1++;
	}
	while (y1 < y2)
	{
		pWind->DrawImage(GateImage, r_GfxInfo.x2, y1, 1, 1);
		y1++;
	}
}
void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_LEDON.jpg";
	else
		GateImage = "Images\\Gates\\Gate_LEDOFF.jpg";
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawSWITCH(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_SWITCHON.jpg";
	else
		GateImage = "Images\\Gates\\Gate_SWITCHOFF.jpg";
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
/*void Output::Drawconnections() const
{
	string GateImage;

	GateImage = "Images\\Gates\\Gate_WIRE.jpg";
	pWind->DrawImage(GateImage, 100, 100, UI.AND2_Width, UI.AND2_Height);



	GateImage = "Images\\Gates\\Gate_WIRE_BROKEN.jpg";
	pWind->DrawImage(GateImage, 100, 200, UI.AND2_Width, UI.AND2_Height);



	GateImage = "Images\\Gates\\Gate_WIRE_Hi.jpg";
	pWind->DrawImage(GateImage, 200, 100, UI.AND2_Width, UI.AND2_Height);



	GateImage = "Images\\Gates\\Gate_WIRE_Hi_Broken.jpg";
	pWind->DrawImage(GateImage, 200, 200, UI.AND2_Width, UI.AND2_Height);

}*/

void Output::drawline2(int x, int y, int x1, int y1, int count, bool state, bool selected) const
{
	if (selected)
		pWind->SetPen(BLUE, 2);
	else if (state)
		pWind->SetPen(GREEN, 2);
	else
		pWind->SetPen(BLACK, 2);

	int x2, y2;
	x2 = x;
	y2 = y1;
	pWind->DrawLine(x, y, x2, y2);
	pWind->DrawLine(x2, y2, x1, y1);
}

void Output::setBuffer(bool y)
{
	if (y)
	{
		pWind->SetBuffering(y);
		CreateDesignToolBar();
		CreateStatusBar();
	}
	else
		pWind->SetBuffering(0);
}

void Output::DrawConnection(GraphicsInfo r_GfxInfo, int *x, int* y, int count, bool state, bool selected) const
{
	//	int x1, x2, y1, y2;
	/*string GateImage;
	if (selected)	//use image in the highlighted case
	GateImage = "Images\\Gates\\GATE_Dot.jpg";
	else
	GateImage = "Images\\Gates\\GATE_Dot.jpg";*/
	//TODO: Add code to draw connection
	///ADD: a bool 2d array
	/*int x;
	int y;
	pWind->GetMouseCoord(x, y);
	button s;
	buttonstate;
	bool w = 1;
	while (w)
	{
	while (pWind->GetButtonState(LEFT_BUTTON, x, y) == BUTTON_DOWN)
	{
	pWind->DrawPixel(x, y);
	w = false;
	}
	}*/
	/*for (int i = 0; i < count; i++)
	{

	x1 = x[i];
	x2 = x[i + 1];
	y1 = y[i];
	y2 = y[i + 1];

	if (x1 > x2)
	{
	int x3 = x1;
	x1 = x2;
	x2 = x3;
	}
	if (y1 > y2)
	{
	int y3 = y1;
	y1 = y2;
	y2 = y3;
	}

	while (x1<x2)
	{
	pWind->DrawImage(GateImage, x1, r_GfxInfo.y1, 1, 1);
	x1++;
	}
	while (y1 < y2)
	{
	pWind->DrawImage(GateImage, r_GfxInfo.x2, y1, 1, 1);
	y1++;
	}
	}*/

	if (selected)
		pWind->SetPen(BLUE, 2);
	else if (state)
		pWind->SetPen(GREEN, 2);
	else
		pWind->SetPen(BLACK, 2);
	for (int i = 0; i < count-1; i++)
	{
		if (x[i] == x[i + 1] || y[i] == y[i + 1])
		{
			pWind->DrawLine(x[i], y[i], x[i + 1], y[i + 1]);
		}
		else
			drawline2(x[i], y[i], x[i + 1], y[i + 1], i, state, selected);
	}


}

void Output::PrintString(int iX, int iY, string s)
{
	//string s;
	//s = pIn->GetSrting(pOut);
	//if(s!="")
	pWind->DrawString(iX, iY, s);
}

Output::~Output()
{
	delete pWind;
}

