#include<bits/stdc++.h>

using namespace std;

int N, M, K;
int Graph[1001][1001];
int visited[1001];

void DFS(int V)
{
	visited[V] = 1;
	for (int i = 1; i <= N; ++i)
		if (Graph[V][i] == 1 && visited[i] == 0)
			DFS(i);
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < M; ++i)
	{
		int v, w;
		scanf("%d %d", &v, &w);
		Graph[v][w] = Graph[w][v] = 1;
	}
	for (int i = 0; i < K; ++i)
	{
		int v, cnt = 0;
		scanf("%d", &v);
		fill(&visited[0], &visited[1001], 0);
		visited[v] = 1;                   //将要分割的点标记为已访问，就会阻止DFS通过，由此诞生多个连通分量
		for (int j = 1; j <= N; ++j)
		{
			if (visited[j] == 0)
			{
				cnt++;
				DFS(j);
			}
		}
		printf("%d\n", cnt - 1);          //N个连通分量可以通过N-1条边来构建成一个完整的连通图
	}
	return 0;
}