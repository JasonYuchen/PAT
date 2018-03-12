#include<bits/stdc++.h>

using namespace std;

long long nextPrime()    //返回下一个素数，用static来存储上一个素数
{
	static long long prime = 2;
	if (prime == 2)
		return prime++;
	while (true)
	{
		int flag = 1;
		for (long long i = 2; i <= sqrt(prime); ++i)
		{
			if (prime % i == 0)
			{
				flag = 0;
				break;
			}
		}
		prime += 2;
		if (flag == 1)
			return prime - 2;
	}
}

int main()
{
	ios::sync_with_stdio(false);                   
	cin.tie(0);
	map<int, int> factors;
	long long N;
	cin >> N;
	cout << N << "=";
	if (N == 1)
	{
		cout << 1;
		return 0;
	}
	while (N > 1)
	{
		int exp = 0;
		long long factor = nextPrime();
		while (N % factor == 0 && N != 1)
		{
			N /= factor;
			exp++;
		}
		if (exp != 0)
			factors.insert({ factor, exp });
	}
	if (factors.begin()->second == 1)
		cout << factors.begin()->first;
	else
		cout << factors.begin()->first << "^" << factors.begin()->second;
	factors.erase(factors.begin());
	for (auto ch : factors)
	{
		if (ch.second == 1)
			cout << "*" << ch.first;
		else
			cout << "*" << ch.first << "^" << ch.second;
	}
	return 0;
}
