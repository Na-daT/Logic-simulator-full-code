#include "AddBuffer.h"
#include "ApplicationManager.h"

AddBuffer::AddBuffer(ApplicationManager* pApp) :Action(pApp)
{
}

AddBuffer::~AddBuffer(void)
{
}

void AddBuffer::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Buffer Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	while (Cy <= UI.ToolBarHeight || Cy >= (UI.height - UI.StatusBarHeight))
	{
		pOut->PrintMsg("Please Click in the Drawing Area");
		pIn->GetPointClicked(Cx, Cy);
	}


	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddBuffer::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.Buffer_Width;
	int Wdth = UI.Buffer_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the Buffer gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	buffer* pA = new buffer(GInfo, BUFFER_FANOUT);
	pManager->AddComponent(pA);

	pA->SetID(pManager->RetrunIndex(pA));
}

void AddBuffer::Undo()
{}

void AddBuffer::Redo()
{}
