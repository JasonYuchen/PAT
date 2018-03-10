#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N, total = 0, prev = 0, next;
	scanf("%d", &N);
	total += 5 * N;
	for (auto i = 0; i < N; ++i)
	{
		scanf("%d", &next);
		if (next > prev)
		{
			total += 6 * (next - prev);
		}
		else if (next < prev)
		{
			total += 4 * (prev - next);
		}
		prev = next;
	}
	printf("%d", total);
	return 0;
}
