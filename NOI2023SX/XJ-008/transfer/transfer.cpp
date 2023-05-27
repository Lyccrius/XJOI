#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int mx=1e5;
typedef long long ll;
#define mkp make_pair
int read();
int sid;
int n,k,Q,fa[N];
vector<int>ver[N]; int siz[N];
int x[N<<1],v[N<<1]; bool del[N<<1];
int op,a1,a2;
void dfs(int u)
{
    siz[u]=1;
    for(int to:ver[u])
    {
        dfs(to);
        siz[u]+=siz[to];
    }
}
namespace subtask1{
    struct segtree{
        #define maxx N*24
        #define ls t[p].lc
        #define rs t[p].rc
        struct tree{
            int lc,rc;ll w;int sz,laz;
        }t[maxx]; int rt[N],tot;
        void init()
        {
            for(int i=1;i<=tot;i++) t[i]=tree{0,0,0,0,0};
            tot=0;
            for(int i=1;i<=n;i++) rt[i]=++tot;
        }
        void push_down(int p,int l,int r)
        {
            if(t[p].laz)
            {
                if(r-l>1) t[ls].laz=t[rs].laz=t[p].laz;
                t[ls].w=t[ls].sz=0; t[rs].w=t[rs].sz=0;
                t[p].laz=0;
            }
        }
        int merge(int a,int b,int l,int r)
        {
            if(!a||!b) return a+b;
            if(l==r) {t[a].w+=t[b].w; t[a].sz+=t[b].sz; return a;}
            int mid=(l+r)>>1;
            push_down(a,l,r); push_down(b,l,r);
            t[a].lc=merge(t[a].lc,t[b].lc,l,mid);
            t[a].rc=merge(t[a].rc,t[b].rc,mid+1,r);
            t[a].w=t[t[a].lc].w+t[t[a].rc].w;
            t[a].sz=t[t[a].lc].sz+t[t[a].rc].sz;
            return a;
        }
        void update(int &p,int l,int r,int a,int w)
        {
            if(w==0||a>mx) return;
            if(!p) p=++tot;
            if(l==r) {t[p].sz+=w; t[p].w+=1ll*l*w; return;}
            push_down(p,l,r);
            int mid=(l+r)>>1;
            if(mid>=a) update(ls,l,mid,a,w);
            else update(rs,mid+1,r,a,w);
            t[p].w=t[ls].w+t[rs].w; t[p].sz=t[ls].sz+t[rs].sz;
        }
        pair<int,int>query(int p,int l,int r,int a)
        {
            if(!p) return mkp(0,0);
            if(l==r)
            {
                int w=min(a,t[p].sz);
                return mkp(l,w);
            }
            push_down(p,l,r);
            int mid=(l+r)>>1; 
            if(t[ls].sz>=a) return query(ls,l,mid,a);
            else
            {
                pair<int,int>f=query(rs,mid+1,r,a-t[ls].sz);
                pair<int,int>ans=mkp(mid,t[ls].sz);
                ans.first=f.first; ans.second+=f.second;
                return ans;
            }
        }
        void clear(int p,int l,int r,int a)
        {
            if(r<=a) 
            {
                t[p].w=t[p].sz=0;
                t[p].laz=1;
                return;
            }
            push_down(p,l,r);
            int mid=(l+r)>>1;
            clear(ls,l,mid,a);
            if(mid+1<=a) clear(rs,mid+1,r,a);
            t[p].w=t[ls].w+t[rs].w; t[p].sz=t[ls].sz+t[rs].sz;
        }
        int nextpos(int p,int l,int r,int a)
        {
            if(!p) return mx+1;
            int mid=(l+r)>>1;
            if(l==r) return l;
            if(t[ls].sz<=a) return nextpos(rs,mid+1,r,a-t[ls].sz);
            return nextpos(ls,l,mid,a); 
        }
        #undef ls
        #undef maxx
        #undef rs
    }t;
    
    void dpp(int u)
    {
        for(int to:ver[u]) dpp(to);
        for(int to:ver[u]) 
            t.rt[u]=t.merge(t.rt[u],t.rt[to],1,mx);
        
        if(t.t[t.rt[u]].sz<=siz[u]) return;
        pair<int,int>f=t.query(t.rt[u],1,mx,t.t[t.rt[u]].sz-siz[u]);
        int res=t.t[t.rt[u]].sz-siz[u]-f.second;
        t.clear(t.rt[u],1,mx,f.first);
        int pp=t.nextpos(t.rt[u],1,mx,f.second);
        t.update(t.rt[u],1,mx,pp,-res);
    }
    void update()
    {
        t.init();
        for(int i=1;i<=k;i++) 
        {
            if(del[i]) continue;
            t.update(t.rt[x[i]],1,mx,v[i],1);
        }
        dpp(1);
        printf("%lld ",t.t[t.rt[1]].w);
    }   
    void solve()
    {
        update();
        while(Q--)
        {
            op=read();
            if(op==1) 
            {
                k++;
                a1=read(); a2=read();
                x[k]=a1; v[k]=a2;
            }
            else
            {
                a2=read();
                del[a2]=1;
            }
            update();
        }
    }
}   
namespace subtask2{
    ll ans;
    void update()
    {
        ans=0;
        for(int i=1;i<=k;i++) ans+=v[i];
        printf("%lld\n",ans);
    }
    void solve()
    {
        update();
        while(Q--)
        {
            op=read();
            if(op==1) 
            {
                k++;
                a1=read(); a2=read();
                x[k]=a1; v[k]=a2; ans+=v[k];
            }
            else
            {
                a2=read();
                del[a2]=1; ans-=v[a2];
            }
            printf("%lld\n",ans);
        }
    }
}




int main()
{
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    scanf("%d%d%d%d",&sid,&n,&k,&Q);
    for(int i=2;i<=n;i++)
    {
        fa[i]=read();
        ver[fa[i]].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=k;i++) x[i]=read(),v[i]=read();
    if(n<=3000||sid==7||sid==6) {subtask1::solve(); puts(""); return 0;}
    else {subtask2::solve(); puts(""); return 0;}
}

int read()
{
    int ans=0; char f; f=getchar();
    while(f<'0'||f>'9') f=getchar();
    while(f>='0'&&f<='9') ans=ans*10+f-'0',f=getchar();
    return ans;
}
