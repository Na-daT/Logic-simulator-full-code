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

	string s;
	s = pIn->GetSrting(pOut);

	File.open(s);
	pOut->PrintMsg("File is loaded");
}

void Load::Execute()
{
	ReadActionParameters();
	int f;
	string s;
	while (!File.eof())
	{
		File >> f;
		for (string line; getline(File, line);)
		{
			pManager->LoadAction(f, line);
		}
	}
}

void Load::Undo()
{}

void Load::Redo()
{}
