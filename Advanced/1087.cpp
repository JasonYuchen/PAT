#include<bits/stdc++.h>

using namespace std;

int Graph[200][200], visited[200], happiness[200], dist[200];
unordered_map<string, int> cityIndex;
unordered_map<int, string> to_city;
int N, K, cost;   //N - cities, K - roads
vector<vector<int>> paths;

int HF(const string &city)                             //城市名到编号的映射
{
	static int i = 0;
	auto it = cityIndex.find(city);
	if (it == cityIndex.end())
		return cityIndex[city] = i, i++;
	else
		return cityIndex[city];
}

vector<int> tmp_route, route;
double avg_gain;
int max_gain, routes;

void DFS(int V)
{
	tmp_route.push_back(V);
	if (V == 0)
	{
		int gain = 0;
		for (int i = 0; i < tmp_route.size(); ++i)
			gain += happiness[tmp_route[i]];
		double avg = gain * 1.0 / (tmp_route.size() - 1);
		if (gain > max_gain)                           //所有等距离路径中，优先最大幸福度
		{
			route = tmp_route;
			max_gain = gain;
			avg_gain = avg;
		}
		else if (gain == max_gain && avg > avg_gain)   //所有等距离、最大幸福度路径中，优先最大平均幸福度
		{
			route = tmp_route;
			avg_gain = avg;
		}
		routes++;                                      //记录最短路径条数
	}
	for (int i = 0; i < paths[V].size(); ++i)
		DFS(paths[V][i]);
	tmp_route.pop_back();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	fill(&Graph[0][0], &Graph[199][199] + 1, INT_MAX);
	fill(&dist[0], &dist[199] + 1, INT_MAX);
	cin >> N >> K;
	string start, tmp;
	cin >> start;
	HF(start);
	for (int i = 0; i < N - 1; ++i)
	{
		cin >> tmp;
		cin >> happiness[HF(tmp)];
	}
	for (auto st = cityIndex.begin(); st != cityIndex.end(); ++st)
		to_city[st->second] = st->first;
	for (int i = 0; i < K; ++i)
	{
		string src, dst;
		cin >> src >> dst >> cost;
		Graph[HF(src)][HF(dst)] = Graph[HF(dst)][HF(src)] = cost;
	}
	paths.resize(N);
	for (int i = 0; i < N; ++i)                       //Dijkstra获得多条最短路径
	{
		if (Graph[0][i] < INT_MAX)
		{
			dist[i] = Graph[0][i];
			paths[i].push_back(0);
		}
	}
	visited[0] = 1;
	while (true)
	{
		int V = -1, minDist = INT_MAX;
		for (int i = 0; i < N; ++i)
		{
			if (visited[i] == 0 && dist[i] < minDist)
			{
				minDist = dist[i];
				V = i;
			}
		}
		if (V == -1)
			break;
		visited[V] = 1;
		for (int W = 0; W < N; ++W)
		{
			if (Graph[V][W] < INT_MAX && visited[W] == 0)
			{
				if (dist[V] + Graph[V][W] < dist[W])
				{
					dist[W] = dist[V] + Graph[V][W];
					paths[W].clear();
					paths[W].push_back(V);
				}
				else if (dist[V] + Graph[V][W] == dist[W])
				{
					paths[W].push_back(V);
				}
			}
		}
	}
	DFS(HF("ROM"));
	cout << routes << " " << dist[HF("ROM")] << " " << max_gain << " " << (max_gain / (route.size() - 1)) << '\n';
	cout << to_city[0];
	for (int i = route.size() - 2; i >= 0; --i)
		cout << "->" << to_city[route[i]];
	return 0;
}
