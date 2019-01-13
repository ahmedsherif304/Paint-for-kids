#include "CLine.h"
#include <fstream>
#include <istream>
#include <cmath>
using namespace std;
CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	ID2=++ID;
	IDPaste=2;
}
bool CLine::IsHere(Point p){
	float slope=float((Corner1.y-Corner2.y))/(Corner1.x-Corner2.x);
	float a=Corner1.y-slope*Corner1.x ;
	float b=p.y-slope*p.x;
	cout<<a<<endl<<b<<endl;
	if(((p.x>=Corner1.x && p.x<=Corner2.x)||(p.x<=Corner1.x && p.x>=Corner2.x))&&((p.y>=Corner1.y && p.y<=Corner2.y)||(p.y<=Corner1.y && p.y>=Corner2.y))&& int(a)==int(b))
	return true;
	return false;
}

void CLine::PrintInfo(Output* pOut){
	float slope=float((Corner1.y-Corner2.y))/(Corner1.x-Corner2.x);
	string z=to_string(ID2);
	string a=to_string(Corner1.x);
	string b=to_string(Corner1.y);
	string c=to_string(Corner2.x);
	string d=to_string(Corner2.y);
	string e=to_string(slope);
	pOut->PrintMessage("Line, ID = "+z+", First point :("+a+","+b+")    Second point ("+c+","+d+"),   Slope ="+e);
}

int CLine::getID(){return IDPaste;}
Point CLine::Get_Mid()
{Point L;
L.x=((Corner1.x + Corner2.x)/2);
L.y=((Corner1.y + Corner2.y)/2);
return L;
}
Point CLine:: Get_Corner_1()
{
	return Corner1;
}
Point CLine::  Get_Corner_2()
{
	return Corner2;}

void CLine::Load(ifstream &Infile)
{
	int id;
	Infile >> id ;
	Infile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;
	GfxInfo info;
	string DrawColor;  //<<<<<<<<<<<<char*>>>>>>>>>>>>>>>
	Infile >> DrawColor;

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
	//info.DrawClr = color(DrawColor[0], DrawColor[1], DrawColor[2]);
	//Infile>> info.BorderWdth;
	ID2 = id;
	CFigure::FigGfxInfo = info;

}
void CLine::Save(ofstream &Outfile){
	string filled; if (FigGfxInfo.isFilled)
	{
		filled= getcolor(FigGfxInfo.FillClr);
	} 
	else
	{ filled= "NO_FILL";}
	Outfile << "LINE   " + to_string(ID2) 
		+ "   " + to_string(Corner1.x) + "    " + to_string(Corner1.y) + "    " 
		+ "   " + to_string(Corner2.x) + "    " + to_string(Corner2.y) + "    " 
		+ getcolor(FigGfxInfo.DrawClr) + "     " +  "\n" ;
}
string CLine::gettype()
{ return "LINE";}

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLine to draw a rectangle on the screen	
	pOut->DRAW_LINE(Corner1, Corner2,FigGfxInfo,CFigure::IsSelected());
}