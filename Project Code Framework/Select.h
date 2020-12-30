#pragma once
#include "Actions/Action.h"


class Select : public Action
{
	int x, y;
public:
	Select(ApplicationManager* pApp); 	//constructor

	//Reads parameters required for action to execute
	virtual void ReadActionParameters() = 0;

	//Execute action (code depends on action type)
	virtual void Execute() = 0;

	//To undo this action (code depends on action type)
	virtual void Undo() = 0;

	//To redo this action (code depends on action type)
	virtual void Redo() = 0;

};