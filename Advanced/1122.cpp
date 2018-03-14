#include<bits/stdc++.h>

using namespace std;

int graph[201][201];

int main()
{
	int N, M, K;   //N - vertices, M - edges, K - queries
	set<int> visited;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		graph[v1][v2] = graph[v2][v1] = 1;
	}
	scanf("%d", &K);
	for (int i = 0; i < K; ++i)
	{
		int n, st, preV, V, flag = 1;
		scanf("%d %d", &n, &st);
		visited.clear();
		visited.insert(st);
		preV = st;
		for (int j = 1; j < n; ++j)
		{
			scanf("%d", &V);
			if (flag == 0)
				continue;
			if (graph[preV][V] == 0 || V != st && visited.find(V) != visited.end())   //路径前后两点有路可走，且点只访问一次
				flag = 0;
			visited.insert(V);
			preV = V;
		}
		if (flag == 0 || visited.size() != N || V != st)       //所有点都访问到，并且回到起点，才是哈密顿回路
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
