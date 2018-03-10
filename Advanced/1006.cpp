#include<bits/stdc++.h>

using namespace std;

struct record
{
	int hour;
	int min;
	int sec;
	record(int h, int m, int s) :hour(h), min(m), sec(s) {}
};
bool operator<(const record &lhs, const record &rhs)
{
	return
		lhs.hour < rhs.hour ||
		lhs.hour == rhs.hour && lhs.min < rhs.min ||
		lhs.hour == rhs.hour && lhs.min == rhs.min && lhs.sec < rhs.sec;
}

int main()
{
	map<record, string> signIn, signOut;
	int N;
	scanf("%d", &N);
	for (auto i = 0; i < N; ++i)
	{
		char tmp[16];
		string name;
		int h, m, s;
		scanf("%s", tmp);
		name = tmp;
		scanf("%d:%d:%d", &h, &m, &s);
		signIn.insert({ record(h, m, s), name });
		scanf("%d:%d:%d", &h, &m, &s);
		signOut.insert({ record(h, m, s), name });
	}
	printf("%s %s", signIn.begin()->second.c_str(), (--signOut.end())->second.c_str());
	return 0;
}
