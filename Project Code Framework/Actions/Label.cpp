#include "Label.h"

#include "../ApplicationManager.h"

Label::Label(ApplicationManager* pApp) :Action(pApp)
{
}

Label::~Label(void)
{
}

void Label::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("click on gate then type label");

	//Wait for User Input
	pIn->GetPointClicked(x, y);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Label::Execute()
{
	ReadActionParameters();
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	Component* pComp;
	pComp = pManager->IsGateinsideArea(x, y);
	
	
	if (pComp)
	{
		string label = pIn->GetSrting(pOut);
		pComp->SetLabel(label);
	}
	else
	{
		pOut->PrintMsg("no gate selected");
		return;
	}

}

void Label::Undo()
{}

void Label::Redo()
{}
