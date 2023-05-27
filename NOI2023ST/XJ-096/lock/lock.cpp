#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,mod=998244353,inf=1e9;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define pre(i,r,l) for(int i=r;i>=l;i--)
#define ll long long
#define fi first
#define se second
int a[N][4],Mn[N][4],Mx[N][4],res[N],b[N],ans,n,m,T;
void dfs(int x){
    if(x==n+1){
        ans=res[x-1];
        return;
    }
    if(res[x-1]>=ans)return;
    rep(i,0,m-1){
        res[x]=res[x-1];
        rep(j,0,m-1){
            Mn[x][(i+j)%m]=min(Mn[x-1][(i+j)%m],a[x][i]);
            Mx[x][(i+j)%m]=max(Mx[x-1][(i+j)%m],a[x][i]);
            res[x]=max(res[x],Mx[x][(i+j)%m]-Mn[x][(i+j)%m]);
        }
        dfs(x+1);
    }
}
void solve(){
    ans=inf;
    cin>>n;int mx=0,mn=1e9;
    rep(i,0,m-1){
        rep(j,1,n)scanf("%d",&a[j][i]);
    }
    if(m==1){
        rep(i,1,n){
            mx=max(mx,a[i][0]);
            mn=min(mn,a[i][0]);
        }
        printf("%d\n",mx-mn);
    }
    if(m==2){
        rep(i,1,n){
            if(a[i][0]>a[i][1])swap(a[i][0],a[i][1]);
            mx=max(mx,a[i][1]);
            mn=min(mn,a[i][0]);
        }
        int ans=0;
        rep(i,1,n){
            ans=max(ans,a[i][0]-mn);
            ans=max(ans,mx-a[i][1]);
        }
        printf("%d\n",ans);
    }
    else{
        rep(i,0,m-1)Mn[0][i]=1e9,Mx[0][i]=0;
        dfs(1);
        printf("%d\n",ans);
    }
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>T>>m;
    while(T--){solve();}
}
