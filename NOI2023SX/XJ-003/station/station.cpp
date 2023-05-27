#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
constexpr int NODESIZE = 200100;
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
struct RailWay
{
	int l, r;
} rw[NODESIZE];
inline bool Coml(const RailWay& rw0, const RailWay& rw1)
{
	return rw0.r == rw1.r ? (rw0.l > rw1.l) : rw0.r < rw1.r;
}
inline bool Comr(const RailWay& rw0, const RailWay& rw1)
{
	return rw0.l == rw1.l ? (rw0.r > rw0.r) : rw0.l < rw1.l;
}
int n, m, x;
inline bool IsContain(int idx, int sta)
{
	return rw[idx].l <= sta && rw[idx].r >= sta;
}
bool stations[NODESIZE];
int main()
{
	freopen("station.in", "r", stdin);
	freopen("station.out", "w", stdout);
	n = rd();
	m = rd();
	x = rd();
	for (int i(0); i < m; ++i)
	{
		rw[i].l = rd();
		rw[i].r = rd();
	}
	int alt(0), art(m);
	int minl(x), maxr(x);
	int ptr(0);
	while (ptr <= art)
	{
		if (IsContain(ptr, x))
		{
			minl = min(minl, rw[ptr].l);
			maxr = max(maxr, rw[ptr].r);
			stations[rw[ptr].l] = true;
			stations[rw[ptr].r] = true;
			++ptr;
		}
		else if (rw[ptr].r < x)
			rw[alt++] = rw[ptr++];
		else // rw[ptr].l > x
			swap(rw[ptr], rw[--art]);
	}
	sort(rw, rw + alt, Coml);
	sort(rw + art, rw + m, Comr);
	--alt;
	while (alt >= 0 && rw[alt].r >= minl)
	{
		minl = min(minl, rw[alt].l);
		stations[rw[alt].l] = true;
		--alt;
	}
	while (art < m && rw[art].l <= maxr)
	{
		maxr = max(maxr, rw[art].r);
		stations[rw[art].r] = true;
		++art;
	}
	stations[x] = false;
	for (int i(1); i <= n; ++i)
		if (stations[i])
			printf("%d ", i);
	return 0;
}