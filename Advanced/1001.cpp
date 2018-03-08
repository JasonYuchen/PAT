#include<bits/stdc++.h>

using namespace std;

int main() 
{
	int a, b;
	cin >> a >> b;
	int sum = a + b;
	int flag = sum < 0 ? -1 : 1;         //单独处理符号，数字在符号处已结束
	                                     //若不单独处理，会出现-,100
	sum = std::abs(sum);
	string out = to_string(sum);
	int cnt = 0;
	for (auto st = out.end(); st != out.begin(); --st, cnt++)
	{
		if (cnt != 0 && cnt % 3 == 0)    //最末尾不用','，从最低位向高处每3位添加','
		{
			st = out.insert(st, ',');    //msvc下不用"st = ..."也可以，迭代器不会失效
			                             //但是gcc下必须"st = ..."否则会由于迭代器失效导致段错误
		}
	}
	if (flag == -1)
		out = string("-") + out;
	cout << out << endl;
	return 0;
}