#include "Load.h"
#include "ApplicationManager.h"

Load::Load(ApplicationManager* pApp) :Action(pApp)
{
}

Load::~Load(void)
{
}

void Load::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	File.open("LoadedFile.txt");
	pOut->PrintMsg("File is loaded");
}

void Load::Execute()
{
	ReadActionParameters();
	pManager->UpdateInterface();
	pManager->LoadAction(File);
}

void Load::Undo()
{}

void Load::Redo()
{}
