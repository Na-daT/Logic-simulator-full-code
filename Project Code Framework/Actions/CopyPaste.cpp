/*#include "copypaste.h"

#include "../ApplicationManager.h"

CopyPaste::CopyPaste(ApplicationManager* pApp) :Action(pApp)
{
}

CopyPaste::~CopyPaste(void)
{
}

void CopyPaste::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click on the item you want to copy");

	//Wait for User Input
	pIn->GetPointClicked(x, y);

	//Clear Status Bar
	pOut->ClearStatusBar(); //de el mafrood nemsa7ha??

}

void CopyPaste::Execute()
{
	ReadActionParameters();
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput(); 
	Input* pIn = pManager->GetInput();
	 


	pOut->PrintInDrawingArea(CopyPaste, xx, yy);

}

void CopyPaste::Undo()
{}

void CopyPaste::Redo()
{}
*/