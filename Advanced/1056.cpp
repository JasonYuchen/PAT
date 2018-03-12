#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int Np, Ng, rounds = 0;
	cin >> Np >> Ng;
	vector<int> weight(Np), rank(Np);
	vector<int> q, tmp_q;
	for (int i = 0; i < Np; ++i)
	{
		cin >> weight[i];
	}
	for (int i = 0; i < Np; ++i)
	{
		int player;
		cin >> player;
		q.push_back(player);                                           //队列来存储进入下一轮比较的人
	}
	while (q.size() > 1)
	{
		auto tmp_rank = q.size() / Ng + (q.size() % Ng == 0 ? 1 : 2);  //排序名次问题，注意并列名次相等，由于每Ng留下1人，可以根据参与的人数来计算当前轮的名次
		auto pos = q.begin();
		while (distance(pos, q.end()) >= Ng)                           //每Ng人求出获胜的1人
		{
			int winner = 0, max = 0;
			for (auto it = pos; it < pos + Ng; ++it)
			{
				rank[*it] = tmp_rank;                                  //初始化本轮所有人的名次为当前轮的名次，获胜者会在后一轮比赛中更新名次
				if (weight[*it] > max)
				{
					winner = *it;
					max = weight[*it];
				}
			}
			tmp_q.push_back(winner);
			pos += Ng;
		}
		if (pos != q.end())                                            //剩余但不足Ng人的，求出获胜的1人
		{
			int winner = 0, max = 0;
			for (auto it = pos; it < q.end(); ++it)
			{
				rank[*it] = tmp_rank;
				if (weight[*it] > max)
				{
					winner = *it;
					max = weight[*it];
				}
			}
			tmp_q.push_back(winner);
		}
		q = tmp_q;
		tmp_q.clear();
	}
	rank[q[0]] = 1;                                                    //最终胜者的名次更新为1
	cout << rank[0];
	for (int i = 1; i < Np; ++i)
	{
		cout << " " << rank[i];
	}
	return 0;
}
