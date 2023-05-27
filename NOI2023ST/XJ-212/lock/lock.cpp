#include <bits/stdc++.h>
using namespace std;
int T, k, n;
int a[100005][5];
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> T >> k;
    if (k == 1)
        while (T--){
            cin >> n;
            int maxn = 0, minn = 100005;
            for (int i = 1; i <= n; i++){
                int x;
                cin >> x;
                maxn = max(maxn, x);
                minn = min(minn, x);
            }
            cout << maxn - minn <<  endl;
        }
    if (k == 2)
        while (T--){
            int maxn1 = 0, minn1 = 100005;
            int maxn2 = 0, minn2 = 100005;
            memset(a, 0, sizeof(a));
            cin >> n;
            for (int i = 1; i <= 2; i++)
                for (int j = 1; j <= n; j++)
                    cin >> a[j][i];
            for (int i = 1; i <= n; i++){
                int maxa = max(a[i][1], a[i][2]);
                maxn1 = max(maxn1, maxa);
                minn1 = min(minn1, maxa);
                int mina = min(a[i][1], a[i][2]);
                maxn2 = max(maxn2, mina);
                minn2 = min(minn2, mina);
            }
            cout << max(maxn1 - minn1, maxn2 - minn2) << endl;
        }
    return 0;
}