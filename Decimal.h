#pragma once
#include "Number.h"
class Integer;
class Decimal : public Number
{
public:
	Decimal();
	Decimal(string);
	~Decimal();

	Decimal& operator=(Decimal&);
	Decimal& operator=(string&);

	// A = 3 
	// PI = 3.14
	friend Decimal operator+(Integer&, Decimal&); // A + PI
	friend Decimal operator+(Decimal&, Integer&); // PI + A
	friend Decimal operator+(Decimal&, Decimal&); // PI + PI
	friend Decimal operator+(Decimal&, string& right); // PI + 3
	friend Decimal operator+(string& right, Decimal&); // 3 + PI

	friend Decimal operator-(Integer&, Decimal&); // A - PI
	friend Decimal operator-(Decimal&, Integer&); // PI - A
	friend Decimal operator-(Decimal&, Decimal&); // PI - PI
	friend Decimal operator-(Decimal&, string& right); // PI - 3
	friend Decimal operator-(string& right, Decimal&); // 3 - PI

	friend Decimal operator*(Integer&, Decimal&); // A * PI
	friend Decimal operator*(Decimal&, Integer&); // PI * A
	friend Decimal operator*(Decimal&, Decimal&); // PI * PI
	friend Decimal operator*(Decimal&, string& right); // PI * 3
	friend Decimal operator*(string& right, Decimal&); // 3 * PI

	friend Decimal operator/(Integer&, Decimal&); // A / PI
	friend Decimal operator/(Decimal&, Integer&); // PI / A
	friend Decimal operator/(Decimal&, Decimal&); // PI / PI
	friend Decimal operator/(Decimal&, string& right); // PI / 3
	friend Decimal operator/(string& right, Decimal&); // 3 / PI

	friend Decimal Power(Integer& left, Decimal& right); // A^PI 非0.5次方報錯
	friend Decimal Power(Decimal& left, Integer& right); // PI^A
	friend Decimal Power(Decimal& left, Decimal& right); // PI^PI 非0.5次方報錯
	friend Decimal Power(string& left, string& right); // 2.5^123 裡面判斷型態，非0.5次方報錯

	friend Decimal Factorial(Decimal& a); // PI! // 1.000 可以  1.0001 不行

	string ans;
};
