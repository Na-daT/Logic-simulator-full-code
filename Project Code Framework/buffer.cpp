#include "buffer.h"

buffer::buffer(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	numberofinputpins = 1;

	type = ITM_BUFF;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void buffer::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	//Add you code here

	m_OutputPin.setStatus((STATUS)GetInputPinStatus(1));
}


// Function Draw
// Draws 2-input AND gate
void buffer::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBuffer(m_GfxInfo, isSelected, GetLabel());
}

//returns status of outputpin
int buffer::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int buffer::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void buffer::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

OutputPin* buffer::getSrcPin()
{
	return &m_OutputPin;
}

InputPin* buffer::getDstPin(int n)
{
	return &m_InputPins[n];
}

void buffer::Save(ofstream& SavedFile)
{

	SavedFile << getType() << " " << GetID() << " " << GetLabel() << " " << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << " " << m_GfxInfo.x2 << " " << m_GfxInfo.y2 << endl;
}

void buffer::Load(ifstream& loadedfile)
{
	int id;
	loadedfile >> id;
	SetID(id);

	string label;
	loadedfile >> label;
	SetLabel(label);

	int x1;
	loadedfile >> x1;
	m_GfxInfo.x1 = x1;

	int y1;
	loadedfile >> y1;
	m_GfxInfo.y1 = y1;

	int x2;
	loadedfile >> x2;
	m_GfxInfo.x2 = x2;

	int y2;
	loadedfile >> y2;
	m_GfxInfo.y2 = y2;
}