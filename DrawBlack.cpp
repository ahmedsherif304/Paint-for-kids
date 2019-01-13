#include "DrawBlack.h"
#include "Figures\CFigure.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

DrawBlack::DrawBlack(ApplicationManager * pApp):Action(pApp)
{}
 void DrawBlack::ReadActionParameters(){
 Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("DrawBlack");
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
 }
//Execute the action
void DrawBlack::Execute() 
{
	
	
	pManager->ChangeDrawColorAction(BLACK);
	ReadActionParameters();
	Point X;
	X.x=0;
	X.y=0;

	pManager->UnSelect(X);
}
