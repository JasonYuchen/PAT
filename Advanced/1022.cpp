#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);                    //全部使用iostream，关闭同步可以提高IO性能
	unordered_map<string, set<int>> index[5];       //索引采用散列表，一个关键字可能对应多个ID且ID要有顺序，用set
	int N;
	string tmp;
	cin >> N;
	getline(cin, tmp);                              //注意cin>>N后会留下上一个\n，这里要先吃掉这个\n
	for (int i = 0; i < N; ++i)
	{
		string line;
		getline(cin, line);
		int ID = stoi(line);
		for (int j = 0; j < 5; ++j)
		{
			getline(cin, line);
			if (j == 2)
			{
				istringstream keywords(line);       //istringstream处理不定数量的keyword
				string keyword;
				while (keywords >> keyword)
				{
						index[j][keyword].insert(ID);
				}
				continue;
			}
			index[j][line].insert(ID);              //添加一本书所有可索引信息到index中
		}
	}
	cin >> N;
	getline(cin, tmp);
	for (int i = 0; i < N; ++i)
	{
		string line;
		getline(cin, line);
		cout << line << '\n';
		string key(line.begin() + 3, line.end());
		int entry = line[0] - '0' - 1;
		auto value = index[entry].find(key);
		if (value == index[entry].end())
			cout << "Not Found\n";
		else
			for (auto ch : value->second)
				cout << setw(7) << setfill('0') << ch << '\n';  //注意ID用int，则需要控制宽度7位，不足补零

	}
	return 0;
}