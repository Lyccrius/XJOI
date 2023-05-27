#include<bits/stdc++.h>
using namespace std;
long long x,n,k,ans=0;
long long vis[1000010];
int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin>>n>>k;
    if(k==1){
        cout<<n;
        return 0;
    }
    for(int i=k;i<=100;i++)
        for(int j=1;j<=sqrt(n);j++){
            x=pow(j,i);
            if(x<=n&&vis[x]==0){
                ans++;
                vis[x]=1;
            }    
        }
    cout<<ans-1;
    return 0;
}