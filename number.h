#ifndef NUMBER_H
#define NUMBER_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

const int priority[] = { 0,1,2,3,4,5,6 };
//優先順序 括號6(直到遇反括號才輸出) > 負號5 > 虛部(i)4 > 階乘3 > 次方2 > 乘、除1 > 加、減0
//使用迴圈，取出中序式的字元，遇運算元直接輸出；堆疊運算子與左括號
//堆疊中運算子優先順序若大於等於讀入的運算子優先順序的話，直接輸出堆疊中的運算子，再將讀入的運算子置入堆疊；
//遇右括號輸出堆疊中的運算子至左括號。
class Number
{
public:
	Number() {}
	Number(string);
	~Number() {}

	int errorTyep = -1; //錯誤編號
	void setInput(const string&); // 輸入數學式
	void inToPostfix(char*, char*); // 中序轉後序
	void computInput(); // 運算後序式  判斷要呼叫整數還是小數做運算

	string input; // 存輸入字串(無空格 '#'代表負號)
};
#include "Integer.h"
#include "Decimal.h"
#endif // !NUMBER_H
