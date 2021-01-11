#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"
#include <fstream>

//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label = "-";
	
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	int type;
	bool isSelected = false;
	int numberofinputpins;
	int ID;
	bool operated = false;
	bool isGateInputConnected = false;
	bool isGateOutputConnected = false;

	//int ID;
public:
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	
	
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	virtual int getType();

	virtual bool IsClickInsideArea(int x , int y);

	void setSelected(bool IsSel);

	bool GetSelected();

	virtual int GetnumberofInputPins();

	virtual void SetLabel(string s);

	virtual string GetLabel();
 
	bool IsClickOnConnection(int x, int y);

	virtual void Save(ofstream& SavedFile)=0;
	virtual void Load(ifstream& loadedfile)=0;

	void SetID(int id);
	int GetID();

	virtual bool DrawInDrawingArea(int y);
	virtual bool IsOperated();
	virtual void SetOperated(bool op);

	void setType(int i);

	void setGateInputConnected(bool s);
	bool getGateInputConnected();

	void setGateOutputConnected(bool s);
	bool getGateOutputConnected();


	
	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
