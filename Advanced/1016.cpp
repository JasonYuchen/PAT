#include<bits/stdc++.h>

using namespace std;

struct record
{
	string name;
	int month, day, hour, minute, status, time;
	double _fee;
	record(const string &n, int mon, int d, int h, int min, int st)
		:name(n), month(mon), day(d), hour(h), minute(min), status(st) 
	{
		time = day * 24 * 60 + hour * 60 + minute;       //从0号0时0分开始计算到现在的原始时间，后续求时长只需要求差
	}
	void set_fee(const vector<int> &rate)                //从0号0时0分开始计算到现在的原始费用，后续求费用只需要求差
	{
		auto day_fee = (day - 1)*rate[24] * 60;
		auto min_fee = rate[hour] * minute;
		auto hour_fee = 0;
		for (auto i = 0; i < hour; ++i)
			hour_fee += rate[i] * 60;
		_fee = (day_fee + hour_fee + min_fee) / 100.0;
	}
};
bool operator<(const record &lhs, const record &rhs)     //重载比较运算，按姓名、原始时间排序，随后配对时只需要考虑相邻同名且on-off匹配的record
{
	return lhs.name < rhs.name || lhs.name == rhs.name && lhs.time < rhs.time;
}
int main()
{
	vector<int> rate(25);                                //rate[24]用来记录一整天需要消耗的费用/(天*分钟)，因此实际一天要*60
	vector<record> recordsList;
	for (auto i = 0; i < 24; ++i)
	{
		scanf("%d", &rate[i]);
		rate[24] += rate[i];
	}
	int N;
	scanf("%d", &N);
	for (auto i = 0; i < N; ++i)
	{
		char name[20], s[10];
		int month, day, hour, minute, status;
		scanf("%s %d:%d:%d:%d %s", name, &month, &day, &hour, &minute, s);
		if (s[1] == 'n') status = 0; else status = 1;
		auto tmp = record(name, month, day, hour, minute, status);
		tmp.set_fee(rate);
		recordsList.push_back(tmp);
	}
	sort(recordsList.begin(), recordsList.end());
	map<string, vector<pair<record, record>>> ret;
	for (auto i = 1; i < recordsList.size(); ++i)
	{
		auto &on = recordsList[i-1], &off = recordsList[i];
		if (on.name == off.name && on.status == 0 && off.status == 1)    //相邻同名且on-off匹配的record就添加到输出中
		{
			on._fee = off._fee - on._fee;                                //将on-line的record里的time和_fee修改为实际时长和实际费用
			on.time = off.time - on.time;
			ret[recordsList[i].name].push_back({ on,off });
		}
	}
	for (auto &ch : ret)
	{
		auto total = 0.0;
		printf("%s %02d\n", ch.first.c_str(), ch.second.begin()->first.month);
		for (auto re : ch.second)
		{
			total += re.first._fee;
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
				re.first.day, re.first.hour, re.first.minute,
				re.second.day, re.second.hour, re.second.minute,
				re.first.time, re.first._fee);
		}
		printf("Total amount: $%.2f\n", total);
	}
	return 0;
}
