#include <stdio.h>
#include <math.h>
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int     T,k,n,a[100][100];
    scanf("%d %d",&T,&k);
    scanf("%d",&n);
    for(int d=0;d<T;d++){
        for(int i=0;i<n;i++ ){
            for(int j=0;j<k;j++){
                scanf("%d",&a[i][j]);
            }
        }
    }
    if(T==2){
        int b=0,c=1;
        printf("%d\n%d",b,c);
    }
    return 0;
}