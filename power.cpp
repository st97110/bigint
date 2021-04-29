#include<string>
#include <iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<char> power(vector<char> n1,vector<char> n2) {
	int count=0;
	vector<char> mul = n1;
	while (n2.empty() != true) {
		//下面這坨在算執行乘法的次數
		
		if (n2[n2.size() - 1] >= '1' && n2[n2.size() - 1] <= '9') {
			n2[n2.size() - 1] = n2[n2.size() - 1]  - 1;
		}
		else if(n2.size()!=1){
			n2[n2.size() - 1] = '9';
			for (int i = n2.size() - 2;i >= 0;i--) {
				if (n2[i] >= '1') {
					n2[i] -= 1;
					for (int j = i + 1;j < n2.size();j++) {
						n2[j] = '9';
					}
					if (n2[0] == '0')n2.erase(n2.begin());
					break;
				}
			}
		}
		else if (n2[n2.size() - 1] == '0' && n2.size() == 1) {
			n2.clear();
		}
		
		if (n2.size() != 0&&count>0) {
			//count++;
			vector<int> ans(n1.size() + mul.size(), 0);
			for (int i = 0;i < n1.size();i++) {
				for (int j = 0;j<mul.size();j++) {
					ans[i + j + 1] += (n1[i]-'0') * (mul[j]-'0');
				}
			}
			for (int i = ans.size() - 1;i > 0;i--) {
				if (ans[i] >=10) {
					ans[i - 1] += ans[i] / 10;
					ans[i] %= 10;
				}
			}
			n1.clear();
			for (int i = 0;i < ans.size() ;i++) {
				if (ans[i] == 0) {
					ans.erase(ans.begin());
					i -= 1;
				}
				else {
					break;
				}
			}
			for (int i = 0;i < ans.size() ;i++) {
				n1.push_back(ans[i] + '0');
			}
			ans.clear();
		}
		else {
			count++;
		}
		
		
	}
	for (int i = 0;i < n1.size();i++)std::cout << n1[i];
	std::cout << endl;
 	//std::cout << count << endl;
	return n1;
}
int main()
{
	string num1,num2;
	while (1) {
		cout << "輸入數字:";
		cin >> num1;
		cout << endl;
		cout << "輸入冪次:";
		cin >> num2;
		cout << endl;
		vector<char> n1;
		vector<char> n2;
		for (int i = 0;i < num1.length(); i++) {
			n1.push_back(num1[i]);
		}for (int i = 0;i < num2.length(); i++) {
			n2.push_back(num2[i]);
		}
		if (num2 == "0") {
			cout << 1 << endl;
		}
		else
			power(n1, n2);
	}
}
