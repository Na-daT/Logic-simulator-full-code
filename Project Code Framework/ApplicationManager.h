#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"


//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	int ClipboardCount;
	Component* CopidComp;
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Component* Clipboard[MaxCompCount];
	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface

public:


public:
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();

	//Creates an action and executes it
	void ExecuteAction(ActionType);

	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	//void AddToClipboard();
	//void PasteToCompList();


	void setCopiedComp(Component* pcomp);
	Component* getCopiedComp();


	

	int GetCompCount();

	Component* IsGateinsideArea(int x, int y);


	int getNConnections();
	int getNSwitches();
	void OperateConnections();
	bool OperateALLgates();

	void DeleteSelectedinComplist();

	void CompConnectionArray(Component * c);

	void DeleteConnection(Component* comp);

	void SaveAction(ofstream& SavedFile);
	void LoadAction(ifstream& File);

	int RetrunIndex();
	//destructor
	~ApplicationManager();
};

#endif