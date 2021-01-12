#include "Move.h"

#include "../Project Code Framework/ApplicationManager.h"

Move::Move(ApplicationManager* pApp) :Action(pApp)
{
}

Move::~Move(void)
{
}

void Move::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("click on component you want to move, then click and drag");
	pIn->GetPointClicked(x, y);



	

}

void Move::Execute()
{
	ReadActionParameters();
    Input* pIn = pManager->GetInput();
    if (pManager->IsGateinsideArea(x, y))
    {
        Component* pComp = pManager->IsGateinsideArea(x, y);
        GraphicsInfo GateGfxInfo = pComp->returnGfxInfo();

        Output* pOut = pManager->GetOutput();
        pOut->PrintMsg("click on new position");
        pIn->GetPointClicked(x, y);

        pComp->setGfxInfo(x, x + 50, y, y + 50);
        Gate* pGate = (Gate*)pComp;
       if (pComp->getGateOutputConnected())
       {
           int j = 0;
           Connection** aConn = pGate->getSrcPin()->returnConnections(j);

           for (int i = 0;i < j;i++)
           {
               aConn[i]->setGfxInfo(x+50, aConn[i]->returnGfxInfo().x2, y+25, aConn[i]->returnGfxInfo().y2);
           }
       }
       if (pComp->getGateInputConnected())
       {
           for(int i =0; i < pGate->GetnumberofInputPins();i++)
           {
               if (pGate->getDstPin(i)->getConnected())
               {
                   Connection* Conn = pGate->getDstPin(i)->GetConnection();
                   Conn->setGfxInfo(Conn->returnGfxInfo().x1, x , Conn->returnGfxInfo().y1, y+10 );
               }
           }
      
       }
    }
	/*if (pManager->IsGateinsideArea(x, y) && pManager->IsGateinsideArea(x,y)->getType()!=ITM_CONNECTION)
	{
        Component* pComp = pManager->IsGateinsideArea(x, y);
        bool bDragging = false;
        int iX = 0;
        int iY = 0;
        int iXOld = 0;
        int iYOld = 0;
        GraphicsInfo GateGfxInfo = pComp->returnGfxInfo();

            // Dragging voodoo
            if (bDragging == false) {
                if (pIn->getbuttonState(LEFT_BUTTON, iX, iY) == BUTTON_DOWN)
                {
                    if (pComp->IsClickInsideArea(iX,iY))
                    {
                        bDragging = true;
                        iXOld = iX; iYOld = iY;
                        GateGfxInfo.x1 = iX; 
                        GateGfxInfo.y1 = iY;
                        GateGfxInfo.x2 = iX + 50;
                        GateGfxInfo.y2 = iY +50;
                    }
                }
            }
            else
            {
                if (pIn->getbuttonState(LEFT_BUTTON, iX, iY) == BUTTON_UP)
                {
                    bDragging = false;
                }
                else {
                    if (iX != iXOld)
                    {
                        GateGfxInfo.x1 = GateGfxInfo.x1 + (iX - iXOld);
                        iXOld = iX;
                        GateGfxInfo.x2 = GateGfxInfo.x1 + 50;
                    }
                    if (iY != iYOld)
                    {
                        GateGfxInfo.y1 = GateGfxInfo.y1 + (iY - iYOld);
                        iYOld = iY;
                        GateGfxInfo.y2 = GateGfxInfo.y1 + 50;
                    }
                }




            
        }
	}*/


}

void Move::Undo()
{}

void Move::Redo()
{}


