#include "InputPin.h"

InputPin::InputPin()
{
	Connected = false;
}

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

void InputPin::SetConnection(Connection* conn)
{
	pConn = conn;
}

Connection* InputPin::GetConnection()
{
	return pConn;
}
