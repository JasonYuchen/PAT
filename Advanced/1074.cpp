#include<bits/stdc++.h>

using namespace std;

struct node
{
	int key;
	int next;
}Nodes[100000];

int main()
{
	int N, K, start, addr, key, next;
	scanf("%d %d %d", &start, &N, &K);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d %d", &addr, &key, &next);
		Nodes[addr].key = key;
		Nodes[addr].next = next;
	}
	vector<node*> lst;
	addr = start;
	while (addr != -1)
	{
		lst.push_back(&Nodes[addr]);
		addr = Nodes[addr].next;
	}
	for (int i = 0; i + K <= lst.size(); i += K)      //可能有多余的结点，因此这里是<=lst.size而不是<=N
	{
		reverse(lst.begin() + i, lst.begin() + i + K);
	}
	printf("%05d %d ", lst[0] - Nodes, lst[0]->key);
	for (int i = 1; i < lst.size(); ++i)
	{
		printf("%05d\n%05d %d ", lst[i] - Nodes, lst[i] - Nodes, Nodes[lst[i] - Nodes].key);
	}
	printf("-1\n");
	return 0;
}