#include <cstdint>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <list>
using namespace std;
uint64_t readI()
{
	char ch;
	uint64_t x(0);
	while (!isdigit(ch = getchar()));
	do
		x = x * 10 + (ch ^ 48);
	while (isdigit(ch = getchar()));
	return x;
}
uint64_t opower(uint64_t base, uint64_t p, bool& overflowed)
{
	if (p == 0)
		return 1;
	union
	{
		uint64_t u64;
		uint32_t u32[2];
	} ans, b;
	ans.u64 = b.u64 = base;
	for (uint64_t i(2); i <= p; ++i)
	{
		if (
			(ans.u32[1] * (uint64_t)b.u32[1]) +
			((ans.u32[0] * (uint64_t)b.u32[1]) >> 32) +
			((ans.u32[1] * (uint64_t)b.u32[0]) >> 32)
			)
		{
			overflowed = true;
			return 0;
		}
		ans.u64 *= base;
	}
	overflowed = false;
	return ans.u64;
}

uint64_t nsqrt(uint64_t val, uint64_t n)
{
	if (n == 1)
		return val;
	uint64_t l(1), r(val), mid, res;
	bool overflowed;
	while (l < r)
	{
		mid = (l + r + 1) >> 1;
		res = opower(mid, n, overflowed);
		if (overflowed || res > val)
			r = mid - 1;
		else
			l = mid;
	}
	return l;
}
bool isUsed[110];
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	if (a < b)
		swap(a, b);
	return gcd(b, a % b);
}
int main()
{
	freopen("power.in", "r", stdin);
	freopen("power.out", "w", stdout);
	uint64_t n, k, ans(1), t;
	n = readI();
	k = readI();
	if (k >= 64)
	{
		puts("1");
		return 0;
	}
	if (k == 1)
	{
		printf("%llu\n", n);
		return 0;
	}

	list<int> ns;
	int i(k);
	for (;; ++i)
	{
		if (isUsed[i])
			continue;
		t = nsqrt(n, i);
		if (t == 1)
			break;
		ans += t - 1;
		ns.push_back(i);
		for (int j(1); j * i <= 100; ++j)
			isUsed[i * j] = true;
	}
	for (auto ita(ns.begin()); ita != ns.end(); ++ita)
		for (auto itb(next(ita)); itb != ns.end(); ++itb)
		{
			int gd(gcd(*ita, *itb));
			ans -= (nsqrt(n, *ita / gd * *itb) - 1);
		}
	printf("%llu\n", ans);
	return 0;
}