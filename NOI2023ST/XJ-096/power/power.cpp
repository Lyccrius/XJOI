#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10,mod=998244353;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define pre(i,r,l) for(int i=r;i>=l;i--)
#define ll long long
#define fi first
#define se second
int k,cnt;
ll n,a[N];
ll qpow(ll x,int y){
    __int128 res=1;
    rep(i,1,y){
        res=res*x;
        if(res>n)return n+1;
    }
    return res;
}
signed main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin>>n>>k;
    if(k==1){
        cout<<n<<endl;
        return 0;
    }
    if(k==2){
        ll ans=sqrt(n);
        rep(i,3,63){
            int x=1;
            while(qpow(x,i)<=n)
                a[++cnt]=qpow(x,i),x++;
        }
        sort(a+1,a+cnt+1);
        cnt=unique(a+1,a+cnt+1)-a-1;
        rep(i,1,cnt){
            ll x=sqrt(a[i]);
            if(1ll*x*x!=a[i])ans++;
        }
        cout<<ans<<endl;
        return 0;
    }
    rep(i,k,100){
        int x=1;
        while(qpow(x,i)<=n){
            a[++cnt]=qpow(x,i);x++;
        }
    }
    sort(a+1,a+cnt+1);
    cnt=unique(a+1,a+cnt+1)-a-1;
    cout<<cnt<<endl;
    fclose(stdin);
    fclose(stdout);
}