#include<bits/stdc++.h>

using namespace std;

struct node
{
	int key;
	int next;
}Nodes[100000];

int main()
{
	unordered_set<int> test;
	vector<int> remain, remove;
	int N, start;
	scanf("%d %d", &start, &N);
	for (int i = 0; i < N; ++i)
	{
		int addr, key, next;
		scanf("%d %d %d", &addr, &key, &next);
		Nodes[addr].key = key;
		Nodes[addr].next = next;
	}
	int addr = start;
	while (addr != -1)
	{
		auto it = test.find(std::abs(Nodes[addr].key));
		if (it == test.end())
		{
			test.insert(std::abs(Nodes[addr].key));
			remain.push_back(addr);
		}
		else
		{
			remove.push_back(addr);
		}
		addr = Nodes[addr].next;
	}
	printf("%05d %d ", remain[0], Nodes[remain[0]].key);
	for (int i = 1; i < remain.size(); ++i)
		printf("%05d\n%05d %d ", remain[i], remain[i], Nodes[remain[i]].key);
	printf("-1\n");
	if (remove.size() == 0)              //有可能没有重复，此时不用任何输出直接返回
		return 0;
	printf("%05d %d ", remove[0], Nodes[remove[0]].key);
	for (int i = 1; i < remove.size(); ++i)
		printf("%05d\n%05d %d ", remove[i], remove[i], Nodes[remove[i]].key);
	printf("-1\n");
	return 0;
}