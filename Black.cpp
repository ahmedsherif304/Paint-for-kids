#include "Black.h"
#include "Figures\CFigure.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

Black::Black(ApplicationManager * pApp):Action(pApp)
{}
 void Black::ReadActionParameters(){
 Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Black");
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
 }
//Execute the action
void Black::Execute() 
{
	
	
	pManager->ChangeColorAction(BLACK);
	ReadActionParameters();
	Point X;
	X.x=0;
	X.y=0;

	pManager->UnSelect(X);
}