#include "ChangeColor.h"


ChangeColor::ChangeColor(ApplicationManager * pApp):Action(pApp)
{
}
void ChangeColor::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if(pManager->getSound())
	PlaySound(TEXT("Sounds\\ChangeFill.wav"),NULL,SND_FILENAME);
	if (pManager->GetSelected() !=NULL)
	{
	pOut->PrintMessage("Choose the color u want");
	pOut->ClearToolBar();
	pOut->CreateColorToolBar();
	}
	else
		pOut->PrintMessage("Select the figure first");
}
void ChangeColor::Execute() {
	ReadActionParameters();
	
}

