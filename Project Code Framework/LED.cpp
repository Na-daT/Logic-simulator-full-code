#include "LED.h"

LED::LED(const GraphicsInfo& r_GfxInfo)
	:Gate(1, 0)
{
	numberofinputpins = 1;
	type = ITM_LED;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void LED::Operate()
{
	return;
	//no operation led on/off depends on inputpin status
}

void LED::Draw(Output* pOut)
{
	pOut->DrawLED(m_GfxInfo, (STATUS)GetInputPinStatus(1), isSelected, GetLabel());
}


int LED::GetOutPinStatus()
{
	return -1;
}

int LED::GetInputPinStatus(int n)
{
	return (int)m_InputPins[n - 1].getStatus();
}

void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}


InputPin* LED::getDstPin(int n)
{
	return &m_InputPins[n];
}

OutputPin* LED::getSrcPin()
{
	return NULL;
}

void LED::Save(ofstream& SavedFile)
{

	SavedFile << getType() << " " << GetID() << " " << GetLabel() << " " << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << endl;
}

void LED::Load(ifstream& loadedfile)
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
}