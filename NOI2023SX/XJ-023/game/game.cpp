#include<bits/stdc++.h>
using namespace std;
int a[150010][4], b[150010][4], a1[200010][20], t[20], cnta = 0, b1[200010][20], visb[200], cntb = 0;
int n, m; 
void dfsa(int p){
    if(p > n){
        cnta ++;
        for(int i = 1; i <= n; i ++)    a1[cnta][i] = t[i];
        return ;
    }
    for(int i = 1; i <= a[p][0]; i ++){
        t[p] = a[p][i];
        dfsa(p + 1);
    }
}
void dfsb(int p){
    if(p > n){
        cntb ++;
        for(int i = 1; i <= n; i ++)    b1[cntb][i] = t[i];
        return ;
    }
    for(int i = 1; i <= b[p][0]; i ++){
        if(visb[b[p][i]] == 0){
            t[p] = b[p][i];
            visb[b[p][i]] = 1;
            dfsb(p + 1);
            visb[b[p][i]] = 0;
        }
    }
}
int compare()
{
    int ans = -1, i = 1, j = 1;
    for(int i = 1; i <= cnta; i ++){
        int mn = 100000000;
        for(int j = 1; j <= cntb; j ++){
            int num = 0;
            for(int t = 1; t <= n; t ++){
                if(a1[i][t] == b1[j][t]) num ++;
            }
            if(mn > num) mn = num;
        }
        if(ans < mn) ans = mn;
    }
    return ans;
}
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int T;
    cin >> T;
    while(T --){
        cin >> n>> m;
        cnta = 0;
        cntb = 0;
        for(int i = 1; i <= 200; i ++)
            visb[i] = 0;
        for(int i = 1; i <= n; i ++){
            cin>> a[i][0];
            if(a[i][0] == 1){
                cin >> a[i][1];
            }
            else{
                cin >> a[i][1] >> a[i][2];
            }
        }
        for(int i = 1; i <= n; i ++){
            cin>> b[i][0];
            if(b[i][0] == 1){
                cin >> b[i][1];
            }
            else{
                cin >> b[i][1] >> b[i][2];
            }
        }
        dfsa(1);
        dfsb(1);
        if(cntb == 0){
            cout << -1 << '\n';
            continue;
        }
        int ans = compare();
        cout << ans << '\n';
    }
    return 0;
}
