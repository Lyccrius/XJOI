#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<map>
using namespace std;

map<long long int,bool> m;
long long int n, ans;
int k;
long long int if_over(int b){
    long long int tol = 1;
    for(int j = 1;j <= k; j++){
        tol *= b;
        m[tol] = 1;
        if(tol > n) return 0;
    }
    return tol;
}
int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    scanf("%lld %d",&n,&k);
    if(k == 1){
        printf("%lld",n);
        return 0;
    }
    ans++;
    for(int i = 2; ; i++){
        if(m[i]) continue;
        long long int t = if_over(i);
        if(t){
            while(t <= n){
                ans++;
                t *= i;
                m[t] = 1;
                if(t > n) break;
            }
        }
        else break;
    }
    printf("%lld",ans);
    return 0;
}