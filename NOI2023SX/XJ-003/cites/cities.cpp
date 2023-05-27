#include <cstdio>
#include <cctype>
using namespace std;
inline int rd()
{
	int x(0);
	char ch;
	while (!isdigit(ch = getchar()));
	do
		x = x * 10 + (ch ^ 48);
	while (isdigit(ch = getchar()));
	return x;
}
int main()
{
	freopen("cities.in", "r", stdin);
	freopen("cities.out", "w", stdout);
	return 0;
}