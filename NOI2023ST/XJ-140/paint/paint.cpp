#include<bits/stdc++.h>
using namespace std;
int path[10010][10010];
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int T,n,opt,m,q,x,c;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n>>m>>q;
        memset(path,0,sizeof path);
        for(int j=1;j<=q;j++){
            scanf("%d%d%d",&opt,&x,&c);
            if(opt==0){
                for(int i=1;i<=m;i++){
                    path[x][i]=c;
                }
            }
            else{
                for(int i=1;i<=n;i++){
                    path[i][x]=c;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                printf("%d ",path[i][j]);
            }
            puts(" ");
        }
    }
    return 0;

}