#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	
	m_GfxInfo = r_GfxInfo;	
}

GraphicsInfo Component::returnGfxInfo()
{
	return m_GfxInfo;
}

void Component::setGfxInfo(int x1, int x2, int y1, int y2)
{
	m_GfxInfo.x1 = x1;
	m_GfxInfo.x2 = x2;
	m_GfxInfo.y1 = y1;
	m_GfxInfo.y2 = y2;

}

int Component::getType()
{
	return type;
}

bool Component::IsClickInsideArea(int x, int y)
{
	if (x >= m_GfxInfo.x1 && x <= m_GfxInfo.x2 && y>= m_GfxInfo.y1 && y <= m_GfxInfo.y2)
		return true;
	else
		return false;
}

bool Component::DrawInDrawingArea(int y) 
{
	y = m_GfxInfo.y1;
	if (y <= UI.ToolBarHeight)
	{
		return false;
	}
	else if (y <= UI.height && y >= (UI.height - UI.StatusBarHeight))
		return false;
	else 
		return true;
}

void Component::setSelected(bool IsSel)
{
	isSelected = IsSel;
}

bool Component::GetSelected()
{
	return isSelected;
}

int Component::GetnumberofInputPins()
{
	return numberofinputpins;
}

void Component::SetLabel(string s)
{
	m_Label = s;
}

string Component::GetLabel()
{
	return m_Label;
}

bool Component::IsClickOnConnection(int x, int y)
{
	if (m_GfxInfo.x1 == m_GfxInfo.x2 && x == m_GfxInfo.x1)
		return true;
	else if (m_GfxInfo.y1 == m_GfxInfo.y2 && y == m_GfxInfo.y1)
		return true;
	else 
	{
		if (m_GfxInfo.x1 > m_GfxInfo.x2)
		{
			if (m_GfxInfo.y1 > m_GfxInfo.y2 && x >= m_GfxInfo.x2 && x<= m_GfxInfo.x1 && y>=m_GfxInfo.y2 && y <= m_GfxInfo.y1)
				return true;
			else if (m_GfxInfo.y1 < m_GfxInfo.y2 && x >= m_GfxInfo.x2 && x <= m_GfxInfo.x1 && y<=m_GfxInfo.y2 && y >= m_GfxInfo.y1)
				return true;
		}
		else if (m_GfxInfo.x1 < m_GfxInfo.x2)
		{
			if (m_GfxInfo.y1 > m_GfxInfo.y2 && x <= m_GfxInfo.x2 && x>= m_GfxInfo.x1 && y>=m_GfxInfo.y2 && y <= m_GfxInfo.y1)
				return true;
			else if (m_GfxInfo.y1 < m_GfxInfo.y2 && x <= m_GfxInfo.x2 && x >= m_GfxInfo.x1 && y<=m_GfxInfo.y2 && y >= m_GfxInfo.y1)
				return true;
		}
	}
	return false;

}


void Component::Load(ifstream& loadedfile)
{
}

void Component::SetID(int id)
{
	ID = id;
}

int Component::GetID()
{
	return ID;
}

bool Component::IsOperated()
{
	return operated;
}

void Component::SetOperated(bool op)
{
	operated = op;
}

void Component::setType(int i)
{
	type = i;
}

void Component::setGateInputConnected(bool s)
{
	isGateInputConnected = s;
}

bool Component::getGateInputConnected()
{
	return isGateInputConnected;
}

void Component::setGateOutputConnected(bool s)
{
	isGateOutputConnected = s;
}

bool Component::getGateOutputConnected()
{
	return isGateOutputConnected;
}
Component::Component()
{}

Component::~Component()
{}

