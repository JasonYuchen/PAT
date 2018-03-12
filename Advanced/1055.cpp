#include<bits/stdc++.h>

using namespace std;

struct record
{
	string name;
	int age;
	int wealth;
	record(const string &n, int a, int w) :name(n), age(a), wealth(w) {}
};

bool operator<(const record &lhs, const record &rhs)
{
	return
		lhs.wealth > rhs.wealth ||
		lhs.wealth == rhs.wealth && lhs.age < rhs.age ||
		lhs.wealth == rhs.wealth && lhs.age == rhs.age && lhs.name < rhs.name;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<record> lst;
	string name;
	int N, K, age, wealth;
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> name >> age >> wealth;
		lst.push_back(record(name, age, wealth));
	}
	sort(lst.begin(), lst.end());
	for (int i = 0; i < K; ++i)
	{
		int out_n, age_lo, age_up, cnt = 0;
		cin >> out_n >> age_lo >> age_up;
		cout << "Case #" << i + 1 << ":\n";
		for (int j = 0; j < N; ++j)
		{
			if (age_lo <= lst[j].age && lst[j].age <= age_up)
			{
				cout << lst[j].name << " " << lst[j].age << " " << lst[j].wealth << '\n';
				++cnt;
			}
			if (cnt == out_n)
				break;
		}
		if (cnt == 0)
			cout << "None" << '\n';
	}
	return 0;
}