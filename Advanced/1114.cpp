#include<bits/stdc++.h>

using namespace std;

struct node
{
	int ID, estate, area;
	vector<int> related;
}Nodes[10000];

int visited[10000];
int minId, sum_estate, sum_area, cnt;
void DFS(int id)
{
	visited[id] = 1;
	if (id < minId)
		minId = id;
	cnt += 1;
	sum_estate += Nodes[id].estate;
	sum_area += Nodes[id].area;
	for (int i = 0; i < Nodes[id].related.size(); ++i)
		if (visited[Nodes[id].related[i]] == 0)
			DFS(Nodes[id].related[i]);
}

struct Set
{
	int id, count;
	double avg_sets, avg_area;
	Set(int i, int c, double avg_s, double avg_a) :id(i), count(c), avg_sets(avg_s), avg_area(avg_a) {}
};
bool operator<(const Set &lhs, const Set &rhs)
{
	return lhs.avg_area > rhs.avg_area || lhs.avg_area == rhs.avg_area && lhs.id < rhs.id;
}
int main()
{
	int N;
	scanf("%d", &N);
	unordered_set<int> person;
	for (int i = 0; i < N; ++i)
	{
		int id, f, m, n, estate, area;
		scanf("%d %d %d %d", &id, &f, &m, &n);
		person.insert(id);                          //所有人都要加入person集合，并且都要出现在彼此的related集合中
		if (f != -1)
		{
			Nodes[id].related.push_back(f);
			person.insert(f);
			Nodes[f].ID = f;
			Nodes[f].related.push_back(id);
		}
		if (m != -1)
		{
			Nodes[id].related.push_back(m);
			person.insert(m);
			Nodes[m].ID = m;
			Nodes[m].related.push_back(id);
		}
		for (int j = 0; j < n; ++j)
		{
			int child;
			scanf("%d", &child);
			Nodes[id].related.push_back(child);
			Nodes[child].ID = child;
			Nodes[child].related.push_back(id);
			person.insert(child);
		}
		scanf("%d %d", &estate, &area);
		Nodes[id].estate = estate;
		Nodes[id].area = area;
	}
	vector<Set> families;
	for (auto it : person)
	{
		if (visited[it] == 0)
		{
			minId = 10000;
			sum_estate = 0;
			sum_area = 0;
			cnt = 0;
			DFS(it);
			families.push_back(Set{ minId,cnt,sum_estate*1.0 / cnt,sum_area*1.0 / cnt });
		}
	}
	sort(families.begin(), families.end());
	printf("%d\n", families.size());
	for (auto c : families)
		printf("%04d %d %.3lf %.3lf\n", c.id, c.count, c.avg_sets, c.avg_area);
	return 0;
};
