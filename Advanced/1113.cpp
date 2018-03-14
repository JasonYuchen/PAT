#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> Seq(N);
	int sum = 0, low;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &Seq[i]);
		sum += Seq[i];
	}
	sort(Seq.begin(), Seq.end());
	int n1 = N / 2, n2 = N - n1;
	low = accumulate(Seq.begin(), Seq.begin() + n1, 0);
	if (n1 == n2)
		printf("0 %d\n", sum - low - low);
	else
	{
		int low0 = low, low1 = low + Seq[n1];
		printf("1 %d\n", max(sum - low0 - low0, sum - low1 - low1));
	}
	return 0;
};
