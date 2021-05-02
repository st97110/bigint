#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

const int priority[] = { 0,1,2,3,4,5 };
//優先順序 括號5(直到遇反括號才輸出) > 負號4 > 階乘3 > 次方2 > 乘、除1 > 加、減0
//使用迴圈，取出中序式的字元，遇運算元直接輸出；堆疊運算子與左括號
//堆疊中運算子優先順序若大於等於讀入的運算子優先順序的話，直接輸出堆疊中的運算子，再將讀入的運算子置入堆疊；
//遇右括號輸出堆疊中的運算子至左括號。

struct newString
{
	bool sign = true; // 預設為true 是正數
	bool decimal = false; // 預設為不是小數

	string numerator = "1";	// 分子 沒有正負號
	string denominator = "1"; // 分母
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
	newString ans; // 最終答案
	

	virtual void assign();
	virtual void print(std::ostream&)const;

	friend std::ostream& operator<<(std::ostream& outputStream, const Number&); //輸出
	friend std::istream& operator>> (std::istream& inputStream, Number&); //輸入

	void setInput(const string&); // 輸入數學式
	void inToPostfix(); // 中序轉後序
	void computInput(); // 運算後序式  判斷要呼叫整數還是小數做運算
	newString checkDecimal(string); // 把string轉成新型態
	string getInt();
	string getDec();
	string get110Dec(newString);
	string get100Dec(newString);
	string printAns();//輸出答案(含防呆)	

	void changeSign(newString&); // 加負號
	newString add(newString, newString); // 大數加法
	newString sub(newString, newString); // 大數減法
	newString mul(newString, newString); // 大數乘法	
	newString div(newString, newString); // 大數除法	
	newString fac(newString); // 大數階乘	
	newString pow(newString, newString); // 大數次方

	string intAdd(string, string); // 整數加法	
	string intSub(string, string); // 整數減法
	string intMul(string, string); // 整數乘法
	string intDiv(string, string); // 整數除法
	string intPow(string, string); // 整數次方
	int intCmp(string, string); //整數比較

	string fracAdd(newString, newString); // 分數加法
	string fracSub(newString, newString); // 分數減法
	string fracMul(string, string); // 分數乘法


	newString fracRoot(newString, bool); // 開根號
	newString about(newString); // 約分
	string gcd(string, string); // 取最大公因數	
	string mod(string, string); // 取餘數
};
#include "Integer.h"
#include "Decimal.h"
