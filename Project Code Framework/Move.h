#pragma once
#include ".//Actions/Action.h"



class Move : public Action
{
	int x, y;
public:
	Move(ApplicationManager* pApp);
	virtual ~Move(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};
