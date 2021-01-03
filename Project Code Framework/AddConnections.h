#pragma once

#include "Actions/Action.h"
#include "Components\Connection.h"


class AddConnections : public Action
{
private:

	GraphicsInfo GfxInfo;	//end and start points of connection made
	OutputPin* src;
	InputPin* dst;
	int IndexDstPin;

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

	virtual bool SetSrcPin(); //sets output pin of selected gate as source pin
	virtual bool SetDstPin(); //sets input pin of selected gate as destination pin

};


