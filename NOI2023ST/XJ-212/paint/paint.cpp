#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll T;
ll n, m, q;
ll f1[100005], f2[100005];
ll g1[100005], g2[100005];
int main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    cin >> T;
    while (T--){
        cin >> n >> m >> q;
        memset(f1, 0, sizeof(f1));
        memset(f2, 0, sizeof(f2));
        memset(g1, 0, sizeof(g1));
        memset(g2, 0, sizeof(g2));
        for (ll i = 1; i <= q; i++){
            ll opt, x, c;
            cin >> opt >> x >> c;
            if (opt == 0){
                f1[x] = c;
                g1[x] = i;
            }
            if (opt == 1){
                f2[x] = c;
                g2[x] = i;
            }
        }
        for (ll i = 1; i <= n; i++){
            for (ll j = 1; j <= m; j++){
                if (g1[i] > g2[j]) 
                    cout << f1[i] << " ";
                else 
                    cout << f2[j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}