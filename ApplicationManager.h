#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
//#include"Components\Connection.h"
#include"Actions\AddConnection.h"
#include "GUI\SubOutput.h"
#include "GUI\SubInput.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	
	enum { MaxConnCount = 200 };	// Max no of Connections
private:
	int CompCount;		//Actual number of Components
	int ConnCount;
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Connection* ConnList[MaxConnCount];	//List of all connections(Array of pointers)
	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	SubOutput *SubOutputInterface;
	SubInput *SubInputInterface;


protected:
	Action*Undo_Array[500];
	int count_undo;
	Action*Redo_Array[500];
	int count_redo;


public:	
	ApplicationManager(); //constructor
	Component**getarrayofcomp();
	void decrementcompcount();
	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType, bool UR=1);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();
	SubOutput* GetSubOutput();
	SubInput* GetSubInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	int getCompcount();
	//destructor
	~ApplicationManager();

	Connection** getarrayconn();
	int getCount();
	int getConnCount();
	//void decrementcompcount();
	void decrmentConnCount();
	void AddConnectiona(Connection* conn);
	void DelConn(Connection* conn);
	void CreateNewWindow();


	Action**get_Undo_Array();
	int get_count_undo();
	void increment_count_undo();
	void decrement_count_undo();

	Action**get_Redo_Array();
	int get_count_redo();
	void increment_count_redo();
	void decrement_count_redo();

};

#endif