#include<bits/stdc++.h>
using namespace std;
int s1[210], s2[210], t1[210], t2[210];
bool ans = 0;
bool vis[256];
int n, m;
void dfs(int now) {
    if(ans) return;
    if(now == n + 1) {
        ans = 1;
        return;
    }
    int x = t1[now], y = t2[now];
    bool flag = 0;
    if(!vis[x]) {
        vis[x] = 1;
        dfs(now + 1);
        vis[x] = 0;
        flag = 1;
    }
    if(y && !vis[y]) {
        vis[y] = 1;
        dfs(now + 1);
        vis[y] = 0;
        flag = 1;
    }
    if(!flag) return;
}
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &m);
        ans = 0;
        for(int i = 1; i <= n; i++) {
            int ns;
            scanf("%d%d", &ns, &s1[i]);
            s2[i] = 0;
            if(ns == 2) scanf("%d", &s2[i]);
        }
        for(int i = 1; i <= n; i++) {
            int nt;
            scanf("%d%d", &nt, &t1[i]);
            t2[i] = 0;
            if(nt == 2) scanf("%d", &t2[i]);
        }
        memset(vis, 0, sizeof vis);
        dfs(1);
        if(ans) printf("0\n");
        else printf("-1\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}