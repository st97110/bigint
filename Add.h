//接受輸入兩個vector<char>,回傳vector<char>
//為[整數]的加法運算
//使用方法:add(被加數,加數);
#pragma once
#include<string>
#include <iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<char> add(vector<char> n1,vector<char> n2) {
	vector<int>num1;
	vector<int>num2;
	for (int i = n1.size() - 1;i >= 0;i--) {
		num1.push_back(n1[i]-'0');
	}
	for (int i = n2.size() - 1;i >= 0;i--) {
		num2.push_back(n2[i]-'0');
	}
	if (num1.size() >= num2.size()) {
		for (int i = 0;i < num2.size();i++){
			num1[i] += num2[i];
			if (num1[i] >= 10&&i!=num1.size()-1) {
				num1[i + 1] += 1;
				num1[i] %= 10;
			}
		}
		for (int i = 0;i < num1.size();i++) {
			if (num1[i] >= 10&&i!=num1.size()-1) {
				num1[i + 1] += 1;
				num1[i] %= 10;
			}
		}
		if (num1[num1.size() - 1] >= 10) {
			num1[num1.size() - 1] -= 10;
			num1.push_back(1);
		}
		n1.clear();
		for (int i = num1.size() - 1;i >= 0;i--) {
			n1.push_back(num1[i] + '0');
		}
	}
	else if(num2.size()>num1.size()){
		for (int i = 0;i < num1.size();i++) {
			num2[i] += num1[i];
			if (num2[i] >= 10) {
				num2[i + 1] += 1;
				num2[i] %= 10;
			}
		}
		for (int i = 0;i < num2.size();i++) {
			if (num2[i] >= 10 && i != num2.size() - 1) {
				num2[i + 1] += 1;
				num2[i] %= 10;
			}
		}
		if (num2[num2.size() - 1] >= 10) {
			num2[num2.size() - 1] -= 10;
			num2.push_back(1);
		}
		n1.clear();
		for (int i = num2.size() - 1;i >= 0;i--) {
			n1.push_back(num2[i] + '0');
		}
	}
	return n1;
}