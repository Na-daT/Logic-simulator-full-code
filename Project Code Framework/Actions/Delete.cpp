#include "Delete.h"
#include "../ApplicationManager.h"
Delete::Delete(ApplicationManager* pApp) :Action(pApp)
{
}

Delete::~Delete(void)
{
}

void Delete::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Deleteing Selected gates");

	//Clear Status Bar
	

}

void Delete::Execute()
{
	ReadActionParameters();

	// code to delete comp from array
	
	pManager->DeleteSelectedinComplist();
	

}

void Delete::Undo()
{
}

void Delete::Redo()
{
}
