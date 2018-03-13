#include<bits/stdc++.h>

using namespace std;

int N;
double base, inc;
struct node
{
	int prev, id;
	double price = -1.0;
};

double update(vector<node> &s, int i)
{
	if (s[i].price  >= 0.0)                             //已被更新过价格，则直接返回，否则递归向上寻找价格
		return s[i].price;
	else
		return s[i].price = inc * update(s, s[i].prev); //每层递增inc
}

int main()
{
	scanf("%d %lf %lf", &N, &base, &inc);
	inc = (100 + inc) / 100;
	vector<node> vec(N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &vec[i].prev);
		vec[i].id = i;
		if (vec[i].prev == -1)
			vec[i].price = base;
	}
	double max = 0;
	int cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		update(vec, i);
		if (vec[i].price > max)
		{
			cnt = 1;
			max = vec[i].price;
		}
		else if (vec[i].price == max)
		{
			cnt++;
		}
	}
	printf("%.2f %d\n", max, cnt);
	return 0;
}
