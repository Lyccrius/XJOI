#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,q;
int o,x,c;
int a[23170][23170];
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>t;
    for(int p=1;p<=t;p++)
    {
        cin>>n>>m>>q;
        for(int i=1;i<=q;i++)
        {
            cin>>o>>x>>c;
            if(o==0)
            {
                for(int si=1;si<=m;si++)
                {
                    a[x][si]=c;
                }
            }
            if(o==1)
            {
                for(int si=1;si<=n;si++)
                {
                    a[si][x]=c;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<a[i][j]<<' ';
            }
            cout<<endl;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                a[i][j]=0;
            }
        }
    }
    return 0;
}
