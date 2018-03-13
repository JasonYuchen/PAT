#include<bits/stdc++.h>

using namespace std;

int M, N, L, T;                                      //[M][N] - sizes of each slice, L - slices, T - threshold
int HF(int i, int j, int k)                          //将3坐标映射到1坐标
{
	return i*M*N + j*N + k;
}
int Find(vector<int> &s, int x)
{
	if (s[x] < 0)
		return x;
	else
		return s[x] = Find(s, s[x]);
}
void Union(vector<int> &s, int x1, int x2)
{
	int root1 = Find(s, x1), root2 = Find(s, x2);
	if (root1 == root2)
		return;
	if (s[root1] < s[root2])
	{
		s[root1] += s[root2];
		s[root2] = root1;
	}
	else
	{
		s[root2] += s[root1];
		s[root1] = root2;
	}
}

int main()
{
	scanf("%d %d %d %d", &M, &N, &L, &T);
	vector<int> MRI(L*M*N), Set(L*M*N, -1);        //MRI记录0/1数据，Set记录MRI每个1所属的集合
	for (int i = 0; i < L; ++i)
		for (int j = 0; j < M; ++j)
			for (int k = 0; k < N; ++k)
				scanf("%d", &MRI[HF(i, j, k)]);
	for (int i = 0; i < L; ++i)
		for (int j = 0; j < M; ++j)
			for (int k = 0; k < N; ++k)
			{
				if (MRI[HF(i, j, k)] == 1)
				{
					if (i > 0 && MRI[HF(i - 1, j, k)] == 1)   //不要超出边界
						Union(Set, HF(i, j, k), HF(i - 1, j, k));
					if (j > 0 && MRI[HF(i, j - 1, k)] == 1)
						Union(Set, HF(i, j, k), HF(i, j - 1, k));
					if (k > 0 && MRI[HF(i, j, k - 1)] == 1)
						Union(Set, HF(i, j, k), HF(i, j, k - 1));
				}
			}
	int total = 0;
	for (int i = 0; i < Set.size(); ++i)
		if (MRI[i] == 1 && Set[i] <= -T)         //无论0还是1，Set[i]初始化为-1，因此添加体积时要额外判断MRI[i]
			total -= Set[i];
	printf("%d\n", total);
	return 0;
}




/**************************************************************************************
BFS

https://www.liuchuo.net/archives/2307

struct node 
{
    int x, y, z;
};
int m, n, l, t;
int X[6] = {1, 0, 0, -1, 0, 0};
int Y[6] = {0, 1, 0, 0, -1, 0};
int Z[6] = {0, 0, 1, 0, 0, -1};
int arr[1300][130][80];
bool visit[1300][130][80];
bool judge(int x, int y, int z) 
{
    if(x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l)    //超出边界
    	return false;
    if(arr[x][y][z] == 0 || visit[x][y][z] == true)              //已访问或是未出血区域
    	return false;
    return true;                                                 //未出边界且未访问过且出血，则返回true
}
int bfs(int x, int y, int z) 
{
    int cnt = 0;
    node temp;
    temp.x = x, temp.y = y, temp.z = z;
    queue<node> q;
    q.push(temp);
    visit[x][y][z] = true;
    while(!q.empty()) {
        node top = q.front();
        q.pop();
        cnt++;                                                   //记录当前坐标所属的出血区域的总元素数
        for(int i = 0; i < 6; i++)                               //6个相邻位置判断是否有出血
        {
            int tx = top.x + X[i];
            int ty = top.y + Y[i];
            int tz = top.z + Z[i];
            if(judge(tx, ty, tz)) 
            {
                visit[tx][ty][tz] = true;
                temp.x = tx, temp.y = ty, temp.z = tz;
                q.push(temp);
            }
        }
    }
    if(cnt >= t)                                                 //>=阈值则返回出血区域大小，<阈值则返回0，即非出血区域
        return cnt;
    else
        return 0;
    
}
int main() {
    scanf("%d %d %d %d", &m, &n, &l, &t);
    for(int i = 0; i < l; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < n; k++)
                scanf("%d", &arr[j][k][i]);
    int ans = 0;
    for(int i = 0; i < l; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < n; k++)
                if(arr[j][k][i] == 1 && visit[j][k][i] == false)
                    ans += bfs(j, k, i);
    printf("%d", ans);
    return 0;
}
**************************************************************************************/