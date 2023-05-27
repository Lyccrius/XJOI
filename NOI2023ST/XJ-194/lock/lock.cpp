#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=50010;
int T,k,n;
int a[5][N];
int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>T>>k;
    while(T--)
    {
       cin>>n;
       for(int i=1;i<=k;i++)
       {
           for(int j=1;j<=n;j++)
           {
               cin>>a[i][j];
           }
       } 
       if(k==1)
       {
           cout<<"0"<<endl;
           continue;
       }
       if(k==2)
       {
           int flag=0;
           for(int i=1;i<=n;i++)
           {
               if(a[2][1]-a[1][1]==0)
               {
                if(abs(a[2][i]-a[1][i])==1)
                 flag=1;
               }
               if(abs(a[2][1]-a[1][1])==1)
               {
                   if(a[2][i]-a[1][i]==0)
                   flag=1;
               }
           }
           cout<<flag<<endl;
           continue;
       }
    }
    return 0;
}