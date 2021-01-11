#include "XNOR2.h"

XNOR2::XNOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	numberofinputpins = 2;

	type = ITM_XNOR2;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void XNOR2::Operate()
{
	int* x = new int[m_Inputs];

	for (int i = 0; i < m_Inputs; i++)
	{
		x[i] = m_InputPins[i].getStatus();
	}

	int count = 0;
	for (int i = 0; i < m_Inputs; i++)
	{
		if (x[i] == 1)
			count++;
	}

	if (count % 2 == 0)
		m_OutputPin.setStatus((STATUS)1);
	else
		m_OutputPin.setStatus((STATUS)0);


}

void XNOR2::Draw(Output* pOut)
{
	pOut->DrawXNOR2(m_GfxInfo, isSelected, GetLabel());

}

int XNOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int XNOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}

void XNOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);

}

OutputPin* XNOR2::getSrcPin()
{
	return &m_OutputPin;
}

InputPin* XNOR2::getDstPin(int n)
{
	return &m_InputPins[n];
}

void XNOR2::Save(ofstream& SavedFile)
{
	SavedFile << getType() << " " << GetID() << " " << GetLabel() << " " << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << endl;
}

void XNOR2::Load(ifstream& loadedfile)
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