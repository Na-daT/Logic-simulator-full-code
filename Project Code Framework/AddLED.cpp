#include "AddLED.h"
#include "ApplicationManager.h"

AddLED::AddLED(ApplicationManager* pApp) :Action(pApp)
{
}

AddLED::~AddLED(void)
{
}

void AddLED::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("LED: Click to add the component");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddLED::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.LED_Width;
	int Wdth = UI.LED_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the LED gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	LED* pA = new LED(GInfo);
	pManager->AddComponent(pA);
	pA->SetID(pManager->RetrunIndex(pA));
}

void AddLED::Undo()
{}

void AddLED::Redo()
{}
