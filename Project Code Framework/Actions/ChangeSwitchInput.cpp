#include "ChangeSwitchInput.h"
#include "..\ApplicationManager.h"

ChangeSwitchInput::ChangeSwitchInput(ApplicationManager* pApp) :Action(pApp)
{
}

ChangeSwitchInput::~ChangeSwitchInput(void)
{
}

void ChangeSwitchInput::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

}

void ChangeSwitchInput::Execute()
{
	ReadActionParameters();
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	// Code to show highlighted component

	Component* pComp;
	pComp = pManager->IsGateinsideArea(Cx, Cy);

	if (pComp)
	{
		if (pComp->getType() == ITM_SWITCH)
		{
			if (pComp->GetOutPinStatus() == 1)
				pComp->setInputPinStatus(0, (STATUS)0);
			else if (pComp->GetOutPinStatus() == 0)
				pComp->setInputPinStatus(0, (STATUS)1);
		}
	}

}

void ChangeSwitchInput::Undo()
{}

void ChangeSwitchInput::Redo()
{}

