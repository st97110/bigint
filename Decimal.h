#pragma once
#include "Number.h"
class Integer;
class Decimal : public Number
{
public:
	Decimal();
	Decimal(const char*);
	~Decimal();

	string getAns()const; // 繼承
	newString getFrac()const; // 繼承
	string getInput()const; // 繼承
	virtual void assign(); // 繼承
	virtual void print(ostream&)const; // 繼承

	Decimal& operator=(Integer&);
	Decimal& operator=(Decimal&);
	Decimal& operator=(string&);
	
	friend Decimal operator+(Decimal&, Integer&); // PI + A
	friend Decimal operator-(Decimal&, Integer&); // PI - A
	friend Decimal operator*(Decimal&, Integer&); // PI * A
	friend Decimal operator/(Decimal&, Integer&); // PI / A
	
	friend Decimal operator+(Decimal&, Decimal&); // PI + PI
	friend Decimal operator-(Decimal&, Decimal&); // PI - PI
	friend Decimal operator*(Decimal&, Decimal&); // PI * PI
	friend Decimal operator/(Decimal&, Decimal&); // PI / PI

	string decAns;
};
