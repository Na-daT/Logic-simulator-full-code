#include "InputPin.h"

InputPin::InputPin()
{}

void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	return pComp;
}

void InputPin::setConnected(bool s)
{
	Connected = s;
}

bool InputPin::getConnected()
{
	return Connected;
}