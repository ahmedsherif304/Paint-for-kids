#include "DeleteAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DeleteAction::DeleteAction(ApplicationManager* pApp):Action(pApp)
{
}
void DeleteAction::ReadActionParameters(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if(pManager->getSound())
	PlaySound(TEXT("Sounds\\Delete.wav"),NULL,SND_FILENAME);
	pOut->PrintMessage("Delete the selected figure");

}
void DeleteAction::Execute(){
	ReadActionParameters();
	pManager->DeleteFigure();

}


DeleteAction::~DeleteAction(void)
{
}
