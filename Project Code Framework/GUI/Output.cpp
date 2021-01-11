#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;

	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}

//Nada
// print message in drawing area
void Output::PrintInDrawingArea(string msg, int X, int Y) const
{
	if (msg.empty())
		return;

	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(X, Y, msg);
}
void Output::ClearDesignToolBar() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	
	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2] = "Images\\Gates\\AND_2.jpg";
	MenuItemImages[ITM_OR2] = "Images\\Gates\\OR_2.jpg";

	MenuItemImages[ITM_AND3] = "Images\\Gates\\AND_3.jpg";
	MenuItemImages[ITM_OR3] = "Images\\Gates\\OR_3.jpg";

	MenuItemImages[ITM_NAND2] = "Images\\Gates\\NAND_2.jpg";
	MenuItemImages[ITM_NAND3] = "Images\\Gates\\NAND_3.jpg";

	MenuItemImages[ITM_NOR2] = "Images\\Gates\\NOR_2.jpg";
	MenuItemImages[ITM_NOR3] = "Images\\Gates\\NOR_3.jpg";

	MenuItemImages[ITM_XOR2] = "Images\\Gates\\XOR_2.jpg";
	MenuItemImages[ITM_XOR3] = "Images\\Gates\\XOR_3.jpg";

	MenuItemImages[ITM_XNOR2] = "Images\\Gates\\XNOR_2.jpg";
	MenuItemImages[ITM_XNOR3] = "Images\\Gates\\XNOR_3.jpg";

	MenuItemImages[ITM_NOT] = "Images\\Gates\\NOT.jpg";

	MenuItemImages[ITM_BUFF] = "Images\\Gates\\buffer.jpg";

	MenuItemImages[ITM_SWITCH] = "Images\\Gates\\switch.jpg";
	MenuItemImages[ITM_LED] = "Images\\Gates\\LED.jpg";

	MenuItemImages[ITM_CONNECTION] = "Images\\Gates\\connection.jpg";


	MenuItemImages[ITM_LABEL] = "Images\\Menu\\tag.jpg";
	MenuItemImages[ITM_SELECT] = "Images\\Menu\\Select.jpg";
	MenuItemImages[ITM_UNSELECT] = "Images\\Gates\\AND_2.jpg";
	MenuItemImages[ITM_DELETE] = "Images\\Menu\\Delete.jpg";
	MenuItemImages[ITM_MOVE] = "Images\\Gates\\AND_2.jpg";
	MenuItemImages[ITM_SAVE] = "Images\\Menu\\Save.jpg";
	MenuItemImages[ITM_LOAD] = "Images\\Menu\\Load.jpg";
	MenuItemImages[ITM_COPY] = "Images\\Gates\\AND_2.jpg";
	MenuItemImages[ITM_CUT] = "Images\\Gates\\AND_2.jpg";
	MenuItemImages[ITM_PASTE] = "Images\\Gates\\AND_2.jpg";
	MenuItemImages[ITM_SWITCH_TO_SIMULATION] = "Images\\Gates\\AND_2.jpg";
	MenuItemImages[ITM_EDIT] = "Images\\Menu\\Edit.jpg";
	MenuItemImages[ITM_EXIT] = "Images\\Menu\\exit.jpg";
	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode


	
	string MenuItemImages[ITM_SIM_CNT];
	MenuItemImages[ITM_SIM] = "images\\Menu\\SIMULATE.jpg";
	MenuItemImages[ITM_TRUTH] = "images\\Menu\\TruthTable.jpg";
	MenuItemImages[ITM_VALIDATE] = "images\\Gates\\AND_2.jpg";
	MenuItemImages[ITM_SWITCH_TO_DESIGN_MODE] = "images\\Menu\\draw.jpg";	
	
	//DONE: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
	


	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)

}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected, string label) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
	{
		GateImage = "Images\\Gates\\AND_2_HI.jpg";
	}
	else
		GateImage = "images\\Gates\\AND_2.jpg";
	
	int y12 = r_GfxInfo.y1 - 50;
	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	if (label != "-")
	{
		PrintInDrawingArea(label, r_GfxInfo.x1, y12);
	}
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);

}

//TODO: Add similar functions to draw all components


void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected, string label) const
{
	string GateImage;
	if (selected)
		GateImage = "images\\Gates\\OR_2_HI.jpg"; //IMAGE TO BE ADDED
	else
		GateImage = "images\\Gates\\OR_2.jpg"; //IMAGE TO BE ADDED

	int y12 = r_GfxInfo.y1 - 50;
	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	if (label != "-")
	{
		PrintInDrawingArea(label, r_GfxInfo.x1, y12);
	}
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR2_Width, UI.OR2_Height);
}


void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected, string label) const
{
	string GateImage;
	if (selected)
		GateImage = "images\\Gates\\NAND_2_HI.jpg"; //IMAGE TO BE ADDED
	else
		GateImage = "images\\Gates\\NAND_2.jpg"; //IMAGE TO BE ADDED0
	int y12 = r_GfxInfo.y1 - 50;
	if (label != "-")
	{
		PrintInDrawingArea(label, r_GfxInfo.x1, y12);
	}
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND2_Width, UI.NAND2_Height);
}



void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected, string label) const
{
	string GateImage;
	if (selected)
		GateImage = "images\\Gates\\NOR_2_HI.jpg"; //IMAGE TO BE ADDED
	else
		GateImage = "images\\Gates\\NOR_2.jpg"; //IMAGE TO BE ADDED
	int y12 = r_GfxInfo.y1 - 50;
	if (label != "-")
	{
		PrintInDrawingArea(label, r_GfxInfo.x1, y12);
	}
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR2_Width, UI.NOR2_Height);
}


void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected, string label) const
{
	string GateImage;
	if (selected)
		GateImage = "images\\Gates\\XOR_2_HI.jpg"; //IMAGE TO BE ADDED
	else
		GateImage = "images\\Gates\\XOR_2.jpg"; //IMAGE TO BE ADDED
	int y12 = r_GfxInfo.y1 - 50;
	if (label != "-")
	{
		PrintInDrawingArea(label, r_GfxInfo.x1, y12);
	}
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR2_Width, UI.XOR2_Height);
}

void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected, string label) const
{
	string GateImage;
	if (selected)
		GateImage = "images\\Gates\\XNOR_2_HI.jpg"; //IMAGE TO BE ADDED
	else
		GateImage = "images\\Gates\\XNOR_2.jpg"; //IMAGE TO BE ADDED
	int y12 = r_GfxInfo.y1 - 50;
	if (label != "-")
	{
		PrintInDrawingArea(label, r_GfxInfo.x1, y12);
	}
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XNOR2_Width, UI.XNOR2_Height);
}


void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected, string label) const
{
	string GateImage;
	if (selected)
		GateImage = "images\\Gates\\AND_3_HI.jpg";//IMAGE TO BE ADDED
	else
		GateImage = "images\\Gates\\AND_3.jpg"; //IMAGE TO BE ADDED
	int y12 = r_GfxInfo.y1 - 50;
	if (label != "-")
	{
		PrintInDrawingArea(label, r_GfxInfo.x1, y12);
	}
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND3_Width, UI.AND3_Height);
}


void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected, string label) const
{
	string GateImage;
	if (selected)
		GateImage = "images\\Gates\\NOR_3_HI.jpg"; //IMAGE TO BE ADDED
	else
		GateImage = "images\\Gates\\NOR_3.jpg"; //IMAGE TO BE ADDED
	int y12 = r_GfxInfo.y1 - 50;
	if (label != "-")
	{
		PrintInDrawingArea(label, r_GfxInfo.x1, y12);
	}
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOR3_Width, UI.NOR3_Height);
}


void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected, string label) const
{
	string GateImage;
	if (selected)
		GateImage = "images\\Gates\\XOR_3_HI.jpg"; //IMAGE TO BE ADDED
	else
		GateImage = "images\\Gates\\XOR_3.jpg"; //IMAGE TO BE ADDED
	int y12 = r_GfxInfo.y1 - 50;
	if (label != "-")
	{
		PrintInDrawingArea(label, r_GfxInfo.x1, y12);
	}
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XOR3_Width, UI.XOR3_Height);
}

void Output::DrawXNOR3(GraphicsInfo r_GfxInfo, bool selected, string label) const
{
	string GateImage;
	if (selected)
		GateImage = "images\\Gates\\XNOR_3_HI.jpg"; //IMAGE TO BE ADDED
	else
		GateImage = "images\\Gates\\XNOR_3.jpg"; //IMAGE TO BE ADDED
	int y12 = r_GfxInfo.y1 - 50;
	if (label != "-")
	{
		PrintInDrawingArea(label, r_GfxInfo.x1, y12);
	}
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.XNOR3_Width, UI.XNOR3_Height);
}

void Output::DrawOR3(GraphicsInfo r_GfxInfo, bool selected, string label) const
{
	string GateImage;
	if (selected)
		GateImage = "images\\Gates\\OR_3_HI.jpg"; //IMAGE TO BE ADDED
	else
		GateImage = "images\\Gates\\OR_3.jpg"; //IMAGE TO BE ADDED
	int y12 = r_GfxInfo.y1 - 50;
	if (label != "-")
	{
		PrintInDrawingArea(label, r_GfxInfo.x1, y12);
	}
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.OR3_Width, UI.OR3_Height);
}


void Output::DrawNAND3(GraphicsInfo r_GfxInfo, bool selected, string label) const
{
	string GateImage;
	if (selected)
		GateImage = "images\\Gates\\NAND_3_HI.jpg"; //IMAGE TO BE ADDED
	else
		GateImage = "images\\Gates\\NAND_3.jpg"; //IMAGE TO BE ADDED
	int y12 = r_GfxInfo.y1 - 50;
	if (label != "-")
	{
		PrintInDrawingArea(label, r_GfxInfo.x1, y12);
	}
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NAND3_Width, UI.NAND3_Height);
}



void Output::DrawSwitch(GraphicsInfo r_GfxInfo, STATUS s, bool selected, string label) const
{
	string GateImage;
	if (UI.AppMode == SIMULATION)
	{
		if (s == HIGH)
		{
			if (selected)
				GateImage = "images\\Gates\\switch_HI.jpg";
			else
				GateImage = "images\\Gates\\switch_ON.jpg";
		}
		else
		{
			if (selected)
				GateImage = "images\\Gates\\switch_HI.jpg"; //IMAGE TO BE ADDED
			else
				GateImage = "images\\Gates\\switch.jpg";//IMAGE TO BE ADDED
		}
		int y12 = r_GfxInfo.y1 - 50;
		if (label != "-")
		{
			PrintInDrawingArea(label, r_GfxInfo.x1, y12);
		}
		pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.Switch_Width, UI.Switch_Height);
	}
	else
	{
		if (selected)
			GateImage = "images\\Gates\\switch_HI.jpg"; //IMAGE TO BE ADDED
		else
			GateImage = "images\\Gates\\switch.jpg";//IMAGE TO BE ADDED
		int y12 = r_GfxInfo.y1 - 50;
		if (label != "-")
		{
			PrintInDrawingArea(label, r_GfxInfo.x1, y12);
		}
		pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.Switch_Width, UI.Switch_Height);
	}
}
//
void Output::DrawLED(GraphicsInfo r_GfxInfo, STATUS s, bool selected, string label) const
{
	string GateImage;
	if (UI.AppMode == SIMULATION)
	{
		if (s == HIGH)
		{
			if (selected)
				GateImage = "images\\Gates\\LED_HI.jpg";
			else
				GateImage = "images\\Gates\\LED_ON.jpg";

		}
		else
		{
			if (selected)
				GateImage = "images\\Gates\\LED_HI.jpg"; //IMAGE TO BE ADDED
			else
				GateImage = "images\\Gates\\LED.jpg";//IMAGE TO BE ADDED
		}
		int y12 = r_GfxInfo.y1 - 50;
		if (label != "-")
		{
			PrintInDrawingArea(label, r_GfxInfo.x1, y12);
		}
		pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.LED_Width, UI.LED_Height);
	}
	else
	{
		if (selected)
			GateImage = "images\\Gates\\LED_HI.jpg"; //IMAGE TO BE ADDED
		else
			GateImage = "images\\Gates\\LED.jpg";//IMAGE TO BE ADDED
		int y12 = r_GfxInfo.y1 - 50;
		if (label != "-")
		{
			PrintInDrawingArea(label, r_GfxInfo.x1, y12);
		}
		pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.Switch_Width, UI.Switch_Height);
	}
}

void Output::DrawNOT(GraphicsInfo r_GfxInfo, bool selected, string label) const
{
	string GateImage;
	if (selected)
		GateImage = "images\\Gates\\NOT_HI.jpg"; //IMAGE TO BE ADDED
	else
		GateImage = "images\\Gates\\NOT.jpg"; //IMAGE TO BE ADDED
	int y12 = r_GfxInfo.y1 - 50;
	if (label != "-")
	{
		PrintInDrawingArea(label, r_GfxInfo.x1, y12);
	}
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.NOT_Width, UI.NOT_Height);
}


void Output::DrawBuffer(GraphicsInfo r_GfxInfo, bool selected, string label) const
{
	string GateImage;
	if (selected)
		GateImage = "images\\Gates\\buffer_HI.jpg"; //IMAGE TO BE ADDED
	else
		GateImage = "images\\Gates\\buffer.jpg"; //IMAGE TO BE ADDED
	int y12 = r_GfxInfo.y1 - 50;
	if (label != "-")
	{
		PrintInDrawingArea(label, r_GfxInfo.x1, y12);
	}
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.Buffer_Width, UI.Buffer_Height);
}


void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected, string label) const
{
	
	//TODO: Add code to draw connection
	
		//draw highlighted connection
		if (selected)
		{
			pWind->SetPen(RED, 3);
			if ((r_GfxInfo.y1 == r_GfxInfo.y2) || (r_GfxInfo.x1 == r_GfxInfo.x2))
			{
				pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);
			}
			//draw broken connection
			else if (r_GfxInfo.x1 != r_GfxInfo.x2 && r_GfxInfo.y1 != r_GfxInfo.y2)
			{
				pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y1);
				pWind->DrawLine(r_GfxInfo.x2, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);
			}
		}
		//draw normal connection
		else
		{
			pWind->SetPen(BLUE, 3);
			if ((r_GfxInfo.y1 == r_GfxInfo.y2) || (r_GfxInfo.x1 == r_GfxInfo.x2))
			{
				pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);
			}
			//draw broken connection
			else if (r_GfxInfo.x1 != r_GfxInfo.x2 && r_GfxInfo.y1 != r_GfxInfo.y2)
			{
				pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y1);
				pWind->DrawLine(r_GfxInfo.x2, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);
			}
		}
		int y12 = r_GfxInfo.y1 - 50;
		if (label != "-")
		{
			PrintInDrawingArea(label, r_GfxInfo.x1, y12);
		}
}



/*bool DrawInDrawingArea(int x, int y)
{
	if ()
		return false;
	if ()
		return false;
	return true;
}*/

Output::~Output()
{
	delete pWind;
}
