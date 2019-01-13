#include "CEllipse.h"
#include <fstream>
#include <istream>
CEllipse::CEllipse(Point P1,  GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	ID2=++ID;
	IDPaste=5;
}
	
bool CEllipse::IsHere(Point p){if(((p.x>Corner1.x-40)&&(p.x<Corner1.x+40))&&((p.y<Corner1.y+90)&&(p.y>Corner1.y-90)))return true;
return false;}

void CEllipse::PrintInfo(Output* pOut){
	string d=to_string(ID2);
	string g=to_string(Corner1.x);
	string h=to_string(Corner1.y);
	pOut->PrintMessage("Ellipse ,ID "+d+" its center is ("+g+","+h+")");
}
int CEllipse::getID(){return IDPaste;}
void CEllipse::Load(ifstream &Infile)
{
	int id;
	Infile >> id ;
	Infile >> Corner1.x >> Corner1.y;
	GfxInfo info;
	string DrawColor; 
	string FillColor;

	Infile >> DrawColor;
	//info.DrawClr = color(DrawColor[0], DrawColor[1], DrawColor[2]);
	Infile >> FillColor;
	if (FillColor == "NO_FILL") {
		info.isFilled = false;
		info.FillClr = UI.BkGrndColor;
	}
	else if(FillColor == "BLACK"){
	info.isFilled = true;
	info.FillClr=BLACK;
	}
	else if(FillColor == "BLUE"){
	info.isFilled = true;
	info.FillClr=BLUE;
	}
	else if(FillColor == "GREEN"){
	info.isFilled = true;
	info.FillClr=GREEN;
	}
	else if(FillColor == "WHITE"){
	info.isFilled = true;
	info.FillClr=WHITE;
	}
	else if(FillColor == "RED"){
	info.isFilled = true;
	info.FillClr=RED;
	}

	if(DrawColor == "BLACK"){
	info.DrawClr=BLACK;
	}
	else if(DrawColor == "BLUE"){
	info.DrawClr=BLUE;
	}
	else if(DrawColor == "GREEN"){
	info.DrawClr=GREEN;
	}
	else if(DrawColor == "WHITE"){
	info.DrawClr=WHITE;
	}
	else if(DrawColor == "RED"){
	info.DrawClr=RED;
	}
	//Infile>> info.BorderWdth ;
	ID2 = id;
	CFigure::FigGfxInfo = info ;

}
void CEllipse::Save(ofstream &Outfile){
		string filled;
		if(FigGfxInfo.isFilled){filled=getcolor(FigGfxInfo.FillClr);} else
			filled = "NO_FILL";
	     Outfile << "ELLIPSE   " + to_string(ID2) 
		+ "   " + to_string(Corner1.x) + "    " + to_string(Corner1.y) + "    " 
		+ getcolor(FigGfxInfo.DrawClr) + "     " +  filled + "\n" ;
}
 string CEllipse::gettype(){
 return "ELLIPSE";
}
void CEllipse::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawEllipse(Corner1,  FigGfxInfo, Selected);
}