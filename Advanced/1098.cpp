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
	auto pos = is_sorted_until(test.begin(), test.end()) - test.begin();
	if (vector<int>(test.begin() + pos, test.end()) == vector<int>(origin.begin() + pos, origin.end()))
	{
		printf("Insertion Sort\n");
		sort(test.begin(), test.begin() + pos + 1);
		printf("%d", test[0]);
		for (int i = 1; i < N; ++i)
			printf(" %d", test[i]);
	}
	else
	{
		printf("Heap Sort\n");
		auto pos = is_heap_until(test.begin(), test.end()) - test.begin();
		make_heap(test.begin(), test.begin() + pos);
		pop_heap(test.begin(), test.begin() + pos);           //pop_heap会自动将[0]位置的元素放置在[.size()-1]位置，并将新的堆的部分调整好
		printf("%d", test[0]);
		for (int i = 1; i < N; ++i)
			printf(" %d", test[i]);
	}
	return 0;
}
