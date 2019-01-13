#include "DrawBlue.h"
#include "Figures\CFigure.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

DrawBlue::DrawBlue(ApplicationManager * pApp):Action(pApp)
{}
 void DrawBlue::ReadActionParameters(){
 Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("DrawBlue");
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
 }
//Execute the action
void DrawBlue::Execute() 
{
	
	
	pManager->ChangeDrawColorAction(BLUE);
	ReadActionParameters();
	Point X;
	X.x=0;
	X.y=0;

	pManager->UnSelect(X);
}
