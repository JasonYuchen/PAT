#include<bits/stdc++.h>

using namespace std;

int Graph[1001][1001], visited[1001];
int main()
{
	int N, L;
	scanf("%d %d", &N, &L);
	for (int i = 1; i <= N; ++i)
	{
		int n, userID;
		scanf("%d", &n);
		for (int j = 1; j <= n; ++j)
		{
			scanf("%d", &userID);
			Graph[userID][i] = 1;   //代表userID被i关注，即userID的微博会被i可见并转发，有向图
		}
	}
	fill(visited, visited + 1001, 0);
	int K, ID;
	scanf("%d", &K);
	for (int i = 0; i < K; ++i)
	{
		scanf("%d", &ID);
		int cnt = -1, last = ID, tail, curr, level = 0;
		fill(visited, visited + 1001, 0);
		queue<int> q;               //BFS
		visited[ID] = 1;
		q.push(ID);
		while (!q.empty())
		{
			int curr = q.front();
			q.pop();
			cnt++;
			for (int id = 1; id <= N; ++id)
			{
				if (Graph[curr][id] == 1 && visited[id] == 0)
				{
					tail = id;
					visited[id] = 1;
					q.push(id);
				}
			}
			if (last == curr)       //新增一层
			{
				last = tail;
				level++;
			}
			if (level > L)          //超过L层了就不再统计
				break;
		}
		printf("%d\n", cnt);
	}
	return 0;
}