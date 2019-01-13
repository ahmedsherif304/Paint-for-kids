#include "CRectangle.h"
#include <fstream>
#include <istream>
CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	ID2=++ID;
	IDPaste=1;
}
bool CRectangle::IsHere(Point p){if(((p.x>=Corner1.x&&p.x<=Corner2.x)||(p.x<=Corner1.x&&p.x>=Corner2.x))&&((p.y>=Corner1.y&&p.y<=Corner2.y)||(p.y<=Corner1.y&&p.y>=Corner2.y)))
		return true;
return false;}

void CRectangle::PrintInfo(Output* pOut){
	string z=to_string(ID2);
	string a=to_string(Corner1.x);
	string b=to_string(Corner1.y);
	string c=to_string(Corner2.x);
	string d=to_string(Corner2.y);
	string e=to_string(abs(Corner1.x-Corner2.x));
	string f=to_string(abs(Corner1.y-Corner2.y));
	pOut->PrintMessage("Rectangle, ID = "+z+", Start point :("+a+","+b+")    End point ("+c+","+d+")   Width ="+e+"   Height ="+f);
}
int CRectangle::getID(){return IDPaste;}
float CRectangle:: Get_Length()
{
	return abs(Corner1.x-Corner2.x);
}

float CRectangle:: Get_Width()
{
	return abs(Corner1.y-Corner2.y);
}
void  CRectangle::Load(ifstream &Infile)
{
	int id;
	Infile >> id;
	Infile >> Corner1.x >> Corner1.y; 
	Infile>> Corner2.x >> Corner2.y;
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
	CFigure::FigGfxInfo = info;
	
	
}
void CRectangle::Save(ofstream &Outfile){
	string filled; 
	if(FigGfxInfo.isFilled)
	{ filled= getcolor(FigGfxInfo.FillClr);} 
	else
		filled= "NO_FILL";
	Outfile << "RECTANGLE " + to_string(ID2) 
		+ "   " + to_string(Corner1.x) + "    " + to_string(Corner1.y) + "    " 
		+ "   " + to_string(Corner2.x) + "    " + to_string(Corner2.y) + "    " 
		+ getcolor(FigGfxInfo.DrawClr) + "     " +  filled + "\n";
}
string CRectangle::gettype()
{ return "RECTANGLE";}

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, CFigure::IsSelected());
}