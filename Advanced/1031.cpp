#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N, n13, n2;
	string in;
	cin >> in;
	N = in.size();
	n13 = (N + 2) / 3;
	n2 = N + 2 - 2 * n13;
	int l = 0, r = N - 1, space = n2 - 2;
	for (int i = 0; i < n13 - 1; ++i)
	{
		string out;
		out.push_back(in[l++]);
		out.insert(out.end(), space, ' ');
		out.push_back(in[r--]);
		cout << out << '\n';
	}
	cout << string(&in[l], &in[r + 1]) << endl;
	return 0;
}
