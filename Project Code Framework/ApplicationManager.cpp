#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "AddANDgate3.h"
#include "AddXORgate3.h"
#include "AddSwitch.h"
#include "AddORgate3.h"
#include "AddORgate2.h"
#include "AddNORgate3.h"
#include "AddNORgate2.h"
#include "AddNANDgate3.h"
#include "AddNANDgate2.h"
#include "AddLED.h"
#include "AddConnections.h"
#include "AddNOTgate.h"
#include "AddBuffer.h"
#include "AddXNORgate2.h"
#include "AddXNORgate3.h"
#include "AddXORgate2.h"
#include "Actions/Select.h"
#include "Actions/Label.h"
#include  "Actions/Copy.h"
#include "Actions/Cut.h"
#include "Components/Paste.h"
#include "Actions/Delete.h"
#include "switch_toSIM_mode.h"
#include "Edit.h"
#include "Actions/Simulate_circuit.h"

ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
/// //////////////////////////////////////////////////////////////


int ApplicationManager::GetCompCount()
{
	return CompCount;
}

Component* ApplicationManager::IsGateinsideArea(int x, int y)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->IsClickInsideArea(x, y))
			return CompList[i];
	}
}

void ApplicationManager::DeleteSelectedinComplist()
{
		while (CompList[CompCount - 1]->GetSelected() == true)
		{
			delete CompList[CompCount - 1];
			CompList[CompCount - 1] = NULL;
			CompCount--;

			if (CompCount == 0)
				break;
		}
	

	if (CompCount != 0)
	{
		for (int i = 0; i < CompCount; i++)
		{
			if (CompList[i]->GetSelected())
			{
				delete CompList[i];
				CompList[i] = NULL;

				CompList[i] = CompList[CompCount - 1];

				CompList[CompCount - 1] = NULL;

				CompCount--;
			}
		}
	}
}

void ApplicationManager::OperateALLgates()
{
	int c = 0;
	int valid =0;
	while (c != CompCount)
	{
		for (int i = 0; i < CompCount; i++)
		{
			if (CompList[i]->getType() == ITM_SWITCH)
			{
				c++;
			}

			if (CompList[i]->getType() == ITM_CONNECTION)
			{
				CompList[i]->Operate();
				c++;
			}
			for (int j = 0; j < CompList[i]->GetnumberofInputPins(); j++)
			{
				if (CompList[i]->getType() != ITM_CONNECTION && CompList[i]->getType()!=ITM_SWITCH)
				{
					if (CompList[i]->GetInputPinStatus(j) == NOT_ASSIGNED)
						break;
					else
					{
						valid++;
					}
					if (valid == CompList[i]->GetnumberofInputPins())
					{
						CompList[i]->Operate();
						valid = 0;
						c++;
					}
				}
			}

		}
	}
}

Component** ApplicationManager::GetArrayofSwitches(int& s)
{
	int c = 0;
	Component** x = new Component* [c];
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->getType() == ITM_SWITCH)
		{
			x[c] = CompList[i];
			c++;
		}
	}
	s = c;
	return x;
}

void ApplicationManager::AddToClipboard()
{
	if (ClipboardCount != 0)
	{
		for (int i = 0; i < ClipboardCount; i++)
		{
			delete Clipboard[i];
			Clipboard[i] = NULL;
		}
		ClipboardCount = 0;
	}
	int c = 0;

	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->GetSelected() == true)
		{
			Clipboard[c] = CompList[i];
			c++;
		}
	}
	ClipboardCount = c;

}
void ApplicationManager::PasteToCompList()
{
	int j = 0;
	for (int i = CompCount; i < (CompCount + ClipboardCount); i++)
	{
	
		CompList[i] = Clipboard[j];
		CompCount++;
		j++;
	}
}
 
void ApplicationManager::Save(ofstream& SavedFile) {
	for (int i = 0; i < CompCount; i++) 
	{
			CompList[i]->Save(SavedFile);
	}
}

////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;

		case ADD_AND_GATE_3:
			pAct = new AddANDgate3(this);
			break;

		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
			break;

		case ADD_OR_GATE_3:
			pAct = new AddORgate3(this);
			break;

		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			break;

		case ADD_NAND_GATE_3:
			pAct = new AddNANDgate3(this);
			break;

		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this);
			break;

		case ADD_NOR_GATE_3:
			pAct = new AddNORgate3(this);
			break;

		case ADD_XOR_GATE_2:
			pAct = new AddXORgate2(this);
			break;

		case ADD_XOR_GATE_3:
			pAct = new AddXORgate3(this);
			break;

		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(this);
			break;

		case ADD_XNOR_GATE_3:
			pAct = new AddXNORgate3(this);
			break;

		case ADD_LED:
			pAct = new AddLED(this);
			break;

		case ADD_Buff:
			pAct = new AddBuffer(this);
			break;

		case ADD_Switch:
			pAct = new AddSwitch(this);
			break;

		case ADD_INV:
			pAct = new AddNOTgate(this);
			break;

		case ADD_CONNECTION:
			//TODO: Create AddConection Action here
			pAct = new AddConnections(this);
			break;

		case SELECT:
			pAct = new Select(this);
			break;

		case ADD_Label:
			pAct = new Label(this);
			break;

		case DEL:
			pAct = new Delete(this);
			break;

		case COPY:
			pAct = new Copy(this);
			break;

		case PASTE:
			pAct = new Paste(this);
			break;

		case (ActionType)38:
			pAct = new switch_toSIM_mode(this);
			break;

		case EDIT_Label:
			pAct = new Edit(this);
			break;

		case SIMULATE_CIRCUIT:
			pAct = new Simulate_Circuit(this);
			break;

		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{

	
		OutputInterface->ClearDrawingArea();

		for (int i = 0; i < CompCount; i++)
			CompList[i]->Draw(OutputInterface);
	



}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}
