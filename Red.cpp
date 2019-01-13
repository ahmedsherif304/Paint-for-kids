#include "Red.h"
#include "Figures\CFigure.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

Red::Red(ApplicationManager * pApp):Action(pApp)
{}
 void Red::ReadActionParameters(){
 Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Red");
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
 }
//Execute the action
void Red::Execute() 
{
	
	
	pManager->ChangeColorAction(RED);
	ReadActionParameters();
	Point X;
	X.x=0;
	X.y=0;

	pManager->UnSelect(X);
}
