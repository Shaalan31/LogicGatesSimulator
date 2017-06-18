#include "SubInput.h"
#include "SubOutput.h"


SubInput::SubInput(window* pW)
{
	pWind = pW; //point to the passed window
}


SubInput::~SubInput()
{
}
window * SubInput::getwindowpointer()
{
	return pWind;
}



void SubInput::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string SubInput::GetSrting(SubOutput *pOut)
{
	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar
	/////////////////////////////// our work /////////////////////////////////////////
	//	keytype option;
	/*	char next;
	int count = 0;
	cout << "Enter a line of SubInput:\n";
	cin.get(next);//gets first character (position zero) from SubInput stream

	while (next != '\n')//check whether the character is not line feed(End of the line)
	{
	if ((count % 2) == 0)//checks if position is even
	cout << next;      //if yes print that letter
	count++;           //increments the count
	cin.get(next);     //gets next character from SubInput stream
	}*/
	/////////////////////////////////
	char inp;
	string s;

	while (s.find_first_of("\r") == -1)
	{
		pWind->WaitKeyPress(inp);
		if (inp == '\b')
		{
			if (s.size() == 0)
				continue;
			s.erase(s.size() - 1);
		}
		else if (inp == '\x1')
			return "\0";
		else
			s.operator+=(inp);
		pOut->PrintMsg(s);
	}
	return s;
}

//This function reads the position where the user clicks to determine the desired action
ActionType SubInput::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick item was clicked

			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_Buff: return ADD_Buff;
			case ITM_INV: return ADD_INV;
			case ITM_AND2: return ADD_AND_GATE_2;
			case ITM_OR2: return ADD_OR_GATE_2;
			case ITM_NAND2: return ADD_NAND_GATE_2;
			case ITM_NOR2: return ADD_NOR_GATE_2;
			case ITM_XOR2: return ADD_XOR_GATE_2;
			case ITM_XNOR2: return ADD_XNOR_GATE_2;
			case ITM_AND3: return ADD_AND_GATE_3;
			case ITM_NOR3: return ADD_NOR_GATE_3;
			case ITM_XOR3: return ADD_XOR_GATE_3;
			case ITM_Switch: return ADD_Switch;
			case ITM_LED: return ADD_LED;
			case ITM_Wire: return ADD_CONNECTION;
			case ITM_Undo: return UNDO;
			case ITM_Redo: return REDO;
			case ITM_EDIT: return Clear_WINDOW;
			case Sim: return SIM_MODE;
			case ITM_Open: return LOAD;
			case ITM_Save: return SAVE;
			case ITM_Delete: return DEL;
			case ITM_Select: return SELECT;
			case ITM_Label: return ADD_Label;
			case ITM_Cut: return CutAct;
			case ITM_Copy: return CopyAct;
			case ITM_Paste: return PasteAct;
			case ITM_Move: return MOVE;
			case ITM_EXIT: return EXIT;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}


		//[2] User clicks on the drawing area
		if (y >= (UI.ToolBarHeight /*+ UI.StatusBarHeight*/) && y < UI.height - UI.StatusBarHeight)
		{

			return SELECT;	//user want to select/unselect a statement in the flowchart
		}
		//if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		//return SIM_MODE;
		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			SimMenuItem x;
			x = (SimMenuItem)ClickedItemOrder;
			switch (x)
			{
			case ITM_VAL:
				return Validation_;
				break;
			case ITM_SIM:
				return SimulateAct;
				break;
			case ITM_TRUTH:
				return Create_TruthTable;
				break;
			case ITM_PROB:
				return Probing;
				break;
			case ITM_DSN:
				return DSN_MODE;
				break;
			default:
				return SIM_TOOL;
			}
		}
		else if (y >= (UI.ToolBarHeight /*UI.StatusBarHeight*/) && y < UI.height - UI.StatusBarHeight)
		{

			return SELECT;	//user want to select/unselect a statement in the flowchart
		}
		return STATUS_BAR;
	}
}
void SubInput::PrintString(int iX, int iY, SubOutput *pOut)
{
	string s;
	s = GetSrting(pOut);
	//if(s!="")
	pWind->DrawString(iX, iY, s);
}



