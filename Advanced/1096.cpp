#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> tmp_factors, factors;
	for (int i = 2; i <= sqrt(N) + 1; ++i)
	{
		int tmp = 1;
		tmp_factors.clear();
		for (int j = i; j <= sqrt(N) + 1; ++j)
		{
			tmp *= j;
			if (N % tmp == 0)                       //若依然是连续因子，就存储因子，否则直接退出本次循环
				tmp_factors.push_back(j);
			else                            
				break;                                 
		}
		if (tmp_factors.size() > factors.size())
			factors = tmp_factors;
	}
	if (factors.size() == 0)                        //若没有因子直接输出自身
	{
		printf("1\n%d\n", N);
		return 0;
	}
	printf("%d\n%d", factors.size(), factors[0]);
	for (int i = 1; i < factors.size(); ++i)
		printf("*%d", factors[i]);
	return 0;
}

