#include "OR2.h"

OR2::OR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	type = ITM_OR2;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void OR2::Operate()
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

void OR2::Draw(Output* pOut)
{
	pOut->DrawOR2(m_GfxInfo, isSelected);

}

int OR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int OR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}

void OR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

OutputPin* OR2::getSrcPin()
{
	return &m_OutputPin;
}

InputPin* OR2::getDstPin(int n)
{
	return &m_InputPins[n];
}