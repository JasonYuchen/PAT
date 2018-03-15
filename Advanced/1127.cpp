#include<bits/stdc++.h>

using namespace std;

struct node
{
	int key;
	node *left, *right;
	node(int k) :key(k), left(nullptr), right(nullptr) {}
};

vector<int> in, post;
node *build(int inSt, int postSt, int N)
{
	if (N <= 0)
		return nullptr;
	if (N == 1)
		return new node{ post[postSt + N - 1] };
	int root = post[postSt + N - 1];
	node *ret = new node{ root };
	int leftLen = find(in.begin() + inSt, in.begin() + inSt + N, root) - in.begin() - inSt;
	ret->left = build(inSt, postSt, leftLen);
	ret->right = build(inSt + leftLen + 1, postSt + leftLen, N - leftLen - 1);
	return ret;
}

int main()
{
	int N;
	scanf("%d", &N);
	in.resize(N);
	post.resize(N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &in[i]);
	for (int i = 0; i < N; ++i)
		scanf("%d", &post[i]);
	node *root = build(0, 0, N), *last = root, *tail = nullptr;
	int cnt = 0, L = 0;
	vector<int> level;
	queue<node*> q;
	q.push(root);
	while (!q.empty())
	{
		node *curr = q.front();
		q.pop();
		level.push_back(curr->key);
		cnt++;
		if (curr->left)
		{
			q.push(curr->left);
			tail = q.back();
		}
		if (curr->right)
		{
			q.push(curr->right);
			tail = q.back();
		}
		if (curr == last)
		{
			if (L % 2 == 0)                //根为0层，偶数层进行逆序
				reverse(level.end() - cnt, level.end());
			cnt = 0;
			L++;
			last = tail;
		}
	}
	printf("%d", level[0]);
	for (int i = 1; i < level.size(); ++i)
		printf(" %d", level[i]);
	return 0;
}
