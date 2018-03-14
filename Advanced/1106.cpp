#include<bits/stdc++.h>

using namespace std;

struct node
{
	int ID;
	double price;
	vector<int> childs;
}Nodes[100000];

int main()
{
	int N, id, num;
	double base, inc, price;
	scanf("%d %lf %lf", &N, &base, &inc);
	inc = (100 + inc) / 100;
	Nodes[0].price = base;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &num);
		for (int j = 0; j < num; ++j)
		{
			scanf("%d", &id);
			Nodes[i].childs.push_back(id);
		}
	}
	double minPrice = INFINITY;
	int lowestId = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		for (int i = 0; i < Nodes[curr].childs.size(); ++i)
		{
			int child = Nodes[curr].childs[i];
			q.push(child);
			Nodes[child].price = Nodes[curr].price*inc;
		}
		if (Nodes[curr].childs.empty())
		{
			if (Nodes[curr].price < minPrice)
			{
				minPrice = Nodes[curr].price;
				lowestId = 1;
			}
			else if (Nodes[curr].price == minPrice)
				lowestId++;
		}
	}
	printf("%.4lf %d\n", minPrice, lowestId);
	return 0;
};
