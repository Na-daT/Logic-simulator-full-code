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
	pOut->PrintMsg("click on component to be modified");
	pIn->GetPointClicked(x, y);
	
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Edit::Execute()
{
	ReadActionParameters();
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	int n = 0;

	pComp = pManager->IsGateinsideArea(x, y);

	string s2;
	Component* sourcecomp;
	Component* destcomp;
	Gate* pGate1;
	Gate* pGate2;

	if (!pComp)
		return;

	if (pComp->getType()==ITM_CONNECTION)
	{
		Connection* pCon = (Connection*)pComp;
		pOut->PrintMsg("Enter 1 for Label, 2 to edit the connection src and dst");
		string s1 = pIn->GetSrting(pOut);
		switch (stoi(s1))
		{
		case 1:
			pOut->PrintMsg("enter label");
			s2 = pIn->GetSrting(pOut);
			pComp->SetLabel(s2);
			break;
		case 2:

			pCon->setSelected(true);
			pManager->ExecuteAction(DEL);

			pManager->ExecuteAction(ADD_CONNECTION);
			pManager->UpdateInterface();
			break;

			/*pOut->PrintMsg("click on new source component");
			pIn->GetPointClicked(x, y);
			sourcecomp = pManager->IsGateinsideArea(x, y);

			pGate1 = (Gate*)sourcecomp;

			pCon->setSourcePin(pGate1->getSrcPin());

			pGate1->getSrcPin()->setComp(pGate1);

			pManager->UpdateInterface();
			break;*/
		/*case 3:
			pOut->PrintMsg("click on new destination component");
			pIn->GetPointClicked(x, y);
			destcomp = pManager->IsGateinsideArea(x, y);
			pGate2 = (Gate*)destcomp;
			int n = pGate2->getInputIndex();
			pCon->setDestPin(pGate2->getDstPin(n));
			pManager->UpdateInterface();*/

		}

	}
	else
	{
			pOut->PrintMsg("enter label");
			string s3 = pIn->GetSrting(pOut);
			pComp->SetLabel(s3);
	}
}

void Edit::Undo()
{}

void Edit::Redo()
{}