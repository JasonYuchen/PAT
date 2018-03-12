#include<bits/stdc++.h>

using namespace std;

int cnt = 0;
void getLev(int root, int n, int *seq, int *lev)   //完全二叉树的中序遍历
{
	if (root <= n)
	{
		getLev(root * 2, n, seq, lev);             //完全二叉树用数组存储且根的下标是1，则符合左子结点=2*root，右子结点=2*root+1
		lev[root] = seq[cnt++];
		getLev(root * 2 + 1, n, seq, lev);
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	int Seq[1001], Lev[1001];
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &Seq[i]);
	}
	sort(Seq, Seq + N);
	getLev(1, N, Seq, Lev);
	printf("%d", Lev[1]);
	for (int i = 2; i <= N; ++i)
	{
		printf(" %d", Lev[i]);
	}
	return 0;
}