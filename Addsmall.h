//������J���vector<char>,�^��vector<char>
//��[�t�p��]���[�k�B��,�i�����䤤�@��Ƥ@�p�Ƭۥ[,�M��ڰ���̫�o�{�o�ӪF��]��䴩��ƥ[���= =
//�аt�X"Add.h"�ϥ�
//�ϥΤ�k:addsmall(�Q�[��,�[��);
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
	//�Υ|��vector�s��Ƹ�p�Ƴ���
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
	//��Ƴ����ۥ[
	n1 = add(int1, int2);
	//�����p�Ƴ̤j���,�p�G���i��,��ƭn���B�z
	int len = biglen(s1, s2);
	//����Ӥp�Ʀ�Ƥ@��,��K�B��
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
	//�p�ƶi��W�L���,��ư��B�z
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
	//�q�̫�@��Ʀ^��,�N�����n��0����
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