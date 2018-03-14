#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	set<int> ID;
	for (int i = 0; i < N; ++i)
	{
		string num;
		cin >> num;
		ID.insert(getId(num));
	}
	cout << ID.size() << '\n';
	cout << *ID.begin();
	for (auto it = ++ID.begin(); it != ID.end(); ++it)
		cout << " " << *it;
	return 0;
}