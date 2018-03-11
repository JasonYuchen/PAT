#include<bits/stdc++.h>

using namespace std;

struct node
{
	int key;
	node *left = nullptr;
	node *right = nullptr;
	node(int k) :key(k) {}
};

node *Insert(node *root, int key)       //构建二叉搜索树
{
	if (root == nullptr)
		return new node{ key };
	else if (key < root->key)
	{
		root->left = Insert(root->left, key);
	}
	else
	{
		root->right = Insert(root->right, key);
	}
	return root;
}

int cnt;

void preorder(node *tree, vector<int> &pre)
{
	if (tree != nullptr)
	{
		pre[cnt++] = tree->key;
		preorder(tree->left, pre);
		preorder(tree->right, pre);
	}
}

void postorder(node *tree, vector<int> &post)
{
	if (tree != nullptr)
	{
		postorder(tree->left, post);
		postorder(tree->right, post);
		post[cnt++] = tree->key;
	}
}

int main()
{
	int N;
	cin >> N;
	node *tree = nullptr, *treeM = nullptr;
	vector<int> input(N), pre(N), post(N);
	for (int i = 0; i < N; ++i)
	{
		int key;
		cin >> key;
		tree = Insert(tree, key);
		input[i] = key;
	}
	cnt = 0;
	preorder(tree, pre);
	cnt = 0;
	postorder(tree, post);
	if (input == pre)
	{
		cout << "YES\n" << post[0];
		for (int i = 1; i < N; ++i)
			cout << " " << post[i];
	}
	else if (input == vector<int>(post.rbegin(), post.rend()))   //注意，镜像树的先序遍历等于原树后序遍历的倒序
	{                                                            //同时，原树的先序遍历等于镜像树后序遍历的倒序
		cout << "YES\n" << pre[N - 1];
		for (int i = N - 2; i >= 0; --i)
			cout << " " << pre[i];
	}
	else
	{
		cout << "NO\n";
	}
	return 0;
}
