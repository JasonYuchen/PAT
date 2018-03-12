#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N, loop;
	scanf("%d", &N);
	vector<int> dist(N + 1);
	dist[1] = 0;
	for (int i = 2; i <= N; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		dist[i] = dist[i - 1] + tmp;
	}
	scanf("%d", &loop);
	loop += dist[N];
	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		int src, dst;
		scanf("%d %d", &src, &dst);
		if (src > dst) 
			swap(src, dst);
		int forward = dist[dst] - dist[src];
		int backward = dist[src] - dist[dst] + loop;
		printf("%d\n", forward < backward ? forward : backward);
	}
	return 0;
}