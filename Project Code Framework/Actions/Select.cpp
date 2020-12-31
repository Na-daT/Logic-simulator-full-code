#include "Select.h"
#include "../ApplicationManager.h" 


Select::Select(ApplicationManager* pApp) :Action(pApp)
{
}

Select::~Select(void)
{

}


void Select::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("click on gate to select or deselct");

	//Wait for User Input
	pIn->GetPointClicked(x, y);

	//Print Action Message
	pOut->PrintMsg("Component is selected");

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Select::Execute()
{
	ReadActionParameters();
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	// Code to show highlighted component

	Component** ListofComponent = pManager->CompListGetter();

	for (int i = 0; i < pManager->GetCompCount(); i++)
	{
		if (ListofComponent[i]->IsClickInsideArea(x, y))
		{
			if (ListofComponent[i]->GetSelected())
				ListofComponent[i]->setSelected(false);
			else 
				ListofComponent[i]->setSelected(true);
		}
	}


}

void Select::Undo()
{
	return;
}

void Select::Redo()
{
	return;
}
