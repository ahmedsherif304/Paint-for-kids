#include "white.h"
#include "Figures\CFigure.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

white::white(ApplicationManager * pApp):Action(pApp)
{}
 void white::ReadActionParameters(){
 Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("white");
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
 }
//Execute the action
void white::Execute() 
{
	
	
	pManager->ChangeColorAction(WHITE);
	ReadActionParameters();
	Point X;
	X.x=0;
	X.y=0;

	pManager->UnSelect(X);
}