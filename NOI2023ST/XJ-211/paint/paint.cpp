#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
 int D;
 int n,m,p;
 int o,x,c;
 int b[2005][2005]
 scanf("%d",&D);
 for(int k=1;k<=D;k++)
 {

     scanf("%d %d %d",&n,&m,&p);
     for (int i=1;i<=p;i++)
     {

     scanf("%d %d %d",&o,&x,&c);
     if(o==0){
        for (int j=1;j<=m;j++){
            b[j][x]=c;
        }
       }
       else if(o==1)
        for (int j=1;j<=n;j++)
        b[j][x]=c;
     }
     for(int i=1;i<=n;i++)
 }
 for (int j=1;j<=m;j++)
 {

     printf("%d",b[i][j]);
     b[i][j]=0;
 }

return 0;
}
