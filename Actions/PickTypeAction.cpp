#include "PickTypeAction.h"
#include "..\Figures\CRectangle.h"
#include"CEllipse.h"
#include "CTriangle.h"
#include "..\Figures\Cline.h"
#include "..\Figures\CRhombus.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
PickTypeAction::PickTypeAction(ApplicationManager* pApp):Action(pApp)
{RCount=WCount=rectCounter=triCounter=lineCounter=ellipseCounter=rhombusCounter=0;
}
void PickTypeAction::ReadActionParameters(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if(pManager->GetFigCount()!=0){
	CFigure* C=pManager->PickRandomFigure();
	pManager->setFigNums(rectCounter,triCounter,lineCounter,ellipseCounter,rhombusCounter);
	if(pManager->getSound())
	PlaySound(TEXT("Sounds\\PickType.wav"),NULL,SND_FILENAME);
if(dynamic_cast<CRectangle*>(C) !=NULL){
pOut->PrintMessage("Choose all Rectangles,Click anywhere to begin");
pIn->GetUserAction();
while(RCount<rectCounter){
s=new SelectAction(pManager);
s->Execute();
if(dynamic_cast<CRectangle*>(pManager->GetFigure(s->getPoint())) !=NULL)
	{RCount++;}
else {WCount++;}
d=new DeleteAction(pManager);
d->Execute();
pManager->UpdateInterface();
	delete s;
	delete d;
}
}
else if(dynamic_cast<CTriangle*>(C) !=NULL){
pOut->PrintMessage("Choose all Tirangles,Click anywhere begin");
pIn->GetUserAction();
while(RCount<triCounter){
s=new SelectAction(pManager);
s->Execute();
if(dynamic_cast<CTriangle*>(pManager->GetFigure(s->getPoint())) !=NULL)
	{RCount++;}
else {WCount++;}
d=new DeleteAction(pManager);
d->Execute();
pManager->UpdateInterface();
	delete s;
	delete d;
}
}
else if(dynamic_cast<CLine*>(C) !=NULL){
pOut->PrintMessage("Choose all Lines,Click anywhere begin");
pIn->GetUserAction();
while(RCount<lineCounter){
s=new SelectAction(pManager);
s->Execute();
if(dynamic_cast<CLine*>(pManager->GetFigure(s->getPoint())) !=NULL)
{RCount++;}
else {WCount++;}
d=new DeleteAction(pManager);
d->Execute();
pManager->UpdateInterface();
	delete s;
	delete d;
}
}
else if(dynamic_cast<CEllipse*>(C) !=NULL){
pOut->PrintMessage("Choose all Ellipses,Click anywhere begin");
pIn->GetUserAction();
while(RCount<ellipseCounter){
	s=new SelectAction(pManager);
	s->Execute();
if(dynamic_cast<CEllipse*>(pManager->GetFigure(s->getPoint())) !=NULL)
{RCount++;}
else {WCount++;}
d=new DeleteAction(pManager);
d->Execute();
pManager->UpdateInterface();
	delete s;
	delete d;
}
}
else if(dynamic_cast<CRhombus*>(C) !=NULL){
pOut->PrintMessage("Choose all Rhombuses,Click anywhere begin");
pIn->GetUserAction();
while(RCount<rhombusCounter){
	s=new SelectAction(pManager);
	s->Execute();
if(dynamic_cast<CRhombus*>(pManager->GetFigure(s->getPoint())) !=NULL)
	{RCount++;}
else {WCount++;}
d=new DeleteAction(pManager);
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
void PickTypeAction::Execute(){
	ReadActionParameters();
}


