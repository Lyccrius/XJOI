#include<bits/stdc++.h>
using namespace std;
int main()
{
      freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    int a,b,c=0,j,i,v[100]={0};
    cin>>a>>b;
    if(b==1)
    {cout<<a;
    return 0;
    }
    if(b==2)
    for(j=1;j<=a;j++)
    for(i=1;i<=100;i++)
    if(i*i==j||i*i*i==j||i*i*i*i==j||i*i*i*i*i==j)
   { c+=1;break;}
    cout<<c;
       if(b==3)
    for(j=1;j<=a;j++)
    for(i=1;i<=100;i++)
    if(i*i*i==j||i*i*i*i==j||i*i*i*i*i==j)
   { c+=1;break;}
    cout<<c;
    return 0;
}