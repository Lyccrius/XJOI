#include<bits/stdc++.h>
using namespace std;
struct dote{
    float x, y;
}d[1010];
int ans[1010], t[1010], vis[1010];
float ans2 = 10000010;
void dfs(int l, int b, int n){
    if(l > n){
       float ss = 0;
        for(int i = 1; i < n; i ++){
            float s;
            s = sqrt((d[i].x - d[i+1].x)*(d[i].x - d[i+1].x)+ (d[i].y - d[i+1].y)*(d[i].y - d[i+1].y));
            ss += s;
        }
        if(ans2 > ss ){
            ans2 = ss;
            for(int i = 1; i <= n; i ++)
                ans[i] = t[i];
        }
        return ;
    }
    for(int i = 1; i <= n; i ++){
        if(vis[i] == 1) continue;
        t[l] = b;
        vis[b] = 1;
        dfs(l+1, i, n);
        vis[i] = 0;
    }
}
int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int n, k = 1;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        cin >> d[i].x >> d[i].y;
        if(d[k].y < d[i].y) k = i;
    }
    vis[k] = 1;
    t[1] = k
    dfs(1, k, n);
    for(int i = 1; i <= n; i ++)
        printf("%d ", ans[i]);
    return 0;
}