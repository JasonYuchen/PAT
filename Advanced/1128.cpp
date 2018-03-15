#include<bits/stdc++.h>

using namespace std;

int main()
{
	int K, N, Qi;
	scanf("%d", &K);
	for (int i = 0; i < K; ++i)
	{
		scanf("%d", &N);
		int flag = 1;
		vector<int> pos;
		for (int j = 0; j < N; ++j)
		{
			scanf("%d", &Qi);
			if (flag == 0)
				continue;
			pos.push_back(Qi);
			for (int k = 0; k + 1 < pos.size(); ++k)
			{
				if (Qi == pos[k] + (j - k)          //不能出现的对角线上
					|| Qi == pos[k]                 //不能出现在同一行
					|| Qi == pos[k] - (j - k))      //不能出现在对角线上
				{
					flag = 0;
					break;
				}
			}
		}
		if (flag == 0)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
};
