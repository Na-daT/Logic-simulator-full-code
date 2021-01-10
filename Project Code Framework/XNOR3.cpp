#include "XNOR3.h"


XNOR3::XNOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	numberofinputpins = 3;

	type = ITM_XNOR3;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void XNOR3::Operate()
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

void XNOR3::Draw(Output* pOut)
{
	pOut->DrawXNOR3(m_GfxInfo, isSelected, GetLabel());

}

int XNOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int XNOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}

void XNOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

OutputPin* XNOR3::getSrcPin()
{
	return &m_OutputPin;
}

InputPin* XNOR3::getDstPin(int n)
{
	return &m_InputPins[n];
}

void XNOR3::Save(ofstream& SavedFile)
{
	SavedFile.open("file1.txt", ios::out);
	SavedFile << "XNOR3" << " "<< GetID() << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << endl;
}

void XNOR3::Load(ifstream& File)
{

}