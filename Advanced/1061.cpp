#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	unordered_set<char> Set;
	string date[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	int cnt = 0;
	for (int i = 0; i < a1.size() && i < b1.size(); ++i)        //并不是找共有的字符，逐位比较即可
	{
		if (a1[i] == b1[i])
		{
			if (cnt == 0 && isupper(a1[i]) && a1[i] <= 'G')
			{
				cout << date[a1[i] - 'A'] << " ";
				cnt = 1;
			}
			else if (cnt == 1 && isupper(a1[i]) && a1[i] <= 'N')
			{
				cout << (10 + a1[i] - 'A') << ":";
				break;
			}
			else if (cnt == 1 && isdigit(a1[i]))
			{
				cout << setw(2) << setfill('0') << (a1[i] - '0') << ":";
				break;
			}

		}
	}
	for (int i = 0; i < a2.size() && i < b2.size(); ++i)
	{
		if (a2[i] == b2[i] && isalpha(a2[i]))
		{
			cout << setw(2) << setfill('0') << i << endl;
			break;
		}
	}
	return 0;
}
