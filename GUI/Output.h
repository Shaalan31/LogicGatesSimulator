#pragma once
#include "..\Defs.h"
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;
	//Pointer to the Graphics Window
public:
	Output(); // Performs the Window Initialization
	Input* CreateInput() const; //creates a pointer to the Input object
	void ChangeTitle(string Title) const;
	void PrintChar(string msg, int pos);
	void CreateDesignToolBar() const;	//Tool bar of the design mode
	void CreateSimulationToolBar() const;//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar

	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area

	window* CreateWind(int wd, int h, int x, int y) const; //Creates user interface window

	
	// Draws 2-input AND gate
	// Draws Functions
	void DrawAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNAND(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNOT(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXNOR(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNOR(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawBUFF(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawAND3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawWIRE(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawLED(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawSWITCH(GraphicsInfo r_GfxInfo, bool selected = false) const;
	//void Drawconnections();
	void setBuffer(bool y);
	void drawline2(int x, int y, int x1, int y1, int count = 0, bool state = 0, bool selected = 0) const;
	void DrawConnection(GraphicsInfo r_GfxInfo, int*x, int*y, int count, bool state = 0, bool selected = false) const;

	///TODO: Make similar functions for drawing all other gates, switch, and LED, .. etc

	// Draws Connection
	//void DrawConnection(GraphicsInfo r_GfxInfo, bool selected = false) const;
	
	void PrintMsg(string msg) const;	//Print a message on Status bar
	void PrintString(int iX, int iY, string s);

	~Output();
};
