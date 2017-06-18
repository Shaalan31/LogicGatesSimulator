
//#include "E:\college\OOP\PT Project S2016 - Logic Sim - student\Project Code Framework\Actions\Action.h"
//#include"Actions\Action.h"

#include"Action.h"
#include"..\Components\Gate.h"
class Copy :
	public Action
{
	int xIn;
	int yIn;
	Component*copycomp;
public:
	Copy(ApplicationManager *pApp);
	~Copy();
	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

