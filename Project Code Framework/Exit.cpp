#include "Save.h"
#include "ApplicationManager.h"
#include "Exit.h"

Exit::Exit(ApplicationManager* pApp) :Action(pApp)
{
}

Exit::~Exit(void)
{
}

void Exit::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();




}

void Exit::Execute()
{


}

void Exit::Undo()
{}

void Exit::Redo()
{}
