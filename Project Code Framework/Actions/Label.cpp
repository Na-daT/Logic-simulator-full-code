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
	pOut->PrintMsg("Add Label to item");

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

	string label = pIn->GetSrting(pOut);
	pOut->PrintInDrawingArea(label, x, y);

}

void Label::Undo()
{}

void Label::Redo()
{}
