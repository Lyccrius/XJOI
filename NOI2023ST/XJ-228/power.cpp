#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,k,j,i,s=0,v[1000]={0};
long long int d;
cin>>n>>k;
if(k==1)
{
cout<<n;
return 0;
}
for(i=1;i<=n;i++)
for(j=k;j<=8;j++)
{
d=pow(i,j);
if(d<=n&&v[d]!=1)
{
v[d]=1;
s++;
}
}
cout<<s;
return 0;
}
