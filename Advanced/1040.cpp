#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);                
	cin.tie(0);                                     
	string s;
	int max = 0;
	getline(cin, s);
	for (int i = 0; i < s.size(); ++i)               //从每个字符为起点向两侧发散，获得一个对称子串长度，最后保留一个最大值
	{
		int left = i, right = i + 1;
		while (right < s.size() && s[right] == s[left])
			right++;
		right--;
		while (left >= 0 && right < s.size() && s[left] == s[right])
		{
			left--;
			right++;
		}
		if (right - left - 1 > max)
			max = right - left - 1;
	}
	cout << max << endl;
	return 0;
}