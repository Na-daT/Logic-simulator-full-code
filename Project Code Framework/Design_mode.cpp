#include "Design_mode.h"
#include "..\Project Code Framework\ApplicationManager.h"

Design_mode::Design_mode(ApplicationManager* pApp) :Action(pApp)
{
}

Design_mode::~Design_mode(void)
{
}

void Design_mode::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("switching to design mood");



}

void Design_mode::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	pOut->ClearDesignToolBar();
	pOut->CreateDesignToolBar();
	pOut->ClearStatusBar();

}

void Design_mode::Undo()
{}

void Design_mode::Redo()
{}

