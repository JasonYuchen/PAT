#include<bits/stdc++.h>

using namespace std;

struct money
{
	int Galleon = 0, Sickle = 0, Knuts = 0;
	money() = default;
	money(int a, int b, int c) :Galleon(a), Sickle(b), Knuts(c) {}
	money &operator+(const money &rhs)
	{
		Knuts += rhs.Knuts;
		if (Knuts >= 29)
		{
			Sickle += Knuts / 29;
			Knuts %= 29;
		}
		Sickle += rhs.Sickle;
		if (Sickle >= 17)
		{
			Galleon += Sickle / 17;
			Sickle %= 17;
		}
		Galleon += rhs.Galleon;
		return *this;
	}
};

int main()
{
	money a, b;
	scanf("%d.%d.%d %d.%d.%d", &a.Galleon, &a.Sickle, &a.Knuts, &b.Galleon, &b.Sickle, &b.Knuts);
	a = a + b;
	printf("%d.%d.%d\n", a.Galleon, a.Sickle, a.Knuts);
	return 0;
}