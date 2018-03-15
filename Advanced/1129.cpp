#include<bits/stdc++.h>

using namespace std;

struct item
{
	int id, access = 0;
}Items[50001];                       //散列记录每个物品的访问次数
bool operator<(const item &lhs, const item &rhs)
{
	return lhs.access > rhs.access || lhs.access == rhs.access && lhs.id < rhs.id;
}

int main()
{
	int N, K;  //N - queries, K - recommandations
	scanf("%d %d", &N, &K);
	vector<item> It;               //It只保存访问次数前K的物品
	int line = 0;
	for (int i = 0; i < N; ++i)
	{
		int id;
		scanf("%d", &id);
		Items[id].id = id;
		Items[id].access++;
		if (i != 0)
		{
			printf("%d:", id);
			for (int j = 0; j < It.size() && j < K; ++j)
				printf(" %d", It[j].id);
			printf("\n");
		}
		if (It.size() <= K)                                    //当目前访问物品不超过K时，若It中已有物品，则更新其访问次数，否则就直接添加新物品
		{
			auto has = find_if(It.begin(), It.end(), [&](const item &s) {return s.id == id; });
			if (has != It.end())
				*has = Items[id];
			else
				It.push_back(Items[id]);
		}
		else if (Items[id].access >= line && It.size() > K)    //当访问物品超过K时，只在It中保留前K的，line就是第K大的访问次数用来控制物品替换
		{
			auto has = find_if(It.begin(), It.begin() + K, [&](const item &s) {return s.id == id; });
			if (has != It.end())
				*has = Items[id];
			else
				It[K - 1] = max(It[K - 1], Items[id]);
		}
		sort(It.begin(), It.end());                            //由于K较小而N极大，因此不能每次都全排列
		line = max(line, Items[K - 1].access);
	}
	return 0;
};
