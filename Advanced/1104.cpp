#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	double sum = 0.0, num;
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf", &num);
		sum += num*(1 + i)*(N - i);    //必须num*后两者，不能后两者先乘再*num，因为N<=10^5，若先乘可能到10^10溢出
	}
	printf("%.2lf\n", sum);
	return 0;
};
