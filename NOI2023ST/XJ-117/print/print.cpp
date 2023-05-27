#include<bits/stdc++.h>
using namespace std;
int n, m, q, t;
int a[10010][10010];
int main() {
    freopen("print.in", "r", stdin);
    freopen("print.out", "w", stdout);
    cin >> t ;
    while(t--) {
        cin >> n >> m >> q;
        while(q--) {
            int opt, x, c;
            cin >> opt >> x >> c;
            if(opt == 0) {
                for(int j = 0 ; j < m ; j++) a[x-1][j] = c;
            }
            else {
                for(int j = 0 ; j < n ; j++) a[j][x-1] = c;
            }
        }
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m ; j++) {
                cout << a[i][j] << " ";
                a[i][j] = 0;
            }
            cout << endl;
        }
    }
    return 0;
}
//"Thanks to this one, or I will get 0 point."