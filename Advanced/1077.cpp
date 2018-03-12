#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	string ret;
	cin >> N;
	getline(cin, ret);
	vector<string> vec(N);
	for (int i = 0; i < N; ++i)
		getline(cin, vec[i]);
	for (int i = 0; i <= vec[0].size(); ++i)   //由于有可能每一句话都相同，此时i==vec[0].size()，在if里短路求值，因此||右侧不会执行越界访问
	{
		for (int j = 0; j < N; ++j)
		{
			if (i >= vec[j].size() || vec[0][vec[0].size() - i - 1] != vec[j][vec[j].size() - i - 1])
			{
				ret = string(vec[0].end() - i, vec[0].end());
				if (ret.empty())
					cout << "nai" << endl;
				else
					cout << ret << endl;
				return 0;
			}
		}
	}
	return 0;
}