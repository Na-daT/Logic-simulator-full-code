#include "InputPin.h"

InputPin::InputPin()
{
	Connected = false;
	pConn = NULL;
	pComp = NULL;
}

void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	if (pComp)
		return pComp;
	else
		return NULL;
	
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
	if (pConn) {
		return pConn;
	}
	else
		return NULL;
}
