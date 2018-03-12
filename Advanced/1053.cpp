#include<bits/stdc++.h>

using namespace std;

struct node
{
	int weight;
	vector<node*> childs;
}Nodes[100];

vector<vector<int>> paths;
vector<int> tmp_path;
int W;      //the given weight

void DFS(int id, int &weight)
{
	tmp_path.push_back(Nodes[id].weight);
	weight += Nodes[id].weight;
	if (weight == W && Nodes[id].childs.empty())      //权重符合要求，且抵达叶结点，则是复合要求的路
	{
		paths.push_back(tmp_path);
	}
	else if (weight < W && !Nodes[id].childs.empty()) //若权重还不够，且未到叶结点，则继续DFS
	{
		for (int i = 0; i < Nodes[id].childs.size(); ++i)
		{
			int _id = Nodes[id].childs[i] - Nodes;
			DFS(_id, weight);
		}
	}
	tmp_path.pop_back();
	weight -= Nodes[id].weight;
}

int main()
{                              
	int N, M;
	scanf("%d %d %d", &N, &M, &W);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &Nodes[i].weight);
	}
	for (int i = 0; i < M; ++i)
	{
		int ID, nums;
		scanf("%d %d", &ID, &nums);
		for (int j = 0; j < nums; ++j)
		{
			int child;
			scanf("%d", &child);
			Nodes[ID].childs.push_back(&Nodes[child]);
		}
	}
	int weight = 0;
	DFS(0, weight);
	sort(paths.begin(), paths.end(), greater<vector<int>>());
	for (auto &ch : paths)
	{
		printf("%d", ch[0]);
		for (int i = 1; i < ch.size(); ++i)
		{
			printf(" %d", ch[i]);
		}
		printf("\n");
	}
	return 0;
}
