#include <iostream>
#include <sstream>
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
	Number();
	Number(std::string);
	~Number();

	std::string name;//存變數名稱
	int errorTyep = -1;//錯誤編號
	void setInput(const std::string&);//輸入數學式	
	void computInput();//運算					
	std::string printAns();//輸出答案(含防呆)	
	std::string getInt();
	std::string getDec();

	virtual void assign();
	virtual void print(std::ostream&)const;

	friend std::ostream& operator<<(std::ostream& outputStream, const Number&); //輸出	
	friend std::istream& operator>> (std::istream& inputStream, Number&); //輸入			

	//整數↓
	std::string getRoot120(std::string);//取得一整數開根號至小數點後150位		
	std::string printRoot(std::string);//開根號輸出小數點後100位				
	
	int cmp(std::string, std::string);//大數比較		
protected:
	std::string input;
	//存輸入字串(無空格 '#'代表負號)
};
