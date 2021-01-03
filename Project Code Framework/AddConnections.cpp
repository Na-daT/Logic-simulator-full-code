#include "AddConnections.h"
#include "ApplicationManager.h"
#include "Components/Connection.h"
#include "Components/Gate.h"

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
	
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddConnections::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//Get start and end points of connection
	ReadActionParameters();

	bool s = SetSrcPin();
	if (s == false)
	{
		pOut->PrintMsg("Invalid pin");
		return;
	}
	bool d = SetDstPin();
	if (d == false)
	{
		pOut->PrintMsg("Invalid pin");
		return;
	}

	Connection* pA = new Connection(GfxInfo,src,dst);
	pA->setSourcePin(src);
	pA->setDestPin(dst);
	pManager->AddComponent(pA);
}


bool AddConnections::SetSrcPin()
{
	Component* c = pManager->IsGateinsideArea(GfxInfo.x1, GfxInfo.y1);
	Gate* g;
	g = (Gate*)c;
	g->GetOutputPinCoordinates(GfxInfo.x1, GfxInfo.y1);
	src = g->getSrcPin();
	if (src->NotAvailable())
	{
		return false;
	}
	return true;
}

bool AddConnections::SetDstPin()
{
	Component* c = pManager->IsGateinsideArea(GfxInfo.x2, GfxInfo.y2);
	Gate* g;
	g = (Gate*)c;
	IndexDstPin = g->getInputIndex();
	if (IndexDstPin == -1)
		return false;
	g->GetInputPinCoordinates(GfxInfo.x2, GfxInfo.y2, IndexDstPin);
	dst = g->getDstPin(IndexDstPin);
	return true;
}




void AddConnections::Undo()
{}

void AddConnections::Redo()
{}
