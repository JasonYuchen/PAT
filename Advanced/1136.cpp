#include<bits/stdc++.h>

using namespace std;

void add(vector<int> &A, vector<int> &B)
{
	for (int j = 0; j < A.size(); ++j)
		printf("%d", A[j]);
	printf(" + ");
	for (int j = 0; j < A.size(); ++j)
		printf("%d", B[j]);
	printf(" = ");
	int carry = 0;
	for (auto ita = A.rbegin(), itb = B.rbegin(); ita != A.rend(); ++ita, ++itb)
	{
		*ita = *ita + *itb + carry;
		carry = *ita / 10;
		*ita %= 10;
	}
	if (carry != 0)
		A.insert(A.begin(), carry);
	for (int j = 0; j < A.size(); ++j)
		printf("%d", A[j]);
	printf("\n");
}

int main()
{
	string num;
	cin >> num;
	vector<int> A;
	for (int i = 0; i < num.size(); ++i)
		A.push_back(num[i] - '0');      //若是任意进制，则这里需要根据进制处理
	int flag = 0;
	for (int i = 0; i < 10; ++i)
	{
		vector<int> tmp(A.rbegin(), A.rend());
		if (A == tmp)
		{
			for (int j = 0; j < A.size(); ++j)
				printf("%d", A[j]);
			printf(" is a palindromic number.\n");
			flag = 1;
			break;
		}
		else
		{
			add(A, tmp);
		}
	}
	if (flag == 0)
		printf("Not found in 10 iterations.\n");
	return 0;
};
