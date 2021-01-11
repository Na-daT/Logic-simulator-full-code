#include "Load.h"
#include <fstream>
#include <string> 
#include<iostream>
using namespace std;
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

	pOut->PrintMsg("Type file name");
	string s;
	s = pIn->GetSrting(pOut);

	loadedfile.open(s, ios::in);
	pOut->PrintMsg("File is loaded");
}

void Load::Execute()
{
	ReadActionParameters();
	int f;
	string s;
	while (loadedfile >> f)
	{
		pManager->LoadAction(f, loadedfile);
	}
}

void Load::Undo()
{}

void Load::Redo()
{}
