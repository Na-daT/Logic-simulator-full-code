/*#include "copypaste.h" 
#include "..\ApplicationManager.h"


CopyPaste::CopyPaste(ApplicationManager* pApp) :Action(pApp)
{
}

CopyCutPaste::CopyPaste(void)
{
}

void CopyPaste::ReadCopiedCompParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click on the component you want to copy");

	//Wait for User Input
	pIn->GetPointClicked(Vx, Vy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void CopyPaste::Copy()
{
	//Get Center point of the Gate
	ReadCopiedCompParameters();

	//Calculate the rectangle Corners
	int Length = UI.Component_Width;
	int Width = UI.Component_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.m1 = Vx - Length / 2;
	GInfo.m2 = Vx + Length / 2;
	GInfo.n1 = Vy - Width / 2;
	GInfo.n2 = Vy + Width / 2;
	AND2* pA = new Comp(GInfo, Component_FANOUT);
	pManager->AddComponent(pA);
}

void CopyPaste::Undo()
{}

void CopyPaste::Redo()
{}
*/