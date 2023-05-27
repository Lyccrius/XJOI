#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
long long n,k;
map <__int128,__int128> qwq;
long long ans=0;
int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin>>n>>k;
    if(k==1){
        cout<<n;
    }
    else{
        for(long long i=1;i<=n;i++){
            __int128 t=i;
            int flag=114;
            for(long long j=2;j<=64;j++){
                t=t*i;
                if(t>n){
                    flag=j;
                    break;
                }
                if(j>=k){
                    if(qwq[t]!=114){
                        ans++;
                    }
                    qwq[t]=114;
                }
            }
            if(flag<=k) break;
        }
        cout<<ans;
    }
    return 0;
}