#include <bits/stdc++.h>
using namespace std;
int a[3][50002], b[100002], p[100002], q[100002];
bool cmp(int i, int j)
{
	return b[i] < b[j];
}
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int T, k, n;
    cin >> T >> k;
    while(T--)
    {
        cin >> n; int t = 0;
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                b[++t] = a[i][j];
                
            }
        }
        if (k == 1)
        {
            int mx = 0, mi = (1<<30);
            for (int i = 1; i <= n; i++)
            {
                mx = max(mx, a[1][i]);
                mi = min(mi, a[1][i]);
            }
            cout << mx - mi << '\n';
        }
        else
        {
            //sort(b+1,b+t+1);
			for (int i = 1; i <= n; i++)
			{
				if (a[1][i] < a[2][i]) swap(a[1][i], a[2][i]);
			}
			int mx = 0, mi = (1<<30);
			for (int i = 1; i <= n; i++)
            {
                mx = max(mx, a[1][i]);
                mi = min(mi, a[1][i]);
            }
            int ans = mx - mi;
            mx = 0, mi = (1<<30);
            for (int i = 1; i <= n; i++)
            {
                mx = max(mx, a[2][i]);
                mi = min(mi, a[2][i]);
            }
            ans = max(ans, mx - mi);
            cout << ans << '\n';
        }
    }
    return 0;
}
