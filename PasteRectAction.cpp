#include "PasteRectAction.h"

#include "ApplicationManager.h"
#include "Figures\CRectangle.h"
#include "Actions\AddRectAction.h"

#include "GUI\input.h"
#include "GUI\Output.h"
#include "DEFS.h"
PasteRectAction::PasteRectAction(ApplicationManager * pApp):Action(pApp)
{}
void PasteRectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput() ;
	Input* pIn = pManager->GetInput();
	
	CRectangle*Paste= dynamic_cast<CRectangle*>(pManager->Get_Clipoard());

	

	
	pOut->PrintMessage("Paste Rectangle , Click at the point");
					do
					{
						pIn->GetPointClicked(temp.x, temp.y);
						P1.x= temp.x - (Paste->Get_Length()/2.0);
			P2.x= temp.x + (Paste->Get_Length()/2.0);
			P1.y= temp.y + (Paste->Get_Width()/2.0);
			P2.y= temp.y - (Paste->Get_Width()/2.0);

	

						if ((P1.y > UI.ToolBarHeight+5 && P1.y< UI.height - UI.StatusBarHeight)&& (P2.y > UI.ToolBarHeight && P2.y < UI.height - UI.StatusBarHeight)) break;
						pOut->PrintMessage("You can not draw here please click on another point");
					} while (1);
				

		//default is not filled

	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.isFilled = pManager->isFilled();
	RectGfxInfo.DrawClr = pManager->GetSelected()->GetGFX().DrawClr;
	RectGfxInfo.FillClr = pManager->Get_Old_Color();

	
	pOut->ClearStatusBar();

}

void PasteRectAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CRectangle *R=new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	
	pManager->AddFigure(R);
	
}


PasteRectAction::~PasteRectAction(void)
{
}
