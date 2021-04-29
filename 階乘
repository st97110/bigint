#include <iostream>
#include <vector>
using namespace std;

vector<char> factorial(vector<char> number)// 階乘
{
	vector<int> result;
	int target = 0, times = 1;

	for (int i = number.size() - 1; i >= 0; i--)
	{
		target += number[i] * times;
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

	vector<char> charTypeResult;
	for (int i = 0; i < result.size(); i++)
		charTypeResult.push_back(result[i]);

	return charTypeResult;
}

int main()
{
	vector<char> num = { 1,0,0 };
	factorial(num);
}
