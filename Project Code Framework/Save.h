#pragma once
#include <fstream>
#include <iostream>
using namespace std;
#include "Actions/Action.h"

class Save : public Action
{
private:
	ofstream SavedFile;
	string fileName;
public:
	//constructor
	Save(ApplicationManager* pApp);
	//destructor
	virtual ~Save(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


