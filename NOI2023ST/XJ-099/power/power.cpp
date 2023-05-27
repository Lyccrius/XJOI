#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll n; int k;
ll qpow(ll a,ll b);
int logg(ll a)
{
    int ans=0;
    while(a) ans++,a>>=1ll;
    return ans;
}
int pri[N],top; bool ispri[N];
void cal_pri(int x)
{
    for(int i=2;i<=x;i++)
    {
        if(!ispri[i]) pri[++top]=i;
        for(int j=1;j<=top&&1ll*i*pri[j]<=x;j++)
        {
            ispri[i*pri[j]]=1;
            if(!(i%pri[j])) break;
        }
    }
}

namespace subtask1{
    bool isok(int x)
    {
        int mx=-1; int used=-1;
        for(int i=1;i<=top;i++)
        {
            if(pri[i]>x) break;
            int w=pri[i],cnt;
            if(x%w==0)
            {
                cnt=0;
                while(x%w==0) cnt++,x/=w;
                mx=cnt;
                if(used==-1) used=cnt;
                else if(used!=cnt) return false;
            }
        }
        if(x>1) return false;
        return mx>=k;
    }
    void solve()
    {   
        cal_pri(1e5); int ans=0;
        for(int i=1;i<=n;i++) ans+=isok(i);
        printf("%d\n",ans+1);
    }    
}

namespace subtask2{
    int f[N];
    bool check(ll w,int k)
    {   
        ll base=w;
        if(base>n) return false;
        for(int i=2;i<=k;i++)
        {
            base=base*w;
            if(base>n) return false; 
        }
        return true;
    }
    int getlc(ll n,int k)
    {
        ll l=1,r=ceil(sqrt(n)),mid,ans;
        while(l<=r)
        {
            mid=(l+r)>>1ll;
            if(check(mid,k)) ans=mid,l=mid+1;
            else r=mid-1;
        }
        return ans;
    }
    void bag(int rc)
    {
        f[1]=1;
        for(int i=1;i<=top;i++)
        {
            int w=pri[i]; if(w>rc) break;
            for(int j=rc/w;j>=1;j--) f[w*j]|=f[j];
        }
        for(int i=1;i<=rc;i++) f[i]=f[i-1]+f[i];
    }
    void solve()
    {
        cal_pri(2e6); int lg=logg(n);
        int rw=getlc(n,k); bag(rw); int ans=0;
        for(int i=k;i<=lg+10;i++)
        {
            int rc=getlc(n,i);
            if(rc==1) break;
            ans+=f[rc];
        }
        ans-=(lg-k-1);
        printf("%d\n",ans);
    }
}

int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    scanf("%lld%d",&n,&k);
    if(k==1) {printf("%lld\n",n); return 0;}
    if(logg(n)<k) {puts("0"); return 0;}
    if(n<=1e6) subtask1::solve();
    else subtask2::solve();
}

ll qpow(ll a,ll b)
{
    ll base=a,ans=1;
    while(b>0)
    {
        if(b&1) ans=ans*base;
        base*=base;
        b>>=1;
    }
    return ans;
}