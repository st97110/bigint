#include "Integer.h"
#include "Decimal.h"
using namespace std;
//Constructor
Integer::Integer() : Number()
{
	ans = "0";
}
Integer::Integer(const char* input) : Number(input)
{
	ans = getInt();
}
Integer::~Integer() {}

void Integer::assign() // 繼承number
{
	ans = getInt();
}

void Integer::print(ostream& out) const // 繼承number
{
	string ret = ans;
	out << ret;
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
