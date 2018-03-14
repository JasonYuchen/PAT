#include<bits/stdc++.h>

using namespace std;

struct node
{
	int key, depth;
	node *left;
	node *right;
	node(int k, int d) :key(k), depth(d), left(nullptr), right(nullptr) {}
};

int max_depth = 0;
node *Insert(node *root, int val)        //修改过的Insert，可以基于父结点给予子结点深度值，并且用max_depth记录最深深度
{
	if (val <= root->key && root->left != nullptr)
		Insert(root->left, val);
	else if (val > root->key && root->right != nullptr)
		Insert(root->right, val);
	else if (val <= root->key)
		root->left = new node{ val, root->depth + 1 };
	else
		root->right = new node{ val, root->depth + 1 };
	if (root->depth + 1 > max_depth)
		max_depth = root->depth + 1;
	return root;
}

int main()
{
	int N, val;
	scanf("%d", &N);
	scanf("%d", &val);
	node *root = new node{ val, 0 };
	for (int i = 1; i < N; ++i)
	{
		scanf("%d", &val);
		root = Insert(root, val);
	}
	int n1 = 0, n2 = 0;
	queue<node*> q;
	q.push(root);
	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();
		if (curr->depth == max_depth - 1)
			n2++;
		if (curr->depth == max_depth)
			n1++;
		if (curr->left)
			q.push(curr->left);
		if (curr->right)
			q.push(curr->right);
	}
	printf("%d + %d = %d\n", n1, n2, n1 + n2);
	return 0;
};
