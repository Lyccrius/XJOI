#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define pre(i,r,l) for(int i=r;i>=l;i--)
#define ll long long
#define se second
#define fi first
using namespace std;
const int N=2e5+10,inf=1e9+10;
int n,k,m,T,a[N],b[N],siz[N];
vector<int>v[N];
vector<int>vec[N];
multiset<int>st1[N],st2[N];
int son[N],dfn[N],rk[N],top[N],f[N],cnt;
bool cmp(int x,int y){
    return b[x]>b[y];
}
void dfs(int x,int fa){
    siz[x]=1;f[x]=fa;
    for(auto y:v[x]){
        dfs(y,x);siz[x]+=siz[y];
        if(siz[son[x]]<siz[y])son[x]=y;
        if(vec[x].size()<vec[y].size())swap(vec[x],vec[y]);
        for(auto cur:vec[y])vec[x].push_back(cur);
    }
    sort(vec[x].begin(),vec[x].end(),cmp);
    while(vec[x].size()>siz[x])vec[x].pop_back();
}
void dfs1(int x,int topf){
    dfn[x]=++cnt;top[x]=topf;
    rk[cnt]=x;
    if(son[x])dfs1(son[x],topf);
    for(auto y:v[x]){
        if(y==son[x])continue;
        dfs1(y,y);
    }
}
ll solve(){
    rep(i,1,n)vec[i].clear();
    rep(i,1,k)if(a[i])vec[a[i]].push_back(i);
    dfs(1,0);
    ll ans=0;
    for(auto x:vec[1])ans+=b[x];
    //for(auto x:vec[1])printf("%d ",x);
    return ans;
}
/*struct sgt1{
    int mn[N<<2],s[N<<2];
    int add[N<<2],mx[N<<2];
    void pd(int k){add[k<<1]=add[k<<1|1]=add[k];}
    int merge1(int x,int y){
        if(*st1[x].begin()<*st1[y].begin())return x;
        return y;
    }
    int merge2(int x,int y){
        if(*(--st2[x].end())>*(--st2[y].end()))return x;
        return y;
    }
    void up(int k){
        mn[k]=merge1(mn[k<<1],mn[k<<1|1]);
        mx[k]=merge2(mx[k<<1],mx[k<<1|1]);
    }
    void modify1(int k,int l,int r,int x,int w){
        if(l==r){
            if(w>0)s[k]++;
            else s[k]--;
            return;
        }
        int mid=l+r>>1;
        if(x<=mid)modify1(k<<1,l,mid,x,w);
        else modify1(k<<1|1,mid+1,r,x,w);
        up(k);
    }
    int qsum(int k,int l,int r,int x,int y){
        if(x<=l&&r<=y)return s[k];
        int mid=l+r>>1,res=0;
        if(x<=mid)res+= qsum(k<<1,l,mid,x,y);
        if(y>mid)res+= qsum(k<<1|1,mid+1,r,x,y);
        return res;
    }
    int qmn(int k,int l,int r,int x,int y){
        if(x<=l&&r<=y)return mn[k];
        int mid=l+r>>1;
        if(x<=mid&&y>mid)return merge1(qmn(k<<1,l,mid,x,y),qmn(k<<1|1,mid+1,r,x,y));
        if(x<=mid)return qmn(k<<1,l,mid,x,y);
        return qmn(k<<1|1,mid+1,r,x,y);
    }
    void build(int k,int l,int r){
        mn[k]=mx[k]=l;
        if(l==r)return;
        int mid=l+r>>1;
        build(k<<1,l,mid);build(k<<1|1,mid+1,r);
    }
    int qmx(int k,int l,int r,int x,int y){
        if(x<=l&&r<=y){
            if(add[k])return 0;
            return mx[k];
        }
        int mid=l+r>>1;pd(k);
        if(x<=mid&&y>mid)return merge2(qmx(k<<1,l,mid,x,y),qmx(k<<1|1,mid+1,r,x,y));
        if(x<=mid)return qmx(k<<1,l,mid,x,y);
        return qmx(k<<1|1,mid+1,r,x,y);
    }
    void modify2(int k,int l,int r,int x,int y,int w){
        if(x<=l&&r<=y){add[k]=w;return;}
        int mid=l+r>>1;pd(k);
        if(x<=mid)modify2(k<<1,l,mid,x,y,w);
        if(y>mid)modify2(k<<1|1,mid+1,r,x,y,w);
        up(k);
    }
    void change(int k,int l,int r,int x){
        if(l==r)return;
        int mid=l+r>>1;pd(k);
        if(x<=mid)change(k<<1,l,mid,x);
        else change(k<<1|1,mid+1,r,x);
        up(k);
    }
}s;
void push(int x){
    while(x){
        s.modify2(1,1,n,dfn[top[x]],dfn[x],0);
        x=f[top[x]];
    }
}
void del(int x){
    while(x){
        if(s.qsum(1,1,n,dfn[top[x]],dfn[top[x]]+siz[x]-1)==siz[top[x]]){
            s.modify2(1,1,n,dfn[top[x]],dfn[x],1);
            x=f[top[x]];
        }
        else {
            int l=dfn[top[x]],r=dfn[x];
            while(l<=r){
                int mid=l+r>>1;
                if(s.qsum(1,1,n,mid,mid+siz[rk[mid]]-1)==siz[rk[mid]])r=mid-1;
                else l=mid+1;
            }
            s.modify2(1,1,n,l,dfn[x],1);
            return;
        }
    }
}
int find(int x){
    while(x){
        if(s.qsum(1,1,n,dfn[top[x]],dfn[top[x]]+siz[x]-1)==siz[top[x]]){
            s.modify2(1,1,n,dfn[top[x]],dfn[x],1);
            x=f[top[x]];
        }
        else {
            int l=dfn[top[x]],r=dfn[x];
            while(l<=r){
                int mid=l+r>>1;
                if(s.qsum(1,1,n,mid,mid+siz[rk[mid]]-1)==siz[rk[mid]])r=mid-1;
                else l=mid+1;
            }
            s.modify2(1,1,n,l,dfn[x],1);
            return;
        }
    }
    return 1;
}
void add(int x,int w){
    int pos;
    if(s.qsum(1,1,n,dfn[x],dfn[x]+siz[x]-1)==siz[x])pos=s.qmn(1,1,n,dfn[x],dfn[x]+siz[x]-1);
    else pos=s.mn[1];
    int nw=*st1[pos].begin();
    if(nw<w||nw==inf){
        st1[x].insert(w);
        s.modify1(1,1,n,x,1);
        s.modify2(1,1,n,pos,-1);
    }
    else{

    }
}*/
int main(){
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    cin>>T;
    cin>>n>>k>>m;
    rep(i,2,n){
        int x;
        scanf("%d",&x);
        v[x].push_back(i);
    }
    rep(i,0,n)st1[i].insert(inf),st2[i].insert(0);
    rep(i,1,k){
        scanf("%d%d",&a[i],&b[i]);
    }
   // dfs(1,0);dfs1(1,0);
    //ll ans=0;
    //for(auto x:vec[1])ans+=b[x];
    // s.build(1,1,n);
    //rep(i,1,n)add(a[i],b[i]);
    printf("%lld ",solve());
    while(m--){
        int op,x,y;
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d",&x,&y);
            a[++k]=x,b[k]=y;
            
        }
        else{
            scanf("%d",&x);
            a[x]=0;
            //delet(a[x],b[x]);
        }
        printf("%lld ",solve());
    }
} 