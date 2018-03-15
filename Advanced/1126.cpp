#include<bits/stdc++.h>

using namespace std;

int N, M;
int degree[501];
int graph[501][501];
int visited[501];
int cnt;
void DFS(int V)
{
	visited[V] = 1;
	cnt++;
	for (int i = 1; i <= N; ++i)
		if (visited[i] == 0 && graph[V][i] == 1)
			DFS(i);
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		degree[v1]++;
		degree[v2]++;
		graph[v1][v2] = graph[v2][v1] = 1;
	}
	int odd = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (degree[i] % 2 != 0)
			odd++;
		printf("%d%s", degree[i], i == N ? "\n" : " ");
	}
	DFS(1);                        //注意连通图才能判断是否存在欧拉回路，若不连通，即使符合要求也不是欧拉回路
	if (odd == 0 && cnt == N)
		printf("Eulerian\n");
	else if (odd == 2 && cnt == N)
		printf("Semi-Eulerian\n");
	else
		printf("Non-Eulerian\n");
	return 0;
}
