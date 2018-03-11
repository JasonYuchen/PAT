#include<bits/stdc++.h>

using namespace std;

struct info        //info记录每个customer所处队列的编号queue、队列内的位置index、需要的时间min
{
	int queue;
	int index;
	int min;
};

int main()
{
	unordered_map<int, info> customers;   //customer用整数编号，散列表存储每个customer的info
	int index[20];                        //每个窗口前的队列的模拟头指针，初始时指向最前位置即index[i]=0
	int base[20];                         //记录每个窗口前队列位于模拟头指针index[i]前的客户所需要的总时间，初始时base[i]=0
	fill(begin(index), end(index), 0);
	fill(begin(base), end(base), 0);
	vector<int> queues[20];               //记录每个队列内的customers消耗的时间
	int N, M, K, Q;                       //窗口数(队列数)N, 单队最多人数M, 一共人数K, 询问次数Q
	scanf("%d %d %d %d", &N, &M, &K, &Q);
	for (int i = 0; i < K; ++i)
	{
		int min;
		scanf("%d", &min);
		customers[i].min = min;
	}
	for (int i = 0; i < K; ++i)
	{
		int entry = 0;                      //entry记录客户i将要进入的队列编号
		if (i < M*N)                        //若黄线还没有到，即人数不足M*N，则新客户按顺序排入每个队
		{
			entry = i % N;
		}
		else                                //若超出黄线，即人数从M*N+1开始，新客户进入最短时间内会出现空位的队列
		{
			auto minTime = INT_MAX;
			for (int j = 0; j < N; ++j)     //最短时间通过从编号由小到大遍历每个队列获得，每个队列未来出现空位的时间为base时间+模拟头位置的时间
			{
				if (queues[j][index[j]] + base[j] < minTime)
				{
					entry = j;
					minTime = queues[j][index[j]] + base[j];
				}
			}
			base[entry] += queues[entry][index[entry]];   //被添加客户的队列需要将模拟头指针后移同时更新base时间
			index[entry]++;
		}
		customers[i].queue = entry;                       //将所进入队列的编号、队列内的位置更新到散列表的customer info中
		customers[i].index = queues[entry].size();
		queues[entry].push_back(customers[i].min);        //将客户所消耗的时间添加进队列
	}
	for (int i = 0; i < Q; ++i)
	{
		int cus;
		scanf("%d", &cus);
		cus--;
		auto entry = customers[cus].queue;
		auto pos = customers[cus].index;
		auto time = 0;
		for (int j = 0; j <= pos; ++j)
			time += queues[entry][j];
		auto hour = 8 + time / 60;
		auto minute = time % 60;
		time -= queues[entry][pos];
		if (time >= 540)                                  //服务结束时间在17:00后并不会Sorry，服务开始时间在17:00后才会Sorry
			printf("Sorry\n");
		else
			printf("%02d:%02d\n", hour, minute);
	}
	return 0;
}

