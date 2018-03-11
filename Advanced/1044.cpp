#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> dm(N + 1), sum(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &dm[i]);
		sum[i] = sum[i - 1] + dm[i];
	}
	int i = 0, j = 1;
	int minSum = INT_MAX;
	vector<pair<int, int>> ret;
	while (j < N + 1)
	{
		auto tmp = sum[j] - sum[i];
		if (tmp >= M && tmp < minSum)         //若发现新的更接近M的结果则刷新ret
		{
			ret.clear();
			minSum = tmp;
			ret.push_back({ i + 1,j });
			++i;                              //若大于M则移动i，保持j不变，则ij范围内的和就会下降
		}
		else if (tmp >= M && tmp == minSum)   //若发现相等的结果就添加结果到ret
		{
			ret.push_back({ i + 1,j });
			++i;
		}
		else if (tmp >= M && tmp > minSum)    
		{
			++i;
		}
		else if (tmp < M)                     
		{
			++j;                              //若小于M则移动j，保持i不变，则ij范围内的和就会上升
		}
	}
	for (auto ch : ret)
	{
		printf("%d-%d\n", ch.first, ch.second);
	}
	return 0;
}
