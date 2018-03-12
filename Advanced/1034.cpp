#include<bits/stdc++.h>

using namespace std;

struct person
{
	int root = -1;
	int weight = 0;
	string name;
}p[2000];

int find(int i)
{
	if (p[i].root <= -1)
		return i;
	else
		return p[i].root = find(p[i].root);
}

void unionset(int i, int j)
{
	int iset = find(i);
	int jset = find(j);
	if (iset == jset)
		return;
	if (iset < jset)
	{
		p[iset].root += p[jset].root;
		p[jset].root = iset;
	}
	else
	{
		p[jset].root += p[iset].root;
		p[iset].root = jset;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	unordered_map<string, int> personID;           //构建名字到结点下标的映射
	int N, K, cnt = 0;                             //利用cnt来指向当前没被占用的结点
	cin >> N >> K;
	for (int i = 0; i < N; ++i)                    //构建并查集
	{
		string name1, name2;
		int time;
		cin >> name1 >> name2 >> time;
		if (personID.find(name1) == personID.end())
		{
			personID[name1] = cnt;
			p[cnt].name = name1;
			p[cnt].weight = time;
			cnt++;
		}
		else
		{
			p[personID[name1]].weight += time;
		}
		if (personID.find(name2) == personID.end())
		{
			personID[name2] = cnt;
			p[cnt].name = name2;
			p[cnt].weight = time;
			cnt++;
		}
		else
		{
			p[personID[name2]].weight += time;
		}
		unionset(personID[name1], personID[name2]);
	}
	unordered_map<int, int> max_weight;            //max_weight构建每个Gang名字（根结点的下标）到Gang内最大权重值的映射
	unordered_map<int, int> total_weight;          //total_weight构建每个Gang名字到Gang总权重值的映射
	unordered_map<int, string> heads;              //heads构建Gang名字到Gang内head名字的映射
	for (auto c : personID)
	{
		auto index = c.second;
		auto group = find(index);
		if (p[group].root >= -2)                   //少于2人的不是Gang
			continue;
		if (p[index].weight > max_weight[group])   //每次发现有人权重比最大权重大，就更新最大权重和对应的人
		{  
			max_weight[group] = p[index].weight;
			heads[group] = p[index].name;
		}
		total_weight[group] += p[index].weight;    //每次都更新总权重（注意这个权重是2倍，因为通话双方都计入了一次权重）
	}
	map<string, int> ret;
	for (auto c : heads)
	{
		if(total_weight[c.first] / 2 > K)          //通话双方重复计入了一次权重，因此总权重要除以2，真实权重小于阈值的不是Gang
			ret.insert({ c.second, std::abs(p[c.first].root) });
	}
	cout << ret.size() << endl;
	for (auto c : ret)
	{
		cout << c.first << " " << c.second << endl;
	}
	return 0;
}


/**************************************************************************************************
DFS/Connected Components

unordered_map<string, int> StrtoV;
unordered_map<int, string> VtoStr;
int Graph[2000][2000], weight[2000], visited[2000];

void DFS(int V, int &num, int &head, int &total)    //每次DFS传递当前gang的人数、头目、总权重
{
	visited[V] = 1;
	num++;
	total += weight[V];
	if (weight[V] > weight[head])                   //若有更大权重的人出现，就更新头目
		head = V;
	for (auto it = StrtoV.begin(); it != StrtoV.end(); ++it)
		if (Graph[V][it->second] == 1 && visited[it->second] == 0)
			DFS(it->second, num, head, total);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, K, cnt = 0;
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		string str1, str2;
		int c, v, w;
		cin >> str1 >> str2 >> c;
		if (StrtoV.find(str1) == StrtoV.end())
		{
			StrtoV[str1] = cnt;
			VtoStr[cnt++] = str1;
		}
		if (StrtoV.find(str2) == StrtoV.end())
		{
			StrtoV[str2] = cnt;
			VtoStr[cnt++] = str2;
		}
		v = StrtoV[str1];
		w = StrtoV[str2];
		weight[v] += c;
		weight[w] += c;
		Graph[v][w] = Graph[w][v] = 1;
	}
	map<string, int> ret;
	for (auto it = StrtoV.begin(); it != StrtoV.end(); ++it)
	{
		int head = it->second, num = 0, total = 0;
		if(visited[it->second] == 0)
			DFS(it->second, num, head, total);
		if (num > 2 && total > 2 * K)               //注意由于通话是双向的，因此total实际上算了两倍权重
			ret.insert({ VtoStr[head],num });
	}
	cout << ret.size() << '\n';
	for (auto it = ret.begin(); it != ret.end(); ++it)
		cout << it->first << " " << it->second << '\n';
	return 0;
}
**************************************************************************************************/