#include<bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
	if (n <= 3)
		return true;
	int flag = 1;
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n%i == 0)
		{
			flag = 0;
			break;
		}
	}
	return flag == 1;
}

int main()
{
	int N, K, id;
	scanf("%d", &N);
	unordered_map<int, int> rankList;
	unordered_set<int> checked;
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &id);
		rankList[id] = i;
	}
	scanf("%d", &K);
	for (int i = 0; i < K; ++i)
	{
		scanf("%d", &id);
		if (rankList.find(id) != rankList.end())
		{
			if (checked.find(id) != checked.end())            
			{
				printf("%04d: Checked\n", id);
			}
			else
			{
				checked.insert(id);
				if (rankList[id] == 1)
					printf("%04d: Mystery Award\n", id);
				else if (isPrime(rankList[id]))
					printf("%04d: Minion\n", id);
				else
					printf("%04d: Chocolate\n", id);
			}
		}
		else
		{
			printf("%04d: Are you kidding?\n", id);       //注意不存在的名字每次都会输出kidding，而不是checked
		}
	}
	return 0;
};
