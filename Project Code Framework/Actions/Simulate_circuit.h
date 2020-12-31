#pragma once
#include "../ApplicationManager.h"
#include "../LED.h"
#include "../SWITCH.h"
#include <vector>

class Simulate_Circuit
	:public Action
{
private:
	int Cx, Cy; //check if point clicked is a switch

public:

	Simulate_Circuit(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();

	~Simulate_Circuit();
};