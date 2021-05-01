#include "Number.h"
class Integer;
class Decimal;

Number::Number()
{
	string _input = "0";
	setInput(_input);
	computInput();
}
Number::Number(string _input)
{
	setInput(_input);
	computInput();
}
Number::~Number() 
{
}

//輸入任意數學式
void Number::setInput(const string& line)
{
	input.clear();
	string temp = line;
	int sign;
	bool negative;
	
	//將負號轉成'#'
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == '+' || temp[i] == '-')
		{
			sign = 0;
			negative = false;
			for (int j = i; j < temp.length(); j++)
			{
				if (temp[j] >= '0' && temp[j] <= '9' || temp[j] == '(')
				{
					if (i && sign % 2 == 0) // even 加號
					{
						input += '+';
					}
					else if (i && sign % 2 == 1 && temp[i - 1] >= '0' && temp[i - 1] <= '9') // odd 減號
					{
						input += '-';
					}
					else
					{
						input += '#'; // 負號
					}
					i = j - 1; // 移動到下一位數字
					break;
				}
				else if (temp[j] == '-')
				{
					sign++;
				}
			}
		}
		else if (temp[i] != ' ')
		{
			input += temp[i];
		}
	}
}

//判斷字串、轉換後序式
void Number::computInput()
{
	vector<string> _operator, postfix;//stack堆疊  _operator(堆疊中的運算子)  postfix(後序式)
	vector<int> operatorPriority;//存堆疊中運算子的優先順序
	int nowPriority;//存當前運算子優先順序
	for (int i = 0; i < input.size(); i++)
	{
		//遇運算元直接輸出至 postfix(後序式)
		if (input[i] <= '9' && input[i] >= '0' || input[i] == '.')
		{
			string temp;
			int j;
			for (j = i; j < input.size(); j++)
			{
				if (input[j] >= '0' && input[j] <= '9' || input[j] == '.')
				{
					temp += input[j];//當前運算元
				}
				else
				{
					break;
				}
			}
			i = j - 1;
			postfix.push_back(temp);
		}
		//遇右括號')'輸出stack中的operator至')'
		else if (input[i] == ')')
		{
			while (!_operator.empty())
			{
				int top = _operator.size() - 1;
				if (_operator[top] == "(") {
					_operator.pop_back();
					operatorPriority.pop_back();
					break;
				}
				postfix.push_back(_operator[top]);
				_operator.pop_back();
				operatorPriority.pop_back();
			}
		}
		//其他狀況：比較運算子優先順序，並判斷要存入運算子堆疊或輸出至後序式
		else {
			switch (input[i])
			{
			case'(':	//左括號優先度：6
				nowPriority = priority[6];
				break;
			case'#':	//負號號優先度：5
				nowPriority = priority[5];
				break;
			case'i':	//虛部優先度：4
				nowPriority = priority[4];
				break;
			case'!':	//階成優先度：3
				nowPriority = priority[3];
				break;
			case'^':	//次方優先度：2
				nowPriority = priority[2];
				break;
			case'*':	//乘號號優先度：1
				nowPriority = priority[1];
				break;
			case'/':	//除號號優先度：1
				nowPriority = priority[1];
				break;
			case'+':	//加號號優先度：0
				nowPriority = priority[0];
				break;
			case'-':	//減號號優先度：0
				nowPriority = priority[0];
				break;
			}
			// stack最上方運算子優先度 大於等於 當前運算子優先度 → 輸出至postfix(後序式)
			// 若最上方運算子為左括號，則直接堆疊運算子
			// 若最上方為 ^ 次方，必須大於 不能等於當前運算子  → 輸出至postfix(後序式)
			if (!operatorPriority.empty())
			{
				while (operatorPriority[operatorPriority.size() - 1] != 6 && ((input[i] != '^' && operatorPriority[operatorPriority.size() - 1] >= nowPriority) || (input[i] == '^' && operatorPriority[operatorPriority.size() - 1] > nowPriority)))
				{
					postfix.push_back(_operator[_operator.size() - 1]);
					_operator.pop_back();
					operatorPriority.pop_back();
					if (operatorPriority.empty())
						break;
				}
			}
			string operat;//堆疊operator
			operat = input[i];//char 轉存 string
			_operator.push_back(operat);//堆疊當前運算子至_operator
			operatorPriority.push_back(nowPriority);//堆疊運算子優先度至operatorPriority
		}
	}
	while (!(_operator.empty()))
	{
		postfix.push_back(_operator[_operator.size() - 1]);
		_operator.pop_back();
		operatorPriority.pop_back();
	}
	for (auto c : postfix)
	{
		cout << c << " ";
	}
	cout << endl;
}
