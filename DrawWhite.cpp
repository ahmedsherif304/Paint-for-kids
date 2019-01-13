#include "DrawWhite.h"
#include "Figures\CFigure.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

DrawWhite::DrawWhite(ApplicationManager * pApp):Action(pApp)
{}
 void DrawWhite::ReadActionParameters(){
 Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("DrawWhite");
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
 }
//Execute the action
void DrawWhite::Execute() 
{
	
	
	pManager->ChangeDrawColorAction(WHITE);
	ReadActionParameters();
	Point X;
	X.x=0;
	X.y=0;

	pManager->UnSelect(X);
}
