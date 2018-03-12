#include<bits/stdc++.h>

using namespace std;

struct mooncake
{
	double amount, price_total, price_unit;
};
bool operator<(const mooncake &lhs, const mooncake &rhs)
{
	return lhs.price_unit > rhs.price_unit;
}

int main()
{
	int N;
	double demand;                      //题目没有说需求是整数，因此可能有小数需求，用double
	scanf("%d %lf", &N, &demand);
	vector<mooncake> vec(N);
	for (int i = 0; i < N; ++i)
		scanf("%lf", &vec[i].amount);
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf", &vec[i].price_total);
		vec[i].price_unit = vec[i].price_total / vec[i].amount;
	}
	sort(vec.begin(), vec.end());
	double profit = 0.0;
	for (int i = 0; i < N; ++i)
	{
		if (demand < 0.001)
			break;
		auto take = min(demand, vec[i].amount);
		profit += take*vec[i].price_unit;
		demand -= take;
	}
	printf("%.2lf\n", profit);
	return 0;
}