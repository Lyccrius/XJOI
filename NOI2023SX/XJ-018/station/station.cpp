#include<bits/stdc++.h>
using namespace std;
int n, m, x, ll = 2147483647, rr = -1, st;
bool ans[200011], use[200011], flag = 1, path[400022];
struct line{
    int l, r;
}M[200011];
queue <int> Q;
int main(){
    freopen("station.in", "r", stdin);
    freopen("station.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &x);
    if(m <= 5000 && n <= 5000){
        for(int i = 1; i <= m; i++){
            scanf("%d%d", &M[i].l, &M[i].r);
            if(M[i].l < x) ans[M[i].l] = 1;
            if(M[i].r > x) ans[M[i].r] = 1;
            if(M[i].l <= x && M[i].r >= x) st = i;
        }
        Q.push(st);
        use[st] = 1;
        while(!Q.empty()){
            int u = Q.front();
            Q.pop();
            ll = min(ll, M[u].l);
            rr = max(rr, M[u].r);
            for(int i = 0; i <= m; i++){
                if(!use[i] && M[i].l <= rr && M[i].r >= ll){
                    Q.push(i);
                    use[i] = 1;
                }
            }
        }
        for(int i = ll; i <= rr; i++){
            if(ans[i] == 1){
                printf("%d ", i);
            }
        }
    }
    else{
        for(int i = 1; i <= m; i++){
            scanf("%d%d", &M[i].l, &M[i].r);
            if(M[i].l < x) ans[M[i].l] = 1;
            if(M[i].r > x) ans[M[i].r] = 1;
            for(int j = 2 * M[i].l; j <= 2 * M[i].r; j++){
                path[j] = 1;
            }
        }
        for(int i = x; i > 0; i--){
            if(path[i - 1] == 0)ll = i / 2;
        }
        for(int i = x; i < 2 * n; i++){
            if(path[i + 1] == 0)rr = i / 2;
        }
        for(int i = ll; i <= rr; i++){
            if(ans[i] == 1){
                printf("%d ", i);
            }
        }
    }
    return 0;
}