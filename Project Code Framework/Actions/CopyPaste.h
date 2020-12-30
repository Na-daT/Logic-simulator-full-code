#pragma once
#include "Action.h"


class CopyPaste : public Action
{
	int x, y; 
public:
	CopyPaste(ApplicationManager* pApp);
	virtual ~CopyPaste(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
