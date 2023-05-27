#include<bits/stdc++.h>
using namespace std;
long long n, x, cnt;
int k;
bool use[1000000010];
int main(){
    freopen("power.in", "r", stdin);
    freopen("power.out", "w", stdout);
    scanf("%lld%d", &n, &k);
    for(int i = 2; i <= n; i++){
        x = 1;
        for(int j = 1; j <= k; j++){
            x *= i;
        }
        if(x <= n){
            if(!use[x]){
                use[x] = 1;
                cnt++;
            }
            while(x * i <= n){
                x *= i;
                if(!use[x]){
                    use[x] = 1;
                    cnt++;
                }
                else break;
            }
        }
        else break;
    }
    if(n != 0) cnt += 1;
    printf("%lld", cnt);
    return 0;
}