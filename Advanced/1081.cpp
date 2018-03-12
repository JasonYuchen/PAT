#include<bits/stdc++.h>

using namespace std;

int GCD(int a, int b)
{
	int tmp;
	if (a == 0 || b == 0)
		return 1;
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
	int num, den;
	ration(int n, int d) :num(n), den(d)
	{
		int gcd = GCD(std::abs(num), std::abs(den));
		num /= gcd;
		den /= gcd;
	}
};

ration &operator+(ration &a, ration &b)
{
	int den = a.den*b.den;
	int num = a.num*b.den + b.num*a.den;
	int gcd = GCD(std::abs(num), std::abs(den));
	num /= gcd;
	den /= gcd;
	a.den = den;
	a.num = num;
	return a;
}

int main()
{
	int N, integer = 0;
	scanf("%d", &N);
	ration total{ 0,1 };
	for (int i = 0; i < N; ++i)
	{
		int num, den;
		scanf("%d/%d", &num, &den);
		ration tmp{ num,den };
		total = total + tmp;
	}
	integer = total.num / total.den;
	total.num = total.num % total.den;
	if (integer != 0)
		printf("%d", integer);
	if (integer != 0 && total.num != 0)
		printf(" ");
	if (total.num != 0)
		printf("%d/%d", total.num, total.den);
	if (integer == 0 && total.num == 0)
		printf("0");
	return 0;
}
