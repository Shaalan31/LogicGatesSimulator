#ifndef _Simulate_
#define _Simulate_
 
 // !_Simulate_

#include"ApplicationManager.h"
#include"Components\Connection.h"
#include"Actions\Action.h"
class Simulate:
	public Action
{
	int x, y;
public:
	//friend class TruthTable;
	Simulate(ApplicationManager *pApp);
	~Simulate();
	virtual void ReadActionParameters();
	virtual void Execute();
	void operating(Component* componentPtr);
	virtual void Undo();
	virtual void Redo();
	//void operating(Component* componentPtr/*,bool operate)*/);
};
#endif
