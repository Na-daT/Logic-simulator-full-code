#include "Cut.h"

#include "../ApplicationManager.h"

Cut::Cut(ApplicationManager* pApp) :Action(pApp)
{
}

Cut::~Cut(void)
{
}

void Cut::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("click on component to cut");
	pIn->GetPointClicked(x, y);

	pOut->PrintMsg("copied to clipboard");
}

void Cut::Execute()
{
	ReadActionParameters();
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	if (pManager->IsGateinsideArea(x, y))
	{
		pManager->setCopiedComptype(pManager->IsGateinsideArea(x, y)->getType());
		pManager->IsGateinsideArea(x, y)->setSelected(true);
	}

	pManager->ExecuteAction(DEL);


}

void Cut::Undo()
{}

void Cut::Redo()
{}
