#include<bits/stdc++.h>

using namespace std;

vector<int> pre, post, in;
int flag;

void build(int preSt, int postSt, int N)
{
	if (N <= 0)
		return;
	if (N == 1)
	{
		in.push_back(pre[preSt]);
		return;
	}
	int root = pre[preSt];
	int leftRoot = pre[preSt + 1];
	auto pos = find(post.begin() + postSt, post.begin() + postSt + N, leftRoot);
	int leftLen = pos - post.begin() - postSt + 1;
	int rightLen = N - 1 - leftLen;
	if (rightLen == 0)                          //当右子树不存在时，此时已获得的左子树可能是左也可能是右，因此不唯一
		flag = 1;
	build(preSt + 1, postSt, leftLen);
	in.push_back(root);
	build(preSt + 1 + leftLen, postSt + leftLen, rightLen);
}

int main()
{
	int N;
	scanf("%d", &N);
	pre.resize(N);
	post.resize(N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &pre[i]);
	for (int i = 0; i < N; ++i)
		scanf("%d", &post[i]);
	build(0, 0, N);
	if (flag == 1)
		printf("No\n%d", in[0]);
	else
		printf("Yes\n%d", in[0]);
	for (int i = 1; i < in.size(); ++i)
		printf(" %d", in[i]);
	printf("\n");
	return 0;
}