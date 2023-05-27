#include <stdio.h>
#include <string.h>
const int MAXN = 256000;
int n, m, k;
int u[MAXN], v[MAXN];
bool vis[MAXN];
bool contact(int a, int b)
{
    for (int i = 1; i <= m; i++)
    {
        if (a == u[i])
        {
            if (b == v[i])
            {
                return true;
            }
        }
        if (a == v[i])
        {
            if (b == u[i])
            {
                return true;
            }
        }
    }
    return false;
}
int sum_blocks(int a)
{
    if (vis[a])
        return 0;
    int sum = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i == a)
            continue;
        if (contact(i, a))
        {
            vis[a]=true;
            sum += sum_blocks(i);
        }
    }
    return sum;
}
int blocks(int a)
{
    memset(vis, 0, sizeof(vis));
    return sum_blocks(a);
}
int main()
{
    freopen("cities.in", "r", stdin);
    freopen("cities.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &u[i], &v[i]);
    }
    u[1]=v[1]=0;
    printf("%d",blocks(1));
    fclose(stdin);
    fclose(stdout);
    return 0;
}