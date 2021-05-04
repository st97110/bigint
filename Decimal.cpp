#include "Decimal.h"
#include "Integer.h"
using namespace std;
//Constructor
Decimal::Decimal() :Number()
{
	decAns = getDec();
}
Decimal::Decimal(const char* input) : Number(input)
{
	decAns = getDec();
}
Decimal::~Decimal() {}

string Decimal::getAns() const
{
	return decAns;
}

newString Decimal::getFrac()const
{
	return ans;
}

string Decimal::getInput()const
{
	return input;
}

void Decimal::assign()
{
	decAns = getDec();
}

void Decimal::print(ostream& out)const
{
	string ret = decAns;
	out << ret;
}

Decimal& Decimal::operator=(Integer& r)
{
	errorTyep = r.errorTyep;
	ans = r.getReal();
	input = r.getInput();
	assign();
	return *this;
}

Decimal& Decimal::operator=(Decimal& r)
{
	errorTyep = r.errorTyep;
	ans = r.ans;
	input = r.input;
	assign();
	return *this;
}

Decimal& Decimal::operator=(string& r)
{
	if (input == r)
		return *this;
	setInput(r);
	computInput();
	assign();
	return *this;
}

Decimal operator+(Decimal& left, Integer& right)
{
	Decimal ret;
	ret.setInput(left.getDec() + '+' + right.getInt());
	ret.inToPostfix();
	ret.computInput();
	ret.assign();
	return ret;
}

Decimal operator-(Decimal& left, Integer& right)
{
	Decimal ret;
	ret.setInput(left.getDec() + '-' + right.getInt());
	ret.inToPostfix();
	ret.computInput();
	ret.assign();
	return ret;
}

Decimal operator*(Decimal& left, Integer& right)
{
	Decimal ret;
	ret.setInput(left.getDec() + '*' + right.getInt());
	ret.inToPostfix();
	ret.computInput();
	ret.assign();
	return ret;
}

Decimal operator/(Decimal& left, Integer& right)
{
	Decimal ret;
	ret.setInput(left.getDec() + '/' + right.getInt());
	ret.inToPostfix();
	ret.computInput();
	ret.assign();
	return ret;
}

Decimal operator+(Decimal& left, Decimal& right)
{
	Decimal ret;
	ret.ans = ret.add(left.getReal(), right.getReal());
	ret.assign();
	return ret;
}

Decimal operator-(Decimal& left, Decimal& right)
{
	Decimal ret;
	ret.ans = ret.sub(left.getReal(), right.getReal());
	ret.assign();
	return ret;
}

Decimal operator*(Decimal& left, Decimal& right)
{
	Decimal ret;
	ret.ans = ret.mul(left.getReal(), right.getReal());
	ret.assign();
	return ret;
}

Decimal operator/(Decimal& left, Decimal& right)
{
	Decimal ret;
	ret.ans = ret.div(left.getReal(), right.getReal());
	ret.assign();
	return ret;
}
