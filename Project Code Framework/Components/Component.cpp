#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
}

Component::Component()
{}

void Component::setSelected(bool ifSel)
{
	selected = ifSel;
}

Component::~Component()
{}

