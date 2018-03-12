#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	vector<vector<string>> course(K);
	string name;
	int num, coures_id;
	for (int i = 0; i < N; ++i)
	{
		cin >> name >> num;
		for (int j = 0; j < num; ++j)
		{
			cin >> coures_id;
			course[coures_id - 1].push_back(name);
		}
	}
	for (int i = 0; i < K; ++i)
		sort(course[i].begin(), course[i].end());
	for (int i = 0; i < K; ++i)
	{
		cout << i + 1 << ' ' << course[i].size() << '\n';
		for (auto ch : course[i])
			cout << ch << '\n';
	}
	return 0;
}
