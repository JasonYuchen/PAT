#include<bits/stdc++.h>

using namespace std;

struct node
{
	int Key;
	vector<int> Adj;
}Nodes[10001];

int Visited[10001];
int deepest = 0, tmp_deepest;
vector<int> deepestRoot;

void BFS(int st)
{
	queue<int> q;
	q.push(st);
	int last = st, tail = st;
	while (!q.empty())
	{
		auto V = q.front();
		q.pop();
		Visited[V] = 1;
		for (auto ch : Nodes[V].Adj)
		{
			if (Visited[ch] == 0)
			{
				q.push(ch);
				tail = ch;
			}
		}
		if (V == last)                      //当前结点是本层末尾结点
		{
			last = tail;                    //令last指向下一层末尾结点
			tmp_deepest++;                  //BFS每增加一层，树深+1
		}
	}
}

int main()
{
	int N, connect = 0;
	scanf("%d", &N);
	for (int i = 1; i < N; ++i)
	{
		int src, dst;
		scanf("%d %d", &src, &dst);
		Nodes[src].Adj.push_back(dst);
		Nodes[dst].Adj.push_back(src);
	}
	for (int i = 1; i <= N; ++i)
	{
		if (Visited[i] == 0)
		{
			BFS(i);
			connect++;                      //统计连通分量
		}
	}
	if (connect != 1)
	{
		printf("Error: %d components\n", connect);
		return 0;
	}
	for (int i = 1; i <= N; ++i)
	{
		fill(Visited, Visited + 10000, 0);  //注意每个点BFS时要把已访问全部清零同时树深清零
		tmp_deepest = 0;
		BFS(i);
		if (tmp_deepest > deepest)          //利用vector记录最深根结点
		{
			deepestRoot.clear();            //若有新的最深深度，则原来的结点全部清除
			deepestRoot.push_back(i);
			deepest = tmp_deepest;
		}
		else if (tmp_deepest == deepest)
		{
			deepestRoot.push_back(i);       //同等深度则添加新的结点
		}
	}
	for (auto ch : deepestRoot)
		printf("%d\n", ch);
	return 0;
}
