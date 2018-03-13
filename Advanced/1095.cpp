#include<bits/stdc++.h>

using namespace std;

struct record
{
	string plate;
	int time, tag;
	record(const string &name, int h, int m, int s, int t) :
		plate(name), time(3600 * h + 60 * m + s), tag(t) {}
};

bool cmpplate(const record &lhs, const record &rhs)
{
	return lhs.plate < rhs.plate || lhs.plate == rhs.plate && lhs.time < rhs.time;
}

bool cmptime(const record &lhs, const record &rhs)
{
	return lhs.time < rhs.time;
}

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	string plate;
	int hour, min, sec;
	vector<record> input, records;
	for (int i = 0; i < N; ++i)
	{
		char tmp[8], tag[4];
		scanf("%s %d:%d:%d %s", tmp, &hour, &min, &sec, tag);
		input.push_back({ tmp,hour,min,sec,tag[0] == 'o' ? 1 : 0 });     //tag = 0 - in, tag = 1 - out
	}
	sort(input.begin(), input.end(), cmpplate);
	set<string> longest;                                                 //字典序存储等时间长的最长停车车牌
	unordered_map<string, int> parkTime;                                 //记录每辆车的停车时间
	int longestTime = 0;
	for (int i = 0; i < N - 1; ++i)                      
	{
		if (input[i].plate == input[i + 1].plate                         //相邻记录同一辆车，且前进后出，则是有效记录
			&& input[i].tag == 0 && input[i + 1].tag == 1)
		{
			records.push_back(input[i]);
			records.push_back(input[i + 1]);
			parkTime[input[i].plate] += input[i + 1].time - input[i].time;
			if (parkTime[input[i].plate] > longestTime)                  //每段记录都更新到散列表中，并更新最长停车时间及车牌
			{
				longestTime = parkTime[input[i].plate];
				longest.clear();
				longest.insert(input[i].plate);
			}
			else if(parkTime[input[i].plate] == longestTime)
			{
				longest.insert(input[i].plate);
			}
		}
	}
	sort(records.begin(), records.end(), cmptime);
	vector<pair<int, int>> parking(records.size() + 1);                  //记录每个时间段内的停车，类似DP，初始化为00:00:00时刻-0辆车
	for (int i = 0; i < records.size(); ++i)
	{
		parking[i + 1].first = records[i].time;
		if (records[i].tag == 0)
			parking[i + 1].second = parking[i].second + 1;               //若某一时刻是in，则在前一时刻的停车数+1
		else
			parking[i + 1].second = parking[i].second - 1;               //若某一时刻是out，则在前一时刻的停车数-1
	}
	auto p = parking.begin();
	for (int i = 0; i < K; ++i)
	{
		scanf("%d:%d:%d", &hour, &min, &sec);
		int tmp = 3600 * hour + 60 * min + sec;
		p = find_if(p, parking.end(),                                    //题设条件是查询记录根据时间递增顺序给出，则这里也可以维护一个当前查询到的结点迭代器
			[&](const pair<int, int> &t) {return t.first > tmp; });
		p = prev(p);
		printf("%d\n", p->second);
	}
	for (auto it = longest.begin(); it != longest.end(); ++it)
		printf("%s ", it->c_str());
	printf("%02d:%02d:%02d\n", longestTime / 3600, longestTime / 60 % 60, longestTime % 60);
	return 0;
}