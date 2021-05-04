#pragma once
#include "Number.h"
class Decimal;
class Integer : public Number
{
public:
	Integer();
	Integer(const char*);
	~Integer();

	string getAns()const; // 繼承
	newString getFrac()const; // 繼承
	string getInput()const; // 繼承
	virtual void assign(); // 繼承
	virtual void print(ostream&)const; // 繼承

	Integer& operator=(Integer& rhs);
	Integer& operator=(Decimal& rhs);
	Integer& operator=(string& rhs);

	friend Integer operator+(Integer&, Integer&); // A + B
	friend Integer operator-(Integer&, Integer&); // A - B
	friend Integer operator*(Integer&, Integer&); // A * B
	friend Integer operator/(Integer&, Integer&); // A / B

	friend Integer operator+(Integer&, Decimal&); // A + PI
	friend Integer operator-(Integer&, Decimal&); // A - PI
	friend Integer operator*(Integer&, Decimal&); // A * PI
	friend Integer operator/(Integer&, Decimal&); // A / PI

	string intAns; // 答案
};
