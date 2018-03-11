#include<bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
	if (n == 1)
		return false;            //注意1不是素数
	if (n == 2 || n == 3)
		return true;
	for (auto i = 2; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int reverse(int n, int radix)
{
	auto sum = 0;
	while (n)
	{
		sum *= radix;
		sum += n%radix;
		n /= radix;
	}
	return sum;
}

int main()
{
	int N, radix;
	cin >> N;
	while (N > 0)
	{
		cin >> radix;
		auto rN = reverse(N, radix);
		if (isPrime(N) && isPrime(rN))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		cin >> N;
	}
	return 0;
}