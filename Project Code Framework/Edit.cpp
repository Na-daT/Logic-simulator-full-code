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

	//Print Action Message
	pOut->PrintMsg("Edit Label or Connections");

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Edit::Execute()
{

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Edit c for Connection or g for Gate");
	int n = 0;
	string s = pIn->GetSrting(pOut);
	string s2;
	Component* sourcecomp;
	Component* destcomp;

	pIn->GetPointClicked(x, y);
	Component* pComp = pManager->IsGateinsideArea(x, y);
	Gate* pGate1;
	Gate* pGate2;
	if (s == "c")
	{
		if (pComp->getType() != ITM_CONNECTION)
		{
			pOut->PrintMsg("Please click on connection");
			return;
		}
		Connection* pCon = (Connection*)pComp;
		pOut->PrintMsg("Enter 1 for Label, 2 to edit source pin, or 3 to edit destination pin");
		string s1 = pIn->GetSrting(pOut);
		switch (stoi(s1))
		{
		case 1:
			s2 = pIn->GetSrting(pOut);
			pComp->SetLabel(s2);
			break;
		case 2:
			pIn->GetPointClicked(x, y);
			sourcecomp = pManager->IsGateinsideArea(x, y);
			pGate1 = (Gate*)sourcecomp;
			pCon->setSourcePin(pGate1->getSrcPin());
			break;
		case 3:
			pIn->GetPointClicked(x, y);
			destcomp = pManager->IsGateinsideArea(x, y);
			pGate2 = (Gate*)destcomp;
			int n = pGate2->getInputIndex();
			pCon->setDestPin(pGate2->getDstPin(n));
		}

	}
	else if(s == "g")
	{
		pOut->PrintMsg("edit label");
		string s3 = pIn->GetSrting(pOut);
		pComp->SetLabel(s3);
	}
	/*if (pComp)
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
	}*/

}

void Edit::Undo()
{}

void Edit::Redo()
{}