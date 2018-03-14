#include<bits/stdc++.h>

using namespace std;

int N, K, P;
int tmp_sum, sum;
vector<int> tmp_fact, fact;

void DFS(int a, int N, vector<int> &powSeq)
{
	tmp_fact.push_back(a);
	if (tmp_fact.size() == K && N == 0)      //余0并且正好K个因子，符合条件
	{
		tmp_sum = accumulate(tmp_fact.begin(), tmp_fact.end(), 0);
		if (tmp_sum > sum)
		{
			fact = tmp_fact;
			sum = tmp_sum;
		}
		else if (tmp_sum == sum && tmp_fact > fact)
			fact = tmp_fact;
	}
	else if (tmp_fact.size() < K && N > 0)   //因子不足K个且还有剩余则继续DFS
	{
		for (int i = a; i > 0; --i)
		{
			if (N - powSeq[i] >= 0)          //不会超过剩余值则才考虑作为一个因子继续DFS
				DFS(i, N - powSeq[i], powSeq);
		}
	}
	tmp_fact.pop_back();
}

int main()
{
	scanf("%d %d %d", &N, &K, &P);
	vector<int> powSeq;
	int st = pow(N*1.0, 1.0 / P), ed = pow(N*1.0 / K, 1.0 / P);   //确定起终点为(N)^(1/P)和(N/K)^(1/P)
	for (int i = 0; i <= st; ++i)
		powSeq.push_back(pow(i, P));         //构建一个从0到P次方不超过N的列表，后续通过索引快速获得值而不是反复调用std::pow（会TLE）
	for (int i = st; i >= ed; --i)
		if(N-powSeq[i] >= 0)
			DFS(i, N - powSeq[i], powSeq);
	if (fact.size() != 0)
	{
		printf("%d = %d^%d", N, fact[0], P);
		for (int i = 1; i < fact.size(); ++i)
			printf(" + %d^%d", fact[i], P);
	}
	else
	{
		printf("Impossible\n");
	}
	return 0;
}

