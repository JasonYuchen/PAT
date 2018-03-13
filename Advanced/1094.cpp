#include<bits/stdc++.h>

using namespace std;

struct node
{
	int ID;
	vector<int> childs;
}Nodes[100];

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i)
	{
		int id, n, childId;
		scanf("%d %d", &id, &n);
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", &childId);
			Nodes[id].childs.push_back(childId);
		}
	}

	int maxPopulation = 0, maxLevel, population = 0, level = 1;
	int curr, tail, last = 1;
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		population++;
		for (int i = 0; i < Nodes[curr].childs.size(); ++i)
		{
			q.push(Nodes[curr].childs[i]);
			tail = Nodes[curr].childs[i];
		}
		if (last == curr)
		{
			if (population > maxPopulation)
			{
				maxPopulation = population;
				maxLevel = level;
			}
			last = tail;
			level++;
			population = 0;
		}
	}
	printf("%d %d", maxPopulation, maxLevel);
	return 0;
}
