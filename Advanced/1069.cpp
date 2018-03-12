#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);                   
	cin.tie(0);
	string val, sub, prev_res, res;
	cin >> val;
	val = string(4 - val.size(), '0') + val;    //根据缺少的位数在前补0
	sub = val;
	sort(val.begin(), val.end(), greater<char>());
	sort(sub.begin(), sub.end());
	res = to_string(stoi(val) - stoi(sub));
	res = string(4 - res.size(), '0') + res;

	while (res != prev_res)
	{
		cout << val << " - " << sub << " = " << res << '\n';
		prev_res = res;
		val = res;
		sub = res;
		sort(val.begin(), val.end(), greater<char>());
		sort(sub.begin(), sub.end());
		res = to_string(stoi(val) - stoi(sub));
		res = string(4 - res.size(), '0') + res;
	}
	return 0;
}