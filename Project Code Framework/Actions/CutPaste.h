#pragma once
#include "Action.h"
#ifndef _CUTPaset_h_
#define _CUTPaset_h_

class CutPaste : public Action
{
	int x, y;
	int xx, yy;
public:
	CutPaste(ApplicationManager* pApp);
	virtual ~CutPaste(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif
