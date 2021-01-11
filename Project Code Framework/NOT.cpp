#include "NOT.h"
NOT::NOT(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	numberofinputpins = 1;

	type = ITM_NOT;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void NOT::Operate()
{
	int x = GetInputPinStatus(1);

	if (x == 1)
		m_OutputPin.setStatus((STATUS)0);
	else
		m_OutputPin.setStatus((STATUS)1);

}

void NOT::Draw(Output* pOut)
{
	pOut->DrawNOT(m_GfxInfo, isSelected, GetLabel());

}

int NOT::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int NOT::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}

void NOT::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);

}

OutputPin* NOT::getSrcPin()
{
	return &m_OutputPin;
}

InputPin* NOT::getDstPin(int n)
{
	return &m_InputPins[n];
}

void NOT::Save(ofstream& SavedFile)
{
	
	SavedFile << getType() << " " << GetID() << " " << GetLabel() << " " << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << " " << m_GfxInfo.x2 << " " << m_GfxInfo.y2 << endl;
}

void NOT::Load(ifstream& loadedfile)
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