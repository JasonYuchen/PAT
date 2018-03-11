#include<bits/stdc++.h>

using namespace std;

bool isPalindromic(vector<int> &n)
{
	int l = 0, r = n.size() - 1;
	if (l == r)
		return true;
	while (n[l] == n[r] && l < r)
	{
		l++; r--;
	}
	if (l >= r)
		return true;
	else
		return false;
}

int main()
{
	string num;
	vector<int> n;                                    //用vector来存储，处理大数计算
	int steps, i = 0, flag = 0;
	cin >> num >> steps;
	for (auto ch : num)
	{
		n.push_back(ch - '0');
	}
	if (isPalindromic(n))
	{
		cout << num << '\n' << 0 << endl;
		return 0;
	}
	while (i++ < steps)
	{
		int carry = 0;
		vector<int> rev(n.rbegin(), n.rend());        //反向迭代器生成相反的大数
		for (int j = rev.size() - 1; j >= 0; --j)
		{
			int value = rev[j] + n[j] + carry;
			carry = value / 10;
			value %= 10;
			n[j] = value;
		}
		if (carry)
			n.insert(n.begin(), carry);
		if (isPalindromic(n))
			break;
	}
	for_each(n.begin(), n.end(), [](int i) {cout << i; });
	cout << '\n' << (i > steps ? steps : i);          //若超出限定步数，则输出限定值
	return 0;
}