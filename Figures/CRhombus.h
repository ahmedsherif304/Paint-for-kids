#ifndef CRHOMBUS_H
#define CRHOMBUS_H
#include<iostream>
using namespace std;
#include "CFigure.h"

class CRhombus : public CFigure
{
private:
	int ID2;
	int IDPaste;
	Point Corner1;	
	
public:
	CRhombus(Point , GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	bool IsHere(Point p);
	float getArea(Point ,Point ,Point ,Point );
	float getArea1(Point,Point,Point);
	int getID();
	void Save(ofstream &OutFile);
	virtual string gettype();
	void Load(ifstream &Infile);
	void PrintInfo(Output* pOut);
};

#endif