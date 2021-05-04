#include "Number.h"
int main()
{
	Integer A;
	Decimal B;
	Integer C;
	cin >> A >> B >> C;
	Integer D = C * B;
	//D = C * B;       /////////////////////////// 錯誤
	cout << D << endl;

	cout << "0.";
	for (int i = 0; i < 100; i++)
	{
		cout << "0";
	}
	cout << endl;

	/*Decimal A = "3";
	Integer B = "-6";
	Integer C = B + A;
	vector<Number*> nums;
	nums.push_back(&A);
	nums.push_back(&B);
	nums.push_back(&C);
	for(const auto & num : nums)
		cout << endl << *num << endl;*/

	vector<Integer> ints;
	vector<Decimal> decs;
	cout << "Command : Set (Int/Dec) / Print / Assign / or any expression." << endl;
	cout << "------------------------------------------------------------------------------------------------------" << endl;
	while (1)
	{
		reset:
		string in, order;
		getline(cin, in);
		istringstream ss(in);
		while (ss >> order)
		{
			if (order == "Set" || order == "set")
			{
				string type, name, temp;
				int t = 0;
				bool exist = false; // 數字是否存在
				ss >> type;
				if (type == "Int" || type == "int")
					t = 1;
				else if (type == "Dec" || type == "dec")
					t = 2;
				ss >> name;
				if (ss >> temp) // Set A "=" 3
				{ 
					string str = ""; // 放算式
					Integer i;
					Decimal d;
					stringstream s;
					getline(ss,temp); // Set A = "3 + C8763 ^ B!" *********** 問題 Power不做可以嗎************
					switch (t)
					{
					case 1:
						i.name = name;

						s << temp; // "3 + C8763 ^ B!"
						while(s >> temp) // "3"
						{
							if (temp[0] >= '0' && temp[0] <= '9' || temp[0] == '+' || temp[0] == '-' || temp[0] == '*' || temp[0] == '/' || temp[0] == '^' || temp[0] == '!' || temp[0] == '(' || temp[0] == ')') // 不是變數
							{
								str += temp; // "3+"
							}
							else // 偵測到變數 轉成 數字進去
							{
								int index;
								bool found1 = false, found2 = false;
								for (int i = 0; i < ints.size(); i++)
								{
									if (ints[i].name == name)
									{
										str += ints[i].intAns;
										found1 = true;
										break;
									}
								}
								for (int i = 0; i < decs.size(); i++)
								{
									if (decs[i].name == name)
									{
										str += decs[i].decAns;
										found2 = true;
										break;
									}
								}
								if (!found1 && !found2) // 沒找到
								{
									cout << endl << "Error (5) : 輸入有地方錯誤了" << endl << "======================================================================================================" << endl;
									goto reset;
								}
							}
						}
						i.setInput(str);
						i.inToPostfix();
						i.computInput();
						i.assign();
						ints.push_back(i);
						break;
					case 2:
						d.name = name;

						s << temp; // "3 + C8763 ^ B!"
						while (s >> temp) // "3"
						{
							if (temp[0] >= '0' && temp[0] <= '9' || temp[0] == '+' || temp[0] == '-' || temp[0] == '*' || temp[0] == '/' || temp[0] == '^' || temp[0] == '!' || temp[0] == '(' || temp[0] == ')') // 不是變數
							{
								str += temp; // "3+"
							}
							else // 偵測到變數 轉成 數字進去
							{
								int index;
								bool found1 = false, found2 = false;
								for (int i = 0; i < ints.size(); i++)
								{
									if (ints[i].name == temp)
									{
										str += ints[i].intAns;
										found1 = true;
										break;
									}
								}
								for (int i = 0; i < decs.size(); i++)
								{
									if (decs[i].name == temp)
									{
										str += decs[i].decAns;
										found2 = true;
										break;
									}
								}
								if (!found1 && !found2) // 沒找到
								{
									cout << endl << "Error (5) : 輸入有地方錯誤了" << endl << "======================================================================================================" << endl;
									goto reset;
								}
							}
						}
						d.setInput(str);
						d.inToPostfix();
						d.computInput();
						d.assign();
						decs.push_back(d);
						break;
					default:
						cout << endl << "Error (5) : 輸入有地方錯誤了" << endl << "======================================================================================================" << endl;
						goto reset;
					}
				}
				else  // 新的數字 Set A
				{
					if (t == 1)
					{
						Integer newI;
						newI.name = name;
						ints.push_back(newI);
					}
					else if (t == 2)
					{
						Decimal newD;
						newD.name = name;
						decs.push_back(newD);
					}
					else
					{
						cout << endl << "Error (5) : 輸入有地方錯誤了" << endl << "======================================================================================================" << endl;
						goto reset;
					}
				}
			}
			else if (order == "Print" || order == "print")
			{
				string name;
				ss >> name;
				bool found = false;
				for (int i = 0; i < ints.size() && !found; i++)
				{
					if (ints[i].name == name)
					{
						cout << endl << ints[i] << endl;
						cout << "======================================================================================================" << endl;
						found = true;
					}
				}
				for (int i = 0; i < decs.size() && !found; i++)
				{
					if (decs[i].name == name)
					{
						cout << endl << decs[i] << endl;
						cout << "======================================================================================================" << endl;
						found = true;
					}
				}
				if (!found)
				{
					cout << endl << "Error (5) : 輸入有地方錯誤了" << endl << "======================================================================================================" << endl;
					goto reset;
				}
			}
			else if (order == "Assign" || order == "assign")
			{
				//name1 = name2  or  name1 << expression
				string str, something; // 放算式 跟 每格算式內容
				Integer i;
				Decimal d;
				stringstream s;
				string name1, name2, temp;
				int index1, index2;
				bool found1 = false, found2 = false;
				ss >> name1 >> temp;
				
				getline(ss, temp); // A = "3 + C8763 ^ B!"
				s << temp; // "3 + C8763 ^ B!"
				while (s >> temp) // "3"
				{
					if (temp[0] >= '0' && temp[0] <= '9' || temp[0] == '+' || temp[0] == '-' || temp[0] == '*' || temp[0] == '/' || temp[0] == '^' || temp[0] == '!' || temp[0] == '(' || temp[0] == ')') // 不是變數
					{
						str += temp; // "3+"
					}
					else // 偵測到變數 轉成 數字進去
					{
						for (int i = 0; i < ints.size(); i++)
						{
							if (ints[i].name == temp)
							{
								str += ints[i].intAns;
								found1 = true;
								break;
							}
						}
						for (int i = 0; i < decs.size(); i++)
						{
							if (decs[i].name == temp)
							{
								str += decs[i].decAns;
								found2 = true;
								break;
							}
						}
						if (!(found1 || found2)) // A = 3 + "C8763" ^ B!  後面變數有找到
						{
							cout << endl << "Error (5) : 輸入有地方錯誤了" << endl << "======================================================================================================" << endl;
							goto reset;
						}
					}
				}
				// 確認左值存不存在
				found1 = false, found2 = false;
				for (int i = 0; i < ints.size(); i++)
				{
					if (ints[i].name == name1)
					{
						index1 = i;
						found1 = true;
						break;
					}
				}
				for (int i = 0; i < decs.size(); i++)
				{
					if (decs[i].name == name1)
					{
						index2 = i;
						found2 = true;
						break;
					}
				}
				if (!found1 && !found2) // 沒找到左邊的變數 "A" = 3 + C8763 ^ B!
				{
					cout << endl << "Error (5) : 輸入有地方錯誤了" << endl << "======================================================================================================" << endl;
					goto reset;
				}

				if (found1)
				{
					i.name = name1;
					i.setInput(str); // A = 3+0.5+2
					i.inToPostfix();
					i.computInput();
					i.assign();
					ints[index1] = i;
				}
				else if(found2)
				{
					d.name = name1;
					d.setInput(str);
					d.inToPostfix();
					d.computInput();
					d.assign();
					decs[index2] = d;
				}
			}
			//else if (order == "Pow" || order == "pow") //Pow a , b  or Pow a ^ b
			//{
			//	Complex out;
			//	string name1, name2, temp;
			//	ss >> name1 >> temp >> name2;
			//	if (temp == ",")
			//	{
			//		bool found1, found2;
			//		int index1, index2, type1, type2;
			//		found1 = found2 = false;
			//		for (int i = 0; i < ints.size() && (!found1 || !found2); i++)
			//		{
			//			if (ints[i].name == name1 && !found1)
			//			{
			//				index1 = i;
			//				type1 = 1;
			//				found1 = true;
			//			}
			//			if (ints[i].name == name2 && !found2)
			//			{
			//				index2 = i;
			//				type2 = 1;
			//				found2 = true;
			//			}
			//		}
			//		for (int i = 0; i < decs.size() && (!found1 || !found2); i++)
			//		{
			//			if (decs[i].name == name1 && !found1)
			//			{
			//				index1 = i;
			//				type1 = 2;
			//				found1 = true;
			//			}
			//			if (decs[i].name == name2 && !found2)
			//			{
			//				index2 = i;
			//				type2 = 2;
			//				found2 = true;
			//			}
			//		}
			//		if (!found1 || !found2)
			//			cout << "Not found." << endl;
			//		else
			//		{
			//			if (type1 == 1)
			//			{
			//				if (type2 == 1)
			//					out = Power(ints[index1], ints[index2]);
			//				else if (type2 == 2)
			//					out = Power(ints[index1], decs[index2]);
			//			}
			//			else if (type1 == 2)
			//			{
			//				if (type2 == 1)
			//					out = Power(decs[index1], ints[index2]);
			//				else if (type2 == 2)
			//					out = Power(decs[index1], decs[index2]);
			//			}
			//			cout << endl << out << endl;
			//			cout << "=============================================================================" << endl;
			//		}
			//	}
			//	else if (temp == "^")
			//	{
			//		bool found = false;
			//		for (int i = 0; i < ints.size() && !found; i++)
			//		{
			//			if (ints[i].name == name1)
			//			{
			//				out = Power(ints[i], name2);
			//				found = true;
			//			}
			//		}
			//		for (int i = 0; i < decs.size() && !found; i++)
			//		{
			//			if (decs[i].name == name1)
			//			{
			//				out = Power(decs[i], name2);
			//				found = true;
			//			}
			//		}
			//		if (!found)
			//			cout << "Not found." << endl;
			//		else
			//		{
			//			cout << endl << out << endl;
			//			cout << "=============================================================================" << endl;
			//		}
			//	}
			//}
			else
			{
				ss.clear(); // 清空
				ss.str(""); // 避免重複輸出
				Number k(in);
				cout << endl << k.printAns() << endl << "======================================================================================================" << endl;
			}
		}
	}
	return 0;
}
