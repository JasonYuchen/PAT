#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);                   
	cin.tie(0);                                 
	unordered_set<char> remove;
	string S1, S2;
	getline(cin, S1);
	getline(cin, S2);
	for (auto ch : S2)
		remove.insert(ch);
	for (auto ch : S1)
	{
		if (remove.find(ch) != remove.end())
			continue;
		cout << ch;
	}
	return 0;
}