#include "DrawGreen.h"
#include "Figures\CFigure.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

DrawGreen::DrawGreen(ApplicationManager * pApp):Action(pApp)
{}
 void DrawGreen::ReadActionParameters(){
 Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("DrawGreen");
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
 }
//Execute the action
void DrawGreen::Execute() 
{
	
	
	pManager->ChangeDrawColorAction(GREEN);
	ReadActionParameters();
	Point X;
	X.x=0;
	X.y=0;

	pManager->UnSelect(X);
}
