#include<bits/stdc++.h>

using namespace std;

int Glength[500][500], Gtime[500][500];
int visited[500], dist[500], timet[500], through[500];

int main()
{
	int N, M;
	fill(&Glength[0][0], &Glength[499][499] + 1, INT_MAX);
	fill(&Gtime[0][0], &Gtime[499][499] + 1, INT_MAX);
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i)
	{
		int V1, V2, one, l, t;
		scanf("%d %d %d %d %d", &V1, &V2, &one, &l, &t);
		if (one == 1)                                     //one-way代表单行道，即有向边
		{
			Glength[V1][V2] = l;
			Gtime[V1][V2] = t;
		}
		else
		{
			Glength[V1][V2] = Glength[V2][V1] = l;
			Gtime[V1][V2] = Gtime[V2][V1] = t;
		}
	}
	int Src, Dst;
	scanf("%d %d", &Src, &Dst);
	vector<int> pathDist(500, -1), pathTime(500, -1);
	fill(&dist[0], &dist[499] + 1, INT_MAX);              //获得最短Distance的Dijkstra，同等Distance选Time更小的
	fill(&timet[0], &timet[499] + 1, INT_MAX);
	fill(&visited[0], &visited[499] + 1, 0);
	for (int i = 0; i < N; ++i)
	{
		if (Glength[Src][i] < INT_MAX)
		{
			dist[i] = Glength[Src][i];
			timet[i] = Gtime[Src][i];
			pathDist[i] = Src;
		}
	}
	timet[Src] = 0;
	dist[Src] = 0;
	visited[Src] = 1;
	while (true)
	{
		int V = -1, minDist = INT_MAX;
		for (int i = 0; i < N; ++i)
		{
			if (visited[i] == 0 && dist[i] < minDist)
			{
				V = i;
				minDist = dist[i];
			}
		}
		if (V == -1)
			break;
		visited[V] = 1;
		for (int i = 0; i < N; ++i)
		{
			if (visited[i] == 0 && Glength[V][i] < INT_MAX)
			{
				if (dist[V] + Glength[V][i] < dist[i])
				{
					dist[i] = dist[V] + Glength[V][i];
					timet[i] = timet[V] + Gtime[V][i];
					pathDist[i] = V;
				}
				else if (dist[V] + Glength[V][i] == dist[i] && timet[V] + Gtime[V][i] < timet[i])
				{
					timet[i] = timet[V] + Gtime[V][i];
					pathDist[i] = V;
				}
			}
		}
	}
	                                                      //获得最短Time的Dijkstra，同等Time选经过的结点数更小的
	fill(&timet[0], &timet[499] + 1, INT_MAX);            //注意，前一个Dijkstra修改了每个点的Time，这里要重新初始化
	fill(&through[0], &through[499] + 1, INT_MAX); 
	fill(&visited[0], &visited[499] + 1, 0);              //注意，前一个Dijkstra修改了每个点的visited，这里要重新初始化
	for (int i = 0; i < N; ++i)
	{
		if (Glength[Src][i] < INT_MAX)
		{
			timet[i] = Gtime[Src][i];
			through[i] = 1;
			pathTime[i] = Src;
		}
	}
	visited[Src] = 1;
	through[Src] = 0;
	timet[Src] = 0;
	while (true)
	{
		int V = -1, minTime = INT_MAX;
		for (int i = 0; i < N; ++i)
		{
			if (visited[i] == 0 && timet[i] < minTime)
			{
				V = i;
				minTime = timet[i];
			}
		}
		if (V == -1)
			break;
		visited[V] = 1;
		for (int i = 0; i < N; ++i)
		{
			if (visited[i] == 0 && Glength[V][i] < INT_MAX)
			{
				if (timet[V] + Gtime[V][i] < timet[i])
				{
					timet[i] = timet[V] + Gtime[V][i];
					through[i] = through[V] + 1;
					pathTime[i] = V;
				}
				else if (timet[V] + Gtime[V][i] == timet[i] && through[V] + 1 < through[i])
				{
					through[i] = through[V] + 1;
					pathTime[i] = V;
				}
			}
		}
	}
	stack<int> retD, retT;                                //根据结点压入堆栈，随后顺序输出，堆栈直接比较判断是否同一条路
	int tmp = Dst;
	while (tmp != Src)
	{
		retD.push(tmp);
		tmp = pathDist[tmp];
	}
	tmp = Dst;
	while (tmp != Src)
	{
		retT.push(tmp);
		tmp = pathTime[tmp];
	}
	if (retD == retT)
	{
		printf("Distance = %d; Time = %d: %d", dist[Dst], timet[Dst], Src);
		while (!retD.empty())
		{
			printf(" -> %d", retD.top());
			retD.pop();
		}
		printf("\n");
	}
	else
	{
		printf("Distance = %d: %d", dist[Dst], Src);
		while (!retD.empty())
		{
			printf(" -> %d", retD.top());
			retD.pop();
		}
		printf("\n");
		printf("Time = %d: %d", timet[Dst], Src);
		while (!retT.empty())
		{
			printf(" -> %d", retT.top());
			retT.pop();
		}
		printf("\n");
	}
	return 0;
};
