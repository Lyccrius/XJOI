#include <bits/stdc++.h>
using namespace std;
int n,m,q;
int t;
int a[4005][4005],s[100005],tt[10005],y;
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin >> t;
    while (t--){
        cin >> n >> m >> q;
        if (n == 1){
            int t2 = 0;
            for(int i = 1;i <= m;i++)s[i] = 0;
            while (q--){
                int op,x,c;
                cin >> op >> x >> c;
                if (op == 0) {
                    t2 = c;
                    for (int i = 1;i <= y;i++){
                        s[tt[i]] = 0;
                        tt[i] = 0;
                        y = 0;
                    }
                }
                else {
                    s[x] = c;
                    y++;
                    tt[y] = x;
                }
            }
            for (int i = 1;i <= m;i++){
                if (s[i] != 0) cout << s[i] << " ";
                else cout << t2 << " ";
            }
            cout << endl;
        }else{
            for (int i = 1;i <= n;i++){
                for (int j = 1;j <= m;j++){
                    a[n][m] = 0;
                }
            }
            while (q--){
                int op1,x,c;
                cin >> op1 >> x >> c;
                if (op1 == 0){
                    for (int i = 1;i <= m;i++) a[x][i] = c;
                }
                if (op1 == 1){
                    for (int i = 1;i <= n;i++) a[i][x] = c;
                }
            }
            for (int i = 1;i <= n;i++){
                for (int j = 1;j <= m;j++){
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
    return 0;
}
