#pragma once
#ifndef _ADD_Redo_H
#define _ADD_Redo_H

#include"Action.h"

class redo : public Action
{	
public:
	redo(ApplicationManager *pApp);
	virtual ~redo(void);
	
	virtual void ReadActionParameters();
	
	virtual void Execute();

	virtual void Undo();

	virtual void Redo();
};

#endif