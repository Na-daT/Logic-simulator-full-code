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
	pIn->GetPointClicked(Cx, Cy);
}

void Simulate_Circuit::Execute()
{
	ReadActionParameters();

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
