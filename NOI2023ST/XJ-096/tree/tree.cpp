#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10,mod=998244353,inf=1e9;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define pre(i,r,l) for(int i=r;i>=l;i--)
#define ll long long
#define fi first
#define se second
int n,T;
double f[N][N][2],d[N][N],a[N],b[N];
double dis(int x,int y){
    return sqrt((a[x]-a[y])*(a[x]-a[y])+(b[x]-b[y])*(b[x]-b[y]));
}
double ddis(int x,int y){
    if(x>n)x-=n;if(y>n)y-=n;
   // cout<<x<<" "<<y<<endl;
    if(x>y)swap(x,y);
    return d[x][y];
}
void find(int x,int y,int o){
    //cout<<x<<" "<<y<<endl;
    //cout<<f[x][y][o]<<endl;
    if(x<y){
    if(!o){
        //if(f[x][y][o]=f[x][y-1][1]+ddis(x,y-1))find(x,y-1,1);
        if(f[x][y][o]==f[x+1][y][0]+ddis(x,x+1))find(x+1,y,0);
        else if(f[x][y][o]==f[x+1][y][1]+ddis(x,y))find(x+1,y,1);
    }
    else{
        if(f[x][y][o]==f[x][y-1][0]+ddis(x,y))find(x,y-1,0);
        //else if(f[x][y][o]=f[x+1][y][0]+ddis(y,x+1))find(x+1,y,0);
        else if(f[x][y][o]==f[x][y-1][1]+ddis(y-1,y))find(x,y-1,1);
    }
    }
    if(y>n)y-=n;if(x>n)x-=n;
    if(o)printf("%d ",y);
    else printf("%d ",x);
}
void solve(){
    cin>>n;int pos=1;
    rep(i,1,n)scanf("%lf%lf",&a[i],&b[i]);
    rep(i,1,n)if(b[i]>b[pos])pos=i;
    rep(i,1,2*n)f[i][i][0]=f[i][i][1]=inf;
    f[pos][pos][0]=f[pos][pos][1]=f[pos+n][pos+n][1]=f[pos+n][pos+n][0]=0;
    rep(i,1,n)rep(j,i,n)d[i][j]=dis(i,j);
    rep(i,1,n)a[n+i]=a[i];
   // cout<<pos<<endl;
   // rep(i,1,n*2)rep(j,i+1,n*2)f[i][j][0]=f[i]=inf;
    rep(len,2,n){
        rep(i,1,2*n-len+1){
            int j=i+len-1;
            //dp[i][j]=min(dp[i][j-1]+min(ddis(j,i),ddis(j,j-1)),dp[i+1][j]+min(ddis(j,i),ddis(i,i+1)))
            f[i][j][0]=min(f[i+1][j][0]+ddis(i,i+1),f[i+1][j][1]+ddis(i,j));
            f[i][j][1]=min(f[i][j-1][0]+ddis(i,j),f[i][j-1][1]+ddis(j,j-1));
        }
    }
    double ans=inf;
    rep(i,1,n+1){
        ans=min(ans,f[i][i+n-1][0]);
        ans=min(ans,f[i][i+n-1][1]);
    }
    //cout<<ans<<endl;
    rep(i,1,n+1){
        if(ans==f[i][i+n-1][0]){find(i,i+n-1,0);exit(0);}
        if(ans==f[i][i+n-1][1]){find(i,i+n-1,1);exit(0);}
    }
   // printf("%lf",ans);
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    T=1;
    while(T--){solve();}
    
}
