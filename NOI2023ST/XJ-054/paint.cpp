#include <bits/stdc++.h>
using namespace std;
int t,a[10005][10005],n,m,q,opt,x,c;
int main(){
    scanf("%d",&t);
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    while(t--){
        memset(a,0,sizeof(a));
        scanf("%d %d %d",&n,&m,&q);
        while(q--){
            scanf("%d %d %d",&opt,&x,&c);
            if(opt){
                for(int i = 1;i<=n;i++)a[i][x] = c;
            }else{
                for(int i = 1;i<=m;i++)a[x][i] = c;
            }
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++)printf("%d ",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}
