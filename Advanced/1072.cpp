#include<bits/stdc++.h>

using namespace std;

struct result
{
	int gas, minimum, total;
	result(int g, int m, int t) :gas(g), minimum(m), total(t) {}
};
bool operator<(const result &lhs, const result &rhs)   //根据题目要求排序所有符合条件的站点
{
	return lhs.minimum > rhs.minimum ||
		lhs.minimum == rhs.minimum && lhs.total < rhs.total ||
		lhs.minimum == rhs.minimum && lhs.total == rhs.total && lhs.gas < rhs.gas;
}

int Graph[1011][1011], Dist[11][1011], visited[1011];  //Dist存储每个站点的距离表
int N, M, K, Ds; //N - total houses, M - candidate locations, K - roads, Ds - maximum service range

void Dijkstra(int gas)
{
	Dist[gas - N][gas] = 0;
	visited[gas] = 1;
	for (int i = 1; i <= N + M; ++i)
		if (Graph[gas][i] < INT_MAX)
			Dist[gas - N][i] = Graph[gas][i];
	while (true)
	{
		int V = -1, minDist = INT_MAX;
		for (int i = 1; i <= N + M; ++i)
			if (visited[i] == 0 && Dist[gas - N][i] < minDist)
			{
				V = i;
				minDist = Dist[gas - N][i];
			}
		if (V == -1) 
			break;
		visited[V] = 1;
		for (int W = 1; W <= N + M; ++W)
			if (Graph[V][W] < INT_MAX && visited[W] == 0)
				if (Dist[gas - N][V] + Graph[V][W] < Dist[gas - N][W])
					Dist[gas - N][W] = Dist[gas - N][V] + Graph[V][W];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> N >> M >> K >> Ds;
	fill(&Dist[0][0], &Dist[10][1010] + 1, INT_MAX);
	fill(&Graph[0][0], &Graph[1010][1010] + 1, INT_MAX);
	for (int i = 0; i < K; ++i)                //1~N点对应house点，N+1~M点对应gas站点
	{
		string src, dst;
		int v, w, dist;
		cin >> src >> dst >> dist;
		if (src[0] == 'G')
			v = N + stoi(string(src.begin() + 1, src.end()));
		else
			v = stoi(src);
		if (dst[0] == 'G')
			w = N + stoi(string(dst.begin() + 1, dst.end()));
		else
			w = stoi(dst);
		Graph[v][w] = Graph[w][v] = dist;
	}
	for (int i = 1; i <= M; ++i)
	{
		fill(visited, visited + 1011, 0);
		Dijkstra(N + i);                       //对每个gas站点都执行一次Dijkstra
	}
	vector<result> res;
	for (int gas = 1; gas <= M; ++gas)
	{
		int flag = 1, minimum = INT_MAX, total = 0;
		for (int W = 1; W <= N; ++W)
		{
			if (Dist[gas][W] > Ds)             //超出服务距离Ds的结果被忽略
			{
				flag = 0;
				break;
			}
			total += Dist[gas][W];             //当前站gas与所有house的距离和
			if (Dist[gas][W] < minimum)
				minimum = Dist[gas][W];        //记录当前站gas距离所有house最小的距离
		}
		if (flag == 0)
			continue;
		res.push_back(result{ gas,minimum,total });
	}
	sort(res.begin(), res.end());
	if (res.size() == 0)
		cout << "No Solution" << endl;
	else
		cout << "G" << res[0].gas << '\n' << setiosflags(ios::fixed) << setprecision(1) 
			<< (res[0].minimum * 1.0) << " " << (res[0].total * 1.0 / N) << '\n';
	return 0;
}
