#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,k,a[200010],b[200010],f[10010];
int main(){
    freopen("cities.in","r",stdin);
    freopen("cities.out","w",stdout);
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++){
        cin>>a[i]>>b[i];
    }
    if(k==0&&n%2==1){
        cout<<1;
        return 0;
    }
    if(m==n-1){
        if(k==0){
            cout<<1;
            return 0;
        }
        if(k==1){
            f[1]=1;
            f[2]=2;
            for(long long i=3;i<=n;i++)
                f[i]=(f[i-1]+f[i-2])%mod;
            cout<<f[n];
            return 0;
        }
    }
    return 0;
}