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

//輸入任意數學式
void Number::setInput(const string& line)
{
	input.clear();
	istringstream ss(line);
	string in, temp;
	int sign;
	bool negative;
	//消除空格
	while (ss >> in)
		temp += in;
	//將負號轉成'#'
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == '+' || temp[i] == '-')
		{
			sign = 0;
			for (int j = i; j < temp.length(); j++)
			{
				if (temp[j] >= '0' && temp[j] <= '9' || temp[j] == '(')
				{
					if (i && (temp[i - 1] >= '0' && temp[i - 1] <= '9' || temp[i - 1] == ')'))
					{
						if (sign % 2 == 0) // even 加號
						{
							input += '+';
						}
						else if (sign % 2 == 1) // odd 減號
						{
							input += '-'; // 減號
						}
						else
						{
							input += '#'; // 負號
						}
						i = j - 1; // 移動到下一位數字
						break;
					}
					else if (sign % 2 == 1)
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
		if ((postfix[i][0] < '0' || postfix[i][0] == '^') && !stack.empty()) // 後敘式中不是數字且stack有東西
		{
			if (postfix[i][0] == '#') //負號
			{
				changeSign(stack[stack.size() - 1]); // -1 # = 1
			}
			else if (postfix[i][0] == '!')
			{
				stack[stack.size() - 1] = fac(stack[stack.size() - 1]); // 4!  4 => 24
			}
			else if (stack.size() >= 2) // stack 有兩個數字 3 5 
			{
				int top = stack.size() - 1;
				switch (postfix[i][0]) // 3 5 '+'
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
		else // 是數字轉型態，存到stack
		{
			stack.push_back(checkDecimal(postfix[i]));
		}
		if (i == postfix.size() - 1)
			ans = stack[0];
	}
}

void Number::changeSign(newString& f) // 變號
{
	if (f.numerator != "0")
		f.sign = !f.sign;
}

newString Number::checkDecimal(string pos) // 轉型態
{
	newString f;
	f.numerator = pos;
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
	bool zero = true;
	if (index == 0 || pos == "0") // 整數或是0
	{
		for (int i = 0; i < pos.size(); i++)
		{
			if (pos[i] != '0' && pos[i] != '-')
			{
				index = i; // 第一個非0的數 EX 000123
				zero = false;
				break;
			}
		}
		if (!zero)
		{
			f.numerator.assign(pos,index);
			f.denominator = "1";
		}
		else
		{
			f.numerator = "0";
			f.denominator = "1";
		}
	}
	else // 是小數 要變分數 2.4 =   24       12
	//                           ----- =  -----
	//                             10       5
	{
		pos.erase(index, 1); // 只刪小數點 2.4 => 24
		for (int i = 0; i < pos.size(); i++)
		{
			if (pos[i] != '0' && pos[i] != '.' && pos[i] != '-')
			{
				zero = false;
				break;
			}
		}
		if (!zero)
		{
			string num = "1";  ////////////// 會溢位
			num.append(pos.size() - index,'0'); // 0.05 = 5/"100"

			for (int i = 0; i < pos.size(); i++)
			{
				if (pos[i] != '0' && pos[i] != '-')
				{
					index = i; // 第一個非0的數 EX 0.00"1"23
					break;
				}
			}
			f.numerator.assign(pos,index); // 0.00123 ==> 123
			f.denominator = num;           //            100000
		}
		else
		{
			f.numerator = "0";
			f.denominator = "1";
		}
	}
	if (f.denominator != "1")
		f = about(f);//約分
	return f;
}

newString Number::add(newString left, newString right) // 大數加法
{
	newString f;
	if (left.decimal || right.decimal) // 判斷是否為小數運算
	{
		f = fracAdd(left,right);
		f.decimal = true;
	}
	else
	{
		if(!left.sign)
			left.numerator.insert(left.numerator.begin(), '-');
		if (!right.sign)
			right.numerator.insert(right.numerator.begin(), '-');
		f.numerator = intAdd(left.numerator, right.numerator);
	}
	return f;
}

newString Number::sub(newString left, newString right) // 大數減法
{
	newString f;
	if (left.decimal || right.decimal) // 判斷是否為小數運算
	{
		f = fracSub(left, right);
		f.decimal = true;
	}
	else
	{
		if (!left.sign)
			left.numerator.insert(left.numerator.begin(), '-');
		if (!right.sign)
			right.numerator.insert(right.numerator.begin(), '-');
		f.numerator = intSub(left.numerator,right.numerator);
	}
	return f;
}

newString Number::mul(newString left, newString right) // 大數乘法
{
	newString f;
	if (!left.sign && !right.sign)
		f.sign = true;
	else if (!left.sign || !right.sign)
		f.sign = false;
	else f.sign = true;
	if (left.decimal || right.decimal) // 判斷是否為小數運算
	{
		f = fracMul(left, right);
		f = fracMul(left, right);
		f.decimal = true;
	}
	else // 整數乘法
	{
		f.numerator = intMul(left.numerator, right.numerator);
		f.denominator = intMul(left.denominator, right.denominator);
	}
	return f;
}

newString Number::div(newString left, newString right) // 大數除法
{
	if (right.numerator == "0")
	{
		errorTyep = 3; // 除數不可是0
		return left;
	}
	newString f;
	f.decimal = true;
	if (!left.sign && !right.sign)
		f.sign = true;
	else if (!left.sign || !right.sign)
		f.sign = false;
	else f.sign = true;

	// 內相乘為分母 外相乘為分子
	f.numerator = intMul(left.numerator, right.denominator);
	f.denominator = intMul(left.denominator, right.numerator);

	if (!left.decimal && !right.decimal) // 1/3 = 0.33333 要變 0, 9/2 = 4.5 ==> 4 
	{
		f.numerator = intDiv(f.numerator,f.denominator);
		f.denominator = "1";
		f.decimal = false;
	}
	if (f.denominator != "0")
		f = about(f);//約分
	return f;
}

newString Number::fac(newString f) // 大數階乘
{
	if (f.sign == false || f.denominator != "1") // 判斷是否為小數
	{
		errorTyep = 1; // 非0!或正整數階乘
	}
	else
	{
		vector<int> result;
		int target = 0, times = 1;

		for (int i = f.numerator.length() - 1; i >= 0; i--)
		{
			target += (f.numerator[i] - '0') * times;
			times *= 10;
		}

		result.push_back(1);

		for (int i = 1; i <= target; i++)
		{
			//檢查要做幾位數
			int digit = result.size();

			//進行乘法
			//每個digit都抓出來乘
			for (int j = 0; j < digit; j++)
				result[j] *= i;

			//處理各個digit進位的問題
			for (int j = 0; j < digit; j++)
			{
				int k = 0;	//偏移量，處理超過雙位數的問題
				while (result[j + k] >= 10)
				{
					if (j + k + 1 >= result.size())
					{
						result.push_back(result[j + k] / 10);
						result[j + k] = result[j + k] % 10;
						k++;
					}
					else
					{
						result[j + k + 1] += result[j + k] / 10;
						result[j + k] = result[j + k] % 10;
						k++;
					}
				}
			}
		}
		f.numerator = "";
		for (int i = result.size() - 1; i >= 0; i--) // 4! = 4 2 所以要倒著存
			f.numerator += result[i] + '0';
	}
	return f;
}

newString Number::pow(newString left, newString right) // 大數次方
{
	if (right.denominator != "1" && !(right.numerator == "1" && right.denominator == "2")) // 不是整數也不是 0.5 次方 
	{
		if (errorTyep == -1)
			errorTyep = 2;
		return left;
	}
	if (right.numerator == "1" && right.denominator == "2") // 3^0.5
	{
		left.decimal = true;
		return fracRoot(left, right.sign);
	}
	else if (right.numerator == "0") // 3^0 = 1
	{
		left.numerator = left.denominator = "1";
		left.sign = true;
		return left;
	}
	else // 不管小數還整數都當分數
	{
		//if (mod(right.numerator, "2") == "0") // 如果是 -0.5^4 答案會是正數
		//	left.sign = false;
		left.numerator = intPow(left.numerator, right.numerator); // (3/8)^2 = 3^2/8^2 = 9/64
		left.denominator = intPow(left.denominator, right.numerator); // (4/1)^2
	}
	return left;
}

string Number::intAdd(string left, string right) // 整數加法
{
	bool sign = true; // true 為正數
	string temp, ans;
	int size1 = left.size(), size2 = right.size();
	if (left[0] != '-' && right[0] == '-') // A + -B
	{
		right.erase(0, 1); // -B -> B
		ans = intSub(left, right); // A - B
		return ans;
	}
	else if (left[0] == '-' && right[0] != '-') // -A + B
	{
		left.erase(0, 1); // -A -> A
		ans = intSub(right, left); // B - A
		return ans;
	}
	else
	{
		if (left[0] == '-' && right[0] == '-') // -A + -B
		{
			sign = false;
			left.erase(0, 1); // 把負號清掉
			right.erase(0, 1);
		}
		if (size1 >= size2)
		{
			ans = left;
			temp = right;
		}
		else
		{
			ans = right;
			temp = left;
		}
	}
	size1 = ans.size();
	size2 = temp.size();
	int i = size1 - 1, j = size2 - 1;

	for (i; i >= 0; i--, j--)
	{
		if (j >= 0)
			ans[i] += temp[j] - '0';
		if (ans[i] > '9')
		{
			ans[i] -= 10;
			if (i > 0)
				ans[i - 1] += 1;
			else if (i == 0)
				ans.insert(ans.begin(), '1');
		}
	}
	if (!sign)
		return "-" + ans;
	else
		return ans;
}

string Number::intSub(string left, string right) // 整數減法
{
	bool sign = true; // ans的正負號
	string ans, temp;
	int size1 = left.size(), size2 = right.size();

	if (left[0] != '-' && right[0] == '-')// A - -B = A + B
	{
		right.erase(0, 1); // -B -> B
		ans = intAdd(left, right);
		return ans;
	}
	else if (left[0] == '-' && right[0] != '-')// -A - B = -A + -B
	{
		right.insert(right.begin(), '-'); // B -> -B
		ans = intAdd(left, right);
		return ans;
	}
	else if (left[0] == '-' && right[0] == '-')//-A - -B= -A + B = B - A
	{
		left.erase(0, 1); // -A -> A
		right.erase(0, 1); // -B -> B
		ans = intSub(right, left);
		return ans;
	}
	else if (left[0] != '-' && right[0] != '-')//A - B
	{
		if (size1 > size2)
		{
			ans = left;
			temp = right;
		}
		else if (size1 < size2)
		{
			ans = right;
			sign = false; // ans -> -ans
			temp = left;
			size1 = ans.size();
			size2 = temp.size();
		}
		else if (size1 == size2)
		{
			for (int i = 0; i < size1; i++)
			{
				if (left[i] > right[i])
				{
					ans = left;
					temp = right;
					break;
				}
				else if (left[i] < right[i])
				{
					ans = right;
					temp = left;
					size1 = ans.size();
					size2 = temp.size();
					sign = false; // ans -> -ans
					break;
				}
				else if (i == size1 - 1)
				{
					return "0";
				}
			}
		}
	}
	int i = size1 - 1, j = size2 - 1;
	for (i; i >= 0; i--, j--)
	{
		if (j >= 0)
			ans[i] -= temp[j] - '0';
		if (ans[i] < '0')
		{
			ans[i] += 10;
			if (i > 0)
				ans[i - 1] -= 1;
		}
	}

	for (; ans.size() > 1;)
	{
		if (ans[0] == '0')
			ans.erase(ans.begin());
		else
			break;
	}
	if (!sign)
		return "-" + ans;
	else
		return ans;
}

string Number::intMul(string left, string right) // 整數乘法
{
	int integer[10] = { 0,1,2,3,4,5,6,7,8,9 };
	vector<int> num;
	int now = 0, next, index;
	for (int j = right.size() - 1; j >= 0; j--)
	{
		index = right.size() - j - 1;
		for (int i = left.size() - 1; i >= 0; i--, index++)
		{
			next = 0;
			if (integer[left[i] - '0'] != 0 && integer[right[j] - '0'] != 0) //遇零進位
			{
				now += integer[left[i] - '0'] * integer[right[j] - '0'];
			}
			if (now >= 10)//超過10就進位到next
			{
				next += now / 10;
				now %= 10;
			}
			if (num.size() <= index)
				num.push_back(now);
			else
			{
				num[index] += now;
				if (num[index] >= 10)//超過10就進位到next
				{
					next += num[index] / 10;
					num[index] %= 10;
				}
			}
			now = next;
		}
		while (now > 0)
		{
			num.push_back(now % 10);
			now /= 10;
		}
	}
	while (now > 0)
	{
		num.push_back(now % 10);
		now /= 10;
	}
	string strNum;
	bool zero = true;
	for (int i = num.size() - 1; i >= 0; i--) // 4201 要變 1024
	{
		if (num[i] != 0)
			zero = false;
		if (!zero)
			strNum += num[i] + '0';
		else if (i == 0) // num = 0 
			strNum = "0";
	}
	return strNum;
}

string Number::intDiv(string left, string right) // 整數除法
{
	bool r = false;//判斷是否要取餘數
	if (left[left.size() - 1] == 'r')
	{
		r = true;
		left.pop_back();
	}

	if (right == "0")
	{
		cout << "Illegal input!" << endl;
		return "0";
	}
	//判斷正負號
	bool divSign = false;//存正負號，default為正號(false)
	if (left[0] == '-' && right[0] == '-')
	{
		left.erase(left.begin());
		right.erase(right.begin());
	}
	else if (left[0] == '-')
	{
		left.erase(left.begin());
		divSign = true;
	}
	else if (right[0] == '-')
	{
		right.erase(right.begin());
		divSign = true;
	}

	string rem; //餘數
				//判斷大小
	int c = intCmp(left, right);
	if (c == 0)//兩數相等
	{
		rem = "0";
		if (r)
			return rem;
		if (divSign)
			return "-1";
		return "1";
	}
	else if (c == 1)//除數>被除數
	{
		rem = left;
		if (r)
			return rem;
		return "0";
	}
	else
	{
		string rem = left, R = right;
		string quotient;
		int s = left.size() - right.size() + 1;
		for (int i = 0; i < s - 1; i++) //若長度不一樣，將left補零至與right一樣長
			R.push_back('0');
		while (s--)
		{
			string a, m;
			for (int i = 9; i >= 0; i--)
			{
				a = '0' + i;
				m = intMul(R, a);
				c = intCmp(m, rem);
				if (c >= 0)
				{
					quotient += a;
					rem = intSub(rem, m);
					break;
				}
			}
			R.pop_back();
		}
		if (r)
			return rem;

		if (quotient[0] == '0')
			quotient.erase(quotient.begin());

		if (divSign)
			return "-" + quotient;
		return quotient;
	}
}

string Number::intPow(string left, string right) // 整數次方
{
	if (right == "1")
		return left;
	if (right == "2")
		return intMul(left, left);

	int tempPow = 0, count = 10;

	for (int i = 0; i < right.size(); i++)   //字串轉整數
	{
		tempPow *= count;
		tempPow += (right[i] - '0');
	}

	int ret = tempPow / 2;
	return intMul(intPow(left, to_string(ret)), intPow(left, to_string(tempPow - ret)));
}

// 大數比較
int Number::intCmp(string left, string right)
{
	int size1 = left.size();
	int size2 = right.size();

	if (size1 > size2) // 左大於右
		return -1;
	else if (size1 < size2) // 右大於左
		return 1;
	else if (size1 == size2) 
	{
		for (int i = 0; i < size1; i++)
		{
			if (left[i] > right[i])
				return -1;
			else if (left[i] < right[i])
				return 1;
			else if (i == size1 - 1) // 相等
				return 0;
		}
	}
}

newString Number::fracAdd(newString left, newString right) // 小數加法
{
	newString f;
	f.decimal = true;

	int c = intCmp(left.denominator, right.denominator);
	if (c == 0) //若分母相同，分子直接相加
	{
		if (!left.sign) //還原負號
			left.numerator.insert(0, "-");
		if (!right.sign)
			right.numerator.insert(0, "-");

		f.numerator = intAdd(left.numerator, right.numerator);
		f.denominator = left.denominator;
	}
	else if (left.numerator == "0") // 一邊分子為0就不用加了
	{
		return right;
	}
	else if (right.numerator == "0") // 一邊分子為0就不用加了
	{
		return left;
	}
	else//若分母不相同，通分後相加
	{
		f.denominator = intMul(left.denominator, right.denominator);
		left.numerator = intMul(left.numerator, right.denominator);
		right.numerator = intMul(right.numerator, left.denominator);

		if (!left.sign) //還原負號
			left.numerator.insert(0, "-");
		if (!right.sign)
			right.numerator.insert(0, "-");
		f.numerator = intAdd(left.numerator, right.numerator);
	}
	f.sign = sign(f.numerator); // 確認正負號後 把正負號清除
	if (f.denominator != "0")
		f = about(f);//約分
	return f;
}

newString Number::fracSub(newString left, newString right) // 小數減法
{
	newString f;
	f.decimal = true;
	
	int c = intCmp(left.denominator, right.denominator);
	if (c == 0) //若分母相同，分子直接相減
	{
		if (!left.sign) //還原負號
			left.numerator.insert(0, "-");
		if (!right.sign)
			right.numerator.insert(0, "-");

		f.numerator = intSub(left.numerator, right.numerator);
		f.denominator = left.denominator;
	}
	else if (left.numerator == "0") // 一邊分子為0就不用加了
	{
		right.sign = !right.sign; // 確認正負號後 把正負號清除
		return right;
	}
	else if (right.numerator == "0") // 一邊分子為0就不用加了
	{
		left.sign = !left.sign; // 確認正負號後 把正負號清除
		return left;
	}
	else//若分母不相同，通分後相加
	{
		f.denominator = intMul(left.denominator, right.denominator);
		left.numerator = intMul(left.numerator, right.denominator);
		right.numerator = intMul(right.numerator, left.denominator);

		if (!left.sign) //還原負號
			left.numerator.insert(0, "-");
		if (!right.sign)
			right.numerator.insert(0, "-");
		f.numerator = intSub(left.numerator, right.numerator);
	}
	f.sign = sign(f.numerator); // 確認正負號後 把正負號清除
	if (f.denominator != "0")
		f = about(f);//約分
	return f;
}

newString Number::fracMul(newString left, newString right) // 小數乘法
{
	newString f;
	f.decimal = true;
	if (!left.sign && !right.sign) // 負負得正
		f.sign = true;
	else if (!left.sign || !right.sign)
		f.sign = false;
	else f.sign = true;

	f.numerator = intMul(left.numerator, right.numerator);
	f.denominator = intMul(left.denominator, right.denominator);

	if (f.numerator == "0" && f.denominator == "0")
		f.sign = false;

	if (f.denominator != "0")
		f = about(f);//約分
	return f;
}

newString Number::fracRoot(newString left, bool sign) // 開根號
{
	if (!left.sign)
	{
		errorTyep = 4; // 負數不可開根號
		return left;
	}
	string t1, t2, s;
	t1 = getRoot120(left.numerator);
	t2 = getRoot120(left.denominator);
	s.insert(s.end(), 50, '0');
	size_t f1, f2;
	f1 = t1.find('.');
	f2 = t2.find('.');
	if (t1.substr(f1 + 1, 50) == s && t2.substr(f2 + 1, 50) == s)
	{
		left.numerator.assign(t1.begin(), t1.begin() + f1);
		left.denominator.assign(t2.begin(), t2.begin() + f2);
		if (!sign)
		{
			string temp = left.denominator;
			left.denominator = left.numerator;
			left.numerator = temp;
		}
		return left;
	}
	else
	{
		t1.erase(f1, 1);
		t2.erase(f2, 1);
		if (!sign) // 2 ^ -0.5 = 1/(2^0.5)
			left.numerator = t2, left.denominator = t1;
		else
			left.numerator = t1, left.denominator = t2;
	}
	if (left.denominator != "0")
		left = about(left);
	return left;
}

string Number::getRoot120(string s)
{
	string ans;
	int len1;
	s.length() % 2 == 0 ? len1 = s.length() / 2 : len1 = s.length() / 2 + 1;
	s.insert(s.end(), 300, '0');
	int len = s.length();
	int i, j;
	int x[300] = {}, y[600] = {};
	for (i = 0, j = len - 1; j >= 0; i++)
	{
		x[i] = s[j] - '0';
		if (j - 1 >= 0)    x[i] = x[i] + (s[j - 1] - '0') * 10;
		if (j - 2 >= 0)    x[i] = x[i] + (s[j - 2] - '0') * 100;
		if (j - 3 >= 0)    x[i] = x[i] + (s[j - 3] - '0') * 1000;
		j -= 4;
	}
	int xlen = len, ylen = 0, head = 0;
	while (xlen >= 0 && x[xlen] == 0) xlen--;
	for (j = (len - 1) / 8, i = j * 2; j >= 0; j--, i -= 2)
	{
		ylen++;
		for (int p = ylen; p >= 1; p--)
			y[p] = y[p - 1];
		y[0] = 0;
		if (xlen < j)
		{
			if (!head)
				ans.push_back('0'), head = 1;
			else
				ans = ans + "0000";
			continue;
		}
		int l = 0, r = 9999, p;
		int z[300]; // z = (y*10 + p)*p;
		while (l <= r)
		{
			p = (l + r) / 2;
			y[0] += p;
			z[0] = 0;
			for (int q = 0; q <= ylen + 5; q++)
			{
				z[q] += p * y[q];
				z[q + 1] = z[q] / 10000;
				z[q] %= 10000;
			}
			int chflag = 0;
			for (int q = ylen + 5; q >= 0; q--)
			{
				if (z[q] > x[i + q])
				{
					chflag = 1;
					break;
				}
				else if (z[q] < x[i + q])
				{
					chflag = 0;
					break;
				}
			}
			y[0] -= p;
			if (chflag)
				r = p - 1;
			else
				l = p + 1;
		}
		p = l - 1;
		y[0] = p;
		z[0] = 0;
		for (int q = 0; q <= ylen + 5; q++)
		{
			z[q] += p * y[q];
			z[q + 1] = z[q] / 10000;
			z[q] %= 10000;
		}
		for (int q = ylen + 5; q >= 0; q--)
			x[i + q] -= z[q];
		for (int q = 0; q <= ylen + 5; q++)
		{
			while (x[i + q] < 0)
				x[i + q] += 10000, x[i + q + 1]--;
		}
		y[0] += p;
		for (int q = 0; q <= ylen + 5; q++)
		{
			if (y[q] >= 10000)
			{
				y[q + 1] += y[q] / 10000;
				y[q] %= 10000;
			}
		}
		ylen += 5;
		while (ylen >= 0 && y[ylen] == 0)    ylen--;
		while (xlen >= 0 && x[xlen] == 0)    xlen--;
		if (!head)
		{
			ans = ans + to_string(p);
			head = 1;
		}
		else
		{
			string str = to_string(p);
			for (int w = 0; w < 4 - str.length(); w++)
				ans.push_back('0');
			ans = ans + str;
		}
	}
	ans.insert(len1, ".");
	return ans;
}

newString Number::about(newString f)
{
	if (f.numerator.size() > 150 && f.denominator.size() > 150)
	{
		long long s1 = f.numerator.size(), s2 = f.denominator.size();
		s1 -= s2;
		f.numerator.erase(f.numerator.begin() + 150 + s1, f.numerator.end());
		f.denominator.erase(f.denominator.begin() + 150, f.denominator.end());
	}
	string g = gcd(f.numerator, f.denominator);
	f.numerator = intDiv(f.numerator, g);
	f.denominator = intDiv(f.denominator, g);

	return f;
}

//最大公因數GCD
string Number::gcd(string a, string b)
{
	if (b == "0")
		return a;
	else
		return gcd(b, mod(a, b));
}

//取餘數 left%right
string Number::mod(string left, string right)
{
	string a = left;
	a += 'r';//加一個判斷字元
	return intDiv(a, right);
}

//正負號判斷
bool Number::sign(string& str)
{
	bool s = true;
	if (str[0] == '-')
	{
		s = false;
		str.erase(str.begin());
	}
	return s;
}

ostream& operator<<(ostream& outputStream, const Number& a)
{
	a.print(outputStream);
	return outputStream;
}

istream& operator>>(istream& inputStream, Number& a)
{
	string in;
	inputStream >> in;
	a.setInput(in);
	a.inToPostfix();
	a.computInput();
	a.assign();
	return inputStream;
}

void Number::assign() {}

void Number::print(ostream&)const {}

//Number輸出答案
string Number::printAns()
{
	if (errorTyep > 0)
	{
		switch (errorTyep)
		{
		case 1:
			return "Error (1) : 只能是非正整數階乘";
			break;
		case 2:
			return "Error (2) : 非整數或0.5次方";
			break;
		case 3:
			return "Error (3) : 除數不可為0";
			break;
		case 4:
			return "Error (4) : 負數不可開根號";
			break;
		case 5:
			return "Error (5) : 輸入有地方錯誤了";
			break;
		default:
			break;
		}
	}
	// 正確答案
	string s = "0.0000000000";
	newString temp;

	if (ans.denominator != "1" && ans.denominator != "0" || ans.decimal)
	{
		string test = getDec(); // 答案是分數 要轉小數
		return test;
	}
	else
		return getInt();
}

newString Number::getFrac()
{
	return ans;
}

newString Number::getReal()
{
	newString ret;
	ret.sign = ans.sign;
	ret.denominator = ans.denominator;
	ret.numerator = ans.numerator;
	return ret;
}

void Number::setFrac(newString& f)
{
	ans = f;
}

string Number::getInt()
{
	if (errorTyep > 0)
		return printAns();
	
	string ret;
	if(!ans.decimal)
	{
		ret = ans.numerator;
	}
	else
	{
		ret = get100Dec(ans);

		size_t index;
		index = ret.find('.');
		ret.assign(ret, 0, index);
	}
	if (!ans.sign && ret[0] != '-')
		ret.insert(ret.begin(), '-');
	if (ret == "-0")
		return "0";
	return ret;
}

string Number::getDec()
{
	if (errorTyep > 0)
		return printAns();
	string ret;
	ret = get100Dec(ans);
	if (!ans.sign) // 負數 加 負號
		ret.insert(ret.begin(), '-');
	string s = "-0.";
	s.insert(s.size() - 1, 100, '0');
	if (ret == s) // s = -0.0000000...
		ret.erase(ret.begin()); // 把負號清掉
	return ret;
}

string Number::get110Dec(newString f)
{
	if (f.numerator == "0" && f.denominator == "0")
	{
		string s;
		s.assign(110, '0');
		return "0." + s;
	}
	string temp;
	string quotient = intDiv(f.numerator, f.denominator);
	int len = quotient.length();
	if (intCmp(f.numerator, f.denominator) == 1 && f.numerator != "0")
	{
		temp = "0.";
		while (intCmp(f.numerator, f.denominator) == 1)
		{
			temp += '0';
			f.numerator += '0';
		}
		if (temp[temp.size() - 1] == '0')
			temp.pop_back();
		f.numerator.insert(f.numerator.end(), 110, '0');
		quotient = intDiv(f.numerator, f.denominator);
		temp += quotient;
		return temp.assign(temp, 0, len + 111);
	}
	else
	{
		f.numerator.insert(f.numerator.end(), 110, '0');
		quotient = intDiv(f.numerator, f.denominator);
		quotient.insert(len, ".");
		return quotient.assign(quotient, 0, len + 111);
	}
}

string Number::get100Dec(newString f)
{
	string get110 = get110Dec(f);
	string s;
	size_t index;
	index = get110.find('.');
	s.assign(105, '9');
	if (s == get110.substr(index + 1, 105))
	{
		get110.assign(get110.begin(), get110.begin() + index);
		get110 = intAdd(get110, "1");
		get110 += '.';
		get110.insert(get110.end(), 110, '0');
	}
	s.assign(10, '9');
	if (s == get110.substr(index + 100, 10))
	{
		string temp;
		temp.assign(get110.begin(), get110.begin() + index); //小數點前
		get110 = get110.substr(index + 1, 110);
		while (get110[0] == '0')
		{
			get110.erase(get110.begin());
		}
		get110 = intAdd(get110, "1");
		if (get110.size() > 110)
		{
			string a;
			a = get110[0];
			get110.erase(get110.begin());
			temp = intAdd(temp, a);
		}

		temp += '.';
		temp += get110;
		get110 = temp;
	}
	return get110.assign(get110, 0, get110.size() - 10);
}
