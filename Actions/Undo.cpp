#include "Undo.h"
#include "..\ApplicationManager.h"

undo::undo(ApplicationManager *pApp) :Action(pApp)
{
}

undo::~undo(void)
{
}

void undo::ReadActionParameters() {}

void undo::Execute()
{
	if (pManager->get_count_undo() != 0)
	{
		pManager->get_Undo_Array()[pManager->get_count_undo() - 1]->Undo();
	}
}
void undo::Undo() {}

void undo::Redo() {}


