#include "Number.h"
int main()
{
	Number f("000020.0012123002");
	cout << f.printAns() << endl;

	cout << "0.";
	for (int i = 0; i < 100; i++)
	{
		cout << "0";
	}
	Integer A = "---3";
	vector<Number*> nums;
	nums.push_back(&A);
	for(const auto & num : nums)
		cout << *num << endl;

	cout << "Command : Set (Int/Dec/Com) / Print / Assign / Pow / Fac / or any expression." << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	while (1)
	{
		string in, order;
		getline(cin, in);
		Number k(in);
		cout <<  endl << k.ans.numerator << endl << "=============================================================================" << endl;
	}
	return 0;
}
