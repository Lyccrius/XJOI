#include <cstdio>
#include <cctype>
#include <bitset>
#include <cstring>
#include <algorithm>
#include <cstdint>
using namespace std;
inline int rdi()
{
	int x(0);
	char ch;
	while (!isdigit(ch = getchar()));
	do
		x = x * 10 + (ch ^ 48);
	while (isdigit(ch = getchar()));
	return x;
}
inline char rdc()
{
	char ch;
	while (isspace(ch = getchar()));
	return ch;
}
bitset<16> gameMap[16];
int id, T, n, m;
int bx, rx[2], by, ry[2];
bitset<2001000> vst;
int off[4][2] = {
	{ -1, 0 },
	{ 0, -1 },
	{ 1, 0 },
	{ 0, 1 }
};
inline int AbsVal(int v)
{
	return v < 0 ? -v : v;
}
inline int GetDist(int x, int y, int x0, int y0)
{
	return AbsVal(x - x0) + AbsVal(y - y0);
}
inline int GetStatusIdx()
{
	int bSta((by - 1) * 10 + (bx - 1));
	int r0Sta((ry[0] - 1) * 10 + (rx[0] - 1));
	int r1Sta((ry[1] - 1) * 10 + (ry[1] - 1));
	return (bSta * 100 + r0Sta) * 100 + r1Sta;
}
inline bool CheckMovable(int x, int y, bool isBlack)
{
	bool res(false);
	for (int i(0); i < (isBlack ? 3 : 4); ++i)
		res |= !gameMap[y + off[i][1]].test(x + off[i][0]);
	return res;
}
void Do1To4()
{
	puts((CheckMovable(rx[0], ry[0], false) || CheckMovable(rx[1], ry[1], false)) ? "Tie" : "Black 0");
}
int DFS(int step)
{
	if (vst.test(GetStatusIdx()))
		return INT32_MAX;
	if ((by == 1) || (bx == rx[0] && by == ry[0]) || (bx == rx[1] && by == ry[1]))
		return step;
	vst.set(GetStatusIdx());
	int swin(INT32_MAX), owin(INT32_MAX);
	// Black
	if (step & 1)
		for (int j(0); j < 4; ++j)
			if (!gameMap[by + off[j][1]].test(bx + off[j][0]))
			{
				by += off[j][1];
				bx += off[j][0];
				auto tres(DFS(step + 1));
				// 
				if (tres & 1)
					owin = min(tres, owin);
				else
					swin = min(swin, tres);
				by -= off[j][1];
				bx -= off[j][0];
			}
			else
				;
	// Red
	else
		for (int i(0); i < 2; ++i)
			for (int j(0); j < 4; ++j)
				if (!gameMap[ry[i] + off[j][1]].test(rx[i] + off[j][0]))
				{
					ry[i] += off[j][1];
					rx[i] += off[j][0];
				auto tres(DFS(step + 1));
				// 
				if (tres & 1)
					swin = min(tres, swin);
				else
					owin = min(owin, tres);
					ry[i] -= off[j][1];
					rx[i] -= off[j][0];
				}
	return swin == INT32_MAX ? owin : swin;
}
void Do()
{
	if (!CheckMovable(rx[0], ry[0], false) && !CheckMovable(rx[1], ry[1], false))
	{
		puts("Black 0");
		return;
	}
	else if (!CheckMovable(bx, by, true))
	{
		puts("Red 1");
		return;
	}
	vst.reset();
	auto comRes(DFS(0));
	if (!~comRes)
		puts("Tie");
	else
		printf((comRes & 1) ? "Red %d\n" : "Black %d\n", comRes);
}
void Do56()
{
	int curi(ry[0] == n ? 1 : 0);
	if (by <= ry[curi])
	{
		printf("Black %d\n", by * 2 - 3);
		return;
	}
	int dist;
	switch (dist = GetDist(rx[curi], ry[curi], bx, by))
	{
	case 2:
		if (rx[curi] < bx)
			printf("Red %d\n", (m - bx) * 2 + 3);
		else
			printf("Red %d\n", bx * 2 + 1);
		break;
	case 3:
		if (AbsVal(rx[curi] - bx) == 0)
			puts("Tie");
		else if (rx[curi] < bx)
			printf("Red %d\n", (m - bx) * 2 + 3);
		else
			printf("Red %d\n", bx * 2 + 1);
		break;
	default:
		Do();
	}
}
void Do7To9()
{
	if (by < ry[0] && by < ry[1])
	{
		for (int i(1); i < by; ++i)
			if (gameMap[i].test(1))
			{
				Do();
				return;
			}
		printf("Black %d\n", by * 2 - 3);
	}
	else
		Do();
}
inline void AddRed(int x, int y)
{
	int idx(rx[0] ? 1 : 0);
	rx[idx] = x;
	ry[idx] = y;
}
typedef void(*DoSolu)();
DoSolu doSolu[] = {
	&Do,       // 0
	&Do1To4,   // 1
	&Do1To4,   // 2
	&Do1To4,   // 3
	&Do1To4,   // 4
	&Do56,     // 5
	&Do56,     // 6
	&Do7To9,   // 7
	&Do7To9,   // 8
	&Do7To9,   // 9
	&Do,       // 10
	&Do,       // 11
	&Do,       // 12
	&Do,       // 13
	&Do,       // 14
	&Do,       // 15
	&Do,       // 16
	&Do,       // 17
	&Do,       // 18
	&Do,       // 19
	&Do,       // 20
};
int main()
{
	freopen("zu.in", "r", stdin);
	freopen("zu.out", "w", stdout);
	id = rdi();
	T = rdi();
	while (T--)
	{
		n = rdi();
		m = rdi();
		// Init
		for (int i(0); i < 16; ++i)
			gameMap[i].set();
		bx = by = rx[0] = rx[1] = ry[0] = ry[1] = 0;
		for (int i(1); i <= n; ++i)
			for (int j(1); j <= m; ++j)
				switch (rdc())
				{
				case '.':
					gameMap[i].set(j, 0);
					break;
				case '#':
					break;
				case 'O':
					gameMap[i].set(j, 0);
					AddRed(j, i);
					break;
				case 'X':
					gameMap[i].set(j, 0);
					bx = j;
					by = i;
					break;
				}
		if (GetDist(rx[0], ry[0], bx, by) == 1 || GetDist(rx[1], ry[1], bx, by) == 1)
			puts("Red 1");
		else if (m == 1)
			Do7To9();
		else
			doSolu[id]();
	}
	return 0;
}