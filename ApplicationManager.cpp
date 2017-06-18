#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
//#include"Actions\AddANDgate3.h"
#include"Actions\AddANDgate3.h"
#include"Actions\AddNANDgate2.h"
#include"Actions\AddNORgate2.h"
#include"Actions\AddNORgate3.h"
#include"Actions\AddORgate2.h"
#include"Actions\AddXNORgate2.h"
#include"Actions\AddXNORgate3.h"
#include"Actions\AddXORgate2.h"
#include"Actions\AddXORgate3.h"
#include"Actions\Copy.h"
#include"Actions\Switch_to_design_mode.h"
#include"Actions\Switch_to_simulation_mode.h"
#include"Cut.h"
#include"Paste.h"
#include"Select.h"
#include"Delete.h"
#include"Move.h"
#include"Actions\AddInverter.h"
#include"Actions\AddBuffer.h"
#include"Save.h"
#include"Actions\Label.h"
#include"Actions\Load.h"
#include"Actions\Edit.h"
#include"DetectErrors.h"
#include"Exit.h"
#include"Actions\Redo.h"
#include"Actions\Undo.h"
//#include"Actions\AddConnection.h"
//#include"Actions\AddNORgate3.h"
#include"Actions\AddNORgate3.h"
#include"Actions\AddLED.h"
#include"Actions\AddSwitch.h"
#include"Simulate.h"
#include"TruthTable.h"
#include"Validation.h"
ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	ConnCount = 0;
	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;
	for (int i = 0; i<MaxConnCount; i++)
		ConnList[i] = NULL;
	count_redo = 0;
	count_undo = 0;
	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
	//SubOutputInterface = new SubOutput();
	//SubInputInterface = SubOutputInterface->CreateInput();
}
void ApplicationManager::CreateNewWindow()
{
	SubOutputInterface = new SubOutput();
	SubInputInterface = SubOutputInterface->CreateInput();
}
Component ** ApplicationManager::getarrayofcomp()
{
	return CompList;
}
/////////////////////////////////////////////
int ApplicationManager::getCompcount() { return CompCount; }

////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType,bool UR)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;
		case ADD_AND_GATE_3:
			pAct = new AddANDgate3(this);
			break;
		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
			break;
		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			break;
		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this);
			break;
		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this);
			break;
		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(this);
			break;
		case ADD_XOR_GATE_3:
			pAct = new AddXORgate3(this);
			break;
		case SELECT:
			pAct = new Select(this);
			break;
		case MOVE:
			pAct = new Move(this);
			break;
		case UNDO:
			pAct = new undo(this);
			UR = 0;
			break;
		case REDO:
			pAct = new redo(this);
			UR = 0;
		case ADD_NOR_GATE_3:
			pAct = new AddNORgate3(this);
			break;
		case ADD_CONNECTION:
			pAct = new AddConnection(this);
			break;
		case ADD_Buff:
			pAct = new AddBuffer(this);
			break;
		case ADD_INV:
			pAct = new AddInverter(this);
			break;
		case PasteAct:
			pAct = new Paste(this);
			break;
		case CopyAct:
			pAct = new Copy(this);
			break;
		case CutAct:
			pAct = new Cut(this);
			break;
		case DEL:
			pAct = new Delete(this);
			break;
		case SAVE:
			pAct = new Save(this);
			break;
		case EDIT_Label:
			pAct = new Edit(this);
			break;
		case Probing:
			pAct = new DetectErrors(this);
			break;
		case SIM_MODE:
			pAct = new Switch_to_simulation_mode(this);
			break;
		case DSN_MODE:
			pAct = new Switch_to_design_mode(this);
			break;
		case Validation_:
			pAct = new Validation(this);
			break;
		case SimulateAct:
			pAct = new Simulate(this);
			break;
		case Create_TruthTable:
			pAct = new TruthTable(this);
			break;
		case LOAD:
			pAct = new Load(this);
			break;
		case ADD_Label:
			pAct = new Label(this);
			break;
		//case SimulateAct:
			//pAct = new Simulate(this);
			//break;
		case ADD_LED:
			pAct = new AddLED(this);
			break;
		case ADD_Switch:
			pAct = new AddSwitch(this);
			break;
		case EXIT:
			pAct = new Exit(this);
			break;
	}
	if (pAct && UR)
	{
		pAct->Execute();
		Undo_Array[count_undo++] = pAct;
		pAct = NULL;
		return;
	}
	if (pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	int x3=0;
	OutputInterface->ClearStatusBar();
	OutputInterface->ClearDrawingArea();
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(OutputInterface);
		for (int i = 0; i < ConnCount; i++)
			ConnList[i]->Draw(OutputInterface);
		for (int i = 0; i < ConnCount; i++)
		{
			x3=ConnList[i]->Overlapping(CompLis);
		}
}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}
void ApplicationManager::decrementcompcount() 
{
	CompCount--;
}
SubOutput* ApplicationManager::GetSubOutput()
{
	return SubOutputInterface;
}
SubInput* ApplicationManager::GetSubInput()
{
	return SubInputInterface;
}
////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}

Connection** ApplicationManager::getarrayconn()
{
	return ConnList;
}

/*void ApplicationManager::decrementcompcount()
{
	CompCount--;
}*/
int ApplicationManager::getConnCount()
{
	return ConnCount;
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::decrmentConnCount()
{
	ConnCount--;
}
void ApplicationManager::DelConn(Connection* conn)
{
	for (int i = 0; i < ConnCount; i++)
	{
		if (ConnList[i] == conn)
		{
			//ConnList[i]->getDestPin()->getComponent();
			//			ConnList[i]->getOPin()->removeCon[ConnList[i]];
			delete ConnList[i];
			ConnList[i] = ConnList[ConnCount - 1];
			ConnList[ConnCount - 1] = NULL;
			ConnCount--;
		}
	}

}


void ApplicationManager::AddConnectiona(Connection* conn)
{
	ConnList[ConnCount++] = conn;
}


Action** ApplicationManager::get_Undo_Array()
{
	return Undo_Array;
}
////////////////////////////////////////////////////////////////////////
int ApplicationManager::get_count_redo() { return count_redo; }
////////////////////////////////////////////////////////////////////////
void ApplicationManager::increment_count_redo() { count_redo++; }
////////////////////////////////////////////////////////////////////////
void ApplicationManager::decrement_count_redo() { count_redo--; }
////////////////////////////////////////////////////////////////////
Action** ApplicationManager::get_Redo_Array()
{
	return Redo_Array;
}
/////////////////////////////////////////////////////////////////////
int ApplicationManager::get_count_undo() { return count_undo; }
////////////////////////////////////////////////////////////////////////
void ApplicationManager::increment_count_undo() { count_undo++; }
////////////////////////////////////////////////////////////////////////
void ApplicationManager::decrement_count_undo() { count_undo--; }
int ApplicationManager::getCount()
{
	return CompCount;
}