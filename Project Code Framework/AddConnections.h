#pragma once

#include "Actions/Action.h"
#include "Components\Connection.h"


class AddConnections : public Action
{
private:

	GraphicsInfo GfxInfo;	//end and start points of connection made
	OutputPin* src;
	InputPin* dst;

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


