#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=20;
int T,n,m,ans,tot;
int a[maxn][3];
int b[maxn][3];
int at[maxn];
int bt[maxn];
int vis[maxn],w;
void work2(int x){
    if(x==(n+1)){
        w++;
        int flg=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(vis[bt[i]]==w){
                flg=1;
                break;
            }
            vis[bt[i]]=w;
            cnt+=(at[i]==bt[i]);
        }
        if(flg==0) tot=min(tot,cnt);
    }
    for(int i=1;i<=b[x][0];i++){
        bt[x]=b[x][i];
        work2(x+1);
    }    
}
void work1(int x){
    if(x==(n+1)){
        tot=n+1;
        work2(1);
        if(tot!=(n+1)) ans=max(ans,tot);
    }
    for(int i=1;i<=a[x][0];i++){
        at[x]=a[x][i];
        work1(x+1);
    }
}
int main(void){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>T;
    for(int t=1;t<=T;t++){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i][0];
            for(int j=1;j<=a[i][0];j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            cin>>b[i][0];
            for(int j=1;j<=b[i][0];j++){
                cin>>b[i][j];
            }
        }
        ans=-1;
        work1(1);
        cout<<ans<<endl;
    }
    return 0;
}