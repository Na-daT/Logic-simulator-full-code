#include "Simulate_circuit.h"

Simulate_Circuit::Simulate_Circuit(ApplicationManager* pApp)
	:Action(pApp)
{
}

void Simulate_Circuit::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Simulating circuit, click on any switch to change value");
	pIn->GetPointClicked(Cx, Cy);//we need a point to see if user click on a switch
}

void Simulate_Circuit::Execute()
{
	
	int ClickedItemOrder=1;
	

	while (!Stop_Sim)
	{

		pManager->OperateALLgates();

		ReadActionParameters();
		if (Cy >= 0 && Cy < UI.ToolBarHeight)
		{
			ClickedItemOrder = (Cx / UI.ToolItemWidth);
		}

		if (ClickedItemOrder == 0)
			Stop_Sim = true;
		else
		{
			pManager->ExecuteAction(Change_Switch);
			pManager->UpdateInterface();
		}
	}

	if (Stop_Sim)
	{
		pManager->ExecuteAction(SIM_MODE);
		return;
	}





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
