#include<cstdio>
#include<iostream>
using namespace std;
    struct{
    int f;
    int t;
    }
    num[1000][100];

int n;
int k;
int cnt;
int main(){
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    scnaf("%d %d",&n,&k);
    if(k==0){
        printf("%d",n);
        return 0;
    }
    for (int i=1;i<=n;i++)
    num[i];
    t=1;

   for (int i=k;i<=n;i++)
   {
       for(int j=k;j<=n;j++)
       {

           find(num[i],t,j);
       }
       for (int i=1;i<=n;i++){
        if(num[i],f==1){
            cnt++;
            printf("%d",num[i]);
        }
      }
    }
for (int i=1;i<=n;i++){
    if(num[i],t ,j);
}
printf("%d",cnt);
return 0;
}

