#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> origin(N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &origin[i]);
	vector<int> sorted(origin);
	sort(sorted.begin(), sorted.end());
	int maxLeft = 0;
	vector<int> pivots;
	for (int i = 0; i < N; ++i)
	{
		if (origin[i] == sorted[i] && origin[i] > maxLeft)   //主元一定就在最终位置，并且大于所有左侧元素
			pivots.push_back(origin[i]);
		if (origin[i] > maxLeft)
			maxLeft = origin[i];
	}
	printf("%d\n", pivots.size());
	if (!pivots.empty())
	{
		printf("%d", pivots[0]);
		for (int i = 1; i < pivots.size(); ++i)
			printf(" %d", pivots[i]);
	}
	printf("\n");      //最后要输出回车，因为如果没有候选pivot，也要输出空行
	return 0;
}
