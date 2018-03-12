#include<bits/stdc++.h>

using namespace std;

/*https://www.liuchuo.net/archives/2323*/

int dp[10010], w[10010];       //dp[i]记录面额总和小于等于i的最大硬币和，w[i]记录第i枚硬币的面额
bool choice[10010][10010];     //choice[i][j]代表面额总和小于等于j时，第i枚硬币是否被选择
int cmp1(int a, int b) { return a > b; }
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &w[i]);
	sort(w + 1, w + n + 1, cmp1);
	for (int i = 1; i <= n; i++)                 //只考虑前i枚硬币，从只考虑1枚开始
	{
		for (int j = m; j >= w[i]; j--)          //单枚硬币超过m的不用考虑，因此j>=w[i]
		{
			if (dp[j] <= dp[j - w[i]] + w[i])    //若当前总和<=j时，选择第i枚硬币能更接近m，则更新
			{
				choice[i][j] = true;             //记录总和<=j并最接近j时，需要选择第i枚硬币
				dp[j] = dp[j - w[i]] + w[i];     //由于选择了第i枚，因此总和不超过j时的最接近和即dp[j]=总和不超过j-w[i]时的最接近和即dp[j-w[i]]+第i枚w[i]
			}
		}
	}
	if (dp[m] != m) printf("No Solution");       //若要求正好是m，而结果不是正好，则无解
	else
	{
		vector<int> arr;
		int v = m, index = n;                    //由于DP时硬币从大到小，因此输出最小序列需要从后往前
		while (v > 0)
		{
			if (choice[index][v] == true)        //若剩余总和为v时第index枚硬币被选择了，则加入到结果向量中
			{
				arr.push_back(w[index]);
				v -= w[index];                   //接下来寻找剩余总和为v-w[index]的最小被选择的硬币
			}
			index--;
		}
		for (int i = 0; i < arr.size(); i++)
		{
			if (i != 0) printf(" ");
			printf("%d", arr[i]);
		}
	}
	return 0;
}