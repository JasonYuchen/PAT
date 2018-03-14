#include<bits/stdc++.h>

using namespace std;

struct node
{
	string name;
	int height;
};

bool operator<(const node &lhs, const node &rhs)
{
	return lhs.height > rhs.height || lhs.height == rhs.height && lhs.name < rhs.name;
}

int main()
{
	ios::sync_with_stdio(false);
	int N, K, cnt = 0;
	cin >> N >> K;
	int m = N / K;
	vector<node> Seq(N);
	for (int i = 0; i < N; ++i)
		cin >> Seq[i].name >> Seq[i].height;
	sort(Seq.begin(), Seq.end());
	deque<string> lines;
	for (int i = 0; i < K; ++i)
	{
		if (i == 0)
			m = N / K + N - N / K*K;            //最后一排可能有多余的人
		else
			m = N / K;
		for (int j = 0; j < m; ++j)
			if (j % 2 == 0)                     //左右依次站人
				lines.push_back(Seq[cnt++].name);
			else
				lines.push_front(Seq[cnt++].name);
		cout << lines.front();
		lines.pop_front();
		while (!lines.empty())
		{
			cout << " " << lines.front();
			lines.pop_front();
		}
		cout << '\n';
	}
	return 0;
};
