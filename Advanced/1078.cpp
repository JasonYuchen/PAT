#include<bits/stdc++.h>

using namespace std;

int nextPrime(int base)
{
	if (base <= 2)
		return 2;
	int prime = base % 2 == 1 ? base : base + 1;
	for (;; prime += 2)
	{
		int flag = 1;
		for (int i = 2; i <= std::sqrt(prime); ++i)
		{
			if (prime % i == 0)
			{ flag = 0; break; }
		}
		if (flag == 0)
			continue;
		else
			break;
	}
	return prime;
}

int insert(vector<int> &table, int val)
{
	int i = 1;
	int pos = val % table.size();
	if (table[pos] == -1)
	{
		table[pos] = val;
		return pos;
	}
	else
	{
		while ((i*i%table.size()) != 0)  //i=0时出现余0，若再次出现余0则出现规律，说明无法再插入
		{
			int probe = (pos + i * i) % table.size();
			if (table[probe] == -1)
			{
				table[probe] = val;
				return probe;
			}
			i++;
		}
	}
	return -1;
}

int main()
{
	int MSize, N, val;
	scanf("%d %d", &MSize, &N);
	MSize = nextPrime(MSize);
	vector<int> hashTable(MSize, -1);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &val);
		int pos = insert(hashTable, val);
		if (pos != -1)
			printf("%d%s", pos, i == N - 1 ? "\n" : " ");
		else
			printf("-%s", i == N - 1 ? "\n" : " ");
	}
	return 0;
}
