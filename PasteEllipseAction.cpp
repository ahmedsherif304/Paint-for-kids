#include "PasteEllipseAction.h"
#include "PasteEllipseAction.h"
#include "Figures\CEllipse.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

PasteEllipseAction::PasteEllipseAction(ApplicationManager * pApp):Action(pApp)
{}


void PasteEllipseAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Ellipse: Click at center point");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	if (P1.y < UI.ToolBarHeight+95 || P1.y > UI.height - UI.StatusBarHeight-90) {
					do
					{
						pOut->PrintMessage("You can not draw here please click on another point");
						pIn->GetPointClicked(P1.x, P1.y);
						if (P1.y > UI.ToolBarHeight+95 && P1.y < UI.height - UI.StatusBarHeight-90) break;
					} while (1);
				}
	EllipseGfxInfo.isFilled =pManager->isFilled();
	//default is not filled
	//get drawing, filling colors and pen width from the interface
	EllipseGfxInfo.DrawClr = pManager->GetColor2();
	EllipseGfxInfo.FillClr = pManager->Get_Old_Color();

	pOut->ClearStatusBar();

}

//Execute the action
void PasteEllipseAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CEllipse *R=new CEllipse(P1, EllipseGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}