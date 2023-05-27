#include<bits/stdc++.h>
using namespace std;
long long int a[100010][10010];
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int x;
    scanf("%d",&x);
    while(x--){
        long long int n,m,c;
        scanf("%lld%lld%lld",&n,&m,&c);
        for(int i=1;i<=n;i++)
          for(int j=1;j<=m;j++){
              a[i][j]=0;
          }
        for(int i=1;i<=c;i++)
        {
            long long int o,y,d;
            scanf("%lld%lld%lld",&o,&y,&d);
            if(o==1){
                for(int j=1;j<=m;j++)
                  a[y][j]=d;
                }
            else {
                for(int j=1;j<=n;j++)
                  a[n][y]=d;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++){
                printf("%lld ",a[i][j]);
            }
            printf("\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
