#include "XOR2.h"

XOR2::XOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void XOR2::Operate()
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

void XOR2::Draw(Output* pOut)
{
	pOut->DrawXOR2(m_GfxInfo);

}

int XOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int XOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}

void XOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}