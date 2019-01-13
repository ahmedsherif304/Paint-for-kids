#ifndef CLINE_H
#define CLINE_H
#include<iostream>
using namespace std;
#include "CFigure.h"

class CLine: public CFigure
{private:
	int ID2;
	int IDPaste;
	Point Corner1;	
	Point Corner2;
public:
	CLine(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool IsHere(Point p);
	Point Get_Mid();
	Point Get_Corner_1();
	Point Get_Corner_2();
	int getID();
	void Save(ofstream &OutFile);
	virtual string gettype();
	void Load(ifstream &Infile);
	void PrintInfo(Output* pOut);
};
#endif