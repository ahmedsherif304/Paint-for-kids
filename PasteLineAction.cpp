#include "PasteLineAction.h"

#include "ApplicationManager.h"
#include "Figures\CLine.h"
#include "Actions\AddLineAction.h"

#include "GUI\input.h"
#include "GUI\Output.h"

PasteLineAction::PasteLineAction(ApplicationManager * pApp):Action(pApp)
{}
void PasteLineAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput() ;
	Input* pIn = pManager->GetInput();
	
	CLine*Paste= dynamic_cast<CLine*>(pManager->Get_Clipoard());

	
	pOut->PrintMessage("Paste Line , Click at the point");
	
	
	if ((P1.y < UI.ToolBarHeight+5 || P1.y > UI.height - UI.StatusBarHeight)){
					do
					{
					
					pIn->GetPointClicked(temp.x, temp.y);
					Point Mid= Paste->Get_Mid();
					float X_Diff = (temp.x) - (Mid.x);
					float Y_Diff = (temp.y) - (Mid.y);

	P1.x= Paste->Get_Corner_1().x + X_Diff; P1.y= Paste->Get_Corner_1().y + Y_Diff;
	P2.x= Paste->Get_Corner_2().x + X_Diff; P2.y= Paste->Get_Corner_2().y + Y_Diff;

						/*pOut->PrintMessage("You can not draw here please click on another point");
						pIn->GetPointClicked(temp.x, temp.y);
						if (temp.y > UI.ToolBarHeight+5 && temp.y< UI.height - UI.StatusBarHeight) break;*/
	if ((P1.y > UI.ToolBarHeight+5 && P1.y < UI.height - UI.StatusBarHeight)&&((P2.y > UI.ToolBarHeight+5 && P2.y < UI.height - UI.StatusBarHeight))) break;
	pOut->PrintMessage("You can not draw here please click on another point");
					} while (1);
				}

	




	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	pOut->ClearStatusBar();

}

//Execute the action
void PasteLineAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	
	CLine *R=new CLine(P1, P2, LineGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}







PasteLineAction::~PasteLineAction()
{
}
