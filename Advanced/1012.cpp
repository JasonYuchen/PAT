#include<bits/stdc++.h>

using namespace std;

pair<int, char> getRank(const vector<int> &list)    //获取A,C,M,E序列下的最好排名，即A,C,M,E下若有多个最小值则取最前面的最小值
{
	int ranks[4] = { list[3], list[0], list[1], list[2] };
	char c[4] = { 'A','C','M','E' };
	auto bestRank = min_element(begin(ranks), end(ranks));  
	return{ *bestRank, c[bestRank - ranks] };
}

int main()
{
	std::ios::sync_with_stdio(false);             //数据量大时，关闭同步可以使iostream性能提升
	vector<pair<int, string>> records[4];         //4个分数的数组，记录分数和对应的学生，后序用来排序
	unordered_map<string, vector<int>> students;  //学生表，记录名字和对应每门课的排名
	string name;
	int N, query;
	cin >> N >> query;
	for (auto i = 0; i < N; ++i)
	{
		int mark[4];
		cin >> name >> mark[0] >> mark[1] >> mark[2];
		mark[3] = (mark[0] + mark[1] + mark[2]) / 3;
		for (auto j = 0; j < 4; ++j)
			records[j].push_back({ mark[j], name });
	}
	for (auto i = 0; i < 4; ++i)
		sort(records[i].begin(), records[i].end(), greater<pair<int, string>>());
	for (auto i = 0; i < 4; ++i)
	{
		int rank = 0;
		for (auto j = 0; j < N; ++j)
		{
			if (j == 0 || records[i][j - 1].first > records[i][j].first)  //处理相同分数的排名问题
				rank = j + 1;
			name = records[i][j].second;
			students[name].push_back(rank);   //根据名字将排名直接输入到学生的表中，哈希表确保O(1)查找
		}
	}
	for (auto i = 0; i < query; ++i)
	{
		cin >> name;
		if (students.find(name) == students.end())
		{
			cout << "N/A" << endl;
			continue;
		}
		auto ret = getRank(students[name]);
		cout << ret.first << " " << ret.second << endl;
	}
	return 0;
}