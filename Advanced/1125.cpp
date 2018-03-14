#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < N; ++i)
	{
		int val;
		scanf("%d", &val);
		q.push(val);
	}
	while (q.size() > 1)
	{
		int A = q.top();
		q.pop();
		int B = q.top();
		q.pop();
		q.push((A + B) / 2);
	}
	printf("%d\n", q.top());
	return 0;
}
