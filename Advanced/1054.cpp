#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	map<int, int> g;
	int M, N;
	cin >> M >> N;
	int half = M*N / 2;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int color;
			cin >> color;
			g[color]++;
		}
	}
	int domin, occupy = 0;
	for (auto ch : g)
	{
		if (ch.second > occupy)
		{
			occupy = ch.second;
			domin = ch.first;
		}
	}
	cout << domin << endl;
	return 0;
}