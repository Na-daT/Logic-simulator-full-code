#include "OR3.h"

OR3::OR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	type = ITM_OR3;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void OR3::Operate()
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
		m_OutputPin.setStatus((STATUS)1);
	else
		m_OutputPin.setStatus((STATUS)0);
}

void OR3::Draw(Output* pOut)
{
	pOut->DrawOR3(m_GfxInfo, isSelected);

}

int OR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int OR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}

void OR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);

}

OutputPin* OR3::getSrcPin()
{
	return &m_OutputPin;
}

InputPin* OR3::getDstPin(int n)
{
	return &m_InputPins[n];
}