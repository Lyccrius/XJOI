#include<bits/stdc++.h>
using namespace std;
int a[1001][100001];
int main()
{
freopen("paint.in","r",stdin);
freopen("paint.out","w",stdout);

int t,n,m,q,opt,x,c;
for(int i=0;i<=1001;i++)
{
    for(int j=0;j<=100001;j++)
    a[i][j]==0;
}
cin>>t;
for(int i=1;i<=t;i++)
{
    cin>>n>>m>>q;
    for(int j=1;j<=q;j++)
    cin>>opt>>x>>c;
    if(opt==0)
    {
        for(int k=0;k<=m;k++)
        a[x][k]=c;
    }
    if(opt==1)
    {
        for(int t=0;t<=n;t++)
        {
        a[t][x]=c;
        }
    }

}
for(int i=0;i<=n;i++)
{
    for(int j=0;j<=m;j++)
    cout<<a[i][j];
}

return 0;
fclose(stdin);
fclose(stdout);
}