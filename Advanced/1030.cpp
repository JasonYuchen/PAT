#include<bits/stdc++.h>

using namespace std;

struct edge
{
	int V;
	int dist;
	int cost;
	edge(int v, int l, int c) :V(v), dist(l), cost(c) {}
};

struct node
{
	vector<edge*> adjv;
}Nodes[500];

int main()
{
	//ios::sync_with_stdio(false);
	int dist[500], cost[500], pre[500], visited[500];
	fill(&dist[0], &dist[500], INT_MAX);
	fill(&cost[0], &cost[500], INT_MAX);
	fill(&pre[0], &pre[500], -1);
	fill(&visited[0], &visited[500], 0);
	int N, M, Src, Dst;
	scanf("%d %d %d %d", &N, &M, &Src, &Dst);
	for (auto i = 0; i < M; ++i)
	{
		int src, dst, len, cost;
		scanf("%d %d %d %d", &src, &dst, &len, &cost);
		Nodes[src].adjv.push_back(new edge(dst, len, cost));
		Nodes[dst].adjv.push_back(new edge(src, len, cost));
	}
	for (auto adjv : Nodes[Src].adjv)
	{
		dist[adjv->V] = adjv->dist;
		cost[adjv->V] = adjv->cost;
		pre[adjv->V] = Src;
	}
	dist[Src] = 0;
	visited[Src] = 1;
	while (true)
	{
		int V = -1, minDist = INT_MAX;
		for (auto i = 0; i < N; ++i)
		{
			if (dist[i] < minDist && visited[i] == 0)
			{
				minDist = dist[i];
				V = i;
			}
		}
		if (V == -1)
			break;
		visited[V] = 1;
		for (auto it = 0; it < Nodes[V].adjv.size(); it++)
		{
			auto W = Nodes[V].adjv[it]->V;
			auto cv = Nodes[V].adjv[it]->dist;
			auto ct = Nodes[V].adjv[it]->cost;
			if (visited[W] == 0)
			{
				if (dist[V] + cv < dist[W])
				{
					pre[W] = V;
					dist[W] = dist[V] + cv;
					cost[W] = cost[V] + ct;
				}
				else if (dist[V] + cv == dist[W] && cost[V] + ct < cost[W])
				{
					pre[W] = V;
					cost[W] = cost[V] + ct;
				}
			}
		}
	}
	int last = pre[Dst];
	vector<int> route;
	while (last != -1)
	{
		route.push_back(last);
		last = pre[last];
	}
	for_each(route.rbegin(), route.rend(), [](int i) {printf("%d ", i); });
	printf("%d %d %d", Dst, dist[Dst], cost[Dst]);
	return 0;
}
