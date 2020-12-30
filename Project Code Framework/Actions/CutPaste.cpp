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
	pOut->ClearStatusBar(); //de el mafrood nemsa7ha??

}

void CutPaste::Execute()
{
	ReadActionParameters();
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	string CutPaste = pIn->GetSrting(pOut); // de kaman el mafrood nemsa7ha?? w ne7ot makanha eh?
	pOut->PrintInDrawingArea(CutPaste, x, y);

}

void CutPaste::Undo()
{}

void CutPaste::Redo()
{}
