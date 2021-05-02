#pragma once
#include "Number.h"
class Decimal;
class Integer : public Number
{
public:
	Integer();
	Integer(const char*);
	~Integer();

	virtual void assign(); // 繼承
	virtual void print(ostream&)const; // 繼承
	//Integer& operator=(Integer&); // A = 48763000 B = A
	Integer& operator=(string&); // A = 487630000

	friend Integer operator+(Integer&, Integer&); // A + B
	//friend Integer operator-(Integer&, Integer&); // A - B
	//friend Integer operator*(Integer&, Integer&); // A * B
	//friend Integer operator/(Integer&, Integer&); // A / B
	//
	//friend Integer operator+(Integer&, string& right); // A + 3
	//friend Integer operator-(Integer&, string& right); // A - 3
	//friend Integer operator*(Integer&, string& right); // A * 3
	//friend Integer operator/(Integer&, string& right); // A / 3

	//friend Integer operator+(string& right, Integer&); // 3 + A
	//friend Integer operator-(string& right, Integer&); // 3 - A
	//friend Integer operator*(string& right, Integer&); // 3 * A
	//friend Integer operator/(string& right, Integer&); // 3 / A		

	//friend Integer Power(Integer& left, Integer& right); // A ^ B
	//friend Integer Power(Integer& left, string& right); // A ^ 3
	//friend Integer Power(Integer& left, string& right); // 3 ^ A

	//friend Integer Factorial(Integer& a); // A!
	//friend Integer Factorial(string& a); // 5!  3.14! 小數階乘報錯

	string ans; // 答案
};
