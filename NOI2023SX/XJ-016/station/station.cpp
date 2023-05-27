#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 4;
int ans[MAXN];
pair<int, int> road[MAXN], road2[MAXN];
int n, m, s, pt, l, r;
int main()
{
    freopen("station.in", "r", stdin);
    freopen("station.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        road[i].second = (1<<30);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> l >> r;
        road[l].first = max(road[l].first, r);
        road[r].second = min(road[r].second, l);
    }
    int R = 0, L = (1<<30);
    for (int i = 1; i <= n; i++)
    {
        if (road[i].first > s && i <= s) R = max(road[i].first, R);
        if (road[i].second < s && i >= s) L = min(road[i].second, L);
    }
    int i = s+1;
    while(i <= R)
    {
        if (road[i].first != 0) R = max(road[i].first, R);
        if (road[i].second != (1<<30)) ans[++pt] = i;
        i++;
    }
    i = s - 1;
    while(i >= L)
    {
        if (road[i].second != (1<<30)) L = min(road[i].second, L);
        if (road[i].first != 0) ans[++pt] = i;
        i--;
    }
    sort(ans + 1, ans + pt + 1);
    for (int i = 1; i <= pt; i++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
