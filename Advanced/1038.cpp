#include<bits/stdc++.h>

using namespace std;

bool cmp(const string &lhs, const string &rhs)       //数字组合的比较，换位并比较两种组合，较小的组合的顺序就是需求顺序
{
	return lhs + rhs < rhs + lhs;
}

int main()
{
	ios::sync_with_stdio(false);               
	cin.tie(0);                                     
	int N;
	string s, ret;
	vector<string> r;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> s;
		r.push_back(s);
	}
	sort(r.begin(), r.end(), cmp);                   //注意必须显式传入pred，不能改用操作符重载，因为string在std里有比较操作符
	for (auto &ch : r)
	{
		ret += ch;
	}
	while (ret.size() != 0 && ret[0] == '0') ret.erase(ret.begin());
	if (ret.size() == 0) cout << 0 << endl;
	else cout << ret << endl;
	return 0;
}
