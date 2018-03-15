#include<bits/stdc++.h>

using namespace std;

vector<int> pre, in;
int post = -1;

void build(int preSt, int preEd, int inSt, int inEd) //preSt等都是绝对坐标，后序换算需要仔细
{
	if (preSt > preEd || post != -1)                 //若已获得了post，则直接返回，剪枝
		return;
	if (preSt == preEd)
	{
		if(post == -1)
			post = pre[preSt];
		return;
	}
	int leftRoot = pre[preSt];
	int leftLen = find(in.begin() + inSt, in.begin() + inEd + 1, leftRoot) - in.begin() - inSt;
	int rightLen = inEd - inSt - leftLen;
	build(preSt + 1, preSt + leftLen, inSt, inSt + leftLen - 1);
	build(preSt + 1 + leftLen, preEd, inSt + 1 + leftLen, inEd);
	if(post == -1)
		post = pre[preSt];
}

int main()
{
	int N;
	scanf("%d", &N);
	pre.resize(N);
	in.resize(N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &pre[i]);
	for (int i = 0; i < N; ++i)
		scanf("%d", &in[i]);
	build(0, N - 1, 0, N - 1);
	printf("%d\n", post);
	return 0;
};
