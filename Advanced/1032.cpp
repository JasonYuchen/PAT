#include<bits/stdc++.h>

using namespace std;

struct node
{
	char c;
	char tag = -1;
	int next = -1;
}List[100000];

int main()
{
	int st1, st2, N;
	scanf("%d %d %d", &st1, &st2, &N);
	for (int i = 0; i < N; ++i)
	{
		int addr1, addr2;
		char c;
		scanf("%d %c %d", &addr1, &c, &addr2);
		List[addr1].c = c;
		List[addr1].next = addr2;
	}
	while (st1 != -1)
	{
		List[st1].tag = 1;
		st1 = List[st1].next;
	}
	while (st2 != -1)
	{
		if (List[st2].tag == 1)       //一旦发现某个结点已被访问过，说明共享结点从这个位置开始
			break;
		st2 = List[st2].next;
	}
	if (st2 == -1)
		printf("-1\n");
	else
		printf("%05d\n", st2);
	return 0;
}
