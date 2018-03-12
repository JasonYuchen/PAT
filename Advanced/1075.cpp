#include<bits/stdc++.h>

using namespace std;

int N, K, M;                                      //N - users, K - problems, M - submissions
struct user
{
	int id, total = 0, perfects = 0, tag = 0;
	vector<int> scores;
	user() { scores.resize(K, -2); }              //初始化分数为-2
	void setScore(int problem, int score, const vector<int> &problems)
	{
		if (score >= 0)                           //只要有一题分出>=0，说明过了编译期的提交，则可排序标记tag=1
			tag = 1;
		if (score > scores[problem - 1])
		{
			scores[problem - 1] = score;
			int tmp = 0;
			for (int i = 0; i < scores.size(); i++)
				tmp += scores[i] >= 0 ? scores[i] : 0;
			total = tmp;
			if (score == problems[problem - 1])   //只有在更新分数的时候需要判断是否出现新的满分题
				perfects++;
		}
	}
};
bool operator<(const user &lhs, const user &rhs)  //tag=1在前，tag=0不输出，然后根据总分-满分题-ID号的优先级来排序
{
	return
		lhs.tag > rhs.tag ||
		lhs.tag == rhs.tag && lhs.total > rhs.total ||
		lhs.tag == rhs.tag && lhs.total == rhs.total && lhs.perfects > rhs.perfects ||
		lhs.tag == rhs.tag && lhs.total == rhs.total && lhs.perfects == rhs.perfects && lhs.id < rhs.id;
}

int main()
{
	scanf("%d %d %d", &N, &K, &M);
	vector<int> maxScore(K);
	vector<user> users(N);
	for (int i = 0; i < K; ++i)
		scanf("%d", &maxScore[i]);
	for (int i = 0; i < M; ++i)
	{
		int id, problem_id, score;
		scanf("%d %d %d", &id, &problem_id, &score);
		users[id - 1].id = id;
		users[id - 1].setScore(problem_id, score, maxScore);
	}
	sort(users.begin(), users.end());
	int cnt, prev = 0;
	for (int i = 0; i < users.size(); ++i)
	{
		if (users[i].tag == 0)
			break;
		if (users[i].total != prev)
		{
			prev = users[i].total;
			cnt = i + 1;
		}
		printf("%d %05d %d", cnt, users[i].id, users[i].total);
		for (auto s : users[i].scores)
		{
			if (s < -1)
				printf(" -");
			else
				printf(" %d", s == -1 ? 0 : s);  //只有未提交的题目显示'-'，未通过编译的是0分
		}
		printf("\n");
	}
	return 0;
}
