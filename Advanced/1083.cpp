#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, upper, lower;
	cin >> N;
	map<int, pair<string, string>, greater<int>> records;
	for (int i = 0; i < N; ++i)
	{
		string name, course;
		int grade;
		cin >> name >> course >> grade;
		records[grade].first = name;
		records[grade].second = course;
	}
	cin >> lower >> upper;
	auto st = records.lower_bound(upper), ed = records.upper_bound(lower);  //由于map是基于greater<int>，因此这里lower和upper正好反过来
	if (st == ed)
		cout << "NONE\n";
	else
		for (; st != ed; ++st)
			cout << st->second.first << " " << st->second.second << '\n';
	return 0;
}
