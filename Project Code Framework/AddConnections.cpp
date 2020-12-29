#include "AddConnections.h"
#include "ApplicationManager.h"

AddConnections::AddConnections(ApplicationManager* pApp) :Action(pApp)
{
}

AddConnections::~AddConnections(void)
{
}

void AddConnections::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Connections: Click to add the connection");

	//Wait for User Input
	pIn->GetPointClicked(x1, y1);
	pIn->GetPointClicked(x2, y2);


	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddConnections::Execute()
{
	//Get start and end points of connection
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	//pOut->DrawConnection();
	//Connection* pA = new Connection(GInfo, AND2_FANOUT);
	//pManager->AddComponent(pA);
}

void AddConnections::Undo()
{}

void AddConnections::Redo()
{}