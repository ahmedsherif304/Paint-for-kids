#include "ExitAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ExitAction::ExitAction(ApplicationManager * pApp):Action(pApp)
{}
void ExitAction::ReadActionParameters() 
{	
	if(pManager->getSound())
	PlaySound(TEXT("Sounds\\Exit.wav"),NULL,SND_FILENAME);
}

void ExitAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->GetFigCount()>0)
	{
		pOut->PrintMessage("Exit Action: you may have unsaved work, click save, or click anywhere to exit");
		ActionType Action = pIn->GetUserAction();
		if (Action == SAVE)
		{
			S=new SaveAction(pManager);
			S->Execute();
		}
	}
	
	pManager->~ApplicationManager();
	pManager->Exitation=true;

}
