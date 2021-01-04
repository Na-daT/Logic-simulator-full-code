#include "Simulate_circuit.h"

Simulate_Circuit::Simulate_Circuit(ApplicationManager* pApp)
	:Action(pApp)
{
}

void Simulate_Circuit::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Simulating circuit, click on any switch to change value");
	
	pIn->GetPointClicked(Cx, Cy);//we need a point to see if user click on a switch
}

void Simulate_Circuit::Execute()
{
	

	/*
	vector <Component*> List;

	for (int i = 0; i < pManager->GetCompCount(); i++)
	{
		List = pManager->VectorCompList(); //get component list as a vector
	}

	Component* n = NULL;
	Component** list = pManager->CompListGetter();

	for (int i = 0;i < pManager->GetCompCount(); i++)
	{
		if (List[i] = dynamic_cast <SWITCH*>(n)) //dynamic cast components in complist to check wether they are a switch
		{
			if (list[i]->GetOutPinStatus() == HIGH)
				list[i]->setInputPinStatus(1, LOW); //this function in the switch class changes the output pin as there is no input pin
			else
				list[i]->setInputPinStatus(1, HIGH);
		}
	}

	if (n)
		delete[]n;
	
	list = NULL;
	*/

	///////////////////////////////////
	/*
	Component** ListCopy = pManager->CompListGetter();
	for (int i = 0; i < pManager->GetCompCount(); i++)
	{
		if (ListCopy[i]->getType()==ITM_SWITCH && ListCopy[i]->IsClickInsideArea(Cx,Cy))
		{
			if (ListCopy[i]->GetOutPinStatus() == HIGH)
				ListCopy[i]->setInputPinStatus(1, LOW); //this function in the switch class changes the output pin as there is no input pin
			else
				ListCopy[i]->setInputPinStatus(1, HIGH);
		}
			
	}
	*/

	ReadActionParameters();
	Component* switchptr;
	Output* pOut = pManager->GetOutput();

	switchptr = pManager->IsGateinsideArea(Cx, Cy);

	if (switchptr && switchptr->getType()==ITM_SWITCH)
	{
		if (switchptr->GetOutPinStatus() == 1)
			switchptr->setInputPinStatus(0, (STATUS)0);
		else if (switchptr->GetOutPinStatus() == 0)
			switchptr->setInputPinStatus(0, (STATUS)1);
	}

	pManager->OperateALLgates();
}

void Simulate_Circuit::Undo()
{
}

void Simulate_Circuit::Redo()
{
}

Simulate_Circuit::~Simulate_Circuit()
{
}
