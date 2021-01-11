#include "Simulate_circuit.h"

Simulate_Circuit::Simulate_Circuit(ApplicationManager* pApp)
	:Action(pApp)
{
}

void Simulate_Circuit::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Simulating circuit");
	pIn->GetPointClicked(Cx, Cy);//we need a point to see if user click on a switch
}

void Simulate_Circuit::Execute()
{
	Output* pOut = pManager->GetOutput();
	int ClickedItemOrder=1;
	

	while (!Stop_Sim)
	{
		bool Valide = true;
		Valide = pManager->OperateALLgates();
		
		if (!Valide)
		{
			return;
		}
		pManager->UpdateInterface();

		ReadActionParameters();
		if (Cy >= 0 && Cy < UI.ToolBarHeight)
		{
			ClickedItemOrder = (Cx / UI.ToolItemWidth);
		}

		if (ClickedItemOrder == 0)
			Stop_Sim = true;
		else
		{

			ChangeSwitchInput changeswitch(pManager, Cx, Cy);
			changeswitch.Execute();
			pManager->UpdateInterface();
		}
	}

	return;






}

void Simulate_Circuit::Undo()
{
}

void Simulate_Circuit::Redo()
{
}

Simulate_Circuit::~Simulate_Circuit()
{
}
