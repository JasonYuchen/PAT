#include<bits/stdc++.h>

using namespace std;

long long GCD(long long a, long long b)          //乘除之后可能溢出，需要long long
{
	long long tmp;
	while (b)
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

struct ration
{
	long long num, den, sign;                    //sign记录是否是Inf
	ration(long long n, long long d) :num(n), den(d), sign(1)
	{ 
		if (d == 0)
			sign = 0;
		else
		{
			long long gcd = GCD(std::abs(num), std::abs(den));
			num /= gcd; den /= gcd;
		}
	}
};
ration operator+(const ration &lhs, const ration &rhs)
{
	long long num = lhs.num*rhs.den + rhs.num*lhs.den;
	long long den = lhs.den*rhs.den;
	return ration(num, den);
}
ration operator-(const ration &lhs, const ration &rhs)
{
	long long num = lhs.num*rhs.den - rhs.num*lhs.den;
	long long den = lhs.den*rhs.den;
	return ration(num, den);
}
ration operator*(const ration &lhs, const ration &rhs)
{
	long long num = lhs.num*rhs.num;
	long long den = lhs.den*rhs.den;
	return ration(num, den);
}
ration operator/(const ration &lhs, const ration &rhs)
{
	long long flag = rhs.num < 0 ? -1 : 1;
	if (rhs.num == 0)
		return ration(rhs.num, 0);
	else
		return lhs*ration(flag * rhs.den, std::abs(rhs.num));
}

void print(const ration &r)
{
	if (r.sign == 0)
	{
		printf("Inf");
		return;
	}
	if (r.num < 0)                               //若数字小于0，则需要在整体外侧加上'('、')'
		printf("(");
	if (r.num % r.den == 0)
		printf("%lld", r.num / r.den);
	else if (r.num / r.den != 0)
		printf("%lld %lld/%lld", r.num / r.den, std::abs(r.num % r.den), r.den);
	else
		printf("%lld/%lld", r.num, r.den);
	if (r.num < 0)
		printf(")");
}

int main()
{
	long long n1, n2, d1, d2;
	scanf("%lld/%lld %lld/%lld", &n1, &d1, &n2, &d2);
	ration r1(n1, d1), r2(n2, d2);
	print(r1); printf(" + "); print(r2); printf(" = "); print(r1 + r2); printf("\n");
	print(r1); printf(" - "); print(r2); printf(" = "); print(r1 - r2); printf("\n");
	print(r1); printf(" * "); print(r2); printf(" = "); print(r1 * r2); printf("\n");
	print(r1); printf(" / "); print(r2); printf(" = "); print(r1 / r2); printf("\n");
	return 0;
}
