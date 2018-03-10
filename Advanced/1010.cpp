#include<bits/stdc++.h>

using namespace std;

long long toDec(string num, long long radix)
{
	long long n = 0;
	for (int i = 0; i < num.size(); ++i)
	{
		int ch = isalpha(num[i]) ? (num[i] - 'a' + 10) : (num[i] - '0');
		n = n * radix;
		n = n + ch;
	}
	return n;
}

long long biSearch(string N1, string N2, long long radix)
{
	long long ret = LLONG_MAX, mid;
	long long A = toDec(N1, radix), st = 1, ed = A + 1;    //确定进制上界ed为基准数字值+1
	for (int i = 0; i < N2.size(); ++i)
	{
		int ch = isalpha(N2[i]) ? (N2[i] - 'a' + 10) : (N2[i] - '0');
		if (ch > st)
			st = ch;
	}
	st++;                                                  //确定进制下界st为待测数字中最大字符对应的进制
	ed = max(st, ed);
	while (st <= ed)
	{
		mid = (st + ed) / 2;
		long long tmp = toDec(N2, mid);
		if (tmp < A && tmp > 0)                            //由于进制上界很大，toDec函数可能溢出，溢出也代表tmp > A，同时比A小的时候要注意没有溢出，即tmp > 0
		{
			st = mid + 1;
		}
		else if (tmp > A || tmp < 0)
		{
			ed = mid - 1;
		}
		else
		{
			if (mid < ret)
				ret = mid;
			ed = mid - 1;                                  //搜索可能存在的更小的radix
		}
	}
	return ret == LLONG_MAX ? -1 : ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string N1, N2;
	long long tag, radix;
	cin >> N1 >> N2 >> tag >> radix;
	if (tag == 2)
		swap(N1, N2);
	long long ret = biSearch(N1, N2, radix);
	if (ret == -1)
		cout << "Impossible\n";
	else
		cout << ret << '\n';
	return 0;
}