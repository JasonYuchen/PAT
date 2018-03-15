#include<bits/stdc++.h>

using namespace std;

struct node
{
	string key;
	node *left;
	node *right;
}Nodes[21];

string ret;
int cnt;
void inOrder(node *root)
{
	if (root->left != nullptr || root->right != nullptr)   //只要是非叶结点，就在前后加上"("、")"
		ret += "(";
	if (root->left != nullptr)
		inOrder(root->left);
	cnt++;
	ret += root->key;
	if (root->right != nullptr)
		inOrder(root->right);
	if (root->left != nullptr || root->right != nullptr)
		ret += ")";
}

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		string key;
		int l, r;
		cin >> key >> l >> r;
		Nodes[i].key = key;
		Nodes[i].left = l == -1 ? nullptr : &Nodes[l];
		Nodes[i].right = r == -1 ? nullptr : &Nodes[r];
	}
	for (int i = 1; i <= N; ++i)
	{
		cnt = 0;
		ret = "";
		inOrder(&Nodes[i]);
		if (cnt == N)      //确定根结点
		{
			cout << (N == 1 ? ret : string(ret.begin() + 1, ret.end() - 1)) << endl;  //若大于1，则要去掉最外侧的()
			break;
		}
	}
	return 0;
};
