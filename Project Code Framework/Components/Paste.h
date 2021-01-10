#pragma once
#include "../Actions/Action.h"
#include "../Defs.H"

class Paste : public Action
{
	int x, y;
public:
	Paste(ApplicationManager* pApp);
	virtual ~Paste(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();
    
	virtual void Undo();
	virtual void Redo();

	virtual ActionType ReturnActType(int c);
};


