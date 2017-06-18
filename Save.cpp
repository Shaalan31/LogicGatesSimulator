#include "Save.h"

Save::Save(ApplicationManager *pApp) :Action(pApp)
{

}

void Save::ReadActionParameters() {}
void Save::Redo() {}
void Save::Undo() {}
void Save::Execute()
{
	Saved.open("File.txt", ios::out);
	Saved << pManager->getCount();
	Saved << endl;
	string s;
	for (int i = 0; i < pManager->getCount(); i++)
	{
		x = pManager->getarrayofcomp()[i]->getGraphics().x1 + pManager->getarrayofcomp()[i]->getGraphics().x2;
		x = x / 2;
		y = pManager->getarrayofcomp()[i]->getGraphics().y1 + pManager->getarrayofcomp()[i]->getGraphics().y2;
		y = y / 2;
		Saved << pManager->getarrayofcomp()[i]->gettype() << "	";
		Saved << pManager->getarrayofcomp()[i]->getID() << " ";
		s = pManager->getarrayofcomp()[i]->getLabel();
		if (s == "")
			Saved << "NOLABEL  ";
		else
			Saved << s;
		//Saved << pManager->getarrayofcomp()[i]->getLabel() << "	";
		Saved << x << " ";
		Saved << y << " ";
		Saved << endl;


	}
	Saved << "Connections" << endl;
	for (int i = 0; i < pManager->getConnCount(); i++)
	{
		
		for (int j = 0; j < pManager->getCompcount(); j++)
		{
			if (pManager->getarrayconn()[i]->getSourceID(pManager->getarrayofcomp()[j]) != -1)
			{
				Saved << pManager->getarrayofcomp()[j]->getID() << "  ";
				break;
			}
		}
		Saved << pManager->getarrayconn()[i]->getInputPin()->getComponent()->getID() << " ";
		
		//Saved << pManager->getarrayconn()[i]->getPIN() << " ";
		Saved << endl;
	}
	Saved << endl;
	Saved << -1;

	Saved.close();

}

Save::~Save()
{
}
