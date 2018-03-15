#include<bits/stdc++.h>

using namespace std;

struct node
{
	vector<int> edge;
}Nodes[10000];

int main()
{
	int N, M, K;
	scanf("%d %d", &N, &M);
	unordered_set<int> edge;             //用散列表存储每个点集接触到的边
	for (int i = 0; i < M; ++i)
	{
		int v, w;
		scanf("%d %d", &v, &w);
		Nodes[v].edge.push_back(i);      //每条边编号为0~M-1
		Nodes[w].edge.push_back(i);
	}
	scanf("%d", &K);
	for (int i = 0; i < K; ++i)
	{
		int n;
		scanf("%d", &n);
		edge.clear();
		for (int j = 0; j < n; ++j)
		{
			int v;
			scanf("%d", &v);
			for (int k = 0; k < Nodes[v].edge.size(); ++k)
			{
				edge.insert(Nodes[v].edge[k]);
			}
		}
		if (edge.size() == M)            //若接触到所有边，即覆盖
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
