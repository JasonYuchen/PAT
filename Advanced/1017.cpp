#include<bits/stdc++.h>

using namespace std;

struct node
{
	int _time, _waste;
};
bool operator<(const node &lhs, const node &rhs)
{
	return lhs._time < rhs._time;
}
int main()
{
	vector<node> records;
	vector<int> base;                                          
	int totalWaste = 0;
	int N, K;
	scanf("%d %d", &N, &K);
	base.resize(K);
	fill(base.begin(), base.end(), 8 * 3600);                    //维护一个窗口时间，记录上一个完成业务的时间，初始为8:00
	for (auto i = 0; i < N; ++i)
	{
		int hour, minute, second, waste;
		scanf("%d:%d:%d %d", &hour, &minute, &second, &waste);
		node tmp;
		tmp._time = hour * 3600 + minute * 60 + second;
		tmp._waste = waste * 60;
		if (tmp._time > 17*3600)
			continue;
		records.push_back(tmp);
	}
	sort(records.begin(), records.end());
	for (auto i = 0; i < records.size(); ++i)
	{
		auto entry = min_element(base.begin(), base.end());
		if (records[i]._time < *entry)                           //若抵达时间早于最近可用窗口，则需要等
		{
			totalWaste += *entry - records[i]._time;
			*entry += records[i]._waste;                         //并将最近可用窗口的上一个完成业务时间加上这位顾客的业务时长
		}
		else
		{
			*entry = records[i]._time + records[i]._waste;       //若抵达时间晚，则不用等直接服务，并将业务完成时间修改为这位顾客的业务结束时间
		}
	}
	if (records.empty())
		printf("0.0\n");
	else
		printf("%.1f\n", totalWaste / 60.0 / records.size());
	return 0;
}
