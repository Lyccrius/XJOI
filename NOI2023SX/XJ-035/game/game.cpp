#include<bits/stdc++.h>
using namespace std;
int id ,T,n,m,vis[3000005];
int s[1000005][3],t[1000005][3];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>T;
    while(T--){
        scanf("%d %d",&n,&id);
        for(int i=1;i<=n;i++){
            scanf("%d",&m);
            for(int j=1;j<=m;j++){
                scanf("%d",&s[i][j]);
            }
        }
        int f=0,cheak=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&m);
            if(m==1){
                cheak++;
            }
            for(int j=1;j<=m;j++){
                scanf("%d",&t[i][j]);
                vis[t[i][j]]++;
                if(vis[t[i][j]]>=id){
                    cout<<-1;
                    f=1;
                    break;
                }   
            }
            if(f==1){
                break;
            }
        }
        if(f==1){
            break;
        }
        if(s[1][1]!=t[1][1]){
            cout<<0;
        }else{
            cout<<cheak;
        }
    }
    return 0;
}