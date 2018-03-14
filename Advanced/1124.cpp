#include<bits/stdc++.h>

using namespace std;

int main()
{
	int M, N, S, cnt = 0, flag = 0; // M - forwards, N - skip number, S - first winner
	cin >> M >> N >> S;
	unordered_set<string> win;
	for (int i = 1; i <= M; ++i)
	{
		string name;
		cin >> name;
		if (i < S)
			continue;
		if (cnt % N == 0 && win.find(name) == win.end())
		{
			win.insert(name);
			cout << name << '\n';
			flag = 1;
		}
		else if (cnt % N == 0 && win.find(name) != win.end())
		{
			cnt--;
		}
		cnt++;
	}
	if (flag == 0)
		cout << "Keep going..." << '\n';
	return 0;
}