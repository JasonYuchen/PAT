#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<string> digit = { "zero","one","two","three","four",
		"five","six","seven","eight","nine" };
	string in;
	cin >> in;
	int sum = 0;
	for (auto ch : in)
	{
		sum += ch - '0';
	}
	string out(to_string(sum));
	for (auto i = 0; i < out.size(); ++i)
	{
		if (i == 0)
			cout << digit[out[i] - '0'];
		else
			cout << " " << digit[out[i] - '0'];
	}
	return 0;
}
