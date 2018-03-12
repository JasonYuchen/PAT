#include<bits/stdc++.h>

using namespace std;

struct node
{
	int key;
	node *left;
	node *right;
	node(int k) :key(k), left(nullptr), right(nullptr) {}
};

node *createTree(vector<int> in, vector<int> pre)   //根据先序和中序建立树
{
	node *root = nullptr;
	if (in.size() == 0)
		return root;
	root = new node{ pre[0] };
	auto pos = find(in.begin(), in.end(), pre[0]);
	auto len = distance(in.begin(), pos);
	root->left = createTree(vector<int>(in.begin(), in.begin() + len), vector<int>(pre.begin() + 1, pre.begin() + 1 + len));
	root->right = createTree(vector<int>(in.begin() + 1 + len, in.end()), vector<int>(pre.begin() + 1 + len, pre.end()));
	return root;
}

void postOrder(node *root, vector<int> &post)       //后序遍历
{
	if (root)
	{
		postOrder(root->left, post);
		postOrder(root->right, post);
		post.push_back(root->key);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string op;
	int N, num;
	cin >> N;
	stack<int> s;
	vector<int> in, pre, post;
	for (int i = 0; i < 2 * N; ++i)
	{
		cin >> op;
		if (op[1] == 'u')                 //入栈顺序就是第一次访问顺序，即先序遍历
		{
			cin >> num;
			s.push(num);
			pre.push_back(num);
		}
		else                              //出栈顺序就是第二次访问顺序，即中序遍历
		{
			in.push_back(s.top());
			s.pop();
		}
	}
	node *root = createTree(in, pre);
	postOrder(root, post);
	cout << post[0];
	for (int i = 1; i < post.size(); ++i)
		cout << " " << post[i];
	return 0;
}
