#include "ApplicationManager.h"
#include "Figures\CEllipse.h"
#include "Figures\CRectangle.h"
#include "Figures\CTriangle.h"
#include "Figures\CRhombus.h"
#include "Figures\CLine.h"
#include "Actions\AddRectAction.h"
#include"Actions\AddLineAction.h"
#include "Actions\AddRhombusAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddEllipseAction.h"
#include "Actions\SelectAction.h"
#include "Actions\AddDrawingAreaAction.h"
#include "switchToPlayAction.h"
#include "Actions\switchToDrawAction.h"
#include"Actions\PickColorAction.h"
#include "Actions\PickTypeAction.h"
#include "Actions\DeleteAction.h"
#include "CopyAction.h"
#include "CutAction.h"
#include "PasteAction.h"
#include "PasteRectAction.h"
#include "PasteTriAction.h"
#include "PasteLineAction.h"
#include "PasteEllipseAction.h"
#include "PasteRhombusAction.h"
#include "Actions\ExitAction.h"
#include "Black.h"
#include "Red.h"
#include "Blue.h"
#include "White.h"
#include "Green.h"
#include "ChangeColor.h"
#include "stdlib.h"
#include <time.h>
#include "ChangeColor.h"
#include "DrawColor.h"
#include "DrawBlack.h"
#include "DrawBlue.h"
#include "DrawGreen.h"
#include "DrawRed.h"
#include "DrawWhite.h"
#include "Resize.h"
#include "Sound.h"
#include "Actions\LoadAction.h"
#include <fstream>
#include "Actions\\SaveAction.h"
#include "Actions\\SaveByTypeAction.h"
#include "BringToFront.h"
#include "BringToBack.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	FigCount=0;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
	{
	FigList[i] = NULL;	
	FigColor[i]=NULL;
	}
	colour=OldColor=UI.BkGrndColor;
	colour2=UI.DrawColor;
	Set_Clipboard(NULL);
	sound=false;
	Exitation = false;

}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			///create AddLineAction here
        pAct = new AddLineAction(this);
			break;

		case DRAW_RHOMBUS:
			//Create AddRhombusAction here
			pAct=new AddRhombusAction(this);
			break;

		case DRAW_TRI:
			//Create AddTriangleAction here
			pAct=new AddTriAction(this);
			break;

		case DRAW_ELLIPSE:
			//Create AddEllipseAction here
			pAct=new AddEllipseAction(this);
			break;

		case TO_DRAW:
			pAct=new switchToDrawAction(this);
			break;
		case TO_PLAY:
			pAct= new switchToPlayAction(this);
			break;
		case SELECT:
			pAct=new SelectAction(this);
			break;
		case DRAWING_AREA:
			pAct=new AddDrawingAreaAction(this);
			break;
		case DEL:
			pAct=new DeleteAction(this);
			break;

		case COPY :
			pAct= new CopyAction (this);
			break;
		case CUT:
			pAct= new CutAction (this);
			break;

		case PASTE :
			pAct= new PasteAction (this,Switch);
			break;
			
		case PASTE_RECT:
			pAct= new PasteRectAction(this);
			break;

		case PASTE_TRI:
			pAct= new PasteTriAction(this);
			break;
		case PASTE_LINE:
			pAct = new PasteLineAction(this);
			break;

		case PASTE_ELLIPSE:
			pAct= new PasteEllipseAction(this);
			break; 

		case PASTE_RHOMBUS:
			pAct= new PasteRhombusAction(this);
			break;
			case C_BLACK2:
			pAct=new DrawBlack(this);
			break;
		case C_BLUE2:
			pAct=new DrawBlue(this);
			break;
		case C_GREEN2:
			pAct=new DrawGreen(this);
			break;
		case C_RED2:
			pAct=new DrawRed(this);
			break;
		case C_WHITE2:
			pAct=new DrawWhite(this);
			break;
		case CHNG_DRAW_CLR:
			pAct=new DrawColor(this);
			break;
		case C_BLACK:
			pAct=new Black(this); 
				break;

		case C_RED:
			pAct=new Red(this);
			    break;

		case C_WHITE:
			pAct=new white(this);
			break;

		case C_BLUE:
			pAct=new Blue(this);
			break;

		case C_GREEN:
		    pAct=new Green(this);
		   break;

		case CHNG_FILL_CLR:
			pAct=new ChangeColor (this);
			break;
		case LOAD:
			pAct=new LoadAction(this);
			break;
		case SOUND :
			pAct=new Sound(this);
			break;
		case RESIZE:
			pAct=new Resize(this);	  
			break;
		case EXIT:
			pAct =new ExitAction(this);
			break;
		case PICK:
			pAct=new PickTypeAction(this);
			break;
		case PICK_COLOR:
			pAct=new PickColorAction(this);
			break;
			case SAVE:
	        pAct= new SaveAction(this);
		    break;
		case SAVE_TYPE:
			pAct= new SaveByTypeAction(this);
			break;

		case BRING_BACK:
			pAct= new BringToFront(this);
			break;

			case BRING_FRONT:
			pAct= new BringToBack(this);
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}



//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//
void ApplicationManager::UnSelect(Point p){
	for(int i=FigCount-1; i>=0; i--)
{
		if(FigList[i]->IsHere(p)==true)
		{FigList[i]->SetSelected(false);}

	{
		if(FigList[i]->IsSelected()==true)
		{FigList[i]->SetSelected(false);}
	}
}
}

void ApplicationManager::BFront(){
	CFigure* F = GetSelected();
	for(int j=0; j<FigCount; j++)
		{
			if (FigList[j]==F)
				{
			for(int k=j-1;k>=0;k--)
			{ FigList[k+1]=FigList[k];}
			FigList[0]=F;
			break;

				}
	
		}
									}

void ApplicationManager::BBack(){
	CFigure* F = GetSelected();
	for(int j=0; j<FigCount; j++)
		{
			if (FigList[j]==F)
				{
					for(int k=j;(FigCount-1)>=k;k++)
					{ FigList[k]=FigList[k+1];}
					FigList[FigCount-1]=F;
					break;

				}
	
		}
									}


void ApplicationManager::saveall(ofstream &Outfile)
{

	//Outfile << getcolor(UI.DrawColor) << "    " << getcolor(UI.FillColor) + "\n";
	Outfile << to_string(FigCount) + "\n";
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(Outfile);
	}
}
string ApplicationManager::getcolor(color colour){
	if (colour == RED)
		return "RED";
	else if(colour == WHITE)
		return "WHITE";
	else if(colour == BLUE)
		return "BLUE";
	else if (colour == GREEN)
		return "GREEN";
	else
		return "BLACK";
}


void ApplicationManager::savebytype(ofstream &Outfile2, string type)
{
	int typecount = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if(FigList[i]->gettype() == type)
			typecount++;
	}
	//Outfile2 << getcolor(UI.DrawColor) + "    "  + getcolor(UI.FillColor) + "\n";
	Outfile2 << to_string(typecount) + "\n";
	for (int i = 0; i < FigCount; i++)
	{
		if(FigList[i]->gettype() == type)
			FigList[i]->Save(Outfile2);
	}
}

void ApplicationManager::ChangeDrawColorAction(color X)  //change
{
	GetSelected()->ChngDrawClr(X);
}
//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
	{
	FigList[FigCount++] = pFig;
	}
}

void ApplicationManager::DeleteFigure(){
	for(int i=FigCount-1;i>=0;i--){
	if(FigList[i]->IsSelected()==true){
		//FigList[i]->SetSelected(false);
		//FigList[i]->ChngFillClr(UI.BkGrndColor);
		//FigList[i]->ChngDrawClr(UI.BkGrndColor);
		//FigList[i]->Draw(pOut);
		delete FigList[i];
		//for ( int j=i; j<FigCount;j++)
		//{  
			//FigList[j-1]=FigList[j];
		FigList[i]=FigList[FigCount-1];
		FigList[--FigCount]=NULL;
		//}
		//FigList[FigCount]=NULL;
				}
	}
}
CFigure *ApplicationManager::GetFigure(int x, int y) const
{Point p;p.x=x;p.y=y;
for(int i=FigCount-1; i>=0; i--)
{
if(FigList[i]->IsHere(p)==true)
{
	if(FigList[i]->IsSelected()==true)
		{FigList[i]->SetSelected(false);
		 return NULL;
	     }

FigList[i]->SetSelected(true);
FigList[i]->PrintInfo(pOut);
return FigList[i];
}
}
return NULL;
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	
}


bool ApplicationManager::isFilled(){
	if (colour==UI.BkGrndColor)return false;
	return true;
}
CFigure* ApplicationManager::GetSelected ()
{
for(int i=0; i<=(FigCount-1); i++)
	{
		if(FigList[i]->IsSelected())
			return FigList[i];
	}
return NULL;
}
void ApplicationManager:: Set_Old_Color(color X)
{ OldColor=X;
}
color ApplicationManager:: Get_Old_Color(){
	return OldColor;
}

	
void ApplicationManager::ChangeColorAction(color X)
{
	GetSelected()->ChngFillClr(X);
	colour=X;	
}

color ApplicationManager::GetColor()
{return colour;}
color ApplicationManager::GetColor2(){return colour2;}
////////////////////////////////////////////////////////////////////////////////////
int ApplicationManager::GetFigCount()
{
	return FigCount;
}

CFigure*ApplicationManager::GetFigure(Point p) const
{
for(int i=FigCount-1; i>=0; i--)
{
if(FigList[i]->IsHere(p)==true)
	return FigList[i];
}
return NULL;
}


CFigure* ApplicationManager::PickRandomFigure(){
	srand(time(NULL));
int A=rand()%FigCount;
return FigList[A];
}
void ApplicationManager::setFigNums(int& a,int& b,int& c,int& d,int& e){
for(int i=0;i<FigCount;i++){
	if(dynamic_cast<CRectangle*>(FigList[i]) !=NULL)     a++;
	else if(dynamic_cast<CTriangle*>(FigList[i]) !=NULL) b++;
	else if(dynamic_cast<CLine*>(FigList[i]) !=NULL)     c++;
	else if(dynamic_cast<CEllipse*>(FigList[i]) !=NULL)  d++;
	else if(dynamic_cast<CRhombus*>(FigList[i]) !=NULL)  e++;
}
}

void ApplicationManager::setColorNums(int& x,int& y,int& z,int& w,int& e,int &h){
for(int i=0;i<FigCount;i++){
	if(FigList[i]->GetGFX().FillClr==BLACK)	     x++;
	else if(FigList[i]->GetGFX().FillClr==RED)   y++;
	else if(FigList[i]->GetGFX().FillClr==WHITE) z++;
	else if(FigList[i]->GetGFX().FillClr==BLUE)  w++;
	else if(FigList[i]->GetGFX().FillClr==GREEN) e++;
	else										 h++;
}
}

void ApplicationManager::setSound(){
if (sound ==true)sound=false;
else sound=true;
}
bool ApplicationManager::getSound(){return sound;}
void ApplicationManager:: Set_Clipboard(CFigure*SEL)
{
	Clipboard =SEL;
}

CFigure* ApplicationManager::Get_Clipoard()
{
	return Clipboard;
}



//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }

////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	if (Exitation)
	{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	}
}
