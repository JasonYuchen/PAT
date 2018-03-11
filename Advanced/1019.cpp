#include<bits/stdc++.h>

using namespace std;

void isPalindromic(int n, int radix)
{
	if (n == 0 || n == 1)          //0或1在任何进制下都是符合条件的
	{
		printf("Yes\n%d\n", n);
		return;
	}
	vector<int> tmp;               //vector<int>储存a0...ak系数，后序直接基于vector比较
	while (n > 0)
	{
		tmp.push_back(n % radix);
		n /= radix;
	}
	vector<int> cmp(tmp.rbegin(), tmp.rend());
	if (tmp == cmp)
		printf("Yes\n");
	else
		printf("No\n");
	printf("%d", cmp[0]);
	for (int i = 1; i < cmp.size(); ++i)
		printf(" %d", cmp[i]);
}

int main()
{
	int N, radix;
	scanf("%d %d", &N, &radix);
	isPalindromic(N, radix);
	return 0;
}
