struct node
{
	int key, height = 1;
	node *left = nullptr;
	node *right = nullptr;
	node(int k) :key(k) {}
};
int getHeight(node *root)
{
	if (root)
		return root->height;
	else
		return 0;
}
node *SingleLeft(node *k1)
{
	auto k2 = k1->left;
	k1->left = k2->right;
	k2->right = k1;
	k1->height = max(getHeight(k1->left), getHeight(k1->right)) + 1;
	k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
	return k2;
}
node *SingleRight(node *k1)
{
	auto k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1->height = max(getHeight(k1->left), getHeight(k1->right)) + 1;
	k2->height = max(getHeight(k2->left), getHeight(k2->right)) + 1;
	return k2;
}
node *LeftRight(node *k1)
{
	k1->left = SingleRight(k1->left);
	return SingleLeft(k1);
}
node *RightLeft(node *k1)
{
	k1->right = SingleLeft(k1->right);
	return SingleRight(k1);
}
node *Insert(node *root, int val)
{
	if (root == nullptr)
		return new node{ val };
	if (val < root->key)
	{
		root->left = Insert(root->left, val);
		if (getHeight(root->left) - getHeight(root->right) == 2)
		{
			if (val < root->left->key)
				root = SingleLeft(root);
			else
				root = LeftRight(root);
		}
	}
	else
	{
		root->right = Insert(root->right, val);
		if (getHeight(root->left) - getHeight(root->right) == -2)
		{
			if (val < root->right->key)
				root = RightLeft(root);
			else
				root = SingleRight(root);
		}
	}
	root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	return root;
}

int main() 
{
	int N;
	node *root = nullptr;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		int val;
		scanf("%d", &val);
		root = Insert(root, val);
	}

	queue<node*> q;
	q.push(root);
	vector<int> ret;
	while (!q.empty())
	{
		auto curr = q.front();
		q.pop();
		ret.push_back(curr->key);
		if (curr->left) q.push(curr->left);
		if (curr->right) q.push(curr->right);
	}
	printf("%d", ret[0]);
	for (int i = 1; i < ret.size(); ++i)
		printf(" %d", ret[i]);
	printf("\n");

	q.push(root);
	int cnt = 0;
	while (cnt < N)
	{
		auto curr = q.front();
		q.pop();
		if (curr == nullptr)
			break;
		cnt++;
		q.push(curr->left);
		q.push(curr->right);
	}
	printf("%s\n", cnt == N ? "YES" : "NO");
	return 0;
}
