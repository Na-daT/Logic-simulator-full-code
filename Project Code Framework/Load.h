#pragma once
#include <fstream>
#include <iostream>
using namespace std;
#include "Actions/Action.h"

class Load : public Action
{
private:
	ifstream loadedfile;

public:
	//constructor
	Load(ApplicationManager* pApp);
	//destructor
	virtual ~Load(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


