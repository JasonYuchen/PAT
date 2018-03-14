#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N, E = 0;
	scanf("%d", &N);
	vector<int> miles(N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &miles[i]);
	sort(miles.begin(), miles.end(), greater<int>());
	for (int i = 0; i < N; ++i)
	{
		if (miles[i] > i + 1)
			E = i + 1;
	}
	printf("%d\n", E);
	return 0;
};