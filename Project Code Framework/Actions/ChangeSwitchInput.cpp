#include "ChangeSwitchInput.h"
#include "..\ApplicationManager.h"

ChangeSwitchInput::ChangeSwitchInput(ApplicationManager* pApp, int x, int y) :Action(pApp)
{
	Cx = x;
	Cy = y;
}

ChangeSwitchInput::ChangeSwitchInput(ApplicationManager* pApp) :Action(pApp)
{
	Cx = -1;
	Cy = -1;
}

ChangeSwitchInput::~ChangeSwitchInput(void)
{
}

void ChangeSwitchInput::ReadActionParameters()
{
	if (Cx == -1 || Cy == -1)
	{
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();

		pIn->GetPointClicked(Cx, Cy);
	}

}

void ChangeSwitchInput::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	// Code to show highlighted component

	ReadActionParameters();
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

