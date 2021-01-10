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
#include "Save.h"
#include "Actions/ChangeSwitchInput.h"
#include "Design_mode.h"

ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	ClipboardCount = 0;

	for (int i = 0; i < MaxCompCount; i++)
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


void ApplicationManager::setCopiedComp(Component* pcomp)
{
	CopidComp = pcomp;
}

Component* ApplicationManager::getCopiedComp()
{
	if (CopidComp)
		return CopidComp;
	else
		return NULL;
}

/*Connection** ApplicationManager::GetConnectionToGate(Component* mainComp, int&j)
{
	Connection** n = new Connection*[j];
	Gate* mainGate = (Gate*)mainComp;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->getType() == ITM_CONNECTION)
		{
			Connection* pConn = (Connection *) CompList[i];
			if (pConn->getSourcePin() == mainGate->getSrcPin())
			{
				n[j] = pConn;
				j++;
			}
			else
			{
				for(int x = 0; x< mainGate->GetnumberofInputPins(); x++)
					if (pConn->getDestPin() == mainGate->getDstPin(x))
					{
						n[j] = pConn;
						j++;
					}
			}

		}
	}
	return n;
}*/




int ApplicationManager::GetCompCount()
{
	return CompCount;
}

Component* ApplicationManager::IsGateinsideArea(int x, int y)
{
	Component* n = NULL;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->getType() != ITM_CONNECTION)
		{
			if (CompList[i]->IsClickInsideArea(x, y))
				n = CompList[i];
		}
		else
		{
			if (CompList[i]->IsClickOnConnection(x, y))
				n = CompList[i];
		}
	}
	return n;
}

void ApplicationManager::DeleteSelectedinComplist()
{
	while (CompList[CompCount - 1]->GetSelected() == true)
	{

		if (CompList[CompCount - 1]->getType() == ITM_CONNECTION)
			DeleteConnection(CompList[CompCount - 1]);

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
				if (CompList[i]->getType() == ITM_CONNECTION)
					DeleteConnection(CompList[i]);

				delete CompList[i];
				CompList[i] = NULL;

				CompList[i] = CompList[CompCount - 1];

				CompList[CompCount - 1] = NULL;

				CompCount--;
			}
		}
	}
}

void ApplicationManager::DeleteConnection(Component* comp)
{
	Connection* conn = (Connection*)comp;
	conn->getSourcePin()->Disconnect(conn);

	Gate* pG=(Gate*)conn->getDestPin()->getComponent();
	pG->DisconnectInputPin(conn->getDestPin()->getComponent());
}

void ApplicationManager::OperateConnections()
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->getType() == ITM_CONNECTION)
		{
			CompList[i]->Operate();

		}
	}
}

bool ApplicationManager::OperateALLgates()
{
	int c = getNSwitches() + getNConnections();
	int valid = 0;

	if (getNConnections() == 0 || getNSwitches() == 0)
		return false;

	OperateConnections();

	while (c != CompCount)
	{
		for (int i = 0; i < CompCount; i++)
		{

			if (CompList[i]->getType() != ITM_SWITCH && CompList[i]->getType() != ITM_CONNECTION)
			{
				if (!CompList[i]->IsOperated())
				{
					for (int j = 0; j < CompList[i]->GetnumberofInputPins(); j++)
					{

						if (CompList[i]->GetInputPinStatus(j + 1) == NOT_ASSIGNED)
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
							CompList[i]->SetOperated(true);
						}
						OperateConnections();
					}
				}
			}

		}
	}
	c = 0;
	valid = 0;

	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->IsOperated())
			CompList[i]->SetOperated(false);
	}
	return true;

}


int ApplicationManager::getNConnections()
{
	int c = 0;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->getType() == ITM_CONNECTION)
			c++;
	}
	return c;
}

int ApplicationManager::getNSwitches()
{
	int c = 0;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->getType() == ITM_SWITCH)
			c++;
	}
	return c;
}

/*void ApplicationManager::AddToClipboard()
{
	if (ClipboardCount != 0)
	{
		for (int i = 0; i < ClipboardCount; i++)
		{
			Clipboard[i] = NULL;
		}
		ClipboardCount = 0;
	}

	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->GetSelected() == true && CompList[i]->getType()!=ITM_CONNECTION)
		{
			int s = CompList[i]->getType();


			
			Clipboard[ClipboardCount++] = CompList[i];
		}
	}
}*/

/*void ApplicationManager::PasteToCompList()
{
	int j = 0;
	int k = CompCount;
	CompCount += ClipboardCount;
	for (int i = k; i < CompCount; i++)
	{

		CompList[i] = Clipboard[j];

		j++;
	}

}*/

void ApplicationManager::SaveAction(ofstream& SavedFile)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->getType() != ITM_CONNECTION)
			CompList[i]->Save(SavedFile);
	}

	SavedFile << "CONNECTIONS" << endl;

	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->getType() == ITM_CONNECTION)
			CompList[i]->Save(SavedFile);

	}
}

/*void ApplicationManager::LoadAction(ActionType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
	case ADD_AND_GATE_2:
		pAct = new AddANDgate2(this);
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
	}
	pAct->Load();
	delete pAct;
	pAct = NULL;
}*/

int ApplicationManager::RetrunIndex()
{
	return CompCount;
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
		pAct = new AddANDgate2(this);
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
	case CUT:
		pAct = new Cut(this);
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

	case SAVE:
		pAct = new Save(this);
		break;

	case Change_Switch:
		pAct = new ChangeSwitchInput(this);
		break;

	case DSN_MODE:
		pAct = new Design_mode(this);
		break;

	case EXIT:
		///TODO: create ExitAction here
		break;
	}
	if (pAct)
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
	for (int i = 0; i < CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;

}
