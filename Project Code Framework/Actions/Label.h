#pragma once
#include "Action.h"


class Label : public Action
{
	int x, y;
public:
	Label(ApplicationManager* pApp);
	virtual ~Label(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};