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
		m_OutputPin.setStatus((STATUS)0);

}

void NOT::Draw(Output* pOut)
{
	pOut->DrawNOT(m_GfxInfo, isSelected);

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