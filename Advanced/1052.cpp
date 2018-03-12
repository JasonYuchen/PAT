#include<bits/stdc++.h>

using namespace std;

struct node
{
	int key;
	int next;
}Node[100000];

bool cmp(const node *lhs, const node *rhs)
{
	return lhs->key < rhs->key;
}

int main()
{
	int N, start;
	scanf("%d %d", &N, &start);
	vector<node*> lst;
	for (int i = 0; i < N; ++i)
	{
		int addr, key, next;
		scanf("%d %d %d", &addr, &key, &next);
		Node[addr].key = key;
		Node[addr].next = next;
	}
	int addr = start;
	while (addr != -1)
	{
		auto tmp = &Node[addr];
		addr = tmp->next;
		lst.push_back(tmp);
	}
	sort(lst.begin(), lst.end(), cmp);
	if (lst.size() == 0)
	{
		printf("0 -1\n");
		return 0;
	}

	addr = lst[0] - Node;
	printf("%d %05d\n%05d %d ", lst.size(), addr, addr, Node[addr].key);
	for (int i = 1; i < lst.size(); ++i)
	{
		addr = lst[i] - Node;
		printf("%05d\n%05d %d ", addr, addr, Node[addr].key);
	}
	printf("-1");
	return 0;
}
