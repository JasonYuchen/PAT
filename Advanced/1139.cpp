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

int Graph[10000][10000];
int gender[10000];                       //0 - boy, 1 - girl

int main()
{
	int N, M, K;
	scanf("%d %d", &N, &M);
	vector<int> friends[10000];
	for (int i = 0; i < M; ++i)
	{
		char id1[6], id2[6];
		scanf("%s %s", id1, id2);
		string v(id1), w(id2);
		int V = abs(stoi(v)), W = abs(stoi(w));
		gender[V] = v.size() == 5;       //长度为5说明有'-'，即女生
		gender[W] = w.size() == 5;
		Graph[V][W] = Graph[W][V] = 1;
		if (v.size() == w.size())        //friends存储同性的朋友
		{
			friends[V].push_back(W);
			friends[W].push_back(V);
		}
	}
	scanf("%d", &K);
	for (int i = 0; i < K; ++i)
	{
		int V, W;
		scanf("%d %d", &V, &W);
		V = abs(V);
		W = abs(W);
		vector<pair<int, int>> ret;
		for (int m = 0; m < friends[V].size(); ++m)
		{
			for (int n = 0; n < friends[W].size(); ++n)
			{
				if (Graph[friends[V][m]][friends[W][n]] == 1 &&           //两人的朋友也是朋友
					friends[V][m] != W && friends[W][n] != V)             //且不是两人直接是朋友这种情况
					ret.push_back({ friends[V][m],friends[W][n] });
			}
		}
		sort(ret.begin(), ret.end());
		printf("%d\n", ret.size());
		for (int i = 0; i < ret.size(); ++i)
			printf("%04d %04d\n", ret[i].first, ret[i].second);
	}
	return 0;
}
************************************************************************************************************/