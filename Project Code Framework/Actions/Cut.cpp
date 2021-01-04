#include "Cut.h"

#include "../ApplicationManager.h"

Cut::Cut(ApplicationManager* pApp) :Action(pApp)
{
}

Cut::~Cut(void)
{
}

void Cut::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();






	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Cut::Execute()
{
	ReadActionParameters();
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pManager->AddToClipboard();
	pManager->DeleteSelectedinComplist();

}

void Cut::Undo()
{}

void Cut::Redo()
{}
