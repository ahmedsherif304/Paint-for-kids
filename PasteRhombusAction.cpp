#include "PasteRhombusAction.h"

#include "Figures\CRhombus.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

PasteRhombusAction::PasteRhombusAction(ApplicationManager * pApp):Action(pApp)
{}

void PasteRhombusAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Paste Rhombus: Click at Center");
	
	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	if (P1.y < UI.ToolBarHeight+105 || P1.y > UI.height - UI.StatusBarHeight-100) {
					do
					{
						pOut->PrintMessage("You can not draw here please click another point");
						pIn->GetPointClicked(P1.x, P1.y);
						if (P1.y > UI.ToolBarHeight+105 && P1.y < UI.height - UI.StatusBarHeight-100) break;
					} while (1);
				}

	
	RhombusGfxInfo.isFilled = pManager->isFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RhombusGfxInfo.DrawClr = pManager->GetColor2();
	RhombusGfxInfo.FillClr = pManager->Get_Old_Color();

	pOut->ClearStatusBar();

}

//Execute the action
void PasteRhombusAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CRhombus *R=new CRhombus(P1,  RhombusGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
