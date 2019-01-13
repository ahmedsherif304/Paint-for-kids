#include "CTriangle.h"
#include <fstream>
#include <istream>
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	ID2=++ID;
	IDPaste=4;
}
float CTriangle::getArea(Point a,Point b,Point c){
return float(abs((b.x*c.y-b.y*c.x)-(a.x*c.y-a.y*c.x)+(a.x*b.y-a.y*b.x)))/2;
}
bool CTriangle::IsHere(Point p){float Area=getArea(Corner1,Corner2,Corner3);
float a1=getArea(p,Corner1,Corner2);
float a2=getArea(p,Corner1,Corner3);
float a3=getArea(p,Corner2,Corner3);
if(a1+a2+a3==Area)	return true;
return false;
}
void CTriangle::Load(ifstream &Infile)
{
	int id;
	Infile >> id;
	Infile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y;
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

void CTriangle::Save(ofstream &Outfile){
	string filled;   if(FigGfxInfo.isFilled){ filled= getcolor(FigGfxInfo.FillClr);} else { filled = "NO_FILL";}
	Outfile << "TRIANGLE   " + to_string(ID2) 
		+ "   " + to_string(Corner1.x) + "    " + to_string(Corner1.y) + "    " 
		+ "   " + to_string(Corner2.x) + "    " + to_string(Corner2.y) + "    " 
		+ "   " + to_string(Corner3.x) + "    " + to_string(Corner3.y) + "    " 
		+ getcolor(FigGfxInfo.DrawClr) + "     " +  filled + "\n";
}
string CTriangle::gettype()
{return "TRIANGLE";}
Point CTriangle:: Get_Center()
{
 Point C;
	C.x=(float(Corner1.x + Corner2.x +  Corner3.x)/3);
	C.y=(float(Corner1.y + Corner2.y +  Corner3.y)/3);
	return C;
}

Point CTriangle:: Get_Corner1()
{
	return Corner1;
}

	Point CTriangle:: Get_Corner2()
	{
		return Corner2;
	}

	Point CTriangle:: Get_Corner3()
	{
		return Corner3;
	}


	void CTriangle::PrintInfo(Output* pOut){
	string z=to_string(ID2);
	string a=to_string(Corner1.x);
	string b=to_string(Corner1.y);
	string c=to_string(Corner2.x);
	string d=to_string(Corner2.y);
	string e=to_string(Corner3.x);
	string f=to_string(Corner3.y);
	string g=to_string(getArea(Corner1,Corner2,Corner3));
	pOut->PrintMessage("Triangle, ID = "+z+", First point :("+a+","+b+")    Second point ("+c+","+d+")  Third point ("+e+","+f+")  The area ="+g);
}

int CTriangle::getID(){return IDPaste;}
void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a triangle on the screen	
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}