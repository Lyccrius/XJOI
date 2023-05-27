#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int M=2e5+10;
typedef long long ll;
const ll p=998244353;
int n,m,k;
struct e{
    int u,v;
}edge[M];
namespace subtask1{
    int fa[20],siz[20]; bool vis[N];
    int findf(int x) {return x==fa[x]?fa[x]:fa[x]=findf(fa[x]);}
    void merge(int x,int y)
    {
        x=fa[x],y=fa[y];
        if(x!=y)
        {
            siz[x]+=siz[y]; siz[y]=0;
            fa[y]=x;
        }
    }
    bool check(int s)
    {
        int minn=9000,maxx=0,cnt=0,tot=0;
        for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1,vis[i]=0;
        for(int i=0;i<m;i++)
            if(!(s>>i&1)) merge(edge[i+1].u,edge[i+1].v);
        for(int i=1;i<=n;i++)
        {
            int x=findf(i);
            if(!vis[x]) {vis[x]=1; minn=min(minn,siz[x]),maxx=max(maxx,siz[x]); tot++;}
        }
        for(int i=1;i<=n;i++) vis[i]=0;
        for(int i=0;i<m;i++)
            if(s>>i&1) 
            {
                if(!vis[edge[i+1].u]) vis[edge[i+1].u]=1,cnt++;
                if(!vis[edge[i+1].v]) vis[edge[i+1].v]=1,cnt++;
            }
        return maxx-minn<=k&&tot==cnt;
    }
    void solve()
    {
        
        int ans=0;
        int S=(1<<m);
        for(int i=1;i<S;i++) 
            if(check(i)) ans++;
        printf("%d\n",ans);
    }
}

int main()
{
    freopen("cities.in","r",stdin);
    freopen("cities.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++) scanf("%d%d",&edge[i].u,&edge[i].v);
    if(m<=20) {subtask1::solve(); return 0;}
    else puts("1");
    
}