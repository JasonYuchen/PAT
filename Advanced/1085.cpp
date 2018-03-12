#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	long long p;                   //p<=10^9，序列元素最大<=10^9，则乘积<=10^18超过了int范围，需要用long long
	scanf("%d %lld", &N, &p);
	vector<long long> seq(N);
	for (int i = 0; i < N; ++i)
		scanf("%lld", &seq[i]);
	sort(seq.begin(), seq.end());  //直接排序之后从头开始扫描
	int L = 0, R = N - 1;          //L指向左侧最小元素，R指向右侧最大元素
	while (seq[R] > seq[L] * p)    //首先循环以找到包括最小元素在内的最长完美序列，随后不断递增L来找到不同起点元素的最长完美序列
		R--;
	int maxNum = R - L + 1;
	while (L < N && R < N)         //L和R都必须小于N
	{
		++L;
		while (L < N && R < N && seq[R] <= seq[L] * p) 
			R++;                   //虽然这里不改动L，但是前面++L，这里也要检测是否超过范围
		if (R - L > maxNum)
			maxNum = R - L;
	}
	printf("%d\n", maxNum);
	return 0;
}