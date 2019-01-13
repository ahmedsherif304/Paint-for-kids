#include "BringToBack.h"
#include "ApplicationManager.h"
#include "Actions\Action.h"
#include "GUI\input.h"
#include "GUI\Output.h"

BringToBack::BringToBack(ApplicationManager * pApp):Action(pApp)
{}

void BringToBack::ReadActionParameters() 
{	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
}

//Execute the action
void BringToBack::Execute() 
{
	ReadActionParameters();
	pManager->BBack();
	
}


