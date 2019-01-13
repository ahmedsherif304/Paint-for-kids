#ifndef CTRI_H
#define CTRI_H
#include<iostream>
using namespace std;
#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	int ID2;
	int IDPaste;
	Point Corner1;	
	Point Corner2;
	Point Corner3;

public:

	CTriangle(Point , Point, Point , GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool IsHere(Point p);
	float getArea(Point ,Point,Point);
	void PrintInfo(Output* pOut);
	Point Get_Center();
	Point Get_Corner1();
	Point Get_Corner2();
	Point Get_Corner3();
	virtual void Load(ifstream &Infile);
	virtual string gettype();
	virtual void Save(ofstream &OutFile);
	int getID();
};

#endif