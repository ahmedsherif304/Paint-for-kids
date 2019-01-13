#include "AddTriAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriAction::AddTriAction(ApplicationManager * pApp):Action(pApp)
{}

void AddTriAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");
	if(pManager->getSound())
	PlaySound(TEXT("Sounds\\Triangle.wav"),NULL,SND_FILENAME);
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
	pOut->PrintMessage("New triangle: Click at second corner");

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
	pOut->PrintMessage("New triangle: Click at third corner");

	//Read 3nd corner and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);
	if (P3.y < UI.ToolBarHeight+5 || P3.y > UI.height - UI.StatusBarHeight) {
					do
					{
						pOut->PrintMessage("You can not draw here please click on another point");
						pIn->GetPointClicked(P3.x, P3.y);
						if (P3.y > UI.ToolBarHeight+5 && P3.y < UI.height - UI.StatusBarHeight) break;
					} while (1);
				}
	TriGfxInfo.isFilled =pManager->isFilled();	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pManager->GetColor2();
	TriGfxInfo.FillClr = pManager->GetColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a triangle with the parameters read from the user
	CTriangle *R=new CTriangle(P1, P2, P3, TriGfxInfo);

	//Add the triangle to the list of figures
	pManager->AddFigure(R);
}
