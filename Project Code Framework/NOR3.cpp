#include "NOR3.h"

NOR3::NOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	type = ITM_NOR3;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void NOR3::Operate()
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

void NOR3::Draw(Output* pOut)
{
	pOut->DrawNOR3(m_GfxInfo);

}

int NOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int NOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}

void NOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);

}
