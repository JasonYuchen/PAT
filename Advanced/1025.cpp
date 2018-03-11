#include<bits/stdc++.h>

using namespace std;

struct record
{
	string name;
	int score;
	int local_rank;
	int location;
	int final_rank;
	record(const string &n, int s, int l) :name(n), score(s), location(l) {}
};

bool operator<(const record &lhs, const record &rhs)
{
	return
		lhs.score < rhs.score ||
		lhs.score == rhs.score && lhs.name > rhs.name;
}

int main()
{
	ios::sync_with_stdio(false);
	int N, K, score;
	string name;
	vector<record> records;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> K;
		for (int j = 0; j < K; ++j)
		{
			cin >> name >> score;
			records.push_back(record(name, score, i + 1));
		}
	}
	sort(records.rbegin(), records.rend());                     //用一个vector来存储，整体排序就能得到final_rank
	int rank_local[301], score_local[301], score_final = 101;   //通过rank_local和score_local来获得局部排名
	fill(rank_local, rank_local + 300, 0);
	fill(score_local, score_local + 300, 101);
	for (int i = 0; i < records.size(); ++i)
	{
		if (records[i].score < score_final)
		{
			score_final = records[i].score;
			records[i].final_rank = i + 1;
		}
		else
		{
			records[i].final_rank = records[i - 1].final_rank;
		}
		int local = records[i].location;
		if (records[i].score < score_local[local])
		{
			score_local[local] = records[i].score;
			records[i].local_rank = rank_local[local] + 1;
		}
		else
		{
			records[i].local_rank = records[i - 1].local_rank;
		}
		rank_local[local]++;
	}
	cout << records.size() << '\n';
	for (auto re : records)
	{
		cout << re.name << " " << re.final_rank << " " << re.location << " " << re.local_rank << '\n';
	}
	return 0;
}
