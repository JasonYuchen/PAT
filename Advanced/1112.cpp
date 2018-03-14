#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int k;
	string str;
	cin >> k;
	getline(cin, str);
	getline(cin, str);
	string stucked, fine, result;
	if (str.size() < k)                           //若短于k，则一定没有重复的，直接输出
	{
		cout << '\n' << str;
		return 0;
	}
	for (int i = 0; i + k - 1 < str.size(); ++i)  //出现重复k次的就加入stucked，此时可能有假重复，即某位置重复了k次但另一位置又没有重复
	{                                             //定义上键盘出问题则某个字符一定会每次出现都是重复的
		int flag = 1;
		char ch = str[i];
		for (int j = 0; j < k; ++j)
		{
			if (str[i + j] != ch)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			if (stucked.find(ch) == string::npos)
				stucked.push_back(ch);
			i += k - 1;                           //由于for每次都会++i，因此这里是k-1，最后跳过重复的k个字符
		}
		else if (flag == 0 && fine.find(ch) == string::npos)
		{
			fine.push_back(ch);                   //出现且不是k次连续可以确保是没有问题的，加入fine集合
		}
	}
	for (int i = 0; i < fine.size(); ++i)         //stucked里去除假重复
	{
		auto it = stucked.find(fine[i]);
		if (it != string::npos)
			stucked.erase(it);
	}
	for (int i = 0; i < str.size(); ++i)          //根据stucked重新处理字符串，出问题字符只保留一个
	{
		if (stucked.find(str[i]) == string::npos)
			result.push_back(str[i]);
		else
		{
			result.push_back(str[i]);
			i += k - 1;                           //由于for每次都会++i，因此这里是k-1，最后跳过重复的k个字符
		}
	}
	cout << stucked << '\n' << result << '\n';
	return 0;
};
