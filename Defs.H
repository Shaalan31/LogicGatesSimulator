#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//All possible actions
enum ActionType 
{
	ADD_Buff,			//Add 1-input Buffer gate
	ADD_INV,			//Add 1-input Inverter gate
	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_OR_GATE_2,		//Add 2-input OR gate
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
	ADD_AND_GATE_3,		//Add 3-input AND gate
	ADD_NOR_GATE_3,		//Add 3-input NOR gate
	ADD_XOR_GATE_3,		//Add 3-input XOR gate
	ADD_Switch,			//Add Switch
	ADD_LED,			//Add LED
	ADD_CONNECTION,		//Add Wire Connection
	Clear_WINDOW,
	ADD_Label,			//Add Label to a Component, a Connection
	EDIT_Label,			//Edit Label of a Component, a Connection

	Validation_,
	SimulateAct,
	Create_TruthTable,	//Create Truth Table of the Circuit
	Probing,

	Change_Switch,		//Change Switch Status in Simulation Mode

	SELECT,		//Select a Component, a Connection
	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection

	SAVE,		//Save the whole Circuit to a file
	LOAD,		//Load a Circuit from a file

	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode

	EXIT,		//Exit the application

	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar
	SIM_TOOL,
	CutAct,
	CopyAct,
	PasteAct

};
enum ComponentType
{
	AND2gate,
	AND3gate,
	OR2gate,
	XOR2gate,
	XOR3gate,
	XNOR2gate,
	XNOR3gate,
	NAND2gate,
	NAND3gate,
	NOR2gate,
	NOR3gate,
	BUFFERgate,
	INVERTERgate,
	Led,
	SWITCH
};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH
};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION,
	EditA
};





enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_Buff,		//Buffer
	ITM_INV,        //NOT gate item in menu
	ITM_AND2,		//AND (2) gate item in menu
	ITM_OR2,		//OR gate item in menu
	ITM_NAND2,      //NAND gate item in menu
	ITM_NOR2,       //NOR (2) gate item in menu
	ITM_XOR2,       //XOR (2) gate item in menu
	ITM_XNOR2,      //XNOR gate item in menu
	ITM_AND3,       //AND (3) gate item in menu
	ITM_NOR3,       //NOR (3) gate item in menu
	ITM_XOR3,       //XOR (3) gate item in menu
	ITM_Switch,     //Switch
	ITM_LED,        //LED
	ITM_Wire,
	ITM_Open,
	ITM_Save,
	ITM_Undo,
	ITM_Redo,
	ITM_Label,
	ITM_Cut,
	ITM_Copy,
	ITM_Paste,
	ITM_Move,
	ITM_Select,
	ITM_Delete,
	ITM_EDIT,
	ITM_Help,
	Sim,		//simulation mode
				//Select,

	ITM_EXIT,//Exit item
			 //TODO: Add more items names here

	ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum
};
enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	ITM_VAL,    //Validate the cicuit
	ITM_SIM,	//Simulate menu item
	ITM_TRUTH,	//Truth table menu item
	ITM_PROB,	//For circuit proibing
	ITM_DSN,	//Switch back to design mode

				//TODO:Add more items names here

	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum

};


//Maximum number of input pins that can be connected to any output pin
#define MAX_CONNS 20

//assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
	AND2_FANOUT = 5	//Default fan out of 2-input AND gate
};

//A structure to contain drawing parameters for each component
//Each component occupies a rectangluar area so it needs 2 points to represent that area
//this structure can be extended if desired
struct GraphicsInfo
{
	int x1,y1, x2, y2;
};

#ifndef NULL
#define NULL 0
#endif

#endif