#include<bits/stdc++.h>
using namespace std;

map<long long, int> mp;
int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    
    long long n,k;
    scanf("%lld%lld",&n,&k);
    if(k==1){
        printf("%lld",n);
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    long long ans=1;
    for(int i=2;i<=n;i++){
        long long now=powl(i,k);
        if(now>n) break;
        while(1){
            if(mp.find(now)==mp.end()){
                mp[now]=1;
                ans++;
            }
            now*=i;
            if(now>n) break;
        }
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}