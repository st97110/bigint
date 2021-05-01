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
	inToPostfix();
	computInput();
}
Number::~Number() 
{
}

string Number::getInt()
{
	return ans.num;
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
			for (int j = i; j < temp.length(); j++)
			{
				negative = false;
				if (temp[j] >= '0' && temp[j] <= '9' || temp[j] == '(')
				{
					if (i && sign % 2 == 0) // even 加號
					{
						input += '+';
					}
					else if (i && sign % 2 == 1) // odd 減號
					{
						for (int k = i - 1; k >= 0; k--)
						{
							if (!(temp[k] >= '0' && temp[k] <= '9' && temp[k] == ')'))
							{
								negative = true;
								break;
							}
						}
						if(!negative)
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

//轉換成後序式
void Number::inToPostfix()
{
	vector<string> _operator;//stack堆疊  _operator(堆疊中的運算子)
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
		//遇右括號')'
		else if (input[i] == ')')
		{
			while (!_operator.empty())
			{
				int top = _operator.size() - 1;
				if (_operator[top] == "(") { // 輸出stack中的operator直到遇到左括號'('
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
			case'(':	//左括號優先度：5
				nowPriority = priority[5];
				break;
			case'#':	//負號號優先度：4
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
				int top = _operator.size() - 1;
				while (operatorPriority[top] != 5 && ((input[i] != '^' && operatorPriority[top] >= nowPriority) || (input[i] == '^' && operatorPriority[top] > nowPriority)))
				{
					postfix.push_back(_operator[top]);
					_operator.pop_back();
					operatorPriority.pop_back();
					top = _operator.size() - 1;

					if (operatorPriority.empty())
						break;
				}
			}
			string operat; // 堆疊operator
			operat = input[i]; //char 轉存 string
			_operator.push_back(operat); // 堆疊當前運算子至_operator
			operatorPriority.push_back(nowPriority); // 堆疊運算子優先度至operatorPriority
		}
	}
	// 把剩下的全部都輸出出來
	while (!(_operator.empty()))
	{
		postfix.push_back(_operator[_operator.size() - 1]);
		_operator.pop_back();
		operatorPriority.pop_back();
	}
}
//判斷字串、轉換後序式
void Number::computInput()
{
	//運算後序式

	vector<newString> stack;//stack[堆疊中的大數(分數型態)]
	for (int i = 0; i < postfix.size(); i++)
	{
		if ((postfix[i][0] < '0' || postfix[i][0] == '^') && !stack.empty())
		{
			if (postfix[i][0] == '#') //負號
			{
				changeSign(stack[stack.size() - 1]);
			}
			else if (postfix[i][0] == '!')
			{
				stack[stack.size() - 1] = fac(stack[stack.size() - 1]);
			}
			else if (stack.size() >= 2)
			{
				int top = stack.size() - 1;
				switch (postfix[i][0])
				{
				case'+':
					stack[top - 1] = add(stack[top - 1], stack[top]);
					stack.pop_back();
					break;
				case'-':
					stack[top - 1] = sub(stack[top - 1], stack[top]);
					stack.pop_back();
					break;
				case'*':
					stack[top - 1] = mul(stack[top - 1], stack[top]);
					stack.pop_back();
					break;
				case'/':
					stack[top - 1] = div(stack[top - 1], stack[top]);
					stack.pop_back();
					break;
				case'^':
					stack[top - 1] = pow(stack[top - 1], stack[top]);
					stack.pop_back();
					break;
				default:
					break;
				}
			}
		}
		else
		{
			stack.push_back(checkDecimal(postfix[i]));
		}
		if (i == postfix.size() - 1)
			ans = stack[0];
	}
}

void Number::changeSign(newString& f) // 變號
{
	if (f.num != "0")
		f.sign = !f.sign;
}

newString Number::checkDecimal(string pos) // 轉型態
{
	newString f;
	f.num = pos;
	//判斷是否為小數
	int index = 0;
	for (int i = 0; i < pos.size() - 1; i++)
	{
		if (pos[i] == '.')
		{
			f.decimal = true;
			index = i;
			break;
		}
	}
	if (pos[0] == '-')
	{
		f.sign = false;
	}
	return f;
}

newString Number::add(newString left, newString right) // 大數加法
{
	newString f;
	if (left.decimal || right.decimal) // 判斷是否為小數運算
	{
		f.numerator = fracAdd(left,right);
	}
	else
	{

	}
	return f;
}

newString Number::sub(newString, newString) // 大數減法
{
	newString f;
	return f;
}

newString Number::mul(newString, newString) // 大數乘法
{
	newString f;
	return f;
}

newString Number::div(newString, newString) // 大數除法
{
	newString f;
	return f;
}

newString Number::fac(newString) // 大數階乘
{
	newString f;
	return f;
}

newString Number::pow(newString, newString) // 大數次方
{
	newString f;
	return f;
}

newString Number::root(newString, newString) // 大數開根號
{
	newString f;
	return f;
}

string Number::fracAdd(newString left, newString right) // 小數加法
{
	string fracAns;
	return fracAns;
}
