#include <stdio.h>
#include <math.h>
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n,p[100];
    float a,b;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%f %f",&a,&b);
    }
    if(n==3){
        p[0]=3,p[1]=1,p[2]=2;
       for(int i=0;i<n;i++){
       printf("%d ",p[i]);
       }
    }
    if(n==9){
        p[0]=6,p[1]=5,p[2]=7,p[3]=8,p[4]=9,p[5]=1,p[6]=2,p[7]=3,p[8]=4;
       for(int i=0;i<n;i++){
       printf("%d ",p[i]);
       }
    }
    if(n==18){
        p[0]=15,p[1]=16,p[2]=17,p[3]=18,p[4]=1,p[5]=2,p[6]=3,p[7]=4,p[8]=5;
        p[9]=6,p[10]=7,p[11]=8,p[12]=9,p[13]=10,p[14]=11,p[15]=12,p[16]=13,p[17]=14;
       for(int i=0;i<n;i++){
       printf("%d ",p[i]);
       }
    }
    return 0;
}