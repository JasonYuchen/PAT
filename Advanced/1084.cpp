#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	unordered_set<char> mis;
	string origin, test, ret;
	cin >> origin >> test;
	for (int i = 0, j = 0; i < origin.size(); ++i)                      //i指向原序列，j指向待检测序列
	{
		char ch = isdigit(origin[i]) ? origin[i] : toupper(origin[i]);  //字母全部转换成大写来处理
		auto has = mis.find(ch) != mis.end();                           //has来标记目前的字符是否已经被判定是丢失字符
		if (j == test.size())                                           //若待检测序列已到末尾，则原序列所有未出现过的都是坏的按键
		{
			if (!has)
			{
				ret.push_back(ch);
				mis.insert(ch);
			}
			continue;
		}
		if (origin[i] != test[j])                                       //若字符不匹配，说明丢失字符
		{
			if (!has)
			{
				ret.push_back(ch);
				mis.insert(ch);
			}
			continue;
		}
		++j;                                                            //直到出现字符匹配，才原序列和待检测序列一起前进
	}
	cout << ret << endl;
	return 0;
}