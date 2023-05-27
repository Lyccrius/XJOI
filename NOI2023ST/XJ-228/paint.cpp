#include<bits/stdc++.h>
using namespace std;
int a[1000][100000]={0},b[100][100000]={0},n,m;
int main()
{
int q,t,i,j,x,c,o;
cin>>t;
while(t--)
{
cin>>n>>m>>q;
for(i=1;i<=q;i++)
{
cin>>o>>x>>c;
if(o==0)
{
for(j=1;j<=m;j++)
a[x][j]=c;
b[x][j]=c;
}
if(o==1)
{
for(j=1;j<=n;j++)
a[j][x]=c;
b[j][x]=c;
}
}

for(i=1;i<=n;i++)
{
if(i>1000)
break;
for(j=1;j<=m;j++)
cout<<a[i][j]<<" ";
cout<<endl;
}
if(n>1000)
for(i=1;i<=n-1000;i++)
{
for(j=1;j<=m;j++)
cout<<b[i][j]<<" ";
cout<<endl;
}
for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
a[i][j]='0';
}
return 0;
}
