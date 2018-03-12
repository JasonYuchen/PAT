#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<string>
		digits = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" },
		unit = { "","Shi","Bai","Qian","Wan","Shi","Bai","Qian","Yi" };
	string num;
	cin >> num;
	if (num[0] == '-')           //处理负数
	{
		cout << "Fu ";
		num.erase(num.begin());
	}
	cout << digits[num[0] - '0'] 
		 << (num.size() == 1 ? "" : " ") << unit[num.size() - 1];  //至少输出1个数字，考虑是否有单位
	for (int i = 1; i < num.size(); ++i)
	{
		if (num[i] != '0')                                         //若不是0则正常输出数字和单位
		{
			cout << " " << digits[num[i] - '0'];
			if (i == num.size() - 1)                               //个位数没有单位"ge"，直接退出循环
				break;
			cout << " " << unit[num.size() - i - 1];
		}
		else                                                       //若遇到0
		{
			int prev = num.size() - i - 1;			               //最先遇到的0所在的位置，序号从0开始低位到高位递增
			while (i < num.size() && num[i] == '0') i++;	       //吞掉与遇到的0连续的所有0
			int curr = num.size() - i - 1;			               //最后遇到的0所在的位置低1位
			if (prev / 4 * 4 != curr / 4 * 4)			           //若吞掉的0跨越了4的倍数的单位位置（万、亿），则要输出最先遇到的0所在的位置的大单位（万、亿）
				cout << " " << unit[prev / 4 * 4];
			if (i == num.size())					               //若已吞掉所有0并且位于尾后位置，则结束转换
				break;
			cout << " ling";                                       //任意多个零，只需输出1个ling
			--i;                                                   //由于i到了下一个非0位置，而for还会++i，因此这里要--i
		}
	}
	return 0;
}