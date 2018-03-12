#include<bits/stdc++.h>

using namespace std;

struct node
{
	int ID, products = 0;
	double price;
	vector<int> childs;
}Nodes[100000];

int main()
{
	int N;
	double price, inc, total = 0.0;
	scanf("%d %lf %lf", &N, &price, &inc);
	Nodes[0].price = price;
	inc = (100 + inc) / 100;
	for (int i = 0; i < N; ++i)
	{
		int n;
		scanf("%d", &n);
		if (n == 0)
			scanf("%d", &Nodes[i].products);
		else
			for (int j = 0; j < n; ++j)
			{
				int id;
				scanf("%d", &id);
				Nodes[i].childs.push_back(id);
			}
	}
	queue<int> q;
	q.push(0);
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		if (Nodes[curr].childs.empty())
			total += Nodes[curr].price*Nodes[curr].products;
		else
		{
			for (auto it = Nodes[curr].childs.begin(); it != Nodes[curr].childs.end(); ++it)
			{
				int id = *it;
				Nodes[id].price = Nodes[curr].price * inc;
				q.push(id);
			}
		}
	}
	printf("%.1lf\n", total);
	return 0;
}
