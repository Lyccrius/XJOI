#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
constexpr int NODESIZE = 100010;
int head[NODESIZE], fa[NODESIZE], nxt[NODESIZE * 2], dst[NODESIZE * 2];
int staff[NODESIZE], w[NODESIZE * 2], nst[NODESIZE * 2];
int nat(1), sat(1);
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
void SetFather(int f, int son)
{
	// father
	nxt[nat] = head[f];
	dst[nat] = son;
	head[f] = nat++;
	// son
	fa[son] = f;
}
void AddStaff(int id, int v)
{
	//printf("Debug Staff%d At N%d, w%d\n", sat, id, v);
	nst[sat] = staff[id];
	w[sat] = v;
	staff[id] = sat++;
}
int sid, n, k, m;
int staffUnused[NODESIZE], uut(1);
bool stv[NODESIZE * 2];
long long DFS(int id)
{
	long long ans(0);
	staffUnused[uut++] = staff[id];
	for (int s(head[id]); s; s = nxt[s])
		ans += DFS(dst[s]);
	int tmpMax(0);
	for (int i(1); i < uut; ++i)
		for (int j(staffUnused[i]); j; j = nst[j])
			if (stv[j])
				continue;
			else if (w[tmpMax] < w[j])
				tmpMax = j;
	stv[tmpMax] = true;
	--uut;
	//printf("Return N%d = %lld\n", id, ans);
	return ans + w[tmpMax];
}
int main()
{
	freopen("transfer.in", "r", stdin);
	freopen("transfer.out", "w", stdout);
	sid = rd();
	n = rd();
	k = rd();
	m = rd();
	for (int i(2); i <= n; ++i)
		SetFather(rd(), i);
	for (int i(1); i <= k; ++i)
	{
		int a(rd());
		int b(rd());
		AddStaff(a, b);
	}
	printf("%lld ", DFS(1));
	for (int i(0); i < m; ++i)
	{
		if (rd() == 1)
		{
			int a(rd());
			int b(rd());
			AddStaff(a, b);
		}
		else
			w[rd()] = 0;
		for (int i(0); i <= sat; ++i)
			stv[i] = false;
		printf("%lld ", DFS(1));
	}
	return 0;
}