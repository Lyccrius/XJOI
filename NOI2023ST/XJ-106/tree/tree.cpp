#include <cstdio>
#include <cctype>
#include <queue>
#include <list>
#include <bitset>
#include <cmath>
#include <algorithm>
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
double readD()
{
	char ch;
	double x = 0.0, m = 0.0;
	bool neg(false);
	while (!isdigit(ch = getchar()) && ch != '-');
	if (ch == '-')
	{
		neg = true;
		ch = getchar();
	}
	do
		x = x * 10.0 + (ch ^ 48);
	while (isdigit(ch = getchar()));
	char buf[10];
	for (int i(0); i < 9; ++i)
		buf[8 - i] = getchar() ^ 48;
	for (int i(0); i < 9; ++i)
		m = (m + buf[i]) / 10.0;
	return neg ? -x - m : x + m;
}
int n;
struct Pos
{
	double x, y;
} pos[1010];
struct BFSStruc
{
	list<int> pth;
	bitset<1010> orbits;
	double lth;
	inline bool operator>(const BFSStruc& bs)const
	{
		return lth > bs.lth;
	}
	inline bool all()const
	{
		for (int i(0); i < n; ++i)
			if (!orbits[i])
				return false;
		return true;
	}
};
inline double dis(int a, int b)
{
	double dx(pos[a].x - pos[b].x), dy(pos[a].y - pos[b].y);
	return sqrt(dx * dx + dy * dy);
}
inline bool cmpl(const Pos& a, const Pos& b)
{
	return a.y < b.y;
}
inline bool cmpg(const Pos& a, const Pos& b)
{
	return a.y > b.y;
}
int SortPos(int k)
{
	Pos pk = pos[k];
	int l(0), r(n - 1);
	while (l <= r)
	{
		if (pos[l].x < pk.x)
			swap(pos[l], pos[r--]);
		else
			++l;
	}
	sort(pos, pos + l, cmpl);
	sort(pos + l, pos + n, cmpg);
	return r;
}
int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	n = readI();
	int k(0);
	double yk(-1e20);
	for (int i(0); i < n; ++i)
	{
		pos[i].x = readD();
		pos[i].y = readD();
		if (pos[i].y > yk)
		{
			k = i;
			yk = pos[i].y;
		}
	}
	// Sort
	k = SortPos(k);
	printf("Sorted:\n");
	for (int i(0); i < n; ++i)
		printf("%.9lf %.9lf\n", pos[i].x, pos[i].y);
	BFSStruc dst;
	priority_queue<BFSStruc, vector<BFSStruc>, greater<BFSStruc> > bfsQ;
	dst.lth = 0.0;
	dst.orbits[k] = 1;
	dst.pth.push_back(k);
	bfsQ.push(dst);
	while (!bfsQ.empty())
	{
		dst = bfsQ.top();
		bfsQ.pop();
		if (dst.all())
		{
			for (auto p : dst.pth)
				printf("%d ", p + 1);
			puts("");
			return 0;
		}
		for (int i(0); i < n; ++i)
		{
			if (dst.orbits[i])
				continue;

			dst.orbits[i] = 1;
			dst.pth.push_back(i);
			yk = dst.lth;
			dst.lth += dis(dst.pth.back(), i);
			bfsQ.push(dst);

			dst.pth.pop_back();
			dst.orbits[i] = 0;
			dst.lth = yk;
		}
	}
	return 0;
}