#include<bits/stdc++.h>
using namespace std;
const int N=150010;
int s[N],t[N],vis[N],viss[N],vist[N];
void start(){
    memset(s,0,sizeof s);
    memset(t,0,sizeof t);
    memset(vis,0,sizeof vis);
    memset(viss,0,sizeof viss);
    memset(vist,0,sizeof vist);
}
void mian(){
    start();
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int kt;
        scanf("%d",&kt);
        for(int j=1;j<=kt;j++){
            int ts;
            scanf("%d",&ts);
            if(!vis[ts]&&!viss[i]){
                vis[ts]=1;
                s[i]=ts;
                viss[i]=1;
            }
        }
    }
    int ans=0;
    memset(vis,0,sizeof vis);
    for(int i=1;i<=n;i++){
        int kt;
        scanf("%d",&kt);
        for(int j=1;j<=kt;j++){
            int tt;
            scanf("%d",&tt);
            if(kt==1){
                if(vist[tt]){
                    printf("-1\n");
                    return;
                }
                else vist[tt]=1;
            }
            if(!vis[tt]){
                vis[tt]=1;
                ans++;
            }
        }
        if(ans<i){
            printf("-1\n");
            return;
        }
    }
    printf("0\n");
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int tl;
    scanf("%d",&tl);
    for(int i=1;i<=tl;i++) mian();
    return 0;
}