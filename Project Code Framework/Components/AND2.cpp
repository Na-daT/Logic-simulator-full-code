#include "AND2.h"


AND2::AND2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	type = ITM_AND2;
	numberofinputpins = 2;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void AND2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
	/*for(int i = 0; i < m_Inputs ; i++)
	{ 
		Component* connectedto;
		if (m_InputPins[i].getConnected())
		{
			connectedto = m_InputPins[i].getComponent();
			m_InputPins[i].setStatus((STATUS)connectedto->GetOutPinStatus());
		}
	}*/
	
	int* x = new int[m_Inputs];

	for (int i = 0; i < m_Inputs; i++)
	{
		x[i] = GetInputPinStatus(i);
	}

	int sum = 0;
	for (int i = 0; i < m_Inputs; i++)
	{
		sum = sum + x[i];
	}

	if (sum == m_Inputs)
		m_OutputPin.setStatus((STATUS)1);
	else
		m_OutputPin.setStatus((STATUS)0);



}


// Function Draw
// Draws 2-input AND gate
void AND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawAND2(m_GfxInfo, isSelected, GetLabel());
}

//returns status of outputpin
int AND2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND2::GetInputPinStatus(int n)
{
	return m_InputPins[n].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}


OutputPin* AND2::getSrcPin()
{
	return &m_OutputPin;
}

InputPin* AND2::getDstPin(int n)
{
	return &m_InputPins[n];
}


void AND2::Save(ofstream& SavedFile)
{
	SavedFile << getType() << " " << GetID()<< " " << GetLabel()<< " " << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << endl;
}

void AND2::Load(ifstream& File)
{
	//File >> "AND2" >> " " >> m_GfxInfo.x1 >> " " >> m_GfxInfo.y1 >> GetLabel();
}
