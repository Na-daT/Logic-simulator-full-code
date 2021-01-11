#include "Copy.h"

#include "../ApplicationManager.h"

Copy::Copy(ApplicationManager* pApp) :Action(pApp)
{
}

Copy::~Copy(void)
{
}

void Copy::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("click on component to be copied");
	pIn->GetPointClicked(x, y);
	


	pOut->PrintMsg("copied");

}

void Copy::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	//Get a Pointer to the Input / Output Interfaces

	if (pManager->IsGateinsideArea(x, y))
		pManager->setCopiedComptype(pManager->IsGateinsideArea(x, y)->getType());

}

void Copy::Undo()
{}

void Copy::Redo()
{}


