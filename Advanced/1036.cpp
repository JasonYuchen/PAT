#include<bits/stdc++.h>

using namespace std;

struct student
{
	string name;
	char gender;
	string test;
	int grade;
	student(const string &n, char gen, const string &t, int gra) :name(n), gender(gen), test(t), grade(gra) {}
};

bool operator<(const student &lhs, const student &rhs)   //将男女学生分别按分数排序即可
{
	return lhs.gender < rhs.gender ||
		lhs.gender == rhs.gender && lhs.grade > rhs.grade;
}

int main()
{
	ios::sync_with_stdio(false);
	vector<student> s;
	string name, test;
	char gender;
	int grade;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> name >> gender >> test >> grade;
		s.push_back(student(name, gender, test, grade));
	}
	sort(s.begin(), s.end());

	auto highestF = *s.begin();
	auto lowestM = *--s.end();
	auto diff = highestF.grade - lowestM.grade;
	auto flag = 1;
	if (highestF.gender == 'F')
	{
		cout << highestF.name << " " << highestF.test << endl;
	}
	else
	{
		cout << "Absent" << endl;
		flag = 0;
	}
	if (lowestM.gender == 'M')
	{
		cout << lowestM.name << " " << lowestM.test << endl;
	}
	else
	{
		cout << "Absent" << endl;
		flag = 0;
	}
	if (flag == 1)
		cout << diff << endl;
	else
		cout << "NA" << endl;
	return 0;
}
