vector<char> sqrt(vector<char> input)
{
	vector<char> ans;
	// 小數點
	int dotPos = 0;
	for (int i = 0; i < input.size(); i++)
		if (input[i] == '.')
			dotPos = i;

	vector<int> intN, decN;
	// 分節
	if (dotPos == 0)
	{
		for (int i = input.size() - 1; i >= 0; i-=2)
		{
			if (i - 1 >= 0)
				intN.push_back(input[i] - '0' + (input[i - 1] - '0') * 10);
			else
				intN.push_back(input[i] - '0');
		}
	}
	else
	{
		for (int i = dotPos + 1; i < input.size(); i+=2)
		{
			if (i + 1 < input.size())
				decN.push_back(input[i + 1] - '0' + (input[i] - '0') * 10);
			else
				decN.push_back(input[i] - '0');
		}
		for (int i = dotPos - 1; i >= 0; i-=2)
		{
			if (i - 1 >= 0)
				intN.push_back(input[i] - '0' + (input[i - 1] - '0') * 10);
			else
				intN.push_back(input[i] - '0');
		}
	}

	BigInt buffer1, buffer2; // 大數型態

	for (int i = intN.size() - 1; i >= 0; i--)
	{
		buffer2 += intN[i];
		for (int j = 1; j < 11; j++)
		{
			if (buffer2 < (buffer1 + j) * j)
			{
				buffer2 -= (buffer1 + j - 1) * (j - 1);
				buffer1 += (j - 1) * 2;
				buffer1 *= 10;
				//cout << j - 1;
				ans.push_back(j - 1 + '0');
				break;
			}
		}
		buffer2 *= 100;
	}

	cout << '.';
	ans.push_back('.');

	int pos = 0;
	for (int i = 0; i < decN.size(); i++)
	{
		buffer2 += decN[i];
		for (int j = 1; j < 11; j++)
		{
			if (buffer2 <= (buffer1 + j) * j)
			{
				buffer2 -= (buffer1 + j - 1) * (j - 1);
				buffer1 += (j - 1) * 2;
				buffer1 *= 10;
				//cout << j - 1;
				ans.push_back(j - 1 + '0');
				pos++;
				break;
			}
		}
		buffer2 *= 100;
	}

	if (pos == 0)
		pos++;

	for (int i = pos - 1; i <= 100; i++)
	{
		for (int j = 1; j < 11; j++)
		{
			if (buffer2 <= (buffer1 + j) * j)
			{
				buffer2 -= (buffer1 + j - 1) * (j - 1);
				buffer1 += (j - 1) * 2;
				buffer1 *= 10;
				//cout << j - 1;
				ans.push_back(j - 1 + '0');
				break;
			}
		}
		buffer2 *= 100;
	}

	return ans;
}

int main() {
	string str;
	vector<char> num, ans;
	while (cin >> str)
	{
		for (int i = 0; i < str.length(); i++)
			num.push_back(str[i]);
		ans = sqrt(num);
		cout << endl;
	}
}
