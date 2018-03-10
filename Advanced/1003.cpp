#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;                                    //顶点数
	int M;                                    //边数
	int Src, Dst;                             //起点Src，终点Dst
	scanf("%d %d %d %d", &N, &M, &Src, &Dst);
	int Graph[500][500];
	for (auto i = 0; i < 500; ++i)
		for (auto j = 0; j < 500; ++j)
			Graph[i][j] = INT_MAX;
	int RescuesOfCity[500];                   //记录每个顶点的搜救队数目
	for (auto i = 0; i < N; ++i)
	{
		int num;
		scanf("%d", &num);
		RescuesOfCity[i] = num;
	}
	for (auto i = 0; i < M; ++i)
	{
		int src, dst, weight;
		scanf("%d %d %d", &src, &dst, &weight);
		Graph[src][dst] = Graph[dst][src] = weight;
	}

	int Visited[500];                         //记录已访问点，已访问就是1，未访问就是0
	int DistFromSrc[500];                     //记录从Src到每个点的距离
	int RescuesOfPath[500];                   //记录从Src到每个点可以聚集的搜救队的数目
	int Ways[500];                            //记录从Src到每个点可以走的最短路径数目
	for (auto i = 0; i < N; ++i)              //初始化上述四个向量
	{
		Visited[i] = 0;
		DistFromSrc[i] = Graph[Src][i];
		RescuesOfPath[i] = RescuesOfCity[i];
		Ways[i] = 0;
		if (Graph[Src][i] < INT_MAX)        //若是Src的邻接点，注意Graph[Src][Src] = INT_MAX
		{
			Ways[i] = 1;                  //则可以抵达的路初始化为1，即Src直接到i
			RescuesOfPath[i] = RescuesOfCity[Src] + RescuesOfCity[i];  //同样搜救队的数目就是Src的数目+i点的数目
		}
	}
	DistFromSrc[Src] = 0;                     //到起点的距离为0
	Visited[Src] = 1;
	Ways[Src] = 1;                            //到起点的路径是1条
	while (true)
	{
		int next = -1, min = INT_MAX;       //线性搜索最近点，可以封装成FindMin
		for (auto i = 0; i < N; ++i)
		{
			if (DistFromSrc[i] < min && Visited[i] == 0)
			{
				min = DistFromSrc[i];
				next = i;
			}
		}
		if (next == -1)
			break;
		Visited[next] = 1;                  //next是当前顶点并标记已访问
		for (auto i = 0; i < N; ++i)
		{
			if (Graph[next][i] < INT_MAX && Visited[i] == 0)
			{
				//i是当前顶点next的邻接点，若发现从next有更短的路到i，则更新距离和搜救队数量，可选最短路径数量保持不变
				if (DistFromSrc[next] + Graph[next][i] < DistFromSrc[i])
				{
					DistFromSrc[i] = DistFromSrc[next] + Graph[next][i];
					RescuesOfPath[i] = RescuesOfPath[next] + RescuesOfCity[i];
					Ways[i] = Ways[next];     //最短路只能从next到i，因此到next有几条，到i就有几条
				}
				//若发现从next到i有同样短的路，但是搜救队更多，则更新搜救队，同时更新可选最短路数目
				else if (DistFromSrc[next] + Graph[next][i] == DistFromSrc[i] &&
					RescuesOfPath[next] + RescuesOfCity[i] > RescuesOfPath[i])
				{
					RescuesOfPath[i] = RescuesOfPath[next] + RescuesOfCity[i];
					Ways[i] += Ways[next];    //最短路是到i的数量加上到next的数量，因此"+="
				}
				//若仅仅发现同样短的路，也要更新可选最短路数目
				else if (DistFromSrc[next] + Graph[next][i] == DistFromSrc[i])
				{
					Ways[i] += Ways[next];    //最短路是到i的数量加上到next的数量，因此"+="
				}
			}
		}
	}
	printf("%d %d", Ways[Dst], RescuesOfPath[Dst]);
	return 0;
}
