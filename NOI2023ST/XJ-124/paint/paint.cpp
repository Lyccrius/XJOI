#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m, p, T;
ll num[10010][10010];

void work1(ll line, ll color)
{
    for (ll i = 1; i <= m; ++ i)
        num[line][i] = color;
}

void work2(ll k, ll color)
{
    for (ll i = 1; i <= n; ++ i)
        num[i][k] = color;
}

void work()
{
    scanf ("%lld %lld %lld", &n, &m, &p);
    for (ll i = 1; i <= p; ++ i)
    {
        ll a, b, c;
        scanf ("%lld %lld %lld", &a, &b, &c);
        if (a == 0) work1(b, c);
        else work2(b, c);
    }
    for (ll i = 1; i <= n; ++ i)
    {
        for (ll j = 1; j <= m; ++ j)
            printf ("%lld ", num[i][j]);
        puts("");
        memset (num[i], 0, sizeof num[i]);
    }
}

int main()
{
    freopen ("paint.in", "r", stdin);
    freopen ("paint.out", "w", stdout);
    scanf("%lld", &T);
    while (T --)
        work();
    fclose(stdin);
    fclose(stdout);
    return 0;
}