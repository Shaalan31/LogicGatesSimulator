#pragma once
#include "..\Defs.h"
#include "SubInput.h"
class SubOutput
{
private:
	window* pWind;
	//Pointer to the Graphics Window
public:
	window*  getwindowpointer();
	SubOutput();
	~SubOutput();
	// Performs the Window Initialization
	SubInput* CreateInput() const; //creates a pointer to the Input object
	void ChangeTitle(string Title) const;
	void PrintChar(string msg, int pos);
	void ClearDrawingArea() const;	//Clears the drawing area
	window* CreateWind(int wd, int h, int x, int y) const; //Creates user interface window
	void PrintMsg(string msg) const;	//Print a message on Status bar
	void PrintString(int iX, int iY, string s);
	void setBuffer(bool y);
	void ClearTruthTable() const;
	void ClearErrors() const;
};

