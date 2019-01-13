#include "switchToDrawAction.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

switchToDrawAction::switchToDrawAction(ApplicationManager * pApp):Action(pApp)
{
}
void switchToDrawAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	l=new LoadAction (pManager,"SavePlay");
	l->Execute();
	if(pManager->getSound())
	PlaySound(TEXT("Sounds\\Draw.wav"),NULL,SND_FILENAME);
	pOut->PrintMessage("Switch to Draw Mode");
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
}
void switchToDrawAction::Execute() {
	ReadActionParameters();
}
switchToDrawAction::~switchToDrawAction(void)
{
}
