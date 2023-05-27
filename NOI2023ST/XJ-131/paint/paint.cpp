#include <stdio.h>
#include <math.h>
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int T,n,m,q,opt,x,c,a[100][100];
    scanf("%d",&T);
    for(int d=0;d<T;d++){
        scanf("%d %d %d ",&n,&m,&q);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                a[j][i]=0;
                for(int p=0;p<q;p++){
                    scanf("%d %d %d",&opt,&x,&c);
                    if(opt==0){
                        for(int i=0;i<x;i++){
                         a[j][i]=c;
                        }
                    }else{
                        for(int j=0;j<x;j++){
                        a[j][i]=c; 
                        }
                    } 
                }  
            printf("%d",a[j][i]);       
            }  
        }
    }
    return 0;
}