#include<bits/stdc++.h>

using namespace std;

struct node
{
	int key;
	node *left;
	node *right;
}Nodes[10];

void invert(node *root)
{
	if (root)
	{
		std::swap(root->left, root->right);
		invert(root->left);
		invert(root->right);
	}
}
vector<int> in;
void inOrder(node *root)
{
	if (root)
	{
		inOrder(root->left);
		in.push_back(root->key);
		inOrder(root->right);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string l, r;
		cin >> l >> r;
		Nodes[i].key = i;
		if (l == "-")
			Nodes[i].left = nullptr;
		else
			Nodes[i].left = &Nodes[stoi(l)];
		if (r == "-")
			Nodes[i].right = nullptr;
		else
			Nodes[i].right = &Nodes[stoi(r)];
	}
	node *root = nullptr;
	for (int i = 0; i < N; ++i)     //中序遍历，找到根结点
	{
		in.clear();
		inOrder(&Nodes[i]);
		if (in.size() == N)
		{
			root = &Nodes[i];
			break;
		}
	}
	invert(root);                   //翻转
	in.clear();
	inOrder(root);                  //翻转之后重新中序遍历
	vector<int> level;
	queue<node*> q;                 //层序遍历
	q.push(root);
	while (!q.empty())
	{
		node *curr = q.front();
		level.push_back(curr->key);
		q.pop();
		if (curr->left)
			q.push(curr->left);
		if (curr->right)
			q.push(curr->right);
	}
	cout << level[0];
	for (int i = 1; i < N; ++i)
		cout << " " << level[i];
	cout << '\n';

	cout << in[0];
	for (int i = 1; i < N; ++i)
		cout << " " << in[i];
	cout << '\n';
	return 0;
}
