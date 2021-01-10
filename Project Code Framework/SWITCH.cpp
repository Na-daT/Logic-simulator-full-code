#include "SWITCH.h"

SWITCH::SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(0, r_FanOut)
{
	numberofinputpins = 0;

	type = ITM_SWITCH;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	m_OutputPin.setStatus((STATUS)0);
}


void SWITCH::Operate()
{
	return;
	// no operation as switch value depends on user action
}


// Function Draw
// Draws SWITCH gate
void SWITCH::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawSwitch(m_GfxInfo,(STATUS)GetOutPinStatus(), isSelected, GetLabel());
}

//returns status of outputpin
int SWITCH::GetOutPinStatus()
{
	return (int)m_OutputPin.getStatus();
}


//returns status of Inputpin #n
//SWITCH SO NO INPUT PIN
int SWITCH::GetInputPinStatus(int n)
{
	return -1;
}

//Set status of an input pin ot HIGH or LOW
//NO INPUT PINs, will be modifying output pin instead
void SWITCH::setInputPinStatus(int n, STATUS s)
{
	m_OutputPin.setStatus(s);
}


OutputPin* SWITCH::getSrcPin()
{
	return &m_OutputPin;
}

InputPin* SWITCH::getDstPin(int n)
{
	return NULL;
}

void SWITCH::Save(ofstream& SavedFile)
{
	SavedFile.open("file1.txt", ios::out);
	SavedFile << getType() << " " << GetID() << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << endl;
}

void SWITCH::Load(ifstream& File)
{

}