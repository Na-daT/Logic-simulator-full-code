#include "LED.h"

LED::LED(const GraphicsInfo& r_GfxInfo)
	:Gate(1, 0)
{
	type = ITM_LED;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}

void LED::Operate()
{
	//no operation led on/off depends on inputpin status
}

void LED::Draw(Output* pOut)
{
	pOut->DrawLED(m_GfxInfo, (STATUS)GetInputPinStatus(1), isSelected);
}


int LED::GetOutPinStatus()
{
	return -1;
}

int LED::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();
}

void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
