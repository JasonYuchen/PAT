#include<bits/stdc++.h>

using namespace std;

struct people
{
	int ID;
	int Virtue;
	int Talent;
	int tag;  //0 - sages, 1 - noblemen, 2 - fool men, 3 - the rest
	people(int a, int b, int c) :ID(a), Virtue(b), Talent(c) {}
	void setTag(int L, int H)
	{
		if (Virtue >= H && Talent >= H)
			tag = 0;
		else if (Virtue >= H && Talent < H)
			tag = 1;
		else if (Virtue < H && Talent < H && Virtue >= Talent)
			tag = 2;
		else
			tag = 3;
	}
};

bool operator<(const people &lhs, const people &rhs)
{
	int lhsTotal = lhs.Talent + lhs.Virtue, rhsTotal = rhs.Talent + rhs.Virtue;
	return
		lhs.tag < rhs.tag ||
		lhs.tag == rhs.tag && lhsTotal > rhsTotal ||
		lhs.tag == rhs.tag && lhsTotal == rhsTotal && lhs.Virtue > rhs.Virtue ||
		lhs.tag == rhs.tag && lhsTotal == rhsTotal && lhs.Virtue == rhs.Virtue && lhs.ID < rhs.ID;
}

int main()
{
	int N, L, H;
	scanf("%d %d %d", &N, &L, &H);
	vector<people> Peoples;
	for (int i = 0; i < N; ++i)
	{
		int id, virtue, talent;
		scanf("%d %d %d", &id, &virtue, &talent);
		if (virtue >= L && talent >= L)
		{
			people tmp(id, virtue, talent);
			tmp.setTag(L, H);
			Peoples.push_back(tmp);
		}
	}
	sort(Peoples.begin(), Peoples.end());
	printf("%d\n", Peoples.size());
	for (auto ch : Peoples)
	{
		printf("%08d %d %d\n", ch.ID, ch.Virtue, ch.Talent);
	}
	return 0;
}