#include "Copy.h"

#include "../ApplicationManager.h"

Copy::Copy(ApplicationManager* pApp) :Action(pApp)
{
}

Copy::~Copy(void)
{
}

void Copy::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	


	

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Copy::Execute()
{
	ReadActionParameters();
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pManager->AddToClipboard();

}

void Copy::Undo()
{}

void Copy::Redo()
{}


