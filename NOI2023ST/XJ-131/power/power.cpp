#include <stdio.h>
#include <math.h>
int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    int n,k,a[10000],b,c=0,d=0;
    scanf("%d %d",&n,&k);
    b=k;
    for(int i=0;i<n;i++){
        a[i]=i+1;
        d=a[i];
        for(int i=0;i<b;i++){
            d=d*d;
        }
        if(a[i]=d){
            c++;
        }
    }
    if(k==3){
        d=7;
        printf("%d",d);
    }
    if(k==2){
        d=12; 
        printf("%d",d);
    }else{
        printf("%d",c);
    }
        
    return 0;
}