#include "AddLineAction.h"

#include "..\Figures\CLine.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddLineAction::AddLineAction(ApplicationManager * pApp):Action(pApp)
{}

void AddLineAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at first corner");
	if(pManager->getSound())
	PlaySound(TEXT("Sounds\\Line.wav"),NULL,SND_FILENAME);
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	if (P1.y < UI.ToolBarHeight+5 || P1.y > UI.height - UI.StatusBarHeight) {
					do
					{
						pOut->PrintMessage("You can not draw here please click on another point");
						pIn->GetPointClicked(P1.x, P1.y);
						if (P1.y > UI.ToolBarHeight+5 && P1.y < UI.height - UI.StatusBarHeight) break;
					} while (1);
				}

	pOut->PrintMessage("New Line: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	if (P2.y < UI.ToolBarHeight+5 || P2.y > UI.height - UI.StatusBarHeight) {
					do
					{
						pOut->PrintMessage("You can not draw here please click on another point");
						pIn->GetPointClicked(P2.x, P2.y);
						if (P2.y > UI.ToolBarHeight+5 && P2.y < UI.height - UI.StatusBarHeight) break;
					} while (1);
				}
	
	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pManager->GetColor2();
	pOut->ClearStatusBar();

}

//Execute the action
void AddLineAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CLine *R=new CLine(P1, P2, LineGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
