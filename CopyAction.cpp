#include "CopyAction.h"

#include "ApplicationManager.h"

#include "GUI\input.h"
#include "GUI\Output.h"

CopyAction::CopyAction(ApplicationManager * pApp): Action(pApp),S(1)
{
		pManager->Set_Clipboard(NULL) ;

}



void CopyAction:: ReadActionParameters()
{
	pManager->Switch=S;
	Output* pOut = pManager->GetOutput();
	CFigure*S= pManager->GetSelected();

	if (S==NULL)
		
		pOut->PrintMessage("Select image first"); // if no figure is selected
			
	else
	{
		if(pManager->getSound())
		PlaySound(TEXT("Sounds\\Copy.wav"),NULL,SND_FILENAME);
		if( S->GetGFX().FillClr== GRAY){
			GfxInfo X;
			X=S->GetGFX();
			X.FillClr=pManager->Get_Old_Color();
			S->SetGFX(X);
		}
		pManager->Set_Clipboard(S) ;
		pOut->PrintMessage("Image Copied");
		pManager->Set_Old_Color(S->GetGFX().FillClr);
	}
}

void CopyAction:: Execute()
{	ReadActionParameters();

}


CopyAction::~CopyAction()
{
}
