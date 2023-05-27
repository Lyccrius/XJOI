#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=1e6+10,mod=998244353;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define pre(i,r,l) for(int i=r;i>=l;i--)
#define ll long long
#define fi first
#define se second
int T,n,m,q;
int f[M],g[M],c1[N],c2[N];
int op[N],x[N],y[N];
void init(){
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
}
void solve(){
    cin>>n>>m>>q;init();
    rep(i,1,q){
        scanf("%d%d%d",&op[i],&x[i],&y[i]);
        if(op[i]==1){
            f[x[i]]=i;c1[x[i]]=y[i];
        }
        else {
            g[x[i]]=i;c2[x[i]]=y[i];
        }
    }
    rep(i,1,n){
        rep(j,1,m){
           // cout<<i<<" "<<j<<" "<<f[j]<<" "<<g[i]<<endl;
            if(!f[j]&&!g[i])printf("0 ");
            else if(f[j]>g[i])printf("%d ",c1[j]);
            else printf("%d ",c2[i]);
        }puts("");
    }
}
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>T;
    while(T--)solve();
    fclose(stdin);
    fclose(stdout);
}