#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <bitset>
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
int n, m;
constexpr int NODESIZE = 1000100;
int alic[NODESIZE], bobc[NODESIZE];
int ak[NODESIZE * 2], bk[NODESIZE * 2];
int bused[NODESIZE];
int64_t bDFS(int idx)
{
	/*printf("Alice: ");
	for (int i(1) ; i <= n; ++i)
		printf("%ld ", alic[i]);
	printf("\nBob: ");
	for (int i(1) ; i <= n; ++i)
		printf("%ld ", bobc[i]);
	puts("");*/
	while (bobc[idx])
		if (bused[bobc[idx]] != idx)
			return -1;
		else
			++idx;
	if (idx > n)
	{
		int64_t a(0ll);
		for (int i(1) ; i <= n; ++i)
			a += (alic[i] == bobc[i] ? 1 : 0);
		return a;
	}
	int64_t res(-1ll);
	if (!bused[bk[2 * idx]])
	{
		bobc[idx] = bk[2 * idx];
		bused[bobc[idx]] = idx;
		res = bDFS(idx + 1);
		bused[bobc[idx]] = 0;
		bobc[idx] = 0;
	}
	if (!bused[bk[2 * idx + 1]])
	{
		bobc[idx] = bk[2 * idx + 1];
		bused[bobc[idx]] = idx;
		auto tmpRes(bDFS(idx + 1));
		if (res == -1ll)
			res = tmpRes;
		else if (tmpRes != -1ll)
			res = min(res, tmpRes);
		bused[bobc[idx]] = 0;
		bobc[idx] = 0;
	}
	return res;
}
int64_t aDFS(int idx)
{
	while (alic[idx])
		++idx;
	if (idx > n)
		return bDFS(1);
	alic[idx] = ak[2 * idx];
	int64_t res(aDFS(idx + 1));
	alic[idx] = ak[2 * idx + 1];
	res = max(res, aDFS(idx + 1));
	alic[idx] = 0;
	return res;
}
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int T(rd());
	while (T--)
	{
		n = rd();
		m = rd();
		memset(alic + 1, 0, (n + 5) * sizeof(int));
		memset(bobc + 1, 0, (n + 5) * sizeof(int));
		memset(bused + 1, 0, (n + 5) * sizeof(int));
		memset(ak + 2, 0, 2 * (n + 5) * sizeof(int));
		memset(bk + 2, 0, 2 * (n + 5) * sizeof(int));
		for (int i(1); i <= n; ++i)
		{
			int c(rd());
			if (c == 1)
				ak[2 * i] = alic[i] = rd();
			else
			{
				ak[2 * i] = rd();
				ak[2 * i + 1] = rd();
			}
		}
		bool changed(true);
		bool contin(false);
		for (int i(1); i <= n; ++i)
		{
			int c(rd());
			if (c == 1)
			{
				bk[2 * i] = bobc[i] = rd();
				if (bused[bobc[i]])
				{
					changed = false;
					contin = true;
				}
				bused[bobc[i]] = i;
				if (ak[2 * i] == bobc[i] || ak[2 * i + 1] == bobc[i])
					alic[i] = bobc[i];
			}
			else
			{
				bk[2 * i] = rd();
				bk[2 * i + 1] = rd();
			}
		}
		while (changed)
		{
			/*printf("Alice: ");
			for (int i(1) ; i <= n; ++i)
				printf("%ld ", alic[i]);
			printf("\nBob: ");
			for (int i(1) ; i <= n; ++i)
				printf("%ld ", bobc[i]);
			puts("");*/
			changed = false;
			for (int i(1); i <= n; ++i)
				if (!bobc[i])
					if (bused[bk[2 * i]])
						if (bused[bk[2 * i + 1]])
						{
							contin = true;
							changed = false;
							break;
						}
						else
						{
							bobc[i] = bk[2 * i + 1];
							bused[bobc[i]] = i;
							changed = true;
						}
					else if (bused[bk[2 * i + 1]])
					{
						bobc[i] = bk[2 * i];
						bused[bobc[i]] = i;
						changed = true;
					}
		}
		printf("%ld\n", contin ? -1l : aDFS(1));
	}
}