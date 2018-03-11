#include<bits/stdc++.h>

using namespace std;

struct hashfunc                                      //根据题目条件，名字是三个大写字母加数字，自定义hash函数会有更好的效率
{
	size_t operator()(const string &s) const
	{
		size_t val = 0;
		for (auto i = 0; i < 3; ++i)
		{
			val += s[i] - 'A';
			val *= 26;
		}
		return val * 10 +s[3] - '0';
	}
};

int main()
{
	ios::sync_with_stdio(false);                     //关闭同步，提升速度
	cin.tie(0);                                      //解除cin和cout的绑定，确保不会过多刷新缓存
	int N, K;
	unordered_map<string, vector<int>, hashfunc> s;  //需要使用vector而不能是set，且需要提供自己的hash函数
	cin >> N >> K;
	string name;
	for (int i = 0; i < K; ++i)
	{
		int courseID, num;
		cin >> courseID >> num;
		for (int j = 0; j < num; ++j)
		{
			cin >> name;
			s[name].push_back(courseID);
		}
	}
	for (auto &ch : s)                               //若使用set则每次插入一门课都进行维护序列，而是用vector在最后才排序
	{                                                //虽然复杂度都是O(NlogN)但是这里后者更好，因为后面输出时vector访问是O(1)的，而set访问是O(logN)的
		sort(ch.second.begin(), ch.second.end());
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> name;
		cout << name << " " << s[name].size();
		for (auto ch : s[name])
		{
			cout << " " << ch;
		}
		cout << '\n';
	}
	return 0;
}
