#include<bits/stdc++.h>

using namespace std;

int N, M, K; //N - applicants, M - schools, K - choices
struct app
{
	int id, GE, GI, rank;
	vector<int> prefer;
	app() { prefer.resize(K); }
};
bool operator<(const app &lhs, const app &rhs)
{
	return lhs.GE + lhs.GI > rhs.GE + rhs.GI ||
		lhs.GE + lhs.GI == rhs.GE + rhs.GI && lhs.GE > rhs.GE;
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	vector<int> quota(M);
	vector<vector<int>> admitted(M);
	vector<app> applicants(N);
	for (int i = 0; i < M; ++i)
		scanf("%d", &quota[i]);
	for (int i = 0; i < N; ++i)
	{
		applicants[i].id = i;
		scanf("%d %d", &applicants[i].GE, &applicants[i].GI);
		for (int j = 0; j < K; ++j)
			scanf("%d", &applicants[i].prefer[j]);
	}
	sort(applicants.begin(), applicants.end());
	int prev_total = 0, prev_GE = 0, rank = 0;
	for (int i = 0; i < N; ++i)
	{
		int total = applicants[i].GE + applicants[i].GI;
		int GE = applicants[i].GE;
		if (!(total == prev_total && GE == prev_GE))            //给出rank，若总分相同且GE相同则rank相同
		{
			prev_total = total;
			prev_GE = GE;
			rank = i + 1;
		}
		applicants[i].rank = rank;
	}
	int prev_rank = 0, prev_school = -1;
	for (int i = 0; i < N; ++i)
	{
		int rank = applicants[i].rank;
		for (int j = 0; j < applicants[i].prefer.size(); ++j)
		{
			int prefer = applicants[i].prefer[j];
			if (admitted[prefer].size() < quota[prefer] ||      //未收满
				rank == prev_rank && prefer == prev_school)     //或同rank且要去同一个学校，则都必须接收
			{
				admitted[prefer].push_back(applicants[i].id);
				prev_rank = rank;
				prev_school = prefer;
				break;
			}
		}
	}
	for (auto &s : admitted)
	{
		sort(s.begin(), s.end());
		for (int i = 0; i < s.size(); ++i)
			printf("%d%s", s[i], i == s.size() - 1 ? "" : " ");
		printf("\n");
	}
	return 0;
}
