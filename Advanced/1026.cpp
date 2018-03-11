#include<bits/stdc++.h>

using namespace std;

struct table
{
	int endTime = 8 * 3600, cnt = 0, tag = 0;
};
struct player
{
	int arrive, serve, play, tag;
};
bool cmpArrive(const player &lhs, const player &rhs)
{
	return lhs.arrive < rhs.arrive;
}
bool cmpServe(const player &lhs, const player &rhs)
{
	return lhs.serve < rhs.serve;
}

int nextTable(vector<table> &tables, int tag)
{
	int endTime = INT_MAX, ret;
	for (int i = 0; i < tables.size(); ++i)
	{
		if (tables[i].endTime < endTime && tables[i].tag == tag)
		{
			ret = i;
			endTime = tables[i].endTime;
		}
	}
	return ret;
}

int nextVIP(vector<player> &players, int curVIP)
{
	int ret = -1;
	for (int i = curVIP + 1; i < players.size(); ++i)
	{
		if (players[i].tag == 1)
		{
			ret = i;
			break;
		}
	}
	return ret;
}

int main()
{
	int N, h, m, s, play, tag, K, M;
	scanf("%d", &N);
	vector<player> players(N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d:%d:%d %d %d", &h, &m, &s, &play, &tag);
		players[i].arrive = h * 3600 + m * 60 + s;
		players[i].play = play > 120 ? 120 * 60 : play * 60;                  //超出2小时截断为2小时
		players[i].tag = tag;
	}
	sort(players.begin(), players.end(), cmpArrive);
	scanf("%d %d", &K, &M);
	vector<table> tables(K);
	for (int i = 0; i < M; ++i)
	{
		int id;
		scanf("%d", &id);
		tables[id - 1].tag = 1;
	}
	int vip = nextVIP(players, -1);
	for (int i = 0; i < N; ++i)
	{
		int nvipTable = nextTable(tables, 0), vipTable = nextTable(tables, 1);
		if (tables[nvipTable].endTime >= 21 * 3600 && tables[vipTable].endTime >= 21 * 3600 || players[i].arrive >= 21 * 3600)  //超出服务时间的player都不接待
			break;
		if (players[i].serve != 0)                                             //若是之前已抢占并被服务的VIP，则跳过
			continue;
		if (players[i].arrive >= tables[nvipTable].endTime && players[i].arrive >= tables[vipTable].endTime) //同时有非VIP桌和VIP桌到位
		{                                                                  
			if (players[i].tag == 1)                                           //VIP去VIP桌
			{
				players[i].serve = players[i].arrive;
				tables[vipTable].endTime = players[i].serve + players[i].play;
				tables[vipTable].cnt++;
				vip = nextVIP(players, vip);
			}
			else                                                               //非vip去序号小的可供使用的桌子，注意非VIP不能优先选择非VIP桌子
			{
				int nxt = min({ nvipTable,vipTable });
				players[i].serve = players[i].arrive;
				tables[nxt].endTime = players[i].serve + players[i].play;
				tables[nxt].cnt++;
			}
		}
		else if (tables[nvipTable].endTime < tables[vipTable].endTime)         //下一张是非VIP桌，顺序处理
		{
			if (players[i].arrive < tables[nvipTable].endTime)
			{
				players[i].serve = tables[nvipTable].endTime;
			}
			else
			{
				players[i].serve = players[i].arrive;
			}
			tables[nvipTable].endTime = players[i].serve + players[i].play;
			tables[nvipTable].cnt++;
			if (vip == i)                                                      //若最近的就是VIP，则更新VIP指向下一个VIP
				vip = nextVIP(players, vip);
		}
		else                                                                   //下一张是VIP桌
		{
			if (vip != -1 && players[vip].arrive <= tables[vipTable].endTime)  //有VIP在等则抢占
			{
				players[vip].serve = tables[vipTable].endTime;
				tables[vipTable].endTime = players[vip].serve + players[vip].play;
				if (vip != i)                                                  //若处理的VIP不是最近的，则最近的还未处理，需要--i然后下一轮再++i处理
					--i;
				vip = nextVIP(players, vip);
			}
			else                                                               //没有VIP抢占，顺序处理
			{
				if (players[i].arrive < tables[vipTable].endTime)              
				{
					players[i].serve = tables[vipTable].endTime;
				}
				else
				{
					players[i].serve = players[i].arrive;
				}
				tables[vipTable].endTime = players[i].serve + players[i].play;
				if (vip == i)                                                  
					vip = nextVIP(players, vip);
			}
			tables[vipTable].cnt++;
		}
	}
	sort(players.begin(), players.end(), cmpServe);
	for (int i = 0; i < players.size(); ++i)
	{
		if (players[i].serve != 0)
		{
			int t = round((players[i].serve - players[i].arrive) / 60.0);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", 
				players[i].arrive / 3600, players[i].arrive / 60 % 60, players[i].arrive % 60,
				players[i].serve / 3600, players[i].serve / 60 % 60, players[i].serve % 60, t);
		}
	}
	printf("%d", tables[0].cnt);
	for (int i = 1; i < tables.size(); ++i)
		printf(" %d", tables[i].cnt);
	return 0;
}