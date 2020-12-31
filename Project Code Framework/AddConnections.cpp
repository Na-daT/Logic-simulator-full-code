#include "AddConnections.h"
#include "ApplicationManager.h"
#include "Components/Connection.h"

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
	pOut->PrintMsg("Click to add the connection");

	//Wait for User Input
	pIn->GetPointClicked(GfxInfo.x1, GfxInfo.y1);
	pIn->GetPointClicked(GfxInfo.x2, GfxInfo.y2);
	//pManager>> get which gate cllicked, da el src, the other clicked gate is dst

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddConnections::Execute()
{
	//Get start and end points of connection
	ReadActionParameters();
	Connection* pA = new Connection(GfxInfo,src,dst);
	pA->setSourcePin(src);
	pA->setDestPin(dst);
	pManager->AddComponent(pA);
}

void AddConnections::Undo()
{}

void AddConnections::Redo()
{}
