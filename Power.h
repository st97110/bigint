//������J���vector<char>,�e�̬����ƫ�̬�����,�^��vector<char>
//���Ƥ䴩�p��,����ثe�٨S��k�䴩�p��
//�ϥΤ�k:power(����,����);
#pragma once
#include<string>
#include <iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
//�p�⦸�誺�{��
vector<char> calculate(vector<char> n1, vector<char> n2) {
	int count = 0;
	vector<char> mul = n1;
	while (n2.empty() != true) {
		//�U���o�@�b����歼�k������

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
		//�o��i�榸��B��
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
	//�p�G�O0�����Ǧ^1
	if (n2[0] == '0') {
		n1.clear();
		n1.push_back('1');
	}
	//�p�G���Ʀ��p���I,���ޱ��p���I,����d���A��^�h
	else if (smallnum) {

		int self = smallpointpos;
		int count = 0;
		n1 = calculate(n1, n2);
		while (n2.empty() != true) {
			//�U���o�@�b��p���I�n�����
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
