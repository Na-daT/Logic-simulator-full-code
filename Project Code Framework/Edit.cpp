/*#include "../Project Code Framework/ApplicationManager.h" 
#include "Edit.h"
#include "Actions/Label.h"


Edit::Edit(ApplicationManager* pApp) :Action(pApp)
{
}

Edit::~Edit(void)
{

}


void Edit::ReadActionParameters() 
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();  

	pOut->PrintMsg("click on gate to select or deselct");

	//Wait for User Input
	pIn->GetPointClicked(x, y);

	//Print Action Message
	pOut->PrintMsg("Edit Label or Connections");

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Edit::Execute()
{
/*	ReadActionParameters();
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Enter New Label");
	Component* pComp;

	pComp = pManager->IsGateinsideArea(x, y);
	if (pComp)
	{
		pComp->SetLabel( s);
	}
}

void Label::Undo()
{}

void Label::Redo()
{}*/