#include<bits/stdc++.h>

using namespace std;

int main()
{
	string init[3] = { "W","T","L" };
	string res;
	double mul = 1.0;
	for (int i = 0; i < 3; ++i)
	{
		map<double, string>cup;
		for (int j = 0; j < 3; ++j)
		{
			double g;
			scanf("%lf", &g);
			cup.insert({ g, init[j] });
		}
		auto st = --(cup.end());
		mul *= st->first;
		res += st->second;
	}
	printf("%c %c %c %.2lf\n", res[0], res[1], res[2], (mul*0.65 - 1) * 2);
	return 0;
}
