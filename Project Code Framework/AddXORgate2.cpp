#include "AddXORgate2.h"
#include "ApplicationManager.h"

AddXORgate2::AddXORgate2(ApplicationManager* pApp) :Action(pApp)
{
}

AddXORgate2::~AddXORgate2(void)
{
}

void AddXORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input XOR Gate: Click to add the gate");

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

void AddXORgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.XOR2_Width;
	int Wdth = UI.XOR2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the XOR2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	XOR2* pA = new XOR2(GInfo, XOR2_FANOUT);
	pManager->AddComponent(pA);
	pA->SetID(pManager->RetrunIndex(pA));
}

void AddXORgate2::Undo()
{}

void AddXORgate2::Redo()
{}