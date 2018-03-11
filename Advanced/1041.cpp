#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);                    
	cin.tie(0);
	int N;
	cin >> N;
	unordered_map<int, int> digit;                   //散列表存储每个数字出现的次数
	vector<int> bet;                                 //向量表顺序存储，随后找winner时顺序查找
	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;
		digit[num]++;
		bet.push_back(num);
	}
	auto it = find_if(bet.begin(), bet.end(), [&](int i) {return digit[i] == 1; });
	if (it == bet.end())
		cout << "None" << endl;
	else
		cout << *it << endl;
	return 0;
}