#include "CRhombus.h"
#include <fstream>
#include <istream>



CRhombus::CRhombus(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	ID2=++ID;
	IDPaste=3;
}
float CRhombus::getArea(Point a,Point b,Point c,Point d){
return (abs(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))/2)+(abs(a.x*(d.y-c.y)+d.x*(c.y-a.y)+c.x*(a.y-d.y))/2);
}
float CRhombus::getArea1(Point a,Point b,Point c){
return abs(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))/2;
}
bool CRhombus::IsHere(Point p){
		Point p1,p2,p3,p4;
		p1.x=Corner1.x;  p1.y=Corner1.y+100;
		p2.x=Corner1.x+50;  p2.y=Corner1.y;
		p3.x=Corner1.x;  p3.y=Corner1.y-100;
		p4.x=Corner1.x-50;  p4.y=Corner1.y;
		float a=getArea(p1,p2,p3,p4);
		float b=getArea1(p,p2,p1);
		float c=getArea1(p,p2,p3);
		float d=getArea1(p,p4,p3);
		float e=getArea1(p,p4,p1);
		//if(((p.x>=Corner1.x-50)&&(p.x<=Corner1.x+50))&&((p.y<=Corner1.y+100)&&(p.y>=Corner1.y-100)))
		if(a==b+c+d+e)
		return true;
return false;}

void CRhombus::PrintInfo(Output* pOut){
		Point p1,p2,p3,p4;
		p1.x=Corner1.x;  p1.y=Corner1.y+100;
		p2.x=Corner1.x+50;  p2.y=Corner1.y;
		p3.x=Corner1.x;  p3.y=Corner1.y-100;
		p4.x=Corner1.x-50;  p4.y=Corner1.y;
		string z=to_string(ID2);
		string a=to_string(Corner1.x);
		string b=to_string(Corner1.y);
		string e=to_string(abs(Corner1.x));
		string f=to_string(abs(Corner1.y));
		string g=to_string(getArea(p1,p2,p3,p4));
		pOut->PrintMessage("Rhombus , ID = "+z+", Center Point :("+a+","+b+") Area ="+g);
}
void CRhombus::Load(ifstream &Infile)
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
	CFigure::FigGfxInfo = info; ;


}
void CRhombus::Save(ofstream &Outfile)
{
	string filled;   if(FigGfxInfo.isFilled){ filled= getcolor(FigGfxInfo.FillClr);} else { filled = "NO_FILL";}
	Outfile << "RHOMBUS   " + to_string(ID2) 
		+ "   " + to_string(Corner1.x) + "    " + to_string(Corner1.y) + "    " 
		+ getcolor(FigGfxInfo.DrawClr) + "     " +  filled + "\n";
}

string CRhombus::gettype()
{return "RHOMBUS";}
int CRhombus::getID(){return IDPaste;}
void CRhombus::Draw(Output* pOut) const
{	
	pOut->DrawRhombus(Corner1, FigGfxInfo, Selected);
}