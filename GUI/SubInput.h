#pragma once
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "UI_Info.h"
class SubOutput;
class SubInput
{
public:
	
private:
	window *pWind;	//Pointer to the Graphics Window

public:
	SubInput(window*);
	~SubInput();
	window*  getwindowpointer();
	void PrintString(int iX, int iY, SubOutput *pOut);
	void GetPointClicked(int &, int &);	//Get coordinate where user clicks
	string GetSrting(SubOutput*);		//Returns a string entered by the user
	ActionType GetUserAction() const; //Reads the user click and maps it to an action
};

