#include<bits/stdc++.h>

using namespace std;

string create(const string &num, const string::iterator &it, int digits)
{
	string ret;
	for (auto st = it; digits > 0;)        //只保留digits位即可，超出的部分直接忽略
	{
		if (st == num.end())               //若原数已到尽头但精度不足，则后续补"0"
		{
			ret.push_back('0');
			--digits;
		}
		else if(isdigit(*st))              //跳过"."，只处理数字
		{
			ret.push_back(*st);
			++st;
			--digits;
		}
		else
		{
			++st;
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);                   
	cin.tie(0);
	int digits;
	string num_1, num_2;
	cin >> digits >> num_1 >> num_2;                                                                        //0.d1d2d3...dn*10^k
	auto point_1 = find(num_1.begin(), num_1.end(), '.');                                                   //获得小数点位置，若没有小数点则返回的尾后迭代器也是正确的小数点位置
	auto point_2 = find(num_2.begin(), num_2.end(), '.');
	auto st_1 = find_if(num_1.begin(), num_1.end(), [](char c) {return isdigit(c) && c != '0'; });          //获得第一位非0数字作为起点
	auto st_2 = find_if(num_2.begin(), num_2.end(), [](char c) {return isdigit(c) && c != '0'; });
	auto exp_1 = distance(st_1, point_1);                                                                   //指数通过第一位非0数字的位置和小数点位置求差获得
	auto exp_2 = distance(st_2, point_2);
	auto ret_num_1 = create(num_1, st_1, digits);                                                           //获得d1d2d3...
	auto ret_num_2 = create(num_2, st_2, digits);
	auto is0_1 = find_if(ret_num_1.begin(), ret_num_1.end(), [](char c) {return isdigit(c) && c != '0'; }); //若d1d2d3..全是0则意味着数字是0，设定指数是0
	auto is0_2 = find_if(ret_num_2.begin(), ret_num_2.end(), [](char c) {return isdigit(c) && c != '0'; });

	if (is0_1 == ret_num_1.end())
		ret_num_1 = "0." + ret_num_1 + "*10^0";
	else
		ret_num_1 = "0." + ret_num_1 + "*10^" + to_string(exp_1 < 0 ? exp_1 + 1 : exp_1);                   //若是负指数，由于小数点占一位，因此要+1

	if (is0_2 == ret_num_2.end())
		ret_num_2 = "0." + ret_num_2 + "*10^0";
	else
		ret_num_2 = "0." + ret_num_2 + "*10^" + to_string(exp_2 < 0 ? exp_2 + 1 : exp_2);

	if (ret_num_1 == ret_num_2)                                                                             //直接利用string来比较是否相等
		cout << "YES " << ret_num_1 << endl;
	else
		cout << "NO " << ret_num_1 << " " << ret_num_2 << endl;
	return 0;
}
