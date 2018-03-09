#include<bits/stdc++.h>

using namespace std;

struct node
{
	int exp;
	double coe;
	node() = default;
	node(int e, double c) :exp(e), coe(c) {}
};

node operator+(node lhs, node rhs)
{
	assert(lhs.exp == rhs.exp);                   //相加的node必须指数exp相等
	return node(lhs.exp, lhs.coe + rhs.coe);
}

int main()
{
	vector<node> poly[2];
	for (auto i = 0; i < 2; ++i)
	{
		int N;
		scanf("%d", &N);
		for (auto j = 0; j < N; ++j)
		{
			int exp;
			double coe;
			scanf("%d %lf", &exp, &coe);
			poly[i].push_back(node(exp, coe));
		}
	}
	vector<node> ret;
	auto it1 = poly[0].begin(), it2 = poly[1].begin();
	auto ed1 = poly[0].end(), ed2 = poly[1].end();
	while (it1 != ed1 && it2 != ed2)              //合并的部分也可以封装在函数里
	{
		if (it1->exp > it2->exp)
		{
			ret.push_back(*it1++);
		}
		else if (it1->exp < it2->exp)
		{
			ret.push_back(*it2++);
		}
		else
		{
			node tmp = *it1 + *it2;
			it1++; it2++;
			if (tmp.coe - 0.0 > 0.09)             //浮点数不能用==0来判断，必须是-0<e，e是足够小的值
				ret.push_back(tmp);
		}
	}
	while (it1 != ed1) ret.push_back(*it1++);     //处理还有剩余项的多项式
	while (it2 != ed2) ret.push_back(*it2++);
	printf("%d", ret.size());
	for (auto c : ret)
	{
		printf(" %d %.1lf", c.exp, c.coe);
	}
	return 0;
}