#include<bits/stdc++.h>

using namespace std;

int main()
{
	int NC, NP;
	scanf("%d", &NC);
	vector<long long> coupon(NC);                 //考虑到最大不超过2^30，则相乘不超过2^60，用long long存储
	for (int i = 0; i < NC; ++i)
	{
		scanf("%lld", &coupon[i]);              //注意long long是%lld
	}
	sort(coupon.begin(), coupon.end());           //排序后大负数从开头往后，大正数从末尾往前
	scanf("%d", &NP);
	vector<long long> product(NP);
	for (int i = 0; i < NP; ++i)
	{
		scanf("%lld", &product[i]);
	}
	sort(product.begin(), product.end());

	long long ret[2] = { 0,0 }, carry = 0;        //考虑到最多10^5组成绩，最大和不超过10^5*2^60>2^64超出long long，因此用数组
	long long max = 1;
	max <<= 60;                                   //数组ret[0]存储<2^60的值，超出的存储在ret[1]中
	vector<long long> multiple;
	int minusC = 0, minusP = 0, posC = coupon.size() - 1, posP = product.size() - 1;
	while (minusC < coupon.size() && minusP < product.size() && coupon[minusC] < 0 && product[minusP] < 0)
	{
		multiple.push_back(coupon[minusC] * product[minusP]);
		++minusC;
		++minusP;
	}
	while (posC >= 0 && posP >=0 && coupon[posC] > 0 && product[posP] > 0)
	{
		multiple.push_back(coupon[posC] * product[posP]);
		--posC;
		--posP;
	}
	for (auto item : multiple)
	{
		ret[0] += item;
		carry = ret[0] / max;
		ret[0] %= max;
		ret[1] += carry;
	}
	if (ret[1] == 0)
		printf("%lld", ret[0]);
	else
		printf("%lld%lld", ret[1], ret[0]);
	return 0;
}
