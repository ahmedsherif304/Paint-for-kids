#include "DrawColor.h"


DrawColor::DrawColor(ApplicationManager * pApp):Action(pApp)
{
}
void DrawColor::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->GetSelected() !=NULL)
	{
	pOut->PrintMessage("Choose the color u want");
	pOut->ClearToolBar();
	pOut->CreateDrawColorToolBar();
	}
	else
		pOut->PrintMessage("Select the figure first");
}
void DrawColor::Execute() {
	ReadActionParameters();
}

