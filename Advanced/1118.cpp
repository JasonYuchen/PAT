#include<bits/stdc++.h>

using namespace std;

int Find(vector<int> &S, int X)
{
	if (S[X] < 0)
		return X;
	else
		return S[X] = Find(S, S[X]);
}
void Union(vector<int> &S, int X, int Y)
{
	int root1 = Find(S, X), root2 = Find(S, Y);
	if (root1 < root2)
	{
		S[root1] += S[root2];
		S[root2] = root1;
	}
	else if (root1 > root2)
	{
		S[root2] += S[root1];
		S[root1] = root2;
	}
}

int main()
{
	int N, K, id0, id;
	unordered_set<int> birds;
	vector<int> S(10001, -1);
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &K);
		for (int j = 0; j < K; ++j)
		{
			scanf("%d", &id);
			if (j == 0)
				id0 = id;
			birds.insert(id);
			Union(S, id, id0);
		}
	}
	int cnt = 0;
	for (auto c : birds)
	{
		if (S[c] < 0)
			cnt++;
	}
	printf("%d %d\n", cnt, birds.size());
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d", &id0, &id);
		if (Find(S, id0) == Find(S, id))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
};
