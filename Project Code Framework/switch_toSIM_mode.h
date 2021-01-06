#ifndef SIM_MODE
#define SIM_MODE

#include "../Project Code Framework/Actions/Action.h"

class switch_toSIM_mode : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	switch_toSIM_mode(ApplicationManager* pApp);
	virtual ~switch_toSIM_mode(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif