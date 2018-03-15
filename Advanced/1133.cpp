#include<bits/stdc++.h>

using namespace std;

struct node
{
	int key, next;
}Nodes[100000];

int main()
{
	int start, N, K;
	scanf("%d %d %d", &start, &N, &K);
	vector<int> Neg, LowK, HighK;          //分别顺序存储负结点、小于K的结点、余下的结点
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
		if (Nodes[addr].key < 0)
			Neg.push_back(addr);
		else if (Nodes[addr].key <= K)
			LowK.push_back(addr);
		else
			HighK.push_back(addr);
		addr = Nodes[addr].next;
	}
	Neg.insert(Neg.end(), LowK.begin(), LowK.end());  //合并三条链表便于输出
	Neg.insert(Neg.end(), HighK.begin(), HighK.end());
	printf("%05d %d ", Neg[0], Nodes[Neg[0]].key);
	for (int i = 1; i < Neg.size(); ++i)
		printf("%05d\n%05d %d ", Neg[i], Neg[i], Nodes[Neg[i]].key);
	printf("-1\n");
	return 0;
}
