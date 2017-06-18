#pragma once
#ifndef _ADD_Undo_H
#define _ADD_Undo_H

#include"Action.h"

class undo : public Action
{
public:
	undo(ApplicationManager *pApp);
	virtual ~undo(void);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual void Undo();

	virtual void Redo();
};

#endif