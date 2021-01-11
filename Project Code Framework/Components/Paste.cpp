#include "Paste.h"

#include "../ApplicationManager.h"

Paste::Paste(ApplicationManager* pApp) :Action(pApp)
{
}

Paste::~Paste(void)
{
}

void Paste::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Wait for User Input
	



	//Clear Status Bar

}

void Paste::Execute()
{
	ReadActionParameters();

	
	int c = pManager->getCopiedComptype();

	ActionType t = ReturnActType(c);

	pManager->ExecuteAction(t);


	//pManager->PasteToCompList();





}


ActionType Paste::ReturnActType(int c)
{
	switch (c)
	{
	case ITM_AND2: return ADD_AND_GATE_2;
	case ITM_OR2: return ADD_OR_GATE_2;
	case ITM_OR3: return ADD_OR_GATE_3;
	case ITM_NAND2: return ADD_NAND_GATE_2;
	case ITM_NAND3: return ADD_NAND_GATE_3;
	case ITM_NOR2: return ADD_NOR_GATE_2;
	case ITM_XOR2: return ADD_XOR_GATE_2;
	case ITM_XNOR2: return ADD_XNOR_GATE_2;
	case ITM_NOT: return ADD_INV;
	case ITM_AND3:return ADD_AND_GATE_3;
	case ITM_NOR3:return ADD_NOR_GATE_3;
	case ITM_XOR3: return ADD_XOR_GATE_3;
	case ITM_SWITCH: return ADD_Switch;
	case ITM_LED: return ADD_LED;
	case ITM_BUFF:return ADD_Buff;
	case ITM_XNOR3: return ADD_XNOR_GATE_3;
	}
}

void Paste::Undo()
{}

void Paste::Redo()
{}