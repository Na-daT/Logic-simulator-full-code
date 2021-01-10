#include "NAND3.h"

NAND3::NAND3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	numberofinputpins = 3;

	type = ITM_NAND3;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void NAND3::Operate()
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

	if (sum > m_Inputs - 1)
		m_OutputPin.setStatus((STATUS)0);
	else
		m_OutputPin.setStatus((STATUS)1);

}

void NAND3::Draw(Output* pOut)
{
	pOut->DrawNAND3(m_GfxInfo, isSelected);
}

int NAND3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int NAND3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}

void NAND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

OutputPin* NAND3::getSrcPin()
{
	return &m_OutputPin;
}

InputPin* NAND3::getDstPin(int n)
{
	return &m_InputPins[n];
}

void NAND3::Save(ofstream& SavedFile)
{

	SavedFile << "NAND3" << " " << GetID() << " " << GetLabel() << " " << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << endl;
}

void NAND3::Load(ifstream& File)
{

}