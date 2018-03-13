#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	vector<int> origin(N), test(N);
	for (int i = 0; i < N; ++i)
		scanf("%d", &origin[i]);
	for (int i = 0; i < N; ++i)
		scanf("%d", &test[i]);
	auto pos = distance(test.begin(), is_sorted_until(test.begin(), test.end()));   //插入排序前半部分有序，后半部分和原序列一样，据此来区分
	if (vector<int>(origin.begin() + pos, origin.end()) == vector<int>(test.begin() + pos, test.end()))
	{
		printf("Insertion Sort\n");
		sort(test.begin(), test.begin() + pos + 1);                                 //插入排序下一轮就是再额外加入一个元素即可
		printf("%d", test[0]);
		for_each(test.begin() + 1, test.end(), [](int i) {printf(" %d", i); });
	}
	else
	{
		printf("Merge Sort\n");
		int flag = 0, interval = 1;
		while (!flag)
		{
			if (origin == test)                                                     //模拟归并的过程，一旦发现和部分排序序列一致，则再进行一轮归并后退出循环
				flag = 1;
			int i = 0;
			interval *= 2;
			for (; i + interval < origin.size(); i += interval)                     //归并可以通过逐段sort来模拟
				sort(origin.begin() + i, origin.begin() + i + interval);
			sort(origin.begin() + i, origin.end());
		}
		printf("%d", origin[0]);
		for_each(origin.begin() + 1, origin.end(), [](int i) {printf(" %d", i); });
	}
	return 0;
}
