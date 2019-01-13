#include "switchToPlayAction.h"


switchToPlayAction::switchToPlayAction(ApplicationManager * pApp):Action(pApp)
{
}
void switchToPlayAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	s= new SaveAction(pManager,"SavePlay");
	s->Execute();
	pOut->PrintMessage("Switch to Play mode");
	pOut->ClearToolBar();
	pOut->CreatePlayToolBar();
}
void switchToPlayAction::Execute() {
	ReadActionParameters();
}

switchToPlayAction::~switchToPlayAction(void)
{
}
