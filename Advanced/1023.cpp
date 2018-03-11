#include<bits/stdc++.h>

using namespace std;

int main()
{
	string num;
	cin >> num;
	vector<int> n;
	int digits[10], carry = 0, flag = 1;   //digits记录每个数字出现次数
	fill(digits, digits + 10, 0);
	for (int i = num.size(); i > 0; --i)
	{
		int c = num[i - 1] - '0';
		c *= 2;
		c += carry;
		carry = c / 10;
		c %= 10;
		n.push_back(c);
		digits[num[i - 1] - '0']++;
	}
	if (carry != 0)
		n.push_back(carry);
	for (auto ch : n)
	{
		digits[ch]--;
	}
	for (int i = 0; i < 10; ++i)          //若digits中有任何数的次数非0，说明不符合
	{
		if (digits[i])
		{
			flag = 0;
			break;
		}
	}
	if (flag)
		printf("Yes\n");
	else
		printf("No\n");
	for (int i = n.size(); i > 0; --i)
	{
		printf("%d", n[i - 1]);
	}
	return 0;
}
