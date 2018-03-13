#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string sell, want;
	cin >> sell >> want;
	unordered_map<char, int> wantCount;                                //记录每个颜色的需求量
	for (auto c : want)
		wantCount[c]++;
	for (auto c : sell)
	{
		if (wantCount.find(c) != wantCount.end() && wantCount[c] > 0)  //若已满足当前颜色的需求，则不能继续--
			wantCount[c]--;
	}
	int more = 0;
	for (auto remain : wantCount)
		more += remain.second;                                         //记录还未满足的需求总数
	if (more == 0)
		cout << "Yes " << (sell.size() - want.size()) << endl;
	else
		cout << "No " << more << endl;
	return 0;
}
