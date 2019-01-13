#include "CutAction.h"
#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"






CutAction::CutAction(ApplicationManager * pApp): Action(pApp) , S(2)
{
		pManager->Set_Clipboard(NULL) ;

}



void CutAction:: ReadActionParameters()
{
	pManager->Switch=S;
	Output* pOut = pManager->GetOutput();
	CFigure*S= pManager->GetSelected();
	
	if (S==NULL)
		
		pOut->PrintMessage("Select image first"); // if no figure is selected
			
	else
	{
		if(pManager->getSound())
		PlaySound(TEXT("Sounds\\Cut.wav"),NULL,SND_FILENAME);
		pManager->Set_Clipboard(S) ;
		pOut->PrintMessage("Image Cut");
		pManager->Set_Old_Color(S->GetGFX().FillClr);
		S->ChngFillClr(GRAY);
	}
}
color CutAction:: GetOldColor(){
	return OldColor;}

void CutAction:: Execute()
{	ReadActionParameters();

}



CutAction::~CutAction(void)
{
}
