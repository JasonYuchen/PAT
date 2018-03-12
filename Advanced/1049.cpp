#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);                   
	cin.tie(0);                                 
	string N;
	int cnt = 0;
	cin >> N;
	for (int i = 0; i < N.size(); ++i)                       //每一位固定为1，变化其他位上的数字，计算可能的数字数量
	{
		string fwd(N.begin(), N.begin() + i);                //该位之前的数字
		string bkd(N.begin() + i + 1, N.end());              //该位之后的数字
		int fwdn = fwd == string() ? 1 : stoi(fwd) + 1;
		int bkdn = bkd == string() ? 1 : stoi(bkd) + 1;
		if (N[i] > '1')                                      //原先数字大于1，则该位为1时，前面共有fwdn种可能性，后面共有10^位数种可能性
		{
			cnt += (fwdn*std::pow(10, bkd.size()));
		}
		else if (N[i] == '1')                                //原先数字等于1，则该位为1时，前面共有fwdn种可能性，分两段：当前面是fwdn-1时后面共有10^位数种可能性，当前面是fwdn时，后面最大只能到bkdn
		{
			cnt += (fwdn - 1)*std::pow(10, bkd.size()) + bkdn;
		}
		else if (N[i] < '1')                                 //原先数字小于1，则只有在前面是fwdn-1时才可以将该位设为1，后面共有10^位数种可能性
		{
			cnt += (fwdn - 1)*std::pow(10, bkd.size());
		}
	}
	cout << cnt << endl;
	return 0;
}