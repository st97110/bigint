//接受輸入兩個vector<char>,前者為底數後者為次方,回傳vector<char>
//底數支援小數,次方目前還沒辦法支援小數
//使用方法:power(底數,次方);
#pragma once
#include<string>
#include <iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
//計算次方的程式
vector<char> calculate(vector<char> n1, vector<char> n2) {
	int count = 0;
	vector<char> mul = n1;
	while (n2.empty() != true) {
		//下面這坨在算執行乘法的次數

		if (n2[n2.size() - 1] >= '1' && n2[n2.size() - 1] <= '9') {
			n2[n2.size() - 1] = n2[n2.size() - 1] - 1;
		}
		else if (n2.size() != 1) {
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
		//這邊進行次方運算
		if (n2.size() != 0 && count > 0) {
			//count++;
			vector<int> ans(n1.size() + mul.size(), 0);
			for (int i = 0;i < n1.size();i++) {
				for (int j = 0;j < mul.size();j++) {
					ans[i + j + 1] += (n1[i] - '0') * (mul[j] - '0');
				}
			}
			for (int i = ans.size() - 1;i > 0;i--) {
				if (ans[i] >= 10) {
					ans[i - 1] += ans[i] / 10;
					ans[i] %= 10;
				}
			}
			n1.clear();
			for (int i = 0;i < ans.size();i++) {
				if (ans[i] == 0) {
					ans.erase(ans.begin());
					i -= 1;
				}
				else {
					break;
				}
			}
			for (int i = 0;i < ans.size();i++) {
				n1.push_back(ans[i] + '0');
			}
			ans.clear();
		}
		else {
			count++;
		}


	}

	//std::cout << count << endl;
	return n1;
}
vector<char> power(vector<char> n1, vector<char> n2) {
	bool smallnum = false;
	int smallpointpos;
	for (int i = n1.size() - 1;i >= 0;i--) {
		if (n1[i] == '.') {
			smallnum = true;
			smallpointpos = n1.size() - i - 1;
			n1.erase(n1.begin() + i);
		}
	}
	//如果是0直接傳回1
	if (n2[0] == '0') {
		n1.clear();
		n1.push_back('1');
	}
	//如果底數有小數點,先拔掉小數點,次方搞完再放回去
	else if (smallnum) {

		int self = smallpointpos;
		int count = 0;
		n1 = calculate(n1, n2);
		while (n2.empty() != true) {
			//下面這坨在算小數點要放哪裡
			if (n2[n2.size() - 1] >= '1' && n2[n2.size() - 1] <= '9') {
				n2[n2.size() - 1] = n2[n2.size() - 1] - 1;
			}
			else if (n2.size() != 1) {
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

			if (n2.size() != 0 && count > 0) {
				smallpointpos += self;
			}
			else {
				count++;
			}
		}
		n1.insert(n1.end() - smallpointpos, '.');
	}
	else {
		n1 = calculate(n1, n2);
	}
	return n1;
}
