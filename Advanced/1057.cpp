#include<bits/stdc++.h>

using namespace std;

/*https://www.liuchuo.net/archives/2265*/

#define lowbit(i) ((i) & (-i)) //快速计算出2^k
const int maxn = 100010;
using namespace std;
int c[maxn];                   //树状数组c
stack<int> s;
void update(int x, int v)      //更新下标为x的位置的值加上v，则一系列后继结点都要加上v
{
	for (int i = x; i < maxn; i += lowbit(i))
		c[i] += v;
}
int getsum(int x)              //获取下标为x的位置之前的元素和，就是求包括x及其前驱结点的和
{
	int sum = 0;
	for (int i = x; i >= 1; i -= lowbit(i))
		sum += c[i];
	return sum;
}
void PeekMedian()              //二分搜索，由于数组c[i]代表i在堆栈中的出现次数，则只要搜索到某个i使得前驱和为stack的一半就说明找到了中点
{
	int left = 1, right = maxn, mid, k = (s.size() + 1) / 2;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (getsum(mid) >= k)
			right = mid;
		else
			left = mid + 1;
	}
	printf("%d\n", left);
}
int main() 
{
	int n, temp;
	scanf("%d", &n);
	char str[15];
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		if (str[1] == 'u')
		{
			scanf("%d", &temp);
			s.push(temp);
			update(temp, 1);
		}
		else if (str[1] == 'o')
		{
			if (!s.empty())
			{
				update(s.top(), -1);
				printf("%d\n", s.top());
				s.pop();
			}
			else
			{
				printf("Invalid\n");
			}
		}
		else
		{
			if (!s.empty())
				PeekMedian();
			else
				printf("Invalid\n");
		}
	}
	return 0;
}
