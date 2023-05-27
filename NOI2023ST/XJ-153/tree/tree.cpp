#include <bits/stdc++.h>
using namespace std;
double a[1005][5],aa[1005][1005];
int d[1005],c[1005];
int n,len = INT_MAX;
bool f[1005];
void dfs(int x,int y,int l){
    if (y == n){
        if (l < len){
            for (int i = 1;i <= n;i++) {
                    d[i] = c[i];
                    len = l;
            }
        }
    }else{
        for (int i = 1;i <= n;i++){
            if (f[i] == 0){
                f[i] = 1;
                c[y+1] = i;
                dfs(i,y+1,l+aa[x][i]);
                f[i] = 0;
            }
        }
    }
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","W",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i][1] >> a[i][2];
    int len = INT_MIN,k;
    for (int i = 1;i <= n;i++){
        if (a[i][2] > len){
            len = a[i][2];
            k = i;
        }
    }
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= n;j++){
            if (i == j){
                aa[i][j] = INT_MAX;
            }else{
                aa[i][j] = sqrt((a[i][1] - a[j][1]) * (a[i][1] - a[j][1]) + (a[i][2] - a[j][2]) * (a[i][2] - a[j][2]));
            }
        }
    }
    d[1] = c[1] = k;
    f[k] = 1;
    dfs(k,1,0);
    for (int i = 1;i <= n;i++) cout << d[i] << " ";
    return 0;
}
