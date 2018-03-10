#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N, Array[10000], MaxSum = -1, ThisSum = 0, nums = 0, Left, Right;
	scanf("%d", &N);
	Left = 0; Right = N - 1;         //初始化为首尾，则当全是负数时会自动输出首尾元素
	for (auto i = 0; i < N; ++i)
	{
		scanf("%d", &Array[i]);
		ThisSum += Array[i];
		++nums;
		if (ThisSum > MaxSum)
		{
			MaxSum = ThisSum;
			Right = i;
			Left = Right - nums + 1;
		}
		else if (ThisSum < 0)
		{
			ThisSum = 0;
			nums = 0;
		}
	}
	printf("%d %d %d", MaxSum >= 0 ? MaxSum : 0, Array[Left], Array[Right]);   //注意若全是负数则要输出0
	return 0;
}