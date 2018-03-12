#include<bits/stdc++.h>

using namespace std;

struct station
{
	double Pi;
	int Di;
};
bool operator<(const station &lhs, const station &rhs)
{
	return lhs.Di < rhs.Di;
}

int main()
{
	int Cmax, D, Davg, N;      //Cmax - maximum capacity, D - distance, Davg - distance per unit gas, N - gas stations
	scanf("%d %d %d %d", &Cmax, &D, &Davg, &N);
	vector<station> gas(N + 1);
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf %d", &gas[i].Pi, &gas[i].Di);
	}
	gas[N].Pi = 0.0;           //添加目的地的信息，作为一个虚拟油站
	gas[N].Di = D;
	sort(gas.begin(), gas.end());
	if (gas[0].Di != 0)
	{
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	double sum = 0, curPi = gas[0].Pi, curPos = 0, maxPos, leftGas = 0;  //curPi - 当前站的价格，curPos - 当前站的位置， leftGas - 邮箱剩余油量
	int curGas = 0;                                                      //curGas - 当前油站
	while (curPos < D)
	{
		maxPos = curPos + Cmax*Davg;                                     //maxPos - 处于当前站，最远能开的距离
		int next = -1, flag = 0;
		double minPi = FLT_MAX;
		for (int i = curGas; i <= N; ++i)
		{
			if (gas[i].Di > curPos && gas[i].Di <= maxPos && gas[i].Pi < curPi)     //第一个价格低于当前站的，加到正好的油，立刻前往
			{
				sum += curPi*((gas[i].Di - curPos) / Davg - leftGas);
				leftGas = 0;                                                        //余油为0
				curPos = gas[i].Di;
				curPi = gas[i].Pi;
				curGas = i;
				flag = 1;
				break;
			}
			if (gas[i].Di > curPos && gas[i].Di <= maxPos && gas[i].Pi < minPi)     //若没有价格低于当前站，找到尽可能抵的站
			{
				minPi = gas[i].Pi;
				next = i;
			}
		}
		if (flag == 0)
		{
			if (next == -1)                                                         //可触及范围内没有油站，则无法抵达
			{
				printf("The maximum travel distance = %.2lf\n", maxPos);
				return 0;
			}
			else                                                                    //在当前站（油价低于下一站）加满油再前往下一站
			{
				sum += curPi*(Cmax - leftGas);
				leftGas = Cmax - (gas[next].Di - curPos) / Davg;                    //余油为装满量减去这次的开销
				curPos = gas[next].Di;
				curPi = gas[next].Pi;
				curGas = next;
			}
		}
	}
	printf("%.2lf\n", sum);
	return 0;
}