#include<bits/stdc++.h>
using namespace std;
int n, m, k, ans;
int C(int x, int y){
    int he = 1;
    for(int i = 0; i < y; i++){
        he *= (x - i);
    }
    for(int i = y; i > 0; i--){
        he /= i;
    }
    return he;
}
struct line{
    int l, r;
}M[100010];

int main(){
    freopen("cities.in", "r", stdin);
    freopen("cities.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= m; i++){
        scanf("%d%d", &M[i].l, &M[i].r);
    }
    if(m == n - 1 && k == 1){
        for(int i = 2; i <= n; i++){
            ans += C(i, (n % i));
            ans %= 998244353;
        }
    }
    else if(k == 0){
        for(int i = 2; i <= n; i++){
            if(n % i == 0){
                ans ++;
                ans %= 998244353;
            }
        }
    }

    printf("%d", ans);
    return 0;
}