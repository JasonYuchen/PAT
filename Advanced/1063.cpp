#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N, num, ele;
	scanf("%d", &N);
	vector<set<int>> setVec(N);          //set可以直接回避原序列的重复元素
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &num);
		for (int j = 0; j < num; ++j)
		{
			scanf("%d", &ele);
			setVec[i].insert(ele);
		}
	}
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		int A, B;
		scanf("%d %d", &A, &B);
		A--; B--;
		int total = setVec[A].size() + setVec[B].size();
		int common = 0;
		for (auto val : setVec[A])
		{
			if (setVec[B].find(val) != setVec[B].end())  //寻找重复元素
				common++;
		}
		double rate = common * 100.0 / (total - common);
		printf("%.1f%%\n", rate);
	}
	return 0;
}
