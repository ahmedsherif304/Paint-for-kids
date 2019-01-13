#include "BringToFront.h"
#include "ApplicationManager.h"
#include "Actions\Action.h"
#include "GUI\input.h"
#include "GUI\Output.h"

BringToFront::BringToFront(ApplicationManager * pApp):Action(pApp)
{}

void BringToFront::ReadActionParameters() 
{	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}

//Execute the action
void BringToFront::Execute() 
{
	ReadActionParameters();
	pManager->BFront();
	
}


