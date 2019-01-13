#include "PasteTriAction.h"
#include "ApplicationManager.h"
#include "Figures\CTriangle.h"
#include "Actions\AddTriAction.h"
#include "GUI\input.h"
#include "GUI\Output.h"
#include "DEFS.h"
PasteTriAction::PasteTriAction(ApplicationManager * pApp):Action(pApp)
{}
void PasteTriAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput() ;
	Input* pIn = pManager->GetInput();
	
	CTriangle*Paste= dynamic_cast<CTriangle*>(pManager->Get_Clipoard());

	pOut->PrintMessage("Paste Triangle , Click at the point");

	
					do
					{
							pIn->GetPointClicked(temp.x, temp.y);

						Point Center =Paste->Get_Center();//Get the center of the original triangle
						float X_Diff=(temp.x - Center.x);
						float Y_Diff=(temp.y - Center.y);


		P1.x= (Paste->Get_Corner1().x + X_Diff); P2.x = (Paste->Get_Corner2().x )+ X_Diff; P3.x= (Paste->Get_Corner3().x + X_Diff);
		P1.y= (Paste->Get_Corner1().y + Y_Diff); P2.y = (Paste->Get_Corner2().y )+ Y_Diff; P3.y= (Paste->Get_Corner3().y + Y_Diff);
		
						if  ((P1.y > UI.ToolBarHeight+5 && P1.y < UI.height - UI.StatusBarHeight)&&(P2.y > UI.ToolBarHeight+5 && P2.y < UI.height - UI.StatusBarHeight)&&(P3.y > UI.ToolBarHeight+5 && P3.y < UI.height - UI.StatusBarHeight)) break;
						pOut->PrintMessage("You can not draw here please click on another point");
					} while (1);
				
	

	TriGfxInfo.isFilled = pManager->isFilled();	
	TriGfxInfo.DrawClr = pManager->GetColor2();
	TriGfxInfo.FillClr = pManager->Get_Old_Color();

	pOut->ClearStatusBar();



}
void PasteTriAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a triangle with the parameters read from the user
	CTriangle *R=new CTriangle(P1, P2, P3, TriGfxInfo);

	//Add the triangle to the list of figures
	pManager->AddFigure(R);
}


 PasteTriAction::~PasteTriAction()
{
}


