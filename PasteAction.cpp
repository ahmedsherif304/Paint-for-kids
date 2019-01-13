
#include "ApplicationManager.h"
#include"PasteAction.h"

#include "GUI\input.h"
#include "GUI\Output.h"



PasteAction::PasteAction(ApplicationManager * pApp,int x):Action(pApp)
{ 
	Switch=x;
}
void PasteAction::ReadActionParameters() 
{	Output* pOut = pManager->GetOutput();


		CFigure*Paste= pManager->Get_Clipoard();
		if(pManager->getSound())
		PlaySound(TEXT("Sounds\\Paste.wav"),NULL,SND_FILENAME);
		if (Paste != NULL)
		switch (Paste->getID())
		{
		case 1:
			pManager->ExecuteAction(PASTE_RECT) ;
			break;

		case 2:
			pManager->ExecuteAction(PASTE_LINE);
			break;
		case 3:
			pManager->ExecuteAction(PASTE_RHOMBUS);
			break;

		case 4:
			pManager->ExecuteAction(PASTE_TRI) ;
			break;

			case 5:
				pManager->ExecuteAction(PASTE_ELLIPSE) ;
			break;

		}

		else {
		pOut->PrintMessage("You should choose an action first");
		}
		if(Switch==2) {
		d=new DeleteAction(pManager);
		d->Execute();
		delete d;
		//pManager->Set_Clipboard(NULL);
		}
		pOut->PrintMessage("");
}




void PasteAction::Execute(){
	ReadActionParameters() ;
}

PasteAction::~PasteAction()
{
}
