#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N, M, L;
	scanf("%d", &N);
	scanf("%d", &M);
	vector<int> eva(M);
	for (int i = 0; i < M; ++i)
		scanf("%d", &eva[i]);
	scanf("%d", &L);
	vector<int> given(L);
	for (int i = 0; i < L; ++i)
		scanf("%d", &given[i]);

	vector<pair<int, int>> pos;
	for (int i = 0, j = 0; i < M && j < L; ++j)
	{
		if (eva[i] == given[j])                  //找到每个喜欢的数字按顺序在给定串中的第一个位置
		{
			pos.push_back({ eva[i],j });
			++i;
		}
	}
	int maxLen = 0;
	for (int i = 0; i < pos.size(); ++i)         //统计每个喜欢的数字在第一个位置和下一个喜欢数字第一个位置之间出现的次数，注意不一定所有喜欢颜色都出现，所以这里遍历pos即可
	{
		if (i < pos.size() - 1)
			maxLen += count(given.begin() + pos[i].second, given.begin() + pos[i + 1].second, pos[i].first);
		else
			maxLen += count(given.begin() + pos[pos.size() - 1].second, given.end(), pos[pos.size() - 1].first);
	}
	printf("%d\n", maxLen);
	return 0;
}


/******************************************************************************************************
LCS/DP

int given[10000], eva[200], dp[201][10001];

int main()
{
	int N, M, L;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i)
		scanf("%d", &eva[i]);
	scanf("%d", &L);
	for (int i = 0; i < L; ++i)
		scanf("%d", &given[i]);
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < L; ++j)
		{
			if (eva[i] == given[j])             //基于LCS修改过的转移方程
				dp[i + 1][j + 1] = max({ dp[i][j + 1], dp[i + 1][j] }) + 1;
			else
				dp[i + 1][j + 1] = max({ dp[i][j + 1], dp[i + 1][j] });
		}
	}
	printf("%d\n", dp[M][L]);
	return 0;
}

******************************************************************************************************/