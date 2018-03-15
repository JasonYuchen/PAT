#include<bits/stdc++.h>

using namespace std;

vector<int> tree;

bool judge(int St, int Ed, int &cnt)                   //传入cnt的引用，记录结点简单路径到叶所遇到的黑结点数目
{
	if (St > Ed)
		return true;
	auto root = tree[St];
	if (root > 0)
		cnt++;
	if (St == Ed)
		return true;
	int leftRootPos, rightRootPos;
	for (leftRootPos = St + 1; leftRootPos <= Ed; ++leftRootPos)
		if (abs(tree[leftRootPos]) < abs(root))
			break;
	for (rightRootPos = St + 1; rightRootPos <= Ed; ++rightRootPos)
		if (abs(tree[rightRootPos]) > abs(root))
			break;
	if (leftRootPos <= Ed && root < 0 && tree[leftRootPos] < 0)       //rule 4：根结点是红色，则子结点都必须是黑色
		return false;
	if (rightRootPos <= Ed && root < 0 && tree[rightRootPos] < 0)     //rule 4：根结点是红色，则子结点都必须是黑色
		return false;
	int leftBlacks = 0, rightBlacks = 0;               //rule 5：从结点到叶结点的每条简单路径上有相同多的黑色结点
	bool l = judge(leftRootPos, rightRootPos - 1, leftBlacks);
	bool r = judge(rightRootPos, Ed, rightBlacks);
	if (l && r && leftBlacks == rightBlacks)
	{
		cnt += leftBlacks;                             //注意记得更新当前结点往下遍历遇到的黑结点数目加上自身
		return true;
	}
	else
		return false;
}

int main()
{
	int K, N, cnt = 0;
	scanf("%d", &K);
	for (int i = 0; i < K; ++i)
	{
		scanf("%d", &N);
		tree.resize(N);
		for (int j = 0; j < N; ++j)
			scanf("%d", &tree[j]);
		if (tree[0] < 0)                               //rule 2：根结点必须是黑色
			printf("No\n");
		else if (judge(0, N - 1, cnt))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
