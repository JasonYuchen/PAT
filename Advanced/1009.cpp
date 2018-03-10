#include<bits/stdc++.h>

using namespace std;

struct term                                        //多项式的每一项
{
	double coe;
	int exp;
	term(double d, int i) :coe(d), exp(i) {}
};

term operator*(term lhs, term rhs)                 //重载多项式乘法
{
	lhs.coe *= rhs.coe;
	lhs.exp += rhs.exp;
	return lhs;
}
bool operator<(const term &lhs, const term &rhs)
{
	return lhs.exp < rhs.exp || lhs.exp == rhs.exp && lhs.coe < rhs.coe;
}
bool operator==(const term &lhs, const term &rhs)
{
	return lhs.exp == rhs.exp;
}

int main()
{
	int l;
	scanf("%d", &l);
	vector<term> p1;                             //读入两个多项式，可以封装成函数
	for (auto i = 0; i < l; ++i)
	{
		double coe;
		int exp;
		scanf("%d %lf", &exp, &coe);
		p1.push_back({ coe,exp });
	}
	scanf("%d", &l);
	vector<term> p2;
	for (auto i = 0; i < l; ++i)
	{
		double coe;
		int exp;
		scanf("%d %lf", &exp, &coe);
		p2.push_back({ coe,exp });
	}
	map<int, double> ret;                        //map来存储相乘之后的项，自动根据exp排序
	for (auto i = 0; i < p1.size(); ++i)
	{
		for (auto j = 0; j < p2.size(); ++j)
		{
			auto tmp = p1[i] * p2[j];
			auto f = ret.find(tmp.exp);
			if (f == ret.end())
			{
				ret.insert({ tmp.exp,tmp.coe });
			}
			else
			{
				f->second += tmp.coe;      //注意因数是浮点数，若是0就删除这一项
				if (abs(f->second - 0) < 0.1)
					ret.erase(f);
			}
		}
	}
	printf("%d", ret.size());
	if (ret.size() == 0)                         //相乘之后若全部消完则输出0
		printf(" 0");
	for (auto st = ret.rbegin(); st != ret.rend(); ++st)
		printf(" %d %.1f", st->first, st->second);
	return 0;
}
