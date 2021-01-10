#pragma once

#include "Actions/Action.h"
#include <fstream>

class Exit : public Action
{
private:
	


public:
	//constructor
	Exit(ApplicationManager* pApp);
	//destructor
	virtual ~Exit(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};



