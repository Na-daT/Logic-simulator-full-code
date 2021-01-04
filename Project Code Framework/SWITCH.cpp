#include "SWITCH.h"

SWITCH::SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(0, r_FanOut)
{
	type = ITM_SWITCH;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void SWITCH::Operate()
{
	if (GetOutPinStatus() == 1)
		m_OutputPin.setStatus((STATUS)0);
	else if (GetOutPinStatus() == 0)
		m_OutputPin.setStatus((STATUS)1);

	// no operation as switch value depends on user action
}


// Function Draw
// Draws SWITCH gate
void SWITCH::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawSwitch(m_GfxInfo,(STATUS)GetOutPinStatus(), isSelected);
}

//returns status of outputpin
int SWITCH::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
//SWITCH SO NO INPUT PIN
int SWITCH::GetInputPinStatus(int n)
{
	return -1;
}

//Set status of an input pin ot HIGH or LOW
//NO INPUT PIN, will be changing stauts of output pin instead
void SWITCH::setInputPinStatus(int n, STATUS s)
{
	return;
}

OutputPin* SWITCH::getSrcPin()
{
	return &m_OutputPin;
}

InputPin* SWITCH::getDstPin(int n)
{
	return NULL;
}