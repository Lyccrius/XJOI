#include <bits/stdc++.h>
using namespace std;

int a[20][30010];

int main() {
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int t, k;
    scanf("%d%d", &t, &k);
    while (t--) {
        int n;
        scanf("%d", &n);
        int mx = 0;
        int mn = 30010;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
                mx = max(mx, a[i][j]);
                mn = min(mn, a[i][j]);
            }
        }
        if (k == 1) {
            printf("%d\n", mx - mn);
        }else {
            mx = 0;
            mn = 30010;
            for (int i = 0; i < k; i++) {
                
            }
        }
    }
    return 0;
}
