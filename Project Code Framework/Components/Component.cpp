#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
}

int Component::getType()
{
	return type;
}

bool Component::IsClickInsideArea(int x, int y)
{
	if (x > m_GfxInfo.x1 && x < m_GfxInfo.x2 && y> m_GfxInfo.y1 && y < m_GfxInfo.y2)
		return true;
	else
		return false;
}


void Component::setSelected(bool IsSel)
{
	isSelected = IsSel;
}

Component::Component()
{}

Component::~Component()
{}

