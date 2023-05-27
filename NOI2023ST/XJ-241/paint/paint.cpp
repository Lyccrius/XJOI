#include<bits/stdc++.h>
using namespace std;
int T, n, m, q, opt, x;
long long c, a[5010][5010];
int main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &n, &m, &q);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                a[i][j] = 0;
            }
        }
        for(int i = 1; i <= q; i++){
            scanf("%d%d%lld", &opt, &x, &c);
            if(opt == 0){
                for(int j = 1; j <= m; j++){
                    a[x][j] = c;
                }
            }
            if(opt == 1){
                for(int j = 1; j <= n; j++){
                    a[j][x] = c;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                printf("%lld ", a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}