#include<bits/stdc++.h>
using namespace std;
int a[10005][10005];
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int n,m,t,i,j,s,k,o,x,c;
    cin>>s;
    while(s--)
    {
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        a[i][j]=0;
        cin>>n>>m>>t;
        for(k=1;k<=t;k++)
        {
            cin>>o>>x>>c;
            if(o==0)
            {
                for(j=1;j<=m;j++)
                a[x][j]=c;
            }
            else
            {
                for(j=1;j<=n;j++)
                a[j][x]=c;
            }
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            cout<<a[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}