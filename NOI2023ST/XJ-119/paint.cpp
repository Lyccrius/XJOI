#include <bits/stdc++.h>
using namespace std;

int t;
int p[10010][10010];

int main() {
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        int m, n, q;
        cin >> m >> n >> q;
        int opt[100010], x[100010], c[100010];
        int p2[100010] = {};
        int flag = 0;
        for (int i = 0; i < q; i++) {
            scanf("%d%d%d", &opt[i], &x[i], &c[i]);
            if (opt[i] == 0) {
                flag = 1;
            }
        }
        if (flag == 0) {
            for (int i = 0; i < q; i++) {
                p2[x[i]] = c[i];
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    printf("%d ", p2[j]);
                }
                printf("\n");
            }
        }else {
            memset(p, 0, sizeof(p));
            for (int i = 0; i < q; i++) {
                if (opt[i] == 0) {
                    for (int j = 1; j <= m; j++) {
                        p[x[i]][j] = c[i];
                    }
                }else {
                    for (int j = 1; j <= n; j++) {
                        p[j][x[i]] = c[i];
                    }
                }
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    printf("%d ", p[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
