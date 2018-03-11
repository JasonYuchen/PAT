#include<bits/stdc++.h>

using namespace std;

int post[30];
int in[30];

struct node
{
	int key;
	node* left;
	node* right;
};

node *buildTree(int *post, int *in, int N)    //根据传入的后序遍历和中序遍历递归构建树
{
	if (N == 0)
		return nullptr;
	auto root = new node;
	root->key = post[N - 1];
	auto pos = find(in, in + N - 1, root->key);
	auto len = pos - in;
	root->left = buildTree(post, in, len);
	root->right = buildTree(post + len, in + len + 1, N - len - 1);
	return root;
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &post[i]);
	for (int i = 0; i < N; ++i)
		scanf("%d", &in[i]);
	auto root = buildTree(post, in, N);
	queue<node*> q;
	printf("%d", root->key);
	if (root->left)
		q.push(root->left);
	if (root->right)
		q.push(root->right);
	while (!q.empty())                        //层序遍历输出
	{
		auto next = q.front();
		q.pop();
		printf(" %d", next->key);
		if (next->left)
			q.push(next->left);
		if (next->right)
			q.push(next->right);
	}
	return 0;
}