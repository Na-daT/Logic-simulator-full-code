#include "Select.h"
#include "../ApplicationManager.h" 


Select::Select(ApplicationManager* pApp) :Action(pApp)
{
}

/*Select::~Select()
{
}
*/

void Select::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Component is selected");

	//Wait for User Input
	pIn->GetPointClicked(x, y);

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

	for (int i = 0; i < pManager->GetCompCount(); i++)
	{
		if (pManager->GetspecificComponentinList(i)->IsClickInsideArea(x, y))
		{
			pManager->GetspecificComponentinList(i)->setSelected(true);
		}
	}


}