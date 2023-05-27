#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 4;
int t[MAXN][2], s[MAXN][2];
int main()
{	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
    ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
    cin >> T;
    while(T--)
    {
        int n, m, k;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> k;
            for (int j = 0; j < k; j++)
            {
                cin >> s[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> k;
            for (int j = 0; j < k; j++)
            {
                cin >> t[i][j];
            }
            if (t[i][0] && t[i][1] && t[i][0] > t[i][1]) swap(t[i][0], t[i][1]);
        }
        int flag = 0;
        for (int i = 1; i < n; i++)
        {
            if (t[i][0] == i && t[i][1] ==i + 1) flag = 1;
            else 
            {
                flag = 0; break;
            }
        }
        if (!flag)
        {
            cout << 0 << '\n';
            continue;
        }
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i][0] == t[i][0] || s[i][1] == t[i][0]) cnt1++;
            if (s[i][0] == t[i][1] || s[i][1] == t[i][1]) cnt2++;
        }
        cout << min(cnt1, cnt2) << '\n';
    }
    return 0;
}
