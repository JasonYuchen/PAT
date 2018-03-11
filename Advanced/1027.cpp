#include<bits/stdc++.h>

using namespace std;

string toMars(int *in)
{
	string table{ "0123456789ABC" };
	string out[3];
	for (auto i = 0; i < 3; ++i)
	{
		while (in[i] > 0)
		{
			out[i].insert(out[i].begin(), table[in[i] % 13]);
			in[i] /= 13;
		}
		if (out[i].size() != 2)
			out[i].insert(out[i].begin(), 2 - out[i].size(), '0');   //注意可能需要补1~2个0
	}
	return "#" + out[0] + out[1] + out[2];
}

int main()
{
	ios::sync_with_stdio(false);
	int in[3];
	cin >> in[0] >> in[1] >> in[2];
	cout << toMars(in) << endl;
	return 0;
}