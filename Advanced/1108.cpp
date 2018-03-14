#include<bits/stdc++.h>

using namespace std;

bool judge(const string &s)
{
	int points = 0;
	int i = 0;
	if (!isdigit(s[0]) && s[0] != '-')               //开头不是数字或负号非法
		return false;
	if (s[0] == '-')
		i = 1;
	for (; i < s.size(); ++i)
	{
		if (s[i] == '.')
			points++;
		else if (!isdigit(s[i]))                     //数字中出现非数字符号非法
			return false;
		if (points > 1)                              //超过1个小数点非法
			return false;
	}
	auto pos = s.find('.');
	if (pos != string::npos && s.size() - pos > 3)   //超出2位小数非法
		return false;
	double ret = stod(s);
	if (ret > 1000 || ret < -1000)                   //超出[-1000,1000]非法
		return false;
	return true;
}
int main()
{
	int N, cnt = 0;
	scanf("%d", &N);
	double sum = 0;
	for (int i = 0; i < N; ++i)
	{
		string tmp;
		cin >> tmp;
		if (judge(tmp) == false)
			cout << "ERROR: " << tmp << " is not a legal number\n";
		else
		{
			cnt++;
			sum += stod(tmp);
		}
	}
	if (cnt == 0)
	{
		printf("The average of 0 numbers is Undefined\n");
	}
	else if (cnt > 1)
		printf("The average of %d numbers is %.2lf\n", cnt, sum / cnt);
	else
		printf("The average of %d number is %.2lf\n", cnt, sum);
	return 0;
};
