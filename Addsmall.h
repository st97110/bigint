//钡块ㄢvector<char>,肚vector<char>
//[计]猭笲衡,钡ㄤい俱计计,礛и暗程祇瞷硂狥﹁や穿俱计俱计= =
//叫皌"Add.h"ㄏノ
//ㄏノよ猭:addsmall(砆计,计);
#pragma once
#include "Add.h"
#include<string>
#include <iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
int biglen(vector<char>n1, vector<char>n2) {
	if (n1.size() >= n2.size()) return n1.size();
	else return n2.size();
}
vector<char> addsmall(vector<char> n1, vector<char> n2) {
	int i;
	//ノvector俱计蛤计场だ
	vector<char> int1;
	vector<char> int2;
	vector<char> s1;
	vector<char> s2;
	s1.push_back('0');
	s2.push_back('0');
	int flag = 0;
	for (i = 0;i < n1.size();i++) {
		if (n1[i] == '.') {
			flag = 1;
			s1.clear();
			i++;
		}
		if (flag == 0) {
			int1.push_back(n1[i]);
		}
		else {
			s1.push_back(n1[i]);
		}
	}
	flag = 0;
	for (i = 0;i < n2.size();i++) {
		if (n2[i] == '.') {
			s2.clear();
			flag = 1;
			i++;
		}
		if (flag == 0) {
			int2.push_back(n2[i]);
		}
		else {
			s2.push_back(n2[i]);
		}
	}
	//俱计场だ
	n1 = add(int1, int2);
	//魁计程计,狦Τ秈,俱计璶暗矪瞶
	int len = biglen(s1, s2);
	//琵ㄢ计计妓,よ獽笲衡
	if (s1.size() > s2.size()) {
		int size = s1.size() - s2.size();
		for (int i = 0;i < size;i++) {
			s2.push_back('0');
		}
	}
	else if (s2.size() > s1.size()) {
		int size = s2.size() - s1.size();
		for (int i = 0;i < size;i++) {
			s1.push_back('0');
		}
	}
	n2 = add(s1, s2);
	//计秈禬筁计,俱计暗矪瞶
	if (n2.size() > len) {
		vector<char> t;
		t.push_back(n2[0]);
		n2.erase(n2.begin());
		n1 = add(n1, t);
	}
	n1.push_back('.');
	for (int i = 0;i < n2.size();i++) {
		n1.push_back(n2[i]);
	}
	//眖程计ㄓ,盢ぃゲ璶0奔
	for (int i = n1.size() - 1;i >= 0;i--) {
		if (n1[i] == '0')n1.pop_back();
		else if (n1[i] == '.') {
			n1.pop_back();
			break;
		}
		else {
			break;
		}
	}
	return n1;
}