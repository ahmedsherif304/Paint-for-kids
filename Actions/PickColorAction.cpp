#include "PickColorAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Blue.h"
#include "..\Black.h"
#include "..\Red.h"
#include "..\Green.h"
#include "..\white.h"
PickColorAction::PickColorAction(ApplicationManager* pApp):Action(pApp)
{RCount=WCount=GreenCounter=BlueCounter=BlackCounter=WhiteCounter=RedCounter=BKGCcounter=0;
}
void PickColorAction::ReadActionParameters(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if(pManager->GetFigCount()!=0){
	CFigure* C=pManager->PickRandomFigure();
	if(pManager->getSound())
	PlaySound(TEXT("Sounds\\PickColor.wav"),NULL,SND_FILENAME);

		pManager->setColorNums(BlackCounter,RedCounter,WhiteCounter,BlueCounter,GreenCounter,BKGCcounter);
	if(C->GetGFX().FillClr==BLACK){
pOut->PrintMessage("Choose all Blacks,Click anywhere to begin");
pIn->GetUserAction();
while(RCount<BlackCounter){
s=new SelectAction(pManager);
d=new DeleteAction(pManager);
s->Execute();
if(pManager->GetSelected()!=NULL){
if(pManager->GetSelected()->GetGFX().FillClr==BLACK)
RCount++;
else WCount++;
}
else WCount++;
d->Execute();
pManager->UpdateInterface();
	delete s;
	delete d;
}
}
else if(C->GetGFX().FillClr==RED){
pOut->PrintMessage("Choose all Reds,Click anywhere begin");
pIn->GetUserAction();
while(RCount<RedCounter){
s=new SelectAction(pManager);
d=new DeleteAction(pManager);
s->Execute();
if(pManager->GetSelected()!=NULL){
if(pManager->GetSelected()->GetGFX().FillClr==RED)
RCount++;
else WCount++;
}
else WCount++;
d->Execute();
pManager->UpdateInterface();
	delete s;
	delete d;
}
}
else if(C->GetGFX().FillClr==WHITE){
pOut->PrintMessage("Choose all Whites,Click anywhere begin");
pIn->GetUserAction();
while(RCount<WhiteCounter){
s=new SelectAction(pManager);
d=new DeleteAction(pManager);
s->Execute();
if(pManager->GetSelected()!=NULL){
if(pManager->GetSelected()->GetGFX().FillClr==WHITE)
RCount++;
else WCount++;
}
else WCount++;
d->Execute();
pManager->UpdateInterface();
	delete s;
	delete d;
}
}
else if(C->GetGFX().FillClr==BLUE){
pOut->PrintMessage("Choose all Blues,Click anywhere begin");
pIn->GetUserAction();
while(RCount<BlueCounter){
	s=new SelectAction(pManager);
	d=new DeleteAction(pManager);
	s->Execute();
	if(pManager->GetSelected()!=NULL){
if(pManager->GetSelected()->GetGFX().FillClr==BLUE)
RCount++;
else WCount++;
	}
	WCount++;
d->Execute();
pManager->UpdateInterface();
	delete s;
	delete d;
}}
else if(C->GetGFX().FillClr==GREEN){
pOut->PrintMessage("Choose all Greens,Click anywhere begin");
pIn->GetUserAction();
while(RCount<GreenCounter){
	s=new SelectAction(pManager);
	d=new DeleteAction(pManager);
	s->Execute();
	if(pManager->GetSelected()!=NULL){
if(pManager->GetSelected()->GetGFX().FillClr==GREEN)
RCount++;
else WCount++;
	}
	else WCount++;
d->Execute();
pManager->UpdateInterface();
	delete s;
	delete d;
}
}
else if (C->GetGFX().FillClr==UI.BkGrndColor){
pOut->PrintMessage("Choose all Non Filled Figurs,Click anywhere begin");
pIn->GetUserAction();
while(RCount<BKGCcounter){
	s=new SelectAction(pManager);
	d=new DeleteAction(pManager);
	s->Execute();
	if(pManager->GetSelected()!=NULL){
	if(pManager->GetSelected()->GetGFX().FillClr ==UI.BkGrndColor)
RCount++;
else WCount++;
	}
	else WCount++;
d->Execute();
pManager->UpdateInterface();
	delete s;
	delete d;
}
}
pOut->ClearDrawArea();
string h=to_string(RCount);
string g=to_string(WCount);
pOut->PrintMessage("You finished,  Right picks= "+h+" ,Wrong picks= "+g);
}
else {pOut->PrintMessage("There is no figures to play ");}
}
void PickColorAction::Execute(){
	ReadActionParameters();
}




