#include<bits/stdc++.h>

using namespace std;

vector<int> AdjV[10000];     
int Graph[10000][10000];
int visited[10000];
vector<int> tmp_route, route;
int tmp_trans, trans;

int getTrans()                       //获得转乘线路的次数
{
	int cnt = 0, prev = 0, v = tmp_route[0], w;
	for (int i = 1; i < tmp_route.size(); ++i)
	{
		w = tmp_route[i];
		if (Graph[v][w] != prev)
		{
			prev = Graph[v][w];
			cnt++;
		}
		v = w;
	}
	return cnt;
}

void DFS(int V, int dst)
{
	tmp_route.push_back(V);
	visited[V] = 1;
	if (V == dst)
	{
		if (tmp_route.size() < route.size() 
			|| route.size() == 0)    //获得首条路线时无论size都赋值给route
		{
			route = tmp_route;
			trans = getTrans();
		}
		else if (tmp_route.size() == route.size())
		{
			tmp_trans = getTrans();
			if (tmp_trans < trans)
			{
				route = tmp_route;
				trans = tmp_trans;
			}
		}
	}
	else
	{
		for (int i = 0; i < AdjV[V].size(); ++i)
			if(visited[AdjV[V][i]] == 0)
				DFS(AdjV[V][i], dst);
	}
	visited[V] = 0;                  //返回时需要visited[V] = 0，这里与Dijkstra不同
	tmp_route.pop_back();
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		int M, v, w;
		scanf("%d %d", &M, &v);
		for (int j = 1; j < M; ++j)
		{
			scanf("%d", &w);
			Graph[v][w] = Graph[w][v] = i;   //Graph[v][w]记录从站v到站w这一段所属于的线路为i（这种情况所属线路唯一）
			AdjV[v].push_back(w);
			AdjV[w].push_back(v);
			v = w;
		}
	}
	int K, st, ed;
	scanf("%d", &K);
	for (int i = 0; i < K; ++i)
	{
		scanf("%d %d", &st, &ed);
		fill(visited, visited + 10000, 0);   //每轮DFS前都务必初始化所有相关数据
		route.clear();
		trans = 0;
		DFS(st, ed);
		int w = route[1], prev = Graph[st][w];
		printf("%d\nTake Line#%d from %04d to ", route.size() - 1, Graph[st][w], st);
		for (int j = 2; j < route.size(); ++j)
		{
			st = w;
			w = route[j];
			if (Graph[st][w] != prev)
			{
				printf("%04d.\nTake Line#%d from %04d to ", st, Graph[st][w], st);
				prev = Graph[st][w];
			}
		}
		printf("%04d.\n", ed);
	}
	return 0;
}