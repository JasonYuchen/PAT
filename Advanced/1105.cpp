#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> nums(N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &nums[i]);
	sort(nums.begin(), nums.end(), greater<int>());
	int n = sqrt(N), m;
	for (; n > 0; --n)
		if (N%n == 0)
			break;
	m = N / n;
	vector<vector<int>> ret(m, vector<int>(n));
	int i = 0, j = 0, Li = 0, Ri = m - 1, Lj = 0, Rj = n - 1, state = 0;
	for (int cnt = 0; cnt < N; ++cnt)       //FSM解决
	{
		ret[i][j] = nums[cnt];
		if (state % 4 == 0)
		{
			++j;
			if (j > Rj)
			{
				--j;
				++i;
				state++;
				Li++;
			}
		}
		else if (state % 4 == 1)
		{
			++i;
			if (i > Ri)
			{
				--i;
				--j;
				state++;
				Rj--;
			}
		}
		else if (state % 4 == 2)
		{
			--j;
			if (j < Lj)
			{
				++j;
				--i;
				state++;
				Ri--;
			}
		}
		else if (state % 4 == 3)
		{
			--i;
			if (i < Li)
			{
				++i;
				++j;
				state++;
				Lj++;
			}
		}
	}
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			printf("%d%s", ret[i][j], j == n - 1 ? "\n" : " ");
	return 0;
};
