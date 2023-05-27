#include<bits/stdc++.h>
using namespace std;
int T,n,m,s[100010][2],t[100010][2],vis[100010];

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>T;
    int a;
    for(int i=1;i<=T;i++){
        scanf("%d%d",&n,&m);
        memset(vis,0,sizeof vis);
        for(int j=1;j<=n;j++){
            scanf("%d",&a);
            if(a==1)scanf("%d",&s[j][0]);
            else scanf("%d%d",&s[j][0],&s[j][1]);
        }
        for(int j=1;j<=n;j++){
            scanf("%d",&a);
            if(a==1){
                scanf("%d",&t[j][0]);
                vis[i]++;
            }
            else scanf("%d%d",&t[j][0],&t[j][1]);
        }
        for(int i=1;i<=n;i++){
            if(vis[i]>=2)cout<<-1<<endl;
            else cout<<"0"<<endl;
        }// :-( 
    }
    
    return 0;
}