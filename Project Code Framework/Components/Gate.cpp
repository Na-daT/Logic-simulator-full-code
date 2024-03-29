#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	
	//Associate all input pins to this gate
	for(int i=0; i<m_Inputs; i++)
		m_InputPins[i].setComponent(this);
	
	m_OutputPin.setStatus(NOT_ASSIGNED);

	for (int i = 0; i < m_Inputs; i++)
		m_InputPins[i].setStatus(NOT_ASSIGNED);

}

void Gate::GetOutputPinCoordinates(int& x, int& y)
{
	x = m_GfxInfo.x2;
	y = m_GfxInfo.y1+(m_GfxInfo.y2 - m_GfxInfo.y1) / 2;
}

void Gate::GetInputPinCoordinates(int& x, int& y, int m_Inputs)
{
	x = m_GfxInfo.x1;
	switch (m_Inputs)
	{
	case 1:
			y = m_GfxInfo.y1 + (m_GfxInfo.y2 - m_GfxInfo.y1) / 2;
			break;
	case 2:
		y = m_GfxInfo.y1 + (m_GfxInfo.y2 - m_GfxInfo.y1) / 2 + (UI.DistBetPins / 2);
		break;
	case 3:
		y = m_GfxInfo.y1 + (m_GfxInfo.y2 - m_GfxInfo.y1) / 2 + UI.DistBetPins;
	}
}

int Gate::getInputIndex()
{
	for (int i = 0; i < m_Inputs; i++)
	{
		bool s;
		s = m_InputPins[i].getConnected();
		if (s == false)
		{
			m_InputPins[i].setConnected(!s);
			return i;
		}
	}
	return -1; //if no input pin available
}

void Gate::DisconnectInputPin(Component* C_Conn)
{
	for (int i = 0; i < m_Inputs; i++)
	{
		if (m_InputPins[i].getComponent() == C_Conn)
			m_InputPins[i].setConnected(false);
	}

}

