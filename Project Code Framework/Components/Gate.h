#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"

class Gate:public Component
{
protected:
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	int m_Inputs;		//No. of input pins of that Gate.

public:
	Gate(int r_Inputs, int r_FanOut);
	virtual void GetOutputPinCoordinates(int &x, int &y);
	virtual void GetInputPinCoordinates(int &x, int& y, int n);
	virtual OutputPin* getSrcPin() = 0;
	virtual InputPin* getDstPin(int n) = 0;
	virtual int getInputIndex(); //returns available input pins to connect to
	virtual void DisconnectInputPin(Component* C_Conn);

};

#endif
