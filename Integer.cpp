#include "Integer.h"
#include "Decimal.h"
using namespace std;
//Constructor
Integer::Integer() : Number()
{
	intAns = getInt();
}
Integer::Integer(const char* input) : Number(input)
{
	intAns = getInt();
}
Integer::~Integer() {}

void Integer::assign() // 繼承number
{
	intAns = getInt();
}

string Integer::getAns()const
{
	return intAns;
}

newString Integer::getFrac()const
{
	return ans;
}

string Integer::getInput()const
{
	return input;
}

void Integer::print(ostream& out) const // 繼承number
{
	string ret = intAns;
	out << ret;
}

Integer& Integer::operator=(Integer& r)
{
	errorTyep = r.errorTyep;
	ans = r.ans;
	input = r.input;
	assign();
	return *this;
}

Integer& Integer::operator=(Decimal& r)
{
	errorTyep = r.errorTyep;
	//ans = r.getFrac();     ///////////////////////////////
	//input = r.getInput();
	assign();
	return *this;
}

Integer& Integer::operator=(string& r)
{
	setInput(r);
	inToPostfix();
	computInput();
	assign();
	return *this;
}

Integer operator+(Integer& left, Integer& right)
{
	Integer ret;
	ret.setInput(left.getInt() + '+' + right.getInt());
	ret.inToPostfix();
	ret.computInput();
	ret.assign();
	return ret;
}

Integer operator-(Integer& left, Integer& right)
{
	Integer ret;
	ret.setInput(left.getInt() + '-' + right.getInt());
	ret.inToPostfix();
	ret.computInput();
	ret.assign();
	return ret;
}

Integer operator*(Integer& left, Integer& right)
{
	Integer ret;
	ret.setInput(left.getInt() + '*' + right.getInt());
	ret.inToPostfix();
	ret.computInput();
	ret.assign();
	return ret;
}

Integer operator/(Integer& left, Integer& right)
{
	Integer ret;
	ret.setInput(left.getInt() + '/' + right.getInt());
	ret.inToPostfix();
	ret.computInput();
	ret.assign();
	return ret;
}

Integer operator+(Integer& left, Decimal& right)
{
	Integer ret;
	ret.setInput(left.getInt() + '+' + right.getDec());
	ret.inToPostfix();
	ret.computInput();
	ret.assign();
	return ret;
}

Integer operator-(Integer& left, Decimal& right)
{
	Integer ret;
	ret.setInput(left.getInt() + '-' + right.getDec());
	ret.inToPostfix();
	ret.computInput();
	ret.assign();
	return ret;
}

Integer operator*(Integer& left, Decimal& right)
{
	Integer ret;
	ret.setInput(left.getInt() + '*' + right.getDec());
	ret.inToPostfix();
	ret.computInput();
	ret.assign();
	return ret;
}

Integer operator/(Integer& left, Decimal& right)
{
	Integer ret;
	ret.setInput(left.getInt() + '/' + right.getDec());
	ret.inToPostfix();
	ret.computInput();
	ret.assign();
	return ret;
}
