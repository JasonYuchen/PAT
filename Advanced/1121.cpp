#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d", &N);
	unordered_set<int> come;
	vector<int> a(100000, -1), b(100000, -1);
	set<int> alone;
	for (int i = 0; i < N; ++i)
	{
		int id1, id2;
		scanf("%d %d", &id1, &id2);
		a[id1] = id2;
		b[id2] = id1;
	}
	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		int id;
		scanf("%d", &id);
		come.insert(id);
	}
	for (auto it = come.begin(); it != come.end(); ++it)
	{
		int id = *it;
		if (a[id] == -1 && b[id] == -1)
			alone.insert(id);
		else if (a[id] != -1 && come.find(a[id]) == come.end())
			alone.insert(id);
		else if (b[id] != -1 && come.find(b[id]) == come.end())
			alone.insert(id);
	}
	printf("%d\n", alone.size());
	if (alone.size() == 0)
		return 0;
	printf("%05d", *alone.begin());
	for (auto it = ++alone.begin(); it != alone.end(); ++it)
		printf(" %05d", *it);
	return 0;
}