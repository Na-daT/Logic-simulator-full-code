#include "Simulate_circuit.h"

Simulate_Circuit::Simulate_Circuit(ApplicationManager* pApp)
	:Action(pApp)
{
}

void Simulate_Circuit::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Simulating circuit, click on any switch to change value, then click enter when done");
	pIn->GetPointClicked(Cx, Cy);
}

void Simulate_Circuit::Execute()
{
	ReadActionParameters();
	int* y = pManager->ListofComp();

	int n_switches = 0;
	int* switches_ids = new int[n_switches];
	

	for (int i = 0; i < pManager->GetCompCount(); i++)
	{
		if (y[i] == ITM_SWITCH)
		{
			switches_ids[n_switches] = i;
			n_switches++;
		}
	}

	Component** ListofSwitches= new Component*[n_switches];

	for (int i = 0; i < n_switches; i++)
	{
		ListofSwitches[i] = pManager->GetspecificComponentinList(i);
	}

	for (int i = 0; i < n_switches; i++)
	{
		if (ListofSwitches[i]->IsClickInsideArea(Cx, Cy))
			ListofSwitches[i]->setInputPinStatus(1, HIGH);
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
