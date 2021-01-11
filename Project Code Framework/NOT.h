#pragma once
#ifndef NOT_H_
#define NOT_H_

#include "Components/Gate.h"

class NOT :
	public Gate
{
public:
	NOT(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the NOT gate
	virtual void Draw(Output* pOut);	//Draws 1-input gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual OutputPin* getSrcPin();
	virtual InputPin* getDstPin(int n);
	virtual void Save(ofstream& SavedFile);
	virtual void Load(string l);
};

#endif