#include <bits/stdc++.h>
using namespace std;
int p[1005], n, vis[1005], path[1005];
double x[1005], y[1005];
double ans = (1<<30);
double f[1005][1005];
double cal(int a, int b)
{
    return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]));
}
void dfs(int k)
{
    if (k == n+1)
    {
        double res = 0;
        for (int i = 1; i < n; i++)
        {
            res += cal(p[i], p[i+1]);
        }
        if (res < ans)
        {
            ans = res;
            for (int i = 1; i <= n; i++) path[i] = p[i];
        }
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i]) continue;
        vis[i] = 1;
        p[k] = i;
        dfs(k+1);
        vis[i] = 0;
    }
}
int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
    //int n;
    cin >> n;
    int k;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        if (y[k] < y[i]) k = i;
    }
    p[1] = k; vis[k] = 1;
    dfs(2);
    for (int i = 1; i <= n; i++) cout << path[i] << ' ';
    return 0;
}
