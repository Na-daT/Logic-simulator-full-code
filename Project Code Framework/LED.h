#pragma once
#include "Components/Gate.h"

class LED : public Gate
{
public:
	LED(const GraphicsInfo& r_GfxInfo);
	virtual void Operate();	//Calculates the output of the LED gate //no operation as no output
	virtual void Draw(Output* pOut);	//Draws LED gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

};