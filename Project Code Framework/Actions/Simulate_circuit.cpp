#include "Simulate_circuit.h"

Simulate_Circuit::Simulate_Circuit(ApplicationManager* pApp)
	:Action(pApp)
{
}

void Simulate_Circuit::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Simulating circuit, click on any switch to change value, then click enter when done");
	
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

	do {
		pOut->PrintMsg("please click on a switch to change its status");
		ReadActionParameters();
		switchptr = pManager->IsGateinsideArea(Cx, Cy);

	} while (switchptr->getType() != ITM_SWITCH);

	if (switchptr)
	{
		switchptr->Operate();
	}

	Component** switchArray;
	int s;

	switchArray = pManager->GetArrayofSwitches(s);
	/*
	for (int i = 0; i < s; i++)
	{
		switchArray[i]->
	}
	*/


	///////////////////////////////////

	/*
	int* y = pManager->ListofCompTypes();//copying type of components from CompList in AppManager

	int n_switches = 0;//no of switches found in the list
	int* switches_ids = new int[n_switches];//index of the switches


	for (int i = 0; i < pManager->GetCompCount(); i++)//loop over the array of component types y to get number of switches and leds
	{
		if (y[i] == ITM_SWITCH)
		{
			switches_ids[n_switches] = i;
			n_switches++;
		}
	}

	Component** ListofSwitches= new Component*[n_switches]; //array of pointers to the switches in CompList (dynamically allocated )
	

	for (int i = 0; i < n_switches; i++)
	{
		ListofSwitches[i] = pManager->GetspecificComponentinList(i); //point to each switch
	}

	for (int i = 0; i < n_switches; i++)
	{
		if (ListofSwitches[i]->IsClickInsideArea(Cx, Cy))//check if user clicks on a switch
		{//check if the output pin is high to change to low and vice versa
			if (ListofSwitches[i]->GetOutPinStatus() == HIGH)
				ListofSwitches[i]->setInputPinStatus(1, LOW);//this function in the switch class changes the output pin as there is no input pin
			else
				ListofSwitches[i]->setInputPinStatus(1, HIGH);
		}
	}

	/*had to get the type of each gate in CompList first  then get the index of the specific
	type i wanted then make the array of pointers point to it, if the type of gate didtn matter 
	i couldve used another function to itterate over the compList and check whether the gate was clicked*/


	/*still have to implement Leds being ON in this mode only not in drawing mode brdo*/


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
