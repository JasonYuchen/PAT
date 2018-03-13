#include<bits/stdc++.h>

using namespace std;

vector<string>
digit0 = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" }, 
digit1 = { "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

void toMars(string num)
{
	int n = stoi(num);
	if (n % 13 == 0)         //若是13的倍数，则只输出一个高位
		cout << digit1[n / 13] << '\n';
	else if (n / 13 == 0)    //若是小于13的数，则只输出一个低位
		cout << digit0[n] << '\n';
	else                     //需要输出两位
		cout << digit1[n / 13] << " " << digit0[n % 13] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	string str;
	cin >> N;
	getline(cin, str);       //吞掉遗留的\n
	for (int i = 0; i < N; ++i)
	{
		string num1, num2;
		getline(cin, str);
		if (isdigit(str[0]))
			toMars(str);
		else
		{
			istringstream is(str);
			is >> num1;  if (is)  is >> num2;                       //利用istringstream，因为tret是4位，其他都是3位，直接操作位会有问题
			auto high0 = find(digit0.begin(), digit0.end(), num1);
			auto high1 = find(digit1.begin(), digit1.end(), num1);
			auto low = find(digit0.begin(), digit0.end(), num2);
			if(low == digit0.end() && high0 != digit0.end())        //单独一个低位数字
				cout << (high0 - digit0.begin()) << '\n';
			else if (low == digit0.end() && high1 != digit1.end())  //单独一个高位数字
				cout << ((high1 - digit1.begin()) * 13) << '\n';
			else                                                    //两位数字
				cout << ((high1 - digit1.begin()) * 13 + (low - digit0.begin())) << '\n';
		}
	}
	return 0;
}
