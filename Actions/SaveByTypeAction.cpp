#include "SaveByTypeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"


SaveByTypeAction::SaveByTypeAction(ApplicationManager * pApp):Action(pApp)
{
}

void SaveByTypeAction::ReadActionParameters() 
{	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	pOut->PrintMessage("Please Choose a type to save.");
	do
	{
		ActionType Act = pManager->GetUserAction();
		switch (Act)
		{
		case DRAW_LINE:
			type = "LINE";
			break;
		case DRAW_RECT:
			type = "RECTANGLE";
			break;
		case DRAW_ELLIPSE:
			type = "ELLIPSE";
			break;
		case DRAW_RHOMBUS:
			type = "RHOMBUS";
			break;
		case DRAW_TRI:
			type = "TRIANGLE";
			break;
		default:
			break;
		}
	}while( type != "LINE" && type != "RECTANGLE" && type != "ELLIPSE" && type != "RHOMBUS" && type != "TRIANGLE");
	pOut->PrintMessage("Enter file name: ");
	file_name = pIn->GetSrting(pOut) + ".txt";
	pOut->ClearStatusBar();
}

//Execute the action
void SaveByTypeAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	Outfile2.open(file_name);
	pManager->savebytype(Outfile2, type);
	Outfile2.close();
	pOut->PrintMessage("Considered Saved :)");
	
}

