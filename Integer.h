#pragma once
#include "Number.h"
class Integer : public Number
{
public:
	Integer();
	Integer(string);
	~Integer();

	Integer& operator=(Integer&);
	Integer& operator=(std::string&);

	friend Integer Power(Integer& left, Integer& right);
	friend Integer Power(Integer& left, std::string& right);
	friend Integer operator+(Integer&, Integer&);
	friend Integer operator-(Integer&, Integer&);
	friend Integer operator*(Integer&, Integer&);
	friend Integer operator/(Integer&, Integer&);
	friend Integer Factorial(Integer& a);
	friend Integer Factorial(std::string& a);

	std::string ans;
};
