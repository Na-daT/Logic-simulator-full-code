#ifndef _change_switch_h
#define _change_switch_h

#include "action.h"
#include "..\Components\AND2.h"

class ChangeSwitchInput : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ChangeSwitchInput(ApplicationManager* pApp, int x, int y);
	ChangeSwitchInput(ApplicationManager* pApp);
	virtual ~ChangeSwitchInput(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif#pragma once
