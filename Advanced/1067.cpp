#include<bits/stdc++.h>

using namespace std;

int getLoop(vector<int> &seq, vector<int> &visited, int start)
{
	int cnt = 1, end = seq[start];
	int next = seq[start];
	visited[start] = 1;
	while (seq[next] != end)                        //寻找链内的元素数量
	{
		cnt++;
		visited[next] = 1;
		next = seq[next];
	}
	return cnt;
}

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> seq(N), visited(N, 0);              //最快有序的方法就是每次都选择0与所在位置最终的元素直接交换
	for (int i = 0; i < N; ++i)                 
	{
		scanf("%d", &seq[i]);
		if (seq[i] == i)
			visited[i] = 1;
	}
	int swaps = visited[0] == 1 ? 0 : -2;           //若0不在[0]则可以少两次交换，初始化为-2
	for (int i = 0; i < N; ++i)
	{
		if (visited[i] == 0)
		{
			swaps += getLoop(seq, visited, i) + 1;  //假定0不在任一条交换链中，则使链有序必须交换链中元素个数+1次（将0换入，然后元素个数-1次交换，再将0换出）
		}
	}
	printf("%d\n", swaps);
	return 0;
}