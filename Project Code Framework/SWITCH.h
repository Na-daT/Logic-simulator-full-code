#pragma once
#include "Components/Gate.h"
class SWITCH :
	public Gate
{
public:
	SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the SWITCH gate
	virtual void Draw(Output* pOut);	//Draws SWITCH

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual OutputPin* getSrcPin();
	virtual InputPin* getDstPin(int n);
	virtual void Save(ofstream& SavedFile);
	virtual void Load(ifstream& loadedfile);
};

