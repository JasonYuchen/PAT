#include<bits/stdc++.h>

using namespace std;

struct node          //不超过100个结点，每个结点内部用vector来表示可变长的子结点指针向量
{
	vector<node*> childs;
}Node[100];

int main()
{
	int N;         //结点数量
	int M;         //非叶结点数量
	scanf("%d %d", &N, &M);
	for (auto i = 0; i < M; ++i)
	{
		int ID, num;
		scanf("%d %d", &ID, &num);
		for (auto j = 0; j < num; ++j)
		{
			int child;
			scanf("%d", &child);
			Node[ID].childs.push_back(&Node[child]);
		}
	}
	queue<node*> q;
	q.push(&Node[1]);
	auto last = &Node[1];                //last标记前一个最末尾子结点，即前一层的最后结点
	auto tail = last;
	int NumberOfNoChild = 0;
	vector<int> ret;
	while (!q.empty())                   //BFS，可以封装成函数
	{
		auto curr = q.front();
		q.pop();
		if (curr->childs.empty())      //没有子结点，则当前层非叶结点数量+1
		{
			NumberOfNoChild++;
		}
		for (auto ch : curr->childs)
		{
			q.push(ch);
			tail = ch;               //tail来标记当前结点最末尾子结点
		}
		if (curr == last)              //若当前访问结点curr到了前一层的最后结点last
		{
			last = tail;             //则last变为这一层的最后结点
			ret.push_back(NumberOfNoChild);
			NumberOfNoChild = 0;     //同时清零当前层的叶结点数量
		}
	}
	printf("%d", *ret.begin());
	for (auto st = ++ret.begin(); st != ret.end(); ++st)
	{
		printf(" %d", *st);
	}
	return 0;
}
