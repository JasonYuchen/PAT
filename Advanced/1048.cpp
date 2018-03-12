#include<bits/stdc++.h>

using namespace std;

int main()
{
	int coins[501];                                  //散列标记每个数额的硬币出现的枚数
	fill(coins, coins + 501, 0);
	int N, M, one = -1, two, i, minCoin = 501;
	cin >> N >> M;
	for (i = 0; i < N; ++i)
	{
		int tmp;
		cin >> tmp;
		coins[tmp]++;
		if (M - tmp < 1)                             //若当前的硬币单枚就超出了需要给的量，则跳过
			continue;
		if (coins[M - tmp] >= 1)                     //若与tmp配对的M-tmp数额的硬币存在，即可行
		{
			tmp = min(tmp, M - tmp);
			if (tmp == M - tmp && coins[tmp] < 2)    //若正好是M的一半的硬币，则只有在枚数大于两枚时才可行，否则跳过
				continue;
			if (tmp < minCoin)                       //若出现小数额的比原先记录最小的更小，则更新最终方案
			{
				one = tmp;
				two = M - tmp;
			}
		}
	}
	if (one == -1)
		cout << "No Solution" << '\n';
	else
		cout << one << " " << two << '\n';
	return 0;
}
