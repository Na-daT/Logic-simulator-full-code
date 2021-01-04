#include "XOR3.h"


XOR3::XOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	type = ITM_XOR3;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void XOR3::Operate()
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

	if (count % 2 != 0)
		m_OutputPin.setStatus((STATUS)1);
	else
		m_OutputPin.setStatus((STATUS)0);



}

void XOR3::Draw(Output* pOut)
{
	pOut->DrawXOR3(m_GfxInfo, isSelected);

}

int XOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int XOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}

void XOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);

}

OutputPin* XOR3::getSrcPin()
{
	return &m_OutputPin;
}

InputPin* XOR3::getDstPin(int n)
{
	return &m_InputPins[n];
}