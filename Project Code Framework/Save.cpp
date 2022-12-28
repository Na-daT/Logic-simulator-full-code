#include "Save.h"
#include "ApplicationManager.h"

Save::Save(ApplicationManager* pApp) :Action(pApp)
{
}

Save::~Save(void)
{
}

void Save::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	pOut->PrintMsg("enter file name");

	fileName = pIn->GetSrting(pOut);
	//Print Action Message
	pOut->PrintMsg("saving");


}

void Save::Execute()
{
	ReadActionParameters();
	SavedFile.open(fileName, ios::out);
	pManager->SaveAction(SavedFile);
}

void Save::Undo()
{}

void Save::Redo()
{}
