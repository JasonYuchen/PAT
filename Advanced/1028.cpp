#include<bits/stdc++.h>

using namespace std;

struct record
{
	string ID;
	string Name;
	int Grade;
}tmp;

bool cmpID(const record &lhs, const record &rhs)
{
	return lhs.ID < rhs.ID;
}

bool cmpName(const record &lhs, const record &rhs)
{
	return lhs.Name < rhs.Name || lhs.Name == rhs.Name && lhs.ID < rhs.ID;
}

bool cmpGrade(const record &lhs, const record &rhs)
{
	return lhs.Grade < rhs.Grade || lhs.Grade == rhs.Grade && lhs.ID < rhs.ID;
}

int main()
{
	ios::sync_with_stdio(false);  //必须关闭同步，否则超时
	int N, column;
	vector<record> students;
	cin >> N >> column;
	for (auto i = 0; i < N; ++i)
	{
		cin >> tmp.ID >> tmp.Name >> tmp.Grade;
		students.push_back(tmp);
	}
	switch (column)
	{
	case 1:sort(students.begin(), students.end(), cmpID); break;
	case 2:sort(students.begin(), students.end(), cmpName); break;
	case 3:sort(students.begin(), students.end(), cmpGrade); break;
	}
	for (auto ch : students)
	{
		cout << ch.ID << " " << ch.Name << " " << ch.Grade << '\n';
	}
	return 0;
}
