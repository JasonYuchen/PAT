#include<bits/stdc++.h>

using namespace std;

struct node
{
	int id, gender;                 //1 - boy, -1 - girl, gender记录性别，其余全部用正数来作为结点编号
	vector<int> adj;
}Nodes[10000];

vector<pair<int, int>> res;
vector<int> tmp_route;
void DFS(int id, int tar, bool g)   //g = true - same gender, g = false - opposite gender
{
	tmp_route.push_back(id);
	if (tmp_route.size() == 4)
	{
		if(id == tar)               //正好4人，且抵达目标学生，则记录中间两人
			res.push_back({ tmp_route[1], tmp_route[2] });
		tmp_route.pop_back();
		return;
	}
	int gender = Nodes[id].gender;
	if (g == true)
	{
		for (int i = 0; i < Nodes[id].adj.size(); ++i)
			if (Nodes[Nodes[id].adj[i]].gender == gender &&                                        //同性则4个学生都要同性
				find(tmp_route.begin(), tmp_route.end(), Nodes[id].adj[i]) == tmp_route.end())     //确保不重复通过某个同学
				DFS(Nodes[id].adj[i], tar, g);
	}
	else
	{
		if (tmp_route.size() == 2)
		{
			for (int i = 0; i < Nodes[id].adj.size(); ++i)
				if (Nodes[Nodes[id].adj[i]].gender != gender &&                                    //不同性则只有第2个-第3个这两者可以不同性
					find(tmp_route.begin(), tmp_route.end(), Nodes[id].adj[i]) == tmp_route.end())
					DFS(Nodes[id].adj[i], tar, g);
		}
		else
		{
			for (int i = 0; i < Nodes[id].adj.size(); ++i)
				if (Nodes[Nodes[id].adj[i]].gender == gender &&
					find(tmp_route.begin(), tmp_route.end(), Nodes[id].adj[i]) == tmp_route.end())
					DFS(Nodes[id].adj[i], tar, g);
		}
	}
	tmp_route.pop_back();
}

bool cmp(const pair<int, int> &lhs, const pair<int, int> &rhs)
{
	return lhs.first<rhs.first || lhs.first == rhs.first && lhs.second<rhs.second;
}

int main()
{
	ios::sync_with_stdio(false);  
	cin.tie(0);
	int N, M, K;
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		string id1, id2;
		cin >> id1 >> id2;
		int id_1 = stoi(id1), id_2 = stoi(id2);               //注意处理负号，由于id是[0000,9999]，直接stoi并和0比较大小无法区分出-0这种情况
		Nodes[abs(id_1)].id = abs(id_1);
		Nodes[abs(id_1)].gender = id1[0] == '-' ? -1 : 1;
		Nodes[abs(id_1)].adj.push_back(abs(id_2));
		Nodes[abs(id_2)].id = abs(id_2);
		Nodes[abs(id_2)].gender = id2[0] == '-' ? -1 : 1;
		Nodes[abs(id_2)].adj.push_back(abs(id_1));
	}
	cin >> K;
	for (int i = 0; i < K; ++i)
	{
		res.clear();
		tmp_route.clear();
		string id1, id2;
		cin >> id1 >> id2;
		int id_1 = stoi(id1), id_2 = stoi(id2);
		bool g = true;
		if (id1[0] == '-' && id2[0] != '-' || id1[0] != '-' && id2[0] == '-')
			g = false;
		id_1 = abs(id_1);
		id_2 = abs(id_2);
		DFS(id_1, id_2, g);
		sort(res.begin(), res.end(), cmp);
		cout << res.size() << '\n';
		if (res.size() != 0)
			for (int j = 0; j < res.size(); ++j)
				cout << setfill('0') << setw(4) << res[j].first << " "   //这里的setw只对紧随其后的一个输出有效，因此两个数据都需要setw
				     << setfill('0') << setw(4) << res[j].second << '\n';
	}
	return 0;
};


/************************************************************************************************************
https://www.liuchuo.net/archives/4210

bool arr[10000][10000];                 //存储所有有朋友关系的
struct node
{
	int a, b;
};
bool cmp(node x, node y) {
	return x.a != y.a ? x.a < y.a : x.b < y.b;
}
int main() {
	int n, m, k;
	scanf("%d%d", &n, &m);
	vector<int> v[10000];               //v[i]存储i的所有同性朋友
	for (int i = 0; i < m; i++)
	{
		string a, b;
		cin >> a >> b;
		if (a.length() == b.length())   //利用长度来区分性别，女生有'-'因此长度是5，男生没有'-'因此长度是4
		{
			v[abs(stoi(a))].push_back(abs(stoi(b)));
			v[abs(stoi(b))].push_back(abs(stoi(a)));
		}
		arr[abs(stoi(a))][abs(stoi(b))] = arr[abs(stoi(b))][abs(stoi(a))] = true;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		int c, d;
		cin >> c >> d;
		vector<node> ans;
		for (int j = 0; j < v[abs(c)].size(); j++)        //直接遍历判断：c的同性友人v[abs(c)][j]和d的同性友人v[abs(d)][k]是否是朋友
		{
			for (int k = 0; k < v[abs(d)].size(); k++)
			{
				if (v[abs(c)][j] == abs(d) || abs(c) == v[abs(d)][k]) continue;   //跳过正好三个朋友相连的情况
				if (arr[v[abs(c)][j]][v[abs(d)][k]] == true)                      //若正好构成符合性别要求的4人串，则加入结果
					ans.push_back(node{ v[abs(c)][j], v[abs(d)][k] });
			}
		}
		sort(ans.begin(), ans.end(), cmp);
		printf("%d\n", int(ans.size()));
		for (int j = 0; j < ans.size(); j++)
			printf("%04d %04d\n", ans[j].a, ans[j].b);
	}
	return 0;
}
************************************************************************************************************/