#include "Redo.h"
#include "..\ApplicationManager.h"
redo::redo(ApplicationManager *pApp) :Action(pApp)
{
}

redo::~redo(void)
{
}

void redo::ReadActionParameters() {}

void redo::Execute()
{
	if (pManager->get_count_redo() != 0)
	{
		pManager->get_Redo_Array()[pManager->get_count_redo()-1]->Redo();
	}
}
void redo::Undo() {}

void redo::Redo() {}


