#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

const int priority[] = { 0,1,2,3,4,5 };
//優先順序 括號5(直到遇反括號才輸出) > 負號4 > 階乘3 > 次方2 > 乘、除1 > 加、減0
//使用迴圈，取出中序式的字元，遇運算元直接輸出；堆疊運算子與左括號
//堆疊中運算子優先順序若大於等於讀入的運算子優先順序的話，直接輸出堆疊中的運算子，再將讀入的運算子置入堆疊；
//遇右括號輸出堆疊中的運算子至左括號。

struct newString
{
	bool sign = true; // 預設為正數
	bool decimal = false; // 預設為不是小數

	string num; // 把struct當string用，還可以把負號拿掉
	string numerator = "0";	// 分子
	string denominator = "0"; // 分母
};

class Number
{
public:
	Number();
	Number(string);
	~Number();

	string input; // 存輸入字串(無空格 '#'代表負號)
	vector<string> postfix; // 存後序式
	int errorTyep = -1; //錯誤編號
	newString ans;
	string getInt();

	void setInput(const string&); // 輸入數學式
	void inToPostfix(); // 中序轉後序
	void computInput(); // 運算後序式  判斷要呼叫整數還是小數做運算
	newString checkDecimal(string); // 把string轉成新型態

	void changeSign(newString&); // 加負號
	newString add(newString, newString); // 大數加法
	newString sub(newString, newString); // 大數減法
	newString mul(newString, newString); // 大數乘法	
	newString div(newString, newString); // 大數除法	
	newString fac(newString); // 大數階乘	
	newString pow(newString, newString); // 大數次方
	newString root(newString, newString); // 大數開根號

	string fracAdd(newString, newString); //分數加法
};
#include "Integer.h"
#include "Decimal.h"
