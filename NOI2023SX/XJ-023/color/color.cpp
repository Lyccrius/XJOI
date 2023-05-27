#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n, m, t, account, goal, fs;
int a[100], vis[300];
void red(int g, int p, int al){
    if(al > g){
        int shang = 1;
        while(vis[shang] == 1) shang ++;
        for(int i = shang; i <= n; i ++){
            if(vis[i] == 1) continue;
            if(a[shang] < a[i]) return ;
        }
        fs ++;
        return ;
    }
    for(int i = p; i <= n; i ++){
        if(vis[i] == 1) continue;
        vis[i] = 1;
        red(g, i + 1, al + 1);
        vis[i] = 0;
    }
}
bool panduan(){
    fs = 0;
    for(int i = 1; i <= n; i ++){
        red(i, 1, 1);
    }
    if(fs >= 2) return true;
    else return false;
}
int defen(){
    return 0;
}
void tianshu(int p){
    if(p > n && panduan()){
        account ++;
        goal = goal + defen();
        return ;
    }
    for(int i = 1; i <= m; i ++){
        a[p] = i;
        tianshu(p + 1);
    }
    return ;
}
int main()
{
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int C;
    cin >> C;
    while(C --){
        account = 0;
        goal = 0;
        fs = 0;
        cin >> n >> m >> t;
        for(int i = 1; i <= t; i ++)
            cin >> a[i];
        tianshu(t + 1);
        cout << account % mod << ' ' << goal % mod<< '\n';
    }
    return 0;
}