#include "cutpaste.h"

#include "../ApplicationManager.h"

CutPaste::CutPaste(ApplicationManager* pApp) :Action(pApp)
{
}

CutPaste::~CutPaste(void)
{
}

void CutPaste::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click on the item you want to cut");

	//Wait for User Input
	pIn->GetPointClicked(x, y);

	//Clear Status Bar
	pOut->ClearStatusBar(); 

}

void CutPaste::Execute()
{
	ReadActionParameters();
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	
	pOut->PrintInDrawingArea(CutPaste, xx, yy);

}

void CutPaste::Undo()
{}

void CutPaste::Redo()
{}
