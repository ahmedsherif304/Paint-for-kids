#include "Blue.h"
#include "Figures\CFigure.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

Blue::Blue(ApplicationManager * pApp):Action(pApp)
{}
 void Blue::ReadActionParameters(){
 Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Blue");
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
	pOut->ClearStatusBar();
 }
//Execute the action
void Blue::Execute() 
{
	
	
	pManager->ChangeColorAction(BLUE);
	ReadActionParameters();
	Point X;
	X.x=0;
	X.y=0;

	pManager->UnSelect(X);
}