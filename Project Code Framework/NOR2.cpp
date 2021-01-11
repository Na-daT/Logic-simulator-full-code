#include "NOR2.h"


NOR2::NOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	numberofinputpins = 2;

	type = ITM_NOR2;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void NOR2::Operate()
{
	int* x = new int[m_Inputs];

	for (int i = 0; i < m_Inputs; i++)
	{
		x[i] = m_InputPins[i].getStatus();
	}

	int sum = 0;
	for (int i = 0; i < m_Inputs; i++)
	{
		sum = sum + x[i];
	}

	if (sum > 0)
		m_OutputPin.setStatus((STATUS)0);
	else
		m_OutputPin.setStatus((STATUS)1);
}

void NOR2::Draw(Output* pOut)
{
	pOut->DrawNOR2(m_GfxInfo, isSelected, GetLabel());

}

int NOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int NOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}

void NOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

OutputPin* NOR2::getSrcPin()
{
	return &m_OutputPin;
}

InputPin* NOR2::getDstPin(int n)
{
	return &m_InputPins[n];
}

void NOR2::Save(ofstream& SavedFile)
{

	SavedFile << getType() << " " << GetID() << " " << GetLabel() << " " << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << " " << m_GfxInfo.x2 << " " << m_GfxInfo.y2 << endl;
}

void NOR2::Load(ifstream& loadedfile)
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