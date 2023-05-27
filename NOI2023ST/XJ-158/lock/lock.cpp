#include<bits/stdc++.h>
using namespace std;
struct ba{
    int a[4];
    int b[4];
    int c[4];
}lo[50010];
int a[4][50010];
int ans = 50000;
void dfs(int l, int g, int n, int k){
    if(l > n){
        int num = -1;
        for(int i = 1; i <= k; i ++){
            int mn = 50000, mx = -1;
            for(int j = 1; j <= n; j ++){
                if(mn > a[i][j]) mn = a[i][j];
                if(mx < a[i][j]) mx = a[i][j];
            }
            if(num < mx - mn) num = mx - mn;
        }
        if(ans > num) ans = num;
        return ;
    }
        for(int i = 1; i <= k; i ++){
            int sum = i;
            if(sum == 1)
                for(int j = 1; j <= k; j ++)
                    a[j][l] = lo[l].a[j];
            else if(sum == 2)
                for(int j = 1; j <= k; j ++)
                    a[j][l] = lo[l].b[j];
            else if(sum == 3)
                for(int j = 1; j <= k; j ++)
                    a[j][l] = lo[l].c[j];
            dfs(l+1, sum, n, k);
        }
}
void shuru(int k, int x){//k --> ba quan ge shu , x --> ba quan bian hao
    for(int i = 1; i <= k; i ++){
        lo[x].a[i] = a[i][x];
        int num = (i + 1) % (k+1);
        if(num == 0) num = 1;
        lo[x].b[num] = a[i][x];
        num = (i + 2) % (k+1);
        if(num == 0) num = 1;
        else if(num == 1) num = 2;
        lo[x].c[num] = a[i][x];
    }
}
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int T, k;
    scanf("%d %d", &T, &k);
    while(T --){
        ans = 50000;
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= k; i ++)
            for(int j = 1; j <= n; j ++){
            scanf("%d", &a[i][j]);
        }
        for(int i = 1; i <= n; i ++){
            shuru(k, i);
        }
        dfs(1, 1, n, k);
        printf("%d\n", ans);
    }
    return 0;
}