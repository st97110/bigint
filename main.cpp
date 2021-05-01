#include "Number.h"
int main()
{
	cout << "Command : Set (Int/Dec/Com) / Print / Assign / Pow / Fac / or any expression." << endl;
	cout << "-----------------------------------------------------------------------------" << endl;
	while (1)
	{
		string in, order;
		getline(cin, in);
		Number k(in);
		cout << "=============================================================================" << endl;
	}
	return 0;
}
