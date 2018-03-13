#include<bits/stdc++.h>

using namespace std;

struct node
{
	int key, left, right;
}Nodes[100];

int cnt = 0;
void inOrder(vector<int> &Seq, int root)    //BST的中序遍历就是递增序列，Seq排序后中序遍历并放入值
{
	if (root != -1)
	{
		inOrder(Seq, Nodes[root].left);
		Nodes[root].key = Seq[cnt++];
		inOrder(Seq, Nodes[root].right);
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		Nodes[i].left = l;
		Nodes[i].right = r;
	}
	vector<int> Seq(N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &Seq[i]);
	sort(Seq.begin(), Seq.end());
	inOrder(Seq, 0);
	cnt = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty())
	{
		int curr = q.front();
		q.pop();
		Seq[cnt++] = Nodes[curr].key;
		if (Nodes[curr].left != -1)
			q.push(Nodes[curr].left);
		if (Nodes[curr].right != -1)
			q.push(Nodes[curr].right);
	}
	printf("%d", Seq[0]);
	for (int i = 1; i < Seq.size(); ++i)
		printf(" %d", Seq[i]);
	return 0;
}
