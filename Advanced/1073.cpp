#include<bits/stdc++.h>

using namespace std;

int main()
{
	string in, out;
	cin >> in;
	auto point = find(in.begin(), in.end(), '.');    //获得小数点的位置
	auto E = find(in.begin(), in.end(), 'E');        //获得指数标记的位置
	int exp = stoi(string(E + 1, in.end()));         //获得指数值
	for (auto it = in.begin(); it < E; ++it)
	{
		if (isdigit(*it))
			out.push_back(*it);                      //所有有效数字都添加进out中
	}
	if (exp < 0)                                     //负指数就在前添"0.0000..."，正指数就在合适的位置添'.'或超出填充'0'
	{
		out = "0." + string(-exp - 1, '0') + out;
	}
	else
	{
		for (auto it = ++out.begin(); it <= out.end(); ++it)
		{
			if (exp == 0)
			{
				it = out.insert(it, '.');
				break;
			}
			else if (it == out.end())
			{
				it = out.insert(it, '0');
			}
			exp--;
		}
	}
	if (in[0] == '-')            //若输出负数，添加'-'
		out = "-" + out;
	if (*--out.end() == '.')     //若只有末尾有'.'，则去掉
		out.erase(--out.end());
	cout << out << endl;
	return 0;
}