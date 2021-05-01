#include "Integer.h"
#include "Decimal.h"
using namespace std;
//Constructor
Integer::Integer() : Number()
{
	ans = "0";
}
Integer::Integer(string input):Number(input)
{
	ans = getInt();
}
Integer::~Integer() {}

void Integer::assign()
{
	ans = getInt();
}

Integer& Integer::operator=(string& r)
{
	setInput(r);
	computInput();
	assign();
	return *this;
}

Integer operator+(Integer& left, Integer& right)
{
	Integer ret;
	ret.setInput(left.ans + '+' + right.ans);
	ret.computInput();
	ret.assign();
	return ret;
}
