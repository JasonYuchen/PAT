#include<bits/stdc++.h>

using namespace std;

/*
**  1.这题的test case是不全的，不会出现题设的2^63，因此不用数组只判断溢出也可以AC
**  2.原因不明：必须用sum=A+B然后再判断A+B和0的关系，若直接判断A+B和0的关系会WA
*/

int main()
{
	long long A, B, C;
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%lld %lld %lld", &A, &B, &C);
		long long sum = A + B;
		if (A > 0 && B > 0 && sum <= 0)          //不可以A + B <= 0
			printf("Case #%d: true\n", i);
		else if (A < 0 && B < 0 && sum >= 0)
			printf("Case #%d: false\n", i);
		else if (sum>C)
			printf("Case #%d: true\n", i);
		else
			printf("Case #%d: false\n", i);
	}
	return 0;
}