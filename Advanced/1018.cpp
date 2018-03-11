#include<bits/stdc++.h>

using namespace std;

int Cmax, N, Sp, M;
int Graph[501][501], visited[501], bike[501], dist[501];
vector<int> pre[501];                           //每个结点一个vector<int>记录前一个（或多个）结点

void Dijkstra()
{
	for (int i = 1; i <= N; ++i)
	{
		if (Graph[0][i] < INT_MAX)
		{
			dist[i] = Graph[0][i];
			pre[i].push_back(0);
		}
	}
	visited[0] = 1;
	dist[0] = 0;
	while (true)
	{
		int V = -1, minDist = INT_MAX;
		for (int W = 1; W <= N; ++W)
		{
			if (visited[W] == 0 && dist[W] < minDist)
			{
				minDist = dist[W];
				V = W;
			}
		}
		if (V == -1)
			break;
		visited[V] = 1;
		for (int W = 1; W <= N; ++W)
		{
			if (Graph[V][W] < INT_MAX && visited[W] == 0)
			{
				if (dist[V] + Graph[V][W] < dist[W])
				{
					pre[W].clear();
					pre[W].push_back(V);
					dist[W] = dist[V] + Graph[V][W];
				}
				else if (dist[V] + Graph[V][W] == dist[W])
				{
					pre[W].push_back(V);
				}
			}
		}
	}
}

vector<int> tmp_route, route; 
int take_from = INT_MAX, take_back = INT_MAX;   //所有最短路径中，至少需要从PBMC带出的数量和最少从Sp带回的数量    

void DFS(int V)
{
	tmp_route.push_back(V);
	if (V == 0)
	{
		int tmp_from = 0, tmp_bike = 0;         //tmp_from是平衡到目前的点之前需要PBMC带出的数量，tmp_bike是从目前的点之前盈余出来的数量
		for (int i = tmp_route.size() - 2; i >= 0; --i)
		{
			if (bike[tmp_route[i]] + tmp_bike < Cmax / 2)        //若某点自身数量+从前面带过来的车的数量不足半满，则需要增加PBMC带出的数量，同时盈余数量归零
			{
				tmp_from += Cmax / 2 - tmp_bike - bike[tmp_route[i]];
				tmp_bike = 0;
			}
			else if (bike[tmp_route[i]] + tmp_bike > Cmax / 2)   //若某点自身数量+从前面带过来的车的数量超过半满，则盈余数量加上超出的部分
			{
				tmp_bike += bike[tmp_route[i]] - Cmax / 2;
			}
		}
		if (tmp_from < take_from)               //优先选择PBMC带出量少的路，相等则选择Sp平衡后盈余量少的路
		{
			route = tmp_route;
			take_from = tmp_from;
			take_back = tmp_bike;
		}
		else if (tmp_from == take_from && tmp_bike < take_back)
		{
			route = tmp_route;
			take_back = tmp_bike;
		}
	}
	else
	{
		for (int i = 0; i < pre[V].size(); ++i)
			DFS(pre[V][i]);
	}
	tmp_route.pop_back();
}

int main()
{

	fill(&Graph[0][0], &Graph[500][500] + 1, INT_MAX);
	fill(&dist[0], &dist[501], INT_MAX);
	scanf("%d %d %d %d", &Cmax, &N, &Sp, &M);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &bike[i]);
	for (int i = 0; i < M; ++i)
	{
		int v, w, cost;
		scanf("%d %d %d", &v, &w, &cost);
		Graph[v][w] = Graph[w][v] = cost;
	}
	Dijkstra();
	DFS(Sp);
	printf("%d 0", take_from);
	for (int i = route.size() - 2; i >= 0; --i)
		printf("->%d", route[i]);
	printf(" %d\n", take_back);
	return 0;
}