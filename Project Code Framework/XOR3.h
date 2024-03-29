#pragma once
#ifndef XOR3_H_
#define XOR3_H_

#include "Components/Gate.h"
class XOR3 :
	public Gate
{
public:
	XOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the XOR gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	virtual OutputPin* getSrcPin();
	virtual InputPin* getDstPin(int n);
	virtual void Save(ofstream& SavedFile);
	virtual void Load(ifstream& loadedfile);
};
#endif
