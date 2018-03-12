#include<bits/stdc++.h>

using namespace std;

int main()
{                           
	int M, N, K;
	scanf("%d %d %d", &M, &N, &K);
	vector<int> s(N);
	for (int k = 0; k < K; ++k)
	{
		int flag = 1;
		for (int i = 0; i < N; ++i)
		{
			scanf("%d", &s[i]);
		}
		if (N <= 2)                   //少于2个元素的一定符合条件
		{
			printf("YES\n");
			continue;
		}
		for (int i = 0; i < N; ++i)
		{
			if (s[i] - i > M ||       //pop位置与push位置相差超过stack的大小，则不可能
				i > 1 && s[i - 2] > s[i] && s[i] > s[i - 1])        //push顺序是依次递增的，因此不可能出现A,B,C且A>C>B这样的序列
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}