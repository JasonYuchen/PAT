#include<bits/stdc++.h>

using namespace std;

struct node;
int getHeight(node *);
struct node
{
	int key;
	int height;
	node *left;
	node *right;
	node(int k) :key(k), left(nullptr), right(nullptr)
	{
		height = max(getHeight(left), getHeight(right)) + 1;
	}
};

int getHeight(node *root)
{
	if (root == nullptr)    //空树高度定义为0
		return 0;
	else
		return root->height;
}
node *singleLeft(node *root)
{
	auto tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;     //注意旋转后及时更新高度
	tmp->height = max(getHeight(tmp->left), getHeight(tmp->right)) + 1;
	return tmp;
}

node *singleRight(node *root)
{
	auto tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	tmp->height = max(getHeight(tmp->left), getHeight(tmp->right)) + 1;
	return tmp;
}

node *leftRight(node *root)
{
	root->left = singleRight(root->left);
	return singleLeft(root);
}

node *rightLeft(node *root)
{
	root->right = singleLeft(root->right);
	return singleRight(root);
}

node *insert(node *root, int val)
{
	if (root == nullptr)
	{
		root = new node{ val };
	}
	else if (val < root->key)
	{
		root->left = insert(root->left, val);
		if (getHeight(root->left) - getHeight(root->right) == 2)                //高度比较必须用getHeight，因为可能有空树
		{
			if (getHeight(root->left->left) > getHeight(root->left->right))
				root = singleLeft(root);
			else
				root = leftRight(root);
		}
	}
	else if (val > root->key)
	{
		root->right = insert(root->right, val);
		if (getHeight(root->left) - getHeight(root->right) == -2)
		{
			if (getHeight(root->right->left) < getHeight(root->right->right))
				root = singleRight(root);
			else
				root = rightLeft(root);
		}
	}
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;      //注意插入后及时更新高度
	return root;
}

int main()
{
	int N, num;
	node *root = nullptr;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &num);
		root = insert(root, num);
	}
	printf("%d\n", root->key);
	return 0;
}
