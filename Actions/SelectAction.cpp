#include "SelectAction.h"


#include "..\Figures\CFigure.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
SelectAction::SelectAction(ApplicationManager * pApp):Action(pApp)
{}
void SelectAction::SetPoint(Point p){P1.x=p.x;P1.y=p.y;}
Point SelectAction::getPoint(){
	return P1;
}
void SelectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if(pManager->getSound())
	PlaySound(TEXT("Sounds\\Select.wav"),NULL,SND_FILENAME);
	pOut->PrintMessage("Click on figure u want to select ");
	Point P;

	
	//Read  point P
	pIn->GetPointClicked(P.x, P.y);

	SetPoint(P);
	
	pOut->ClearStatusBar();
	
}

//Execute the action
void SelectAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	pManager->UnSelect(P1);
	pManager->GetFigure(P1.x,P1.y);
}