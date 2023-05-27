#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;
int readI()
{
	char ch;
	int x(0);
	while (!isdigit(ch = getchar()));
	do
		x = x * 10 + (ch ^ 48);
	while (isdigit(ch = getchar()));
	return x;
}
int * mptr;
int main()
{
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
	int T;
	int n, m, q;
	int op, d, c;
	T = readI();
	while (T--)
	{
		n = readI();
		m = readI();
		q = readI();
		mptr = new int[n * m + 10];
		for (int i(0); i < n * m; ++i)
			mptr[i] = 0;
		while (q--)
		{
			op = readI();
			d = readI() - 1;
			c = readI();
			if (op == 0)
				for (int i(0); i < m; ++i)
					mptr[d * m + i] = c;
			else
				for (int i(0); i < n; ++i)
					mptr[i * m + d] = c;
		}
		for (int i(0); i < n; ++i)
		{
			for (int j(0); j < m; ++j)
				printf("%d ", mptr[i * m + j]);
			puts("");
		}
		delete[] mptr;
	}
	return 0;
}