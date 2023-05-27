#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int line[MAXN], col[MAXN], t1[MAXN], t2[MAXN];
int main()
{
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
		int n, m, p, op, x, c;
		cin >> n >> m >> p;
		memset(col, 0, sizeof(int) * (m+3));
		memset(line, 0, sizeof(int) * (n+3));
		memset(t2, 0, sizeof(int) * (m+3));
		memset(t1, 0, sizeof(int) * (n+3));
		for (int i = 1; i <= p; i++)
		{
			cin >> op >> x >> c;
			if (op == 1)
			{
				col[x] = c;
				t2[x] = i;
			}
			else
			{
				line[x] = c;
				t1[x] = i;
			}
		}
		for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (t2[j] > t1[i])
                {
                    cout << col[j];
                }
                else
                {
                    cout << line[i];
                }
                if (j != m) cout << ' ';
            }
            cout << '\n';
        }
	}
    return 0;
}
