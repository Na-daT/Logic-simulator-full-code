#pragma once

#include "Actions/Action.h"
#include "Components\Connection.h"

class AddConnections : public Action
{
private:

	int x1, y1, x2, y2;	//end and start points of connection made
public:
	//constructor
	AddConnections(ApplicationManager* pApp);
	//destructor
	virtual ~AddConnections(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


