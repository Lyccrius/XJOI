#include <cstdio>
#include <cstring>
using namespace std;
int T,n,m,q;
int a[1][110000];
int b[2100][2100];
int opt[110000],x[110000],c[110000];
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        n=0;m=0;q=0;
        memset(a,0,sizeof(int)*110000);
        memset(b,0,sizeof(int)*1100*1100);
        memset(opt,0,sizeof(int)*110000);
        memset(x,0,sizeof(int)*110000);
        memset(c,0,sizeof(int)*110000);
        scanf("%d%d%d",&n,&m,&q);
        int qwq=1;
        for(int j=1;j<=q;j++){
            scanf("%d%d%d",&opt[j],&x[j],&c[j]);
            if(opt[j]==0){
                qwq=j;
            }
        }
        if(n==1){
            if(opt[qwq]==0){
                for(int j=1;j<=m;j++){
                    a[0][j]=c[qwq];
                }
            }
            for(int j=qwq+1;j<=q;j++){
                a[0][x[j]]=c[j];
            }
            for(int j=1;j<=m;j++){
                printf("%d ",a[0][j]);
            }
            printf("\n");
        }
        else if(n<=2000){
            for(int j=1;j<=q;j++){
                if(opt[j]==1){
                    for(int k=1;k<=n;k++){
                        b[k][x[j]]=c[j];
                    }
                }
                else if(opt[j]==0){
                for(int k=1;k<=m;k++){
                        b[x[j]][k]=c[j];
                    }
                }
            }
            for(int j=1;j<=n;j++){
                for(int k=1;k<=m;k++){
                    printf("%d ",b[j][k]);
                }
                printf("\n");
            }
        }
        else{
            if(qwq==1&&opt[qwq]==1){
                for(int j=1;j<=q;j++){
                    a[0][x[j]]=c[j];
                }
                for(int j=1;j<=n;j++){
                    for(int k=1;k<=m;k++){
                        printf("%d ",a[0][k]);
                    }
                    printf("\n");
                }
            }
            else{
                
            }
        }
    }
    return 0;
}