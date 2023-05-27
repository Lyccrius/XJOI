#include<bits/stdc++.h>
using namespace std;
int a[100000][100000];
int main()
{

int n,m,q,t,i,j,k,x,c,o;
cin>>t;
while(t--)
{
cin>>n>>m>>t;
for(i=1;i<=t;i++)
{
cin>>o>>x>>c;
if(o==0)
{
for(j=1;j<=m;j++)
a[j][x]=c;
}
else
if(o==1)
{
for(j=1;j<=n;j++)
a[x][j]=c;
}
}
for(i=1;i<=n;i++)
{
for(j=1;j<=m;j++)
cout<<a[i][j];
cout<<endl;
}
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
a[i][j]=0;
}
return 0;
}