#include "AddDrawingAreaAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddDrawingAreaAction::AddDrawingAreaAction(ApplicationManager * pApp):Action(pApp)
{}
void AddDrawingAreaAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();	
	pOut->PrintMessage("Drawing Area");
	
	
	

	pOut->ClearStatusBar();

}

//Execute the action
void AddDrawingAreaAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();

	pManager->UnSelect(P1);
}
