#include<bits/stdc++.h>
using namespace std;
const int N=1010;
struct edge{
    int to,nxt;
    double w;
}e[100000010];
priority_queue <int,vector<int>,greater<int> > heap;
int q[N][N];
int head[N],outd[N],vis[N];
double x[N],y[N],dist[N];
int cnt=0,n,bi=0,r,flag=1;
void add(int u,int v){
    e[++cnt].to=v;
    e[cnt].nxt=head[u];
    e[cnt].w=sqrt((x[u]-x[v])*(x[u]-x[v])+(y[u]-y[v])*(y[u]-y[v]));
    head[u]=cnt;
}
double dfs(int x){
    vis[x]=1;
    double des=0.0;
    for(int i=head[x];i;i=e[i].nxt){
        int j=e[i].to;
        if(vis[j]) continue;
        vis[j]=1;
        des=e[i].w+dfs(j);
        vis[j]=0;
    }
    return des;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    double res=99999999.9;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            add(i,j);
            add(j,i);
        }
    }
    double dmin=99999999.9;
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof vis);
        double dq=dfs(i);
        cout<<dfs(i)<<" ";
        if(res>dq) res=dq;
    }
    cout<<res<<endl;
    return 0;
}