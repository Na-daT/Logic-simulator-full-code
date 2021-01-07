#include "switch_toSIM_mode.h"
#include "..\Project Code Framework\ApplicationManager.h"

switch_toSIM_mode ::switch_toSIM_mode(ApplicationManager* pApp) :Action(pApp)
{
}

switch_toSIM_mode::~switch_toSIM_mode(void)
{
}

void switch_toSIM_mode::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("switching to simulation mood");

	

}

void switch_toSIM_mode::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	pOut->ClearDesignToolBar();
	pOut->CreateSimulationToolBar();
	

}

void switch_toSIM_mode::Undo()
{}

void switch_toSIM_mode::Redo()
{}

