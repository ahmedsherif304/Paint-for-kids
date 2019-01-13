#ifndef CRECT_H
#define CRECT_H
#include<iostream>
#include <cmath>
using namespace std;
#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	int ID2;
	int IDPaste;
	Point Corner1;	
	Point Corner2;
public:
	static int count;
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool IsHere(Point p);
	float Get_Length();
	float Get_Width();
	int getID();
	void Save(ofstream &OutFile);
	virtual string gettype();
	void Load(ifstream &Infile);
	void PrintInfo(Output* pOut);
};
#endif