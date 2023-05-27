#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define pre(i,r,l) for(int i=r;i>=l;i--)
#define ll long long
#define se second
#define fi first
using namespace std;
const int N=2e5+10,inf=1e9+10,mod=998244353;
int n,m;
int u[N],v[N],fa[N];
int dp[1<<20],k,ans;
bool w[1<<20];
int find(int x){
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
int qpow(int x,int y){
    int res=1;
    while(y){
        if(y&1)res=1ll*res*x%mod;
        x=1ll*x*x%mod;y>>=1;
    }
    return res;
}
int main(){
    freopen("cities.in","r",stdin);
    freopen("cities.out","w",stdout);
    cin>>n>>m>>k;
    rep(i,1,m)scanf("%d%d",&u[i],&v[i]);
    rep(i,1,(1<<n)-1){
        rep(i,1,n)fa[i]=i;
        rep(j,1,m){
            if(!(i>>u[j]-1&1))continue;
            if(!(i>>v[j]-1&1))continue;
            fa[find(u[j])]=find(v[j]);
        }
        int lst=0,flag=1;
        rep(j,1,n){
            if((i>>j-1)&1){
                if(!lst)lst=j;
                else if(find(lst)!=find(j))flag=0;
            }
        }
        w[i]=flag;
        //cout<<i<<" "<<w[i]<<endl;
    }
    for(int len=1;len<=n-1;len++){
        //cout<<n%len<<endl;
        if(n%len==0){
           // cout<<len<<endl;
            dp[0]=1;
            rep(i,1,(1<<n)-1){
                int s=__builtin_popcount(i);
                if(s%len==0){
                    if(s==len)dp[i]=w[i];
                    else dp[i]=0;
                    //cout<<i<<" "<<dp[i]<<endl;
                    for(int j=i-1&1;j;j=(j-1)&i){
                        if(__builtin_popcount(j)==len&&w[j])dp[i]+=dp[i^j];
                        if(dp[i]>=mod)dp[i]-=mod;
                    }
                }
            }
            int res=1;
            rep(i,1,n/len)res=1ll*res*i%mod;
            ans+=1ll*dp[(1<<n)-1]*qpow(res,mod-2)%mod;
            if(ans>=mod)ans-=mod;
        }
    }
    cout<<ans<<endl;
}