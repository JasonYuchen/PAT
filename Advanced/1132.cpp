#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string num;
		cin >> num;
		int Z = stoi(num);
		string a(num.begin(), num.begin() + num.size() / 2);
		string b(num.begin() + num.size() / 2, num.end());
		int A = stoi(a), B = stoi(b);
		if (A != 0 && B != 0 && Z % (A*B) == 0)  //注意可能有100000这样，切割后出现0，此时不能再%（会浮点错误），直接输出No
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';
	}
	return 0;
}