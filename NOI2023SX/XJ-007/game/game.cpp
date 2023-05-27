#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define pre(i,r,l) for(int i=r;i>=l;i--)
#define ll long long
#define fi first
#define se second
#define pir pair<int,int>
using namespace std;
const int N=2e5+10;
int T,n,m,fa[N],vis[N];
int find(int x){
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}
int a[N][2],b[N][2],n1,n2;
vector<int>vec[N];
void solve(){
    cin>>n>>m;
    rep(i,1,n)vis[i]=0,fa[i]=i;
    rep(i,1,n){
        int len,x,y;
        scanf("%d",&len);
        scanf("%d",&a[i][0]);
        if(len==2)scanf("%d",&a[i][1]);

    }
    rep(i,1,m){
        vis[i]=0,fa[i]=i;
    }
    bool flag=1;
    rep(i,1,m){
       int len,x,y;
        scanf("%d",&len);
        scanf("%d",&x);
        if(len==2)scanf("%d",&y);
        else y=x;
        if(vis[find(x)]&&vis[find(y)])flag=0;
        if(find(x)==find(y))vis[find(x)]=1;
        else fa[find(x)]=find(y),vis[find(x)]|=vis[find(y)]; 
    }
    if(!flag){puts("-1");return;}
    else printf("%d\n",m-1);
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>T;
    while(T--)solve();
}