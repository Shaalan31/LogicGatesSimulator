#include"Load.h"
#include"..\Components\AND2.h"
#include"..\Components\AND3.h"
#include"..\Components\NAND2.h"
#include"..\Components\NOR2.h"
#include"..\Components\NOR3.h"
#include"..\Components\OR2.h"
#include"..\Components\XNOR2.h"
#include"..\Components\XNOR3.h"
#include"..\Components\XOR2.h"
#include"..\Components\XOR3.h"
#include"..\Components\Switch.h"
#include"..\Components\LED.h"
//////////////////////////////////////////////////////////////////////////////
Load::Load(ApplicationManager *pApp) :Action(pApp)
{
}
Load::~Load(void)
{
}
void Load::ReadActionParameters()
{
	pManager->GetOutput()->PrintMsg("Please enter the name of the file you want to load");
	file_name = pManager->GetInput()->GetSrting(pManager->GetOutput());

}
void Load::Undo(){}
void Load::Redo(){}

void Load::Execute()
{
	file_name = "File.txt";
	GraphicsInfo GInfo;
	//ReadActionParameters();
	file.open(file_name);
	file >> count;
	Id1 = 0;
	for (int i = 0; i < count; i++)
	{
		file >> comptype;
		type = (ComponentType)comptype;
		file >> comp_ID;
		file >> label;
		if (label == "NOLABEL")
			label = "";
		file >> x;
		file >> y;
		GInfo.x1 = x - 25;
		GInfo.y1 = y - 25;
		GInfo.x2 = x + 25;
		GInfo.y2 = y + 25;
		if (comptype == AND2gate)
		{
			//pManager->ExecuteAction(ADD_AND_GATE_2);
			
			AND2 *pA = new AND2(GInfo, AND2_FANOUT);
			pA->setLabel(label);
			pA->setID(comp_ID);
			pManager->AddComponent(pA);
			//break;
		}
		else if (comptype == AND3gate)
		{
			//pManager->ExecuteAction(ADD_AND_GATE_3);
			//break;
			
			AND3 *pA = new AND3(GInfo, AND2_FANOUT);
			pA->setLabel(label);
			pA->setID(comp_ID);
			pManager->AddComponent(pA);
		}
		else if (comptype == OR2gate)
		{
			//pManager->ExecuteAction(ADD_OR_GATE_2);
			//break;
		


			OR2 *pA = new OR2(GInfo, AND2_FANOUT);
			pA->setLabel(label);
			pA->setID(comp_ID);
			pManager->AddComponent(pA);
		}
		else if (comptype == NOR2gate)
		{
			//pManager->ExecuteAction(ADD_NOR_GATE_2);
			//break;
			
			NOR2 *pA = new NOR2(GInfo, AND2_FANOUT);
			pA->setLabel(label);
			pA->setID(comp_ID);
			pManager->AddComponent(pA);
		}
		else if (comptype == NAND2gate)
		{
			//pManager->ExecuteAction(ADD_NAND_GATE_2);
			//break;
			
			NAND2 *pA = new NAND2(GInfo, AND2_FANOUT);
			pA->setLabel(label);
			pA->setID(comp_ID);
			pManager->AddComponent(pA);
		}
		else if (comptype == XOR2gate)
		{
			//pManager->ExecuteAction(ADD_XOR_GATE_2);
			//break;
			
			XOR2 *pA = new XOR2(GInfo, AND2_FANOUT);
			pA->setLabel(label);
			pA->setID(comp_ID);
			pManager->AddComponent(pA);
		}
		else if (comptype == XNOR2gate)
		{
			//pManager->ExecuteAction(ADD_XNOR_GATE_2);
			//break;
			
			XNOR2 *pA = new XNOR2(GInfo, AND2_FANOUT);
			pA->setLabel(label);
			pA->setID(comp_ID);
			pManager->AddComponent(pA);
		}
		else if (comptype == XOR3gate)
		{
			//pManager->ExecuteAction(ADD_XOR_GATE_3);
			//break;
			
			XOR3 *pA = new XOR3(GInfo, AND2_FANOUT);
			pA->setLabel(label);
			pA->setID(comp_ID);
			pManager->AddComponent(pA);
		}
		else if  (comptype == NOR3gate)
		{
			//pManager->ExecuteAction(ADD_NOR_GATE_3);
			// break;
			
			NOR3 *pA = new NOR3(GInfo, AND2_FANOUT);
			pA->setLabel(label);
			pA->setID(comp_ID);
			pManager->AddComponent(pA);
		}
		else if (comptype == SWITCH)
		{
			Switch *pA = new Switch(GInfo, 5);
			pA->setLabel(label);
			pA->setID(comp_ID);
			pManager->AddComponent(pA);
		}
		else
		{
			LED *pA = new LED(GInfo,5);
			pA->setLabel(label);
			pA->setID(comp_ID);
			pManager->AddComponent(pA);

		}
	
	}
	file >> label;
	file >> Id1;
	int x3, y3;
	Connection *con;
	while (Id1 != -1)
	{
		file >> Id2;
		for (int i = 0; i < count; i++)
		{
			if (pManager->getarrayofcomp()[i]->getID() == Id1)
				Comp1 = pManager->getarrayofcomp()[i];
			else if (pManager->getarrayofcomp()[i]->getID() == Id2)
				Comp2 = pManager->getarrayofcomp()[i];
		}
			con = new Connection(GInfo, Comp1->getOPin(), Comp2->whichInput());
			Comp1->getOPin()->ConnectTo(con);
			x3 = Comp1->getXcoordiantescorner2();
			y3 = (Comp1->getYcoordiantescorner2() + Comp1->getYcoordiantescorner1()) / 2;
			int x1 = x3;
			int y1 = y3;
			int c = 2;
			con->setCount(c);
			con->setX(Comp1->getXcoordiantescorner2(), 0);
			con->setY((Comp1->getYcoordiantescorner2() + Comp1->getYcoordiantescorner1()) / 2, 0);
			pManager->AddConnectiona(con);
			con->setX(Comp2->getXcoordiantescorner1(), c - 1);
			con->setY(Comp2->getYIn(), c - 1);

		


		file >> Id1;
	}
}













