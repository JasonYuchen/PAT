#include<bits/stdc++.h>

using namespace std;

struct node
{
	int key, left = -1, right = -1;
}Nodes[20];

int cnt;
void DFS(int i)
{
	cnt++;
	if (Nodes[i].left != -1)
		DFS(Nodes[i].left);
	if (Nodes[i].right != -1)
		DFS(Nodes[i].right);
}

int main()
{
	ios::sync_with_stdio(false);
	int N;
	string l, r;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> l >> r;
		Nodes[i].key = i;
		if (l != "-")
			Nodes[i].left = stoi(l);
		if (r != "-")
			Nodes[i].right = stoi(r);
	}
	int root = -1;
	for (int i = 0; i < N; ++i)            //DFS找到root
	{
		cnt = 0;
		DFS(i);
		if (cnt == N)
		{
			root = i;
			break;
		}
	}
	cnt = 0;
	vector<int> Seq(N);
	queue<int> q;
	q.push(root);
	while (cnt < N)                        //若是完全二叉树，则循环插入N次一定正好插入每个结点
	{
		int curr = q.front();
		Seq[cnt++] = curr;
		q.pop();
		if (curr == -1)                    //一旦中间出现-1就说明有空缺，即非完全二叉树
		{
			cout << "NO " << root << endl;
			return 0;
		}
		q.push(Nodes[curr].left);
		q.push(Nodes[curr].right);
	}
	cout << "YES " << Seq[N - 1] << endl;  //层序遍历最后一个结点就是二叉树最底层最右侧结点
	return 0;
};
