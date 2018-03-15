#include<bits/stdc++.h>

using namespace std;

struct record
{
	string name;
	int Oj, mid = -1, fin = -1, tot = -1;
	void update()
	{
		if (mid > fin)
			tot = round(mid*0.4 + fin*0.6);
		else
			tot = fin;
	}
};
bool operator<(const record &lhs, const record &rhs)
{
	return lhs.tot > rhs.tot || lhs.tot == rhs.tot && lhs.name < rhs.name;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int P, M, N;       //P - done Oj, M - done mid-term, N - done final
	cin >> P >> M >> N;
	unordered_set<string> passOj;
	unordered_map<string, record> lst;
	vector<record> ret;
	string name;
	int score;
	for (int i = 0; i < P; ++i)
	{
		cin >> name >> score;
		if (score < 200)                    //没有通过OJ200分的直接忽略
			continue;
		passOj.insert(name);
		record tmp;
		tmp.name = name;
		tmp.Oj = score;
		lst[name] = tmp;
	}
	for (int i = 0; i < M; ++i)
	{
		cin >> name >> score;
		if (passOj.find(name) == passOj.end())  //若不是通过OJ200分的也直接忽略
			continue;
		lst[name].mid = score;
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> name >> score;
		if (passOj.find(name) == passOj.end())  //若不是通过OJ200分的也直接忽略
			continue;
		lst[name].fin = score;
		lst[name].update();
		if (lst[name].tot >= 60)           //不能是lst[name].tot < 60然后lst.erase
			ret.push_back(lst[name]);      //因为可能有在final缺少成绩的，就会被忽略没被erase
	}
	sort(ret.begin(), ret.end());
	for (int i = 0; i < ret.size(); ++i)
		cout << ret[i].name << " " << ret[i].Oj << " "
		<< ret[i].mid << " " << ret[i].fin << " " << ret[i].tot << '\n';
	return 0;
};
