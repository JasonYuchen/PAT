#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int N;
	vector<pair<string, string>> out;
	unordered_map<char, char> replace = { { '1','@' },{ '0','%' },{ 'l','L' },{ 'O','o' } };
	string name, pass;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> name >> pass;
		int flag = 0;
		for (auto &ch : pass)
		{
			auto it = replace.find(ch);
			if (it != replace.end())
			{
				ch = it->second;
				flag = 1;
			}
		}
		if (flag == 1)
			out.push_back({ name,pass });
	}
	if (out.size() == 0)
		if (N == 1)                 //注意区分单复数，is,are,account(s)
			cout << "There is " << N << " account and no account is modified" << endl;
		else
			cout << "There are " << N << " accounts and no account is modified" << endl;
	else
		cout << out.size() << endl;
	for (auto ch : out)
	{
		cout << ch.first << " " << ch.second << endl;
	}
	return 0;
}
