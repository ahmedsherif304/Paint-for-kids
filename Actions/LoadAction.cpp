#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRhombus.h"
#include <fstream>
#include <iostream>
//#include "SaveAction.h"

LoadAction::LoadAction(ApplicationManager *pApp):Action(pApp)
{

}
LoadAction::LoadAction(ApplicationManager *pApp,string x):Action(pApp){
	File_Name=x;
}
void LoadAction::ReadActionParameters()
{
	//if (pManager->GetFigCount()) 
	//{
	//	pManager->GetOutput()->PrintMessage("You just clicked load graph..Your Current Graph will be lost,click save icon to save");
	//	ActionType act = pManager->GetUserAction();
	//	if(act==ITM_Save)
	//	{
	//		//save current graph
	//	}

	//}
	Input* pIn = pManager->GetInput();
	Output* pOut =pManager->GetOutput();
	if(File_Name!="SavePlay"){
	pOut->PrintMessage("write the name of file you want to load from : ");
	File_Name=pIn->GetSrting(pOut);
	}
}

void LoadAction::Execute()
{
	ReadActionParameters();
	Output* pOut=pManager->GetOutput();
	Input* pIn=pManager->GetInput();
	ifstream Infile;
	Infile.open(File_Name+".txt", ios::in);
	if (!Infile.is_open()) 
	{
		pManager->GetOutput()->PrintMessage("File is not Found");
	}
	string  FigType;
	int NumOfFigs; 
	Infile >> NumOfFigs;
	for (int i = 0; i < NumOfFigs; i++) 
	{
		GfxInfo emptyGFX= GfxInfo() ;
		Infile >> FigType;
		Point emptyP= Point();
		Point emptyA= Point();
		Point emptyB= Point();
		if (FigType == "RECTANGLE")
		{
			CRectangle* rec = new CRectangle(emptyP, emptyA, emptyGFX);
			rec->Load(Infile);
			pManager->AddFigure(rec);
		}
		if (FigType == "TRIANGLE")
		{
			CTriangle* trig = new CTriangle(emptyP, emptyA, emptyB, emptyGFX);
			trig->Load(Infile);
			pManager->AddFigure(trig);
		}
		if (FigType == "ELLIPSE")
		{
			CEllipse* elli=new CEllipse(emptyP, emptyGFX) ;
			elli->Load(Infile);
			pManager->AddFigure(elli);
		}
		if (FigType == "LINE") 
		{
			CLine * line = new CLine(emptyP, emptyA, emptyGFX);
			line->Load(Infile);
			pManager->AddFigure(line);
		}
		if (FigType == "RHOMBUS") 
		{
			CRhombus * Rhombus = new CRhombus(emptyP, emptyGFX);
			Rhombus->Load(Infile);
			pManager->AddFigure(Rhombus);
		}
	}
	Infile.close();
}

LoadAction::~LoadAction(void)
{
}
