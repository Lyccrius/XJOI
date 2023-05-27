#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, maxd;
double maxy = -10000005.0;
double along[1005][1005];
bool blong[1005][1005];
struct S{
    double x, y;
}a[1005];
void dfs(int x, int etimes){
    if (etimes == n - 1) return;
    double maxe = 0;
    ll maxx = 0;
    for (int i = 1; i <= n; i++){
        if (i == x || blong[i][x] || blong[x][i]) continue;
        if (maxe - along[x][i] < 0){
            maxe = along[x][i];
            maxx = i;
        }
    }
    cout << maxx << " ";
    dfs(maxx, etimes + 1);
    return;
}
int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y;
        if (maxy - a[i].y < 0){
            maxy = a[i].y;
            maxd = i;
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            if (i == j) continue;
            along[i][j] = sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));
            along[j][i] = along[i][j];
        }
    }
    dfs(maxd, 0);
    return 0;
}