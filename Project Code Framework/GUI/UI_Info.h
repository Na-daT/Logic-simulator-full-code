#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	MODE AppMode;		//Application Mode (design or simulation)
	
	static const int	width = 1000, height = 650,	//Window width and height
						wx = 50 , wy = 50,			//Window starting coordinates
						StatusBarHeight = 50,	//Status Bar Height
						ToolBarHeight = 30,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
						ToolItemWidth = 30;		//Width of each item in toolbar menu
	static const int DistBetPins = 10; // distance between pins of the gate

	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color


	//This should be calculated accurately because it will be used later to create connections between gates
	//For now, we will assume that rect width = 50 and height = 50
	static const int	AND2_Width = 50,		//AND2 Gate Image default width
						AND2_Height = 50;		//AND2 Gate Image default height
	
	static const int    OR2_Width = 50,
		OR2_Height = 50;

	static const int    NAND2_Width = 50,
		NAND2_Height = 50;

	static const int    NOR2_Width = 50,
		NOR2_Height = 50;

	static const int    XOR2_Width = 50,
		XOR2_Height = 50;

	static const int    XNOR2_Width = 50,
		XNOR2_Height = 50;

	static const int    AND3_Width = 50,
		AND3_Height = 50;

	static const int    NOR3_Width = 50,
		NOR3_Height = 50;

	static const int    XOR3_Width = 50,
		XOR3_Height = 50;

	static const int    XNOR3_Width = 50,
		XNOR3_Height = 50;

	static const int    OR3_Width = 50,
		OR3_Height = 50;

	static const int    NAND3_Width = 50,
		NAND3_Height = 50;

	static const int    NOT_Width = 50,
		NOT_Height = 50;

	static const int    Buffer_Width = 50,
		Buffer_Height = 50;

	static const int    Switch_Width = 50,
		Switch_Height = 50;

	static const int    LED_Width = 50,
		LED_Height = 50;


}UI;	//create a single global object UI

#endif