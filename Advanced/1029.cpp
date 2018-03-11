#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<long int> S1(N);
	for (int i = 0; i < N; ++i)
		cin >> S1[i];
	cin >> N;
	vector<long int> S2(N);
	for (int i = 0; i < N; ++i)
		cin >> S2[i];
	int mid = (S1.size() + S2.size() - 1) / 2, i = 0, j = 0;
	while (mid--)
	{
		if (j == S2.size() || i < S1.size() && j < S2.size() && S1[i] < S2[j])  //注意短路求值顺序
		{
			++i;
		}
		else if (i == S1.size() || i < S1.size() && j < S2.size() && S1[i] >= S2[j])
		{
			++j;
		}
	}
	long int ret;
	if (i == S1.size())
		ret = S2[j];
	else if (j == S2.size())
		ret = S1[i];
	else
		ret = min({ S1[i], S2[j] });
	cout << ret << endl;
	return 0;
}