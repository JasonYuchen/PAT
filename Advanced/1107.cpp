#include<bits/stdc++.h>

using namespace std;

int Graph[2001][2001];    //1000个people结点，1000个hobby结点
int visited[2001];
int N, cnt;
void DFS(int V)
{
	visited[V] = 1;
	if (V <= N)           //V<=N说明是people结点，cnt++
		cnt++;
	for (int i = 1; i <= N + 1000; ++i)
		if (visited[i] == 0 && Graph[V][i] == 1)
			DFS(i);
}

int main()
{
	scanf("%d", &N);
	fill(&Graph[0][0], &Graph[2000][2000] + 1, INT_MAX);
	for (int i = 1; i <= N; ++i)
	{
		int n;
		scanf("%d:", &n);
		for (int j = 0; j < n; ++j)
		{
			int hobby;
			scanf("%d", &hobby);
			Graph[i][N + hobby] = Graph[N + hobby][i] = 1;
		}
	}
	vector<int> ret;
	for (int i = 1; i <= N; ++i)
	{
		cnt = 0;
		if (visited[i] == 0)
			DFS(i);
		if(cnt != 0)
			ret.push_back(cnt);
	}
	sort(ret.begin(), ret.end(), greater<int>());
	printf("%d\n", ret.size());
	printf("%d", ret[0]);
	for (int i = 1; i < ret.size(); ++i)
		printf(" %d", ret[i]);
	return 0;
};

/******************************************************************************************
Disjoint Sets

int findRoot(vector<int> &S, int x)
{
	if (S[x] < 0)
		return x;
	else
		return S[x] = findRoot(S, S[x]);
}

void unionSet(vector<int> &S, int x, int y)
{
	int root1 = findRoot(S, x);
	int root2 = findRoot(S, y);
	if (root1 == root2)
		return;
	if (root1 < root2)
	{
		S[root1] += S[root2];
		S[root2] = root1;
	}
	else
	{
		S[root2] += S[root1];
		S[root1] = root2;
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> people(N + 1, -1), hobby(1001, -1);  //hobby[i]记录第一个出现爱好i的人的下标
	for (int i = 1; i <= N; ++i)
	{
		int n, h;
		scanf("%d:", &n);
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &h);
			if (hobby[h] == -1)
				hobby[h] = i;
			else
				unionSet(people, hobby[h], i);       //已有人爱好是h，则合并现在的人所在的集合和此前人所在的集合
		}
	}
	vector<int> ret;
	for (int i = 1; i <= N; ++i)
	{
		if (people[i] < 0)
			ret.push_back(-people[i]);
	}
	sort(ret.begin(), ret.end(), greater<int>());
	printf("%d\n%d", ret.size(), ret[0]);
	for (int i = 1; i < ret.size(); ++i)
		printf(" %d", ret[i]);
	return 0;
}
******************************************************************************************/