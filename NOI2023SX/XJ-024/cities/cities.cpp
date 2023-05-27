//no pts code by Curlin
#include<bits/stdc++.h>
using namespace std;
const int N=100010,mod=998244353;
struct edge{
    int u,v;
}e[N*4];
struct eg{
    int to,nxt;
}le[N*4];
int fa[N],flag[N*4],flagl[N*4],head[N];
int n,m,k,cnt,cntt;
long long res;
int find(int x){
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
void add(int u,int v){
    e[++cnt].u=u;
    e[cnt].v=v;
    flag[cnt]=1;
}
void addedge(int u,int v){
    le[++cntt].to=v;
    le[cntt].nxt=head[u];
    head[u]=cntt;
    flagl[cntt]=1;
}
/*bool cmp
void kruskal(){
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=m;i++){
        int u=find(e[i].u),v=find(e[i].v);
        if(u==v) continue;
        fa[v]=u;

    }
}*/
/*void dfs(int sum,int rest,int maxp,int nowp,int root){
    /*sum refers to the number of used edges
    rest refers to the number of rest points
    maxp refers to the number of the points of the biggest block
    nowp refers to the number of the points of the block that is building now
    root refers to the point that is the root of the block now
    if(m-sum<rest) return;
    for(int i=1;i<=m;i++){
        int u=find(e[i].u),v=find(e[i].v);
        if(u==v) continue;
        if(fa[u]==root){
            fa[v]=u;

        }
        fa[v]=u;
    }
}
void dfs(int amn,bool fl){
    if(amn==nowa){
        nowa=0;
        res=(res+1)%mod;
    }
    for(int i=1;i<=m;i++){
        flag[i]=0;
        if(!fl){
            for(int j=head[e[i].u];j;j=le[j].nxt){
                if(flagl)
            }
        }
    }
}*/
int main(){
    freopen("cities.in","r",stdin);
    freopen("cities.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        add(u,v);
        add(v,u);
        addedge(u,v);
        addedge(v,u);
    }
    for(int i=1;i<=n;i++) fa[i]=i;
    /*for(int i=1;i<=n/2;i++){
        if(n%i==0) dfs(i,0,n);
    }*/
    res=1;
    for(int i=1;i<=m/2;i++){
        res=res*i%mod;
    }
    cout<<res;
    return 0;
}