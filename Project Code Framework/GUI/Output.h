#pragma once
#include "..\Defs.h"
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output(); // Performs the Window Initialization
	Input* CreateInput() const; //creates a pointer to the Input object
	void ChangeTitle(string Title) const;

	void CreateDesignToolBar() const;	//Tool bar of the design mode
	void CreateSimulationToolBar() const;//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar

	void ClearDesignToolBar() const;
	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area

	window* CreateWind(int wd, int h, int x, int y) const; //Creates user interface window


	// Draws 2-input AND gate
	void DrawAND2(GraphicsInfo r_GfxInfo, bool selected = false, string label="-") const;

	///TODO: Make similar functions for drawing all other gates, switch, and LED, .. etc
	
	void DrawOR2(GraphicsInfo r_GfxInfo, bool selected = false, string label=" ") const;
	void DrawNAND2(GraphicsInfo r_GfxInfo, bool selected = false, string label = " ") const;
	void DrawNOR2(GraphicsInfo r_GfxInfo, bool selected = false, string label = " ") const;
	void DrawXOR2(GraphicsInfo r_GfxInfo, bool selected = false, string label = " ") const;
	void DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected = false, string label = " ") const;
	void DrawAND3(GraphicsInfo r_GfxInfo, bool selected = false, string label = " ") const;
	void DrawNOR3(GraphicsInfo r_GfxInfo, bool selected = false, string label = " ") const;
	void DrawXOR3(GraphicsInfo r_GfxInfo, bool selected = false, string label = " ") const;
	void DrawXNOR3(GraphicsInfo r_GfxInfo, bool selected = false, string label = " ") const;
	void DrawOR3(GraphicsInfo r_GfxInfo, bool selected = false, string label = " ") const;
	void DrawNAND3(GraphicsInfo r_GfxInfo, bool selected = false, string label = " ") const;
	void DrawSwitch(GraphicsInfo r_GfxInfo, STATUS s=LOW, bool selected = false, string label = " ") const;
	void DrawLED(GraphicsInfo r_GfxInfo, STATUS s=LOW, bool selected = false, string label = " ") const;
	void DrawNOT(GraphicsInfo r_GfxInfo, bool selected = false, string label = " ") const;
	void DrawBuffer(GraphicsInfo r_GfxInfo, bool selected = false, string label = " ") const;

	// Draws Connection
	void DrawConnection(GraphicsInfo r_GfxInfo,STATUS s, bool selected = false , string label = " ") const;

	void PrintMsg(string msg) const;	//Print a message on Status bar

	//Nada
	void PrintInDrawingArea(string msg, int X, int Y) const;  // print message in drawing area
	//bool DrawInDrawingArea(int x, int y);

	~Output();
};
