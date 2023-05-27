#include<bits/stdc++.h>
using namespace std;
int a[256];
long long ans = 0;
int n, mx, t;
bool rg[256];
void dfs(int now, int rb, int gb) {
    if(now == n + 1) {
        long long score = 0;
        for(int i = 1; i <= n; i ++ ) {
            if(rg[i]) {
                for(int j = 1; j < i; j ++) {
                    if(a[i]<a[j]) score += mx-a[i]+1;
                }
            }
            else {
                for(int j = 1; j < i; j ++) {
                    if(a[i]>a[j]) score += a[i];
                }
            }
        }
        if(score > ans) ans = score % 998244353;
        return ;
    }
    if (rb >= a[now] && gb <= a[now]) return;
    if(rb < a[now]){
        rg[now] = 1;
        dfs(now+1, a[now], gb);
        rg[now] = 0;
    }
    if(gb > a[now]) dfs(now+1, rb, a[now]);
}
int main() {
    freopen("color.in", "r", stdin);
    freopen("color.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T --) {
        memset(rg, 0, sizeof rg);
        ans = 0;
        scanf("%d%d%d", &n, &mx, &t);
        for(int i = 1; i <= n; i++ ) {
            scanf("%d", &a[i]);
        }
        dfs(1, -1, 0x3f3f3f3f);
        if(!ans) printf("0 0\n");
        else printf("1 %lld\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}