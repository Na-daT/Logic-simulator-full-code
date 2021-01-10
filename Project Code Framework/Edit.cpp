#include "../Project Code Framework/ApplicationManager.h" 
#include "Edit.h"
#include "Actions/Label.h"
#include "Components/Connection.h"
#include "Components/Gate.h"


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
	ReadActionParameters();
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Enter New Label");

	string s = pIn->GetSrting(pOut);
	int n;
	Component* pComp = pManager->IsGateinsideArea(x, y);
	if (pComp)
	{
		if (pComp->getType() != ITM_CONNECTION)
		{
			pComp->SetLabel(s);
		}
		else
		{
			pIn->GetPointClicked(x, y);
			Component* sourcecomp = pManager->IsGateinsideArea(x, y);
			Gate* pGate1 = (Gate*)sourcecomp;
			pIn->GetPointClicked(x, y);
			Component* destcomp = pManager->IsGateinsideArea(x, y);
			Gate* pgate2 = (Gate*)destcomp;
			Connection* pCon=(Connection*)pComp;
			pCon->setSourcePin(pGate1->getSrcPin());
			pCon->setDestPin(pgate2->getDstPin(n));
			
			
		}
	}

}

void Edit::Undo()
{}

void Edit::Redo()
{}