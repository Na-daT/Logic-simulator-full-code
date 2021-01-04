#pragma once
#ifndef _Clipboard_H
#define _Clipboard_H

/*
  Class Clipboard
  -----------
  represent the 2-input AND gate
*/

#include "Gate.h"

class Clipboard : public Gate
{
public:
	
	Clipboard(const GraphicsInfo& r_GfxInfo);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate


	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	/*
	virtual void Save();
	virtual void Load();
	*/

};

#endif
