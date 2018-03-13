#include<bits/stdc++.h>

using namespace std;

int main() 
{
	string s;
	cin >> s;
	int len = s.length(), result = 0, p = 0, t = 0;
	for (int i = 0; i < len; i++)    //统计一共有多少个T
		if (s[i] == 'T')
			t++;
	for (int i = 0; i < len; i++)    //顺序扫描，对于每个当前位置，记录在此之前有p个P，在此之后有t个T，若当前是A则可以组成p*t个PAT
	{
		if (s[i] == 'P')      
			p++;     
		if (s[i] == 'T')        
			t--;     
		if (s[i] == 'A')      
			result = (result + (p * t) % 1000000007) % 1000000007;   //每次运算都要对1e9+7取余，防止溢出
	}
	cout << result;
	return 0;
}

/*
** 1.1000000007是一个质数
** 2.int32位的最大值为2147483647，所以对于int32位来说1000000007足够大
** 3.int64位的最大值为2^63-1，对于1000000007来说它的平方不会在int64中溢出
**
** 所以在大数相乘的时候，因为(a*b)%c=((a%c)*(b%c))%c，所以相乘时两边都对1000000007取模，再保存在int64里面不会溢出
*/